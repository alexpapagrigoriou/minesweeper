#pragma once

#include <stdbool.h>

#define CREDITS_ROW_OFFSET 1
#define CREDITS_COL_OFFSET 2

#define CREDIT_CREDIT_ROW_OFFSET 5

#define BACK_BUTTON_BOTTOM_OFFSET 1

#define BACK_BUTTON_ROWS 1
#define BACK_BUTTON_COLS 14

extern int credits_back_button_start_row, credits_back_button_start_col;

void credits_layout_update(void);

bool credits_layout_is_back_button(int row, int col);
