#include "colors.h"

#include <ncurses.h>

void colors_init(void) {
    start_color();

    init_pair(CP_BKGD, COLOR_WHITE, COLOR_BLACK);
    bkgd(COLOR_PAIR(CP_BKGD) | ' ');

    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
    init_pair(8, COLOR_MAGENTA, COLOR_BLACK);

    init_pair(CP_MINE, COLOR_RED, COLOR_BLACK);
    init_pair(CP_EXIT, COLOR_WHITE, COLOR_RED);
}
