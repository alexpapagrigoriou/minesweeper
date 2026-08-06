#include "text.h"

#include <ncurses.h>
#include <string.h>

void print_centered(int term_rows, int term_cols, const char* msg, int color_pair, int attrs) {
    attron(COLOR_PAIR(color_pair) | attrs);
    mvaddstr(term_rows / 2, (term_cols - strlen(msg)) / 2, msg);
    attroff(COLOR_PAIR(color_pair) | attrs);
}

void print_term_small_msg(int term_rows, int term_cols) {
    clear();
    print_centered(term_rows, term_cols, "Terminal too small", 0, A_BOLD);
    refresh();
}
