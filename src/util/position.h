#pragma once

#include <stdbool.h>
typedef struct {
    int row;
    int col;
} Position;

Position position_create(int row, int col);

Position position_from_index(int index, int width);
int position_to_index(Position position, int width);

bool position_is_valid(Position position, int height, int width);
