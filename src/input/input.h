#pragma once

#include <stdbool.h>

typedef struct {
    int row;
    int col;
    bool is_left_click;
} Action;

Action input_get(void);
