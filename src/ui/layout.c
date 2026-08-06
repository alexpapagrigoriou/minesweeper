#include "layout.h"

#include <ncurses.h>

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
    // TODO: return the index of the cell in the board
    //       return -1 if the cell is not in the board
    (void)row;
    (void)col;

    return -1;
}
