#pragma once

#include "../board/board.h"

#define BOARD_ROWS (BOARD_SIZE * 4 + 1)
#define BOARD_COLS (BOARD_SIZE * 4 + 1)

#define BOARD_START_ROW 2
#define BOARD_START_COL 2

#define WIN_ROWS (BOARD_ROWS + BOARD_START_ROW)
#define WIN_COLS (BOARD_COLS + BOARD_START_COL)

void layout_update(void);
