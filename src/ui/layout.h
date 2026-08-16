#pragma once

#include <stdbool.h>

#include "game_layout.h"

#define WIN_BOARD_ROW_TOP_OFFSET 2
#define WIN_BOARD_ROW_BOTTOM_OFFSET 3

#define WIN_BOARD_COL_LEFT_OFFSET 3
#define WIN_BOARD_COL_RIGHT_OFFSET 3

#define WIN_ROWS (BOARD_ROWS + WIN_BOARD_ROW_TOP_OFFSET + WIN_BOARD_ROW_BOTTOM_OFFSET)
#define WIN_COLS (BOARD_COLS + WIN_BOARD_COL_LEFT_OFFSET + WIN_BOARD_COL_RIGHT_OFFSET)

void layout_update(void);

int get_term_rows(void);
int get_term_cols(void);

int get_win_start_row(void);
int get_win_start_col(void);
