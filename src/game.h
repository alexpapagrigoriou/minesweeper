#pragma once

#include "board/board.h"
#include "position.h"

typedef enum {
    PLAYING,
    WON,
    LOST
} GameState;

typedef struct {
    Board board;
    GameState state;
} Game;

void game_init(Game* game);

void game_update(Game* game, Position pos);
