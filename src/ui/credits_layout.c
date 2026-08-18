#include "credits_layout.h"

#include "layout.h"

int back_button_start_row, back_button_start_col;

void credits_layout_update(void) {
    back_button_start_row = win_start_row + WIN_ROWS - BACK_BUTTON_ROWS - 1;
    back_button_start_col = (term_cols - BACK_BUTTON_COLS) / 2;
}

bool credits_layout_is_back_button(int row, int col) {
    return row >= back_button_start_row && row < back_button_start_row + BACK_BUTTON_ROWS &&
           col >= back_button_start_col && col < back_button_start_col + BACK_BUTTON_COLS;
}
