#include "board.h"

#include <string.h>

#include "../position.h"
#include "../util/random.h"

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
            board->mines |= UINT64_C(1) << mine;

            Position mine_pos = position_from_index(mine, BOARD_SIZE);

            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <= 1; col++) {
                    if (row == 0 && col == 0) {
                        continue;
                    }

                    Position neighbor_pos = position_create(mine_pos.row + row, mine_pos.col + col);

                    if (!position_is_valid(neighbor_pos, BOARD_SIZE, BOARD_SIZE)) {
                        continue;
                    }

                    int neighbor = position_to_index(neighbor_pos, BOARD_SIZE);

                    if (board->cells[neighbor] == MINE) {
                        continue;
                    }

                    board->cells[neighbor]++;
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
    return board->mines & (UINT64_C(1) << index);
}

bool board_is_revealed(Board* board, int index) {
    return board->revealed & (UINT64_C(1) << index);
}

bool board_is_flagged(Board* board, int index) {
    return board->flagged & (UINT64_C(1) << index);
}

void board_reveal(Board* board, int index) {
    board->revealed |= UINT64_C(1) << index;
}

void board_toggle_flag(Board* board, int index) {
    board->flagged ^= UINT64_C(1) << index;
}
