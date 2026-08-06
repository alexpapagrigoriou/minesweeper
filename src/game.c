#include "game.h"

void game_init(Game* game) {
    board_init(&game->board);
    game->state = PLAYING;
}

void game_update(Game* game, Action action) {
    if (action.row == -1) {
        game->state = EXITED;
        return;
    }
}
