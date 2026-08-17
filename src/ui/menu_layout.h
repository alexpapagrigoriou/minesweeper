#pragma once

#include <stdbool.h>

#define TITLE_ROWS 1
#define TITLE_COLS 11

#define TITLE_TOP_OFFSET 1

#define TITLE_BUTTON_ROW_OFFSET 2

#define BUTTON_ROWS 3
#define BUTTON_COLS 10

#define BUTTONS_OFFSET 1

extern int title_start_row, title_start_col;
extern int play_button_start_row, play_button_start_col;
extern int credits_button_start_row, credits_button_start_col;
extern int quit_button_start_row, quit_button_start_col;

void menu_layout_update(void);

bool menu_layout_is_play_button(int row, int col);
bool menu_layout_is_credits_button(int row, int col);
bool menu_layout_is_quit_button(int row, int col);
