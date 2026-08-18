#include "game.h"

#include <ncurses.h>

#include "../input/input.h"
#include "game_render.h"
#include "game_update.h"

void game_init(Game* game) {
    board_init(&game->board);
    game->state = GAME_RUNNING;
    game->render = true;
}

AppState game_run(void) {
    Game game;
    game_init(&game);

    while (game.state != GAME_EXIT) {
        game_render(&game);

        game_update(&game, input_get());
    }

    return APP_MENU;
}
