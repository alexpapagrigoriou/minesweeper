#pragma once

#include <stdbool.h>

#define TITLE_ROWS 1
#define TITLE_COLS 11

#define TITLE_TOP_OFFSET 1

#define TITLE_BUTTON_ROW_OFFSET 2

#define BUTTON_ROWS 3
#define BUTTON_COLS 10

#define BUTTONS_OFFSET 1

typedef enum {
    BUTTON_PLAY,
    BUTTON_CREDITS,
    BUTTON_QUIT,
} Button;

extern int title_start_row, title_start_col;
extern int buttons_start_row, buttons_start_col;

void menu_layout_update(void);

bool menu_layout_is_button(Button button, int row, int col);
