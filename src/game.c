#include "game.h"

void game_init(Game* game) {
    board_init(&game->board);
    game->state = PLAYING;
}

void game_update(Game* game, Position pos) {
    (void)game;
    (void)pos;
}
