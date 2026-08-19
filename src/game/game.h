#pragma once

#include "../app_state.h"
#include "board/board.h"

typedef enum {
    GAME_RUNNING,
    GAME_WON,
    GAME_LOST,
    GAME_EXIT,
    GAME_QUIT
} GameState;

typedef struct {
    Board board;
    GameState state;
    bool render;
} Game;

void game_init(Game* game);

AppState game_run(void);
