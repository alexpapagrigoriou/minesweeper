#pragma once

#include <stdbool.h>

#include "game_layout.h"

#define WIN_BOARD_ROW_TOP_OFFSET 2
#define WIN_BOARD_ROW_BOTTOM_OFFSET 3

#define WIN_BOARD_COL_LEFT_OFFSET 3
#define WIN_BOARD_COL_RIGHT_OFFSET 3

#define WIN_ROWS (BOARD_ROWS + WIN_BOARD_ROW_TOP_OFFSET + WIN_BOARD_ROW_BOTTOM_OFFSET)
#define WIN_COLS (BOARD_COLS + WIN_BOARD_COL_LEFT_OFFSET + WIN_BOARD_COL_RIGHT_OFFSET)

extern int term_rows, term_cols;
extern int win_start_row, win_start_col;

void layout_update(void);
