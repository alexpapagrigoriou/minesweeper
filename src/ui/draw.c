#include "draw.h"

#include <ncurses.h>
#include <string.h>

void draw_text_centered(int term_rows, int term_cols, const char* msg, int color_pair, int attrs) {
    attron(COLOR_PAIR(color_pair) | attrs);
    mvaddstr(term_rows / 2, (term_cols - strlen(msg)) / 2, msg);
    attroff(COLOR_PAIR(color_pair) | attrs);
}

void draw_text_term_small_msg(int term_rows, int term_cols) {
    clear();
    draw_text_centered(term_rows, term_cols, "Terminal too small", 0, A_BOLD);
    refresh();
}

void draw_box(int row, int col, int rows, int cols, int color_pair) {
    attron(COLOR_PAIR(color_pair));

    mvhline(row, col, ' ', cols);
    mvvline(row, col, ' ', rows);
    mvhline(row + rows - 1, col, ' ', cols);
    mvvline(row, col + cols - 1, ' ', rows);

    attroff(COLOR_PAIR(color_pair));
}

void draw_filled_box(int row, int col, int rows, int cols, int color_pair) {
    attron(COLOR_PAIR(color_pair));

    for (int i = 0; i < rows; i++) {
        mvhline(row + i, col, ' ', cols);
    }

    attroff(COLOR_PAIR(color_pair));
}

void draw_grid(int row, int col, int rows, int cols, int spacing, int color_pair) {
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
