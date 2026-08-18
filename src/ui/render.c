#include "render.h"

#include <ncurses.h>
#include <stdint.h>
#include <string.h>

#include "colors.h"
#include "layout.h"

void render_window(void) {
    render_filled_box(win_start_row, win_start_col, WIN_ROWS, WIN_COLS, CP_BOX);

#ifdef DEBUG
    render_text(win_start_row, win_start_col, "[DEBUG MODE]", CP_BOX, A_BOLD);
#endif
}

void render_text(int row, int col, const char* msg, int color_pair, int attrs) {
    attron(COLOR_PAIR(color_pair) | attrs);
    mvaddstr(row, col, msg);
    attroff(COLOR_PAIR(color_pair) | attrs);
}

void render_text_centered(const char* msg, int color_pair, int attrs) {
    render_text(term_rows / 2, (term_cols - strlen(msg)) / 2, msg, color_pair, attrs);
}

void render_text_centered_col(int row, const char* msg, int color_pair, int attrs) {
    render_text(row, (term_cols - strlen(msg)) / 2, msg, color_pair, attrs);
}

void render_box(int row, int col, int rows, int cols, int color_pair) {
    attron(COLOR_PAIR(color_pair));

    mvhline(row, col, ' ', cols);
    mvvline(row, col, ' ', rows);
    mvhline(row + rows - 1, col, ' ', cols);
    mvvline(row, col + cols - 1, ' ', rows);

    attroff(COLOR_PAIR(color_pair));
}

void render_filled_box(int row, int col, int rows, int cols, int color_pair) {
    attron(COLOR_PAIR(color_pair));

    for (int i = 0; i < rows; i++) {
        mvhline(row + i, col, ' ', cols);
    }

    attroff(COLOR_PAIR(color_pair));
}

void render_grid(int row, int col, int rows, int cols, int spacing, int color_pair) {
    attron(COLOR_PAIR(color_pair));

    for (int i = 0; i < rows; i += spacing) {
        mvhline(row + i, col, ACS_HLINE, cols);
        mvvline(row, col + i, ACS_VLINE, cols);
    }

    mvaddch(row, col, ACS_ULCORNER);
    mvaddch(row, col + cols - 1, ACS_URCORNER);
    mvaddch(row + rows - 1, col, ACS_LLCORNER);
    mvaddch(row + rows - 1, col + cols - 1, ACS_LRCORNER);

    for (int i = spacing; i < rows - spacing; i += spacing) {
        mvaddch(row, col + i, ACS_TTEE);
        mvaddch(row + i, col, ACS_LTEE);
        mvaddch(row + rows - 1, col + i, ACS_BTEE);
        mvaddch(row + i, col + cols - 1, ACS_RTEE);

        for (int j = spacing; j < cols - spacing; j += spacing) {
            mvaddch(row + i, col + j, ACS_PLUS);
        }
    }

    attroff(COLOR_PAIR(color_pair));
}
