#include "layout.h"

#include <ncurses.h>

#include "text.h"

static int win_start_row, win_start_col;
static int board_start_row, board_start_col;

void layout_update(void) {
    int term_rows, term_cols;
    getmaxyx(stdscr, term_rows, term_cols);

    if (term_rows < WIN_ROWS || term_cols < WIN_COLS) {
        print_term_small_msg(term_rows, term_cols);

        while (1) {
            int ch = getch();

            if (ch != KEY_RESIZE) {
                continue;
            }

            getmaxyx(stdscr, term_rows, term_cols);

            if (term_rows < WIN_ROWS || term_cols < WIN_COLS) {
                print_term_small_msg(term_rows, term_cols);
                continue;
            }

            break;
        }
    }

    win_start_row = (term_rows - WIN_ROWS) / 2;
    win_start_col = (term_cols - WIN_COLS) / 2;

    board_start_row = win_start_row + BOARD_START_ROW;
    board_start_col = win_start_col + BOARD_START_COL;
}
