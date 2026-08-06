#pragma once

#include <stdbool.h>

#include "../board/board.h"

#define BOARD_ROWS (BOARD_SIZE * 4 + 1)
#define BOARD_COLS (BOARD_SIZE * 4 + 1)

#define WIN_BOARD_ROW_OFFSET 2
#define WIN_BOARD_COL_OFFSET 2

#define WIN_ROWS (BOARD_ROWS + WIN_BOARD_ROW_OFFSET * 2)
#define WIN_COLS (BOARD_COLS + WIN_BOARD_COL_OFFSET * 2)

#define EXIT_ROWS 1
#define EXIT_COLS 3

void layout_update(void);

int get_exit_start_row(void);
int get_exit_start_col(void);

int get_board_start_row(void);
int get_board_start_col(void);

bool layout_is_exit(int row, int col);
int layout_get_board_cell(int row, int col);
