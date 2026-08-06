#pragma once

#include "board/board.h"
#include "input/input.h"

typedef enum {
    PLAYING,
    WON,
    LOST,
    EXITED
} GameState;

typedef struct {
    Board board;
    GameState state;
} Game;

void game_init(Game* game);

void game_update(Game* game, Action action);
