#include "minesweeper.h"

#include <ncurses.h>

#include "board/board.h"

void minesweeper_run(void) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(FALSE);

    Board board;
    board_init(&board);

    endwin();
}
