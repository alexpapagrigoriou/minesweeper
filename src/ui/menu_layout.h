#pragma once

#include <stdbool.h>

#define TITLE_TOP_OFFSET 2

#define TITLE_ROWS 3
#define TITLE_COLS 15

#define TITLE_BUTTON_ROW_OFFSET 5

#define BUTTONS 3

#define BUTTON_ROWS 7
#define BUTTON_COLS 27

#define BUTTONS_OFFSET 3

typedef enum {
    BUTTON_PLAY,
    BUTTON_CREDITS,
    BUTTON_QUIT,
} Button;

extern int buttons_start_row, buttons_start_col;

void menu_layout_update(void);

bool menu_layout_is_button(Button button, int row, int col);
