#include "game.h"

#include <ncurses.h>

#include "../input/input.h"
#include "game_render.h"
#include "game_update.h"

void game_init(Game *game) {
    game->state = GAME_RUNNING;
    game->render = true;
    game->first_move = true;
}

AppState game_run(int mines) {
    Game game;
    game.mines = mines;
    game_init(&game);

    while (game.state != GAME_EXIT) {
        game_render(&game);

        game_update(&game, input_get());

        if (game.state == GAME_QUIT) {
            return APP_QUIT;
        }
    }

    return APP_MENU;
}
