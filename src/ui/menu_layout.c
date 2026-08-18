#include "menu_layout.h"

#include "layout.h"

int title_start_row, title_start_col;
int buttons_start_row, buttons_start_col;

void menu_layout_update(void) {
    title_start_row = win_start_row + TITLE_TOP_OFFSET;
    title_start_col = (term_cols - TITLE_COLS) / 2;

    buttons_start_row = title_start_row + TITLE_BUTTON_ROW_OFFSET;
    buttons_start_col = (term_cols - BUTTON_COLS) / 2;
}

bool menu_layout_is_button(Button button, int row, int col) {
    return row >= buttons_start_row + ((int)button * (BUTTON_ROWS + BUTTONS_OFFSET)) &&
           row < buttons_start_row + ((int)button * (BUTTON_ROWS + BUTTONS_OFFSET)) + BUTTON_ROWS &&
           col >= buttons_start_col &&
           col < buttons_start_col + BUTTON_COLS;
}
