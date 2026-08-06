#include "minesweeper.h"

#include <ncurses.h>

#include "game.h"

void minesweeper_run(void) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(FALSE);

    Game game;
    game_init(&game);

    while (game.state == PLAYING) {
    }

    endwin();
}
