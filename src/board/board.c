#include "board.h"

#include <string.h>

#include "../util/random.h"
#include "position.h"

void board_init(Board* board) {
    memset(board, 0, sizeof(*board));

    random_init();

    for (int i = 0; i < MINE_COUNT; i++) {
        while (1) {
            int mine = random_range(0, BOARD_SIZE * BOARD_SIZE - 1);

            if (board->cells[mine] == MINE) {
                continue;
            }

            board->cells[mine] = MINE;
            board->mines |= 1 << mine;

            Position mine_pos = position_from_index(mine, BOARD_SIZE);

            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <= 1; col++) {
                    if (row == 0 && col == 0) {
                        continue;
                    }

                    int next_row = mine_pos.row + row;
                    int next_col = mine_pos.col + col;

                    if (next_row < 0 || next_row >= BOARD_SIZE || next_col < 0 || next_col >= BOARD_SIZE) {
                        continue;
                    }

                    int next_index = position_to_index(position_create(next_row, next_col), BOARD_SIZE);

                    if (board->cells[next_index] == MINE) {
                        continue;
                    }

                    board->cells[next_index]++;
                }
            }

            break;
        }
    }
}

bool board_is_complete(Board* board) {
    return ~(board->revealed | board->mines) == 0;
}

bool board_has_mine(Board* board, int index) {
    return board->mines & (1 << index);
}

bool board_is_revealed(Board* board, int index) {
    return board->revealed & (1 << index);
}

bool board_is_flagged(Board* board, int index) {
    return board->flags & (1 << index);
}

void board_reveal(Board* board, int index) {
    board->revealed |= 1 << index;
}

void board_toggle_flag(Board* board, int index) {
    board->flags ^= 1 << index;
}
