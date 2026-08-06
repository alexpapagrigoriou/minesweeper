#include "game.h"

#include "ui/layout.h"

void game_init(Game* game) {
    board_init(&game->board);
    game->state = PLAYING;
    game->update = true;
}

void game_update(Game* game, Action action) {
    game->update = false;

    if (action.row == -1) {
        if (action.col == -1) {
            game->state = EXITED;
        }

        return;
    }

    if (action.is_left_click && layout_is_exit(action.row, action.col)) {
        game->state = EXITED;
        return;
    }

    // TODO: check if the move did something and if yes set update to true
    // game->update = true;
}
