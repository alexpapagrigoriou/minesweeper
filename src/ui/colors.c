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
    init_pair(CP_REVEALED_MINE, COLOR_BLACK, COLOR_RED);

    init_pair(CP_FLAG, COLOR_RED, COLOR_CYAN);
    init_pair(CP_WRONG_FLAG, COLOR_RED, COLOR_YELLOW);

    init_pair(CP_REVEALED, COLOR_BLACK, COLOR_BLACK);

    init_pair(CP_EXIT, COLOR_WHITE, COLOR_RED);
    init_pair(CP_BOX, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(CP_GRID, COLOR_WHITE, COLOR_BLACK);
    init_pair(CP_CELL, COLOR_BLACK, COLOR_CYAN);

    init_pair(CP_TERM_SMALL, COLOR_RED, COLOR_BLACK);
    init_pair(CP_WON, COLOR_GREEN, COLOR_BLACK);
    init_pair(CP_LOST, COLOR_RED, COLOR_BLACK);
    init_pair(CP_PLAY_AGAIN, COLOR_BLACK, COLOR_GREEN);
}
