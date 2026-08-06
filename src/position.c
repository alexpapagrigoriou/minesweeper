#include "position.h"

Position position_create(int row, int col) {
    Position pos;

    pos.row = row;
    pos.col = col;

    return pos;
}

Position position_from_index(int index, int width) {
    Position pos;

    pos.row = index / width;
    pos.col = index % width;

    return pos;
}

int position_to_index(Position pos, int width) {
    return pos.row * width + pos.col;
}
