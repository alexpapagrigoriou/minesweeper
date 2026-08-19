#include "menu_layout.h"

#include "layout.h"

int menu_buttons_start_row, menu_buttons_start_col;

void menu_layout_update(void) {
    menu_buttons_start_row = win_start_row + TITLE_TOP_OFFSET + TITLE_BUTTONS_ROW_OFFSET;
    menu_buttons_start_col = (term_cols - BUTTON_COLS) / 2;
}

bool menu_layout_is_button(Button button, int row, int col) {
    return row >= menu_buttons_start_row + ((int)button * (BUTTON_ROWS + BUTTONS_OFFSET)) &&
           row < menu_buttons_start_row + ((int)button * (BUTTON_ROWS + BUTTONS_OFFSET)) + BUTTON_ROWS &&
           col >= menu_buttons_start_col &&
           col < menu_buttons_start_col + BUTTON_COLS;
}
