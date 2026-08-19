#pragma once

#include <stdbool.h>

enum {
    ACTION_QUIT,
    ACTION_BACK,
    ACTION_RESIZE
};

typedef struct {
    int row;
    int col;
    bool is_left_click;
} Action;

Action input_get(void);
