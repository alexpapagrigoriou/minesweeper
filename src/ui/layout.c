#include "layout.h"

#include <ncurses.h>
#include <string.h>

#include "colors.h"
#include "game_layout.h"
#include "menu_layout.h"
#include "render.h"

int term_rows, term_cols;
int win_start_row, win_start_col;

static void render_text_term_small_msg(void) {
    clear();

    if ((int)strlen("Terminal too small") <= term_cols) {
        render_text_centered("Terminal too small", CP_TERM_SMALL, A_BOLD);
    } else {
        int row = term_rows / 2;

        render_text_centered_col(row - 1, "Terminal", CP_TERM_SMALL, A_BOLD);
        render_text_centered_col(row, "too", CP_TERM_SMALL, A_BOLD);
        render_text_centered_col(row + 1, "small", CP_TERM_SMALL, A_BOLD);
    }

    refresh();
}

void layout_update(void) {
    getmaxyx(stdscr, term_rows, term_cols);

    if (term_rows < WIN_ROWS || term_cols < WIN_COLS) {
        render_text_term_small_msg();

        while (1) {
            int ch = getch();

            if (ch != KEY_RESIZE) {
                continue;
            }

            getmaxyx(stdscr, term_rows, term_cols);

            if (term_rows < WIN_ROWS || term_cols < WIN_COLS) {
                render_text_term_small_msg();
                continue;
            }

            break;
        }
    }

    win_start_row = (term_rows - WIN_ROWS) / 2;
    win_start_col = (term_cols - WIN_COLS) / 2;

    menu_layout_update();
    game_layout_update();
}
