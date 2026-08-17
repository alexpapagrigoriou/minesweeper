#pragma once

#include <stdbool.h>

#include "../game/board/board.h"

#define EXIT_ROWS 1
#define EXIT_COLS 5

#define CELL_SIZE 3
#define WALL_SIZE 1
#define CELL_WALL_SIZE (CELL_SIZE + WALL_SIZE)

#define BOARD_ROWS (BOARD_SIZE * CELL_WALL_SIZE + WALL_SIZE)
#define BOARD_COLS (BOARD_SIZE * CELL_WALL_SIZE + WALL_SIZE)

#define PLAY_AGAIN_ROWS 1
#define PLAY_AGAIN_COLS 12

extern int exit_start_row, exit_start_col;
extern int board_start_row, board_start_col;
extern int play_again_start_row, play_again_start_col;

void game_layout_update(void);

bool game_layout_is_exit(int row, int col);
int game_layout_get_board_cell(int row, int col);
bool game_layout_is_play_again(int row, int col);
