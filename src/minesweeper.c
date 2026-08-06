#include "minesweeper.h"

#include <ncurses.h>

#include "game.h"
#include "ui/colors.h"
#include "ui/draw.h"
#include "ui/layout.h"
#include "ui/render.h"

void minesweeper_run(void) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(FALSE);

    colors_init();

    layout_update();

    Game game;
    game_init(&game);

    while (game.state == PLAYING) {
        render_game(&game);

        Action action = input_get();

        game_update(&game, action);
    }

    if (game.state == WON) {
        draw_text_won_msg();
    } else if (game.state == LOST) {
        // TODO: show lost board
        draw_text_lost_msg();
    }

    endwin();
}
