#include "game_layout.h"

#include "../util/position.h"
#include "layout.h"

int exit_start_row, exit_start_col;
int board_start_row, board_start_col;
int play_again_start_row, play_again_start_col;

void game_layout_update(void) {
    exit_start_row = win_start_row;
    exit_start_col = win_start_col + WIN_COLS - EXIT_COLS;

    board_start_row = win_start_row + WIN_BOARD_ROW_TOP_OFFSET;
    board_start_col = win_start_col + WIN_BOARD_COL_LEFT_OFFSET;

    play_again_start_row = win_start_row + WIN_ROWS - 2;
    play_again_start_col = (term_cols - PLAY_AGAIN_COLS) / 2;
}

bool game_layout_is_exit(int row, int col) {
    return row >= exit_start_row && row < exit_start_row + EXIT_ROWS &&
           col >= exit_start_col && col < exit_start_col + EXIT_COLS;
}

int game_layout_get_board_cell(int row, int col) {
    if (row < board_start_row + 1 || row > board_start_row + BOARD_ROWS - 2 ||
        col < board_start_col + 1 || col > board_start_col + BOARD_COLS - 2) {
        return -1;
    }

    row -= board_start_row;
    col -= board_start_col;

    if (row % CELL_WALL_SIZE == 0 || col % CELL_WALL_SIZE == 0) {
        return -1;
    }

    int board_row = row / CELL_WALL_SIZE;
    int board_col = col / CELL_WALL_SIZE;

    return position_to_index(position_create(board_row, board_col), BOARD_SIZE);
}

bool game_layout_is_play_again(int row, int col) {
    return row >= play_again_start_row && row < play_again_start_row + PLAY_AGAIN_ROWS &&
           col >= play_again_start_col && col < play_again_start_col + PLAY_AGAIN_COLS;
}
