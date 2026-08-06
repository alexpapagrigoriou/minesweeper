#pragma once

#include <stdbool.h>

#include "../board/board.h"

#define CELL_SIZE 3
#define CELL_WALL_SIZE (CELL_SIZE + 1)

#define BOARD_ROWS (BOARD_SIZE * CELL_WALL_SIZE + 1)
#define BOARD_COLS (BOARD_SIZE * CELL_WALL_SIZE + 1)

#define WIN_BOARD_ROW_TOP_OFFSET 2
#define WIN_BOARD_ROW_BOTTOM_OFFSET 2

#define WIN_BOARD_COL_LEFT_OFFSET 3
#define WIN_BOARD_COL_RIGHT_OFFSET 3

#define WIN_ROWS (BOARD_ROWS + WIN_BOARD_ROW_TOP_OFFSET + WIN_BOARD_ROW_BOTTOM_OFFSET)
#define WIN_COLS (BOARD_COLS + WIN_BOARD_COL_LEFT_OFFSET + WIN_BOARD_COL_RIGHT_OFFSET)

#define EXIT_ROWS 1
#define EXIT_COLS 5

void layout_update(void);

int get_win_start_row(void);
int get_win_start_col(void);

int get_exit_start_row(void);
int get_exit_start_col(void);

int get_board_start_row(void);
int get_board_start_col(void);

bool layout_is_exit(int row, int col);
int layout_get_board_cell(int row, int col);
