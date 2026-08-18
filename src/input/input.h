#pragma once

#include <stdbool.h>

#define ACTION_BACK 0
#define ACTION_RESIZE 1

typedef struct {
    int row;
    int col;
    bool is_left_click;
} Action;

Action input_get(void);
