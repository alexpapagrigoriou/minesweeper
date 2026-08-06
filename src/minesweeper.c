#include "minesweeper.h"

#include <ncurses.h>

void minesweeper_run(void) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(FALSE);

    printw("Minesweeper");
    getch();

    endwin();
}
