#include "reveal.h"

#include "../position.h"

static void rules_flood_reveal(Board* board, int start) {
    int queue[CELL_COUNT];
    int head = 0;
    int tail = 0;

    queue[tail++] = start;

    while (head < tail) {
        int index = queue[head++];

        if (board_is_revealed(board, index) || board_is_flagged(board, index)) {
            continue;
        }

        board_reveal(board, index);

        if (board->cells[index] != 0) {
            continue;
        }

        Position pos = position_from_index(index, BOARD_SIZE);

        for (int row = -1; row <= 1; row++) {
            for (int col = -1; col <= 1; col++) {
                if (row == 0 && col == 0) {
                    continue;
                }

                Position neighbor_pos = position_create(pos.row + row, pos.col + col);

                if (!position_is_valid(neighbor_pos, BOARD_SIZE, BOARD_SIZE)) {
                    continue;
                }

                int neighbor = position_to_index(neighbor_pos, BOARD_SIZE);

                queue[tail++] = neighbor;
            }
        }
    }
}

void rules_reveal_cell(Board* board, int index) {
    if (board->cells[index] == 0) {
        rules_flood_reveal(board, index);
    } else {
        board_reveal(board, index);
    }
}
