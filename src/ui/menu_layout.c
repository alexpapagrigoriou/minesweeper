#include "menu_layout.h"

#include "layout.h"

int title_start_row, title_start_col;
int play_button_start_row, play_button_start_col;
int credits_button_start_row, credits_button_start_col;
int quit_button_start_row, quit_button_start_col;

void menu_layout_update(void) {
    title_start_row = win_start_row + TITLE_TOP_OFFSET;
    title_start_col = (term_cols - TITLE_COLS) / 2;

    play_button_start_row = title_start_row + TITLE_BUTTON_ROW_OFFSET;
    play_button_start_col = (term_cols - BUTTON_COLS) / 2;

    credits_button_start_row = play_button_start_row + BUTTON_ROWS + BUTTONS_OFFSET;
    credits_button_start_col = play_button_start_col;

    quit_button_start_row = credits_button_start_row + BUTTON_ROWS + BUTTONS_OFFSET;
    quit_button_start_col = play_button_start_col;
}

bool menu_layout_is_play_button(int row, int col) {
    return row >= play_button_start_row && row < play_button_start_row &&
           col >= play_button_start_col && col < play_button_start_col + BUTTON_COLS;
}

bool menu_layout_is_credits_button(int row, int col) {
    return row >= credits_button_start_row && row < credits_button_start_row &&
           col >= credits_button_start_col && col < credits_button_start_col + BUTTON_COLS;
}

bool menu_layout_is_quit_button(int row, int col) {
    return row >= quit_button_start_row && row < quit_button_start_row &&
           col >= quit_button_start_col && col < quit_button_start_col + BUTTON_COLS;
}
