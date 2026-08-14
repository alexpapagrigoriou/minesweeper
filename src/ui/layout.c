#include "layout.h"

#include <ncurses.h>

#include "../position.h"
#include "draw.h"

static int term_rows, term_cols;
static int win_start_row, win_start_col;
static int exit_start_row, exit_start_col;
static int board_start_row, board_start_col;

void layout_update(void) {
    getmaxyx(stdscr, term_rows, term_cols);

    if (term_rows < WIN_ROWS || term_cols < WIN_COLS) {
        draw_text_term_small_msg();

        while (1) {
            int ch = getch();

            if (ch != KEY_RESIZE) {
                continue;
            }

            getmaxyx(stdscr, term_rows, term_cols);

            if (term_rows < WIN_ROWS || term_cols < WIN_COLS) {
                draw_text_term_small_msg();
                continue;
            }

            break;
        }
    }

    win_start_row = (term_rows - WIN_ROWS) / 2;
    win_start_col = (term_cols - WIN_COLS) / 2;

    exit_start_row = win_start_row;
    exit_start_col = win_start_col + WIN_COLS - EXIT_COLS;

    board_start_row = win_start_row + WIN_BOARD_ROW_TOP_OFFSET;
    board_start_col = win_start_col + WIN_BOARD_COL_LEFT_OFFSET;
}

int get_term_rows(void) {
    return term_rows;
}

int get_term_cols(void) {
    return term_cols;
}

int get_win_start_row(void) {
    return win_start_row;
}

int get_win_start_col(void) {
    return win_start_col;
}

int get_exit_start_row(void) {
    return exit_start_row;
}

int get_exit_start_col(void) {
    return exit_start_col;
}

int get_board_start_row(void) {
    return board_start_row;
}

int get_board_start_col(void) {
    return board_start_col;
}

bool layout_is_exit(int row, int col) {
    return row >= exit_start_row && row < exit_start_row + EXIT_ROWS &&
           col >= exit_start_col && col < exit_start_col + EXIT_COLS;
}

int layout_get_board_cell(int row, int col) {
    if (row < board_start_row + 1 || row > board_start_row + BOARD_ROWS - 2 ||
        col < board_start_col + 1 || col > board_start_col + BOARD_COLS - 2) {
        return -1;
    }

    row -= board_start_row;
    col -= board_start_col;

    if (row % CELL_WALL_SIZE == 0 || col % CELL_WALL_SIZE == 0) {
        return -1;
    }

    int board_row = row / CELL_WALL_SIZE;
    int board_col = col / CELL_WALL_SIZE;

    return position_to_index(position_create(board_row, board_col), BOARD_SIZE);
}
