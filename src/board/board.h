#pragma once

#include <stdbool.h>
#include <stdint.h>

#define BOARD_SIZE 8
#define CELL_COUNT (BOARD_SIZE * BOARD_SIZE)

#define MINE 9
#define REVEALED_MINE 10

#define FLAG 11
#define WRONG_FLAG 12

#define MINE_COUNT 10

typedef struct {
    uint8_t cells[CELL_COUNT];

    uint64_t mines;
    uint64_t revealed;
    uint64_t flagged;
} Board;

void board_init(Board* board);

bool board_is_complete(Board* board);

bool board_has_mine(Board* board, int index);
bool board_is_revealed(Board* board, int index);
bool board_is_flagged(Board* board, int index);

void board_reveal(Board* board, int index);
void board_toggle_flag(Board* board, int index);
