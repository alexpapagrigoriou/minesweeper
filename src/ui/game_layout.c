#include "game_layout.h"

#include "../util/position.h"
#include "layout.h"

int game_exit_start_row, game_exit_start_col;
int game_board_start_row, game_board_start_col;
int game_play_again_start_row, game_play_again_start_col;

void game_layout_update(void) {
    game_exit_start_row = win_start_row;
    game_exit_start_col = win_start_col + WIN_COLS - EXIT_COLS;

    game_board_start_row = win_start_row + WIN_BOARD_ROW_TOP_OFFSET;
    game_board_start_col = win_start_col + WIN_BOARD_COL_LEFT_OFFSET;

    game_play_again_start_row = win_start_row + WIN_ROWS - 2;
    game_play_again_start_col = (term_cols - PLAY_AGAIN_COLS) / 2;
}

bool game_layout_is_exit(int row, int col) {
    return row >= game_exit_start_row && row < game_exit_start_row + EXIT_ROWS &&
           col >= game_exit_start_col && col < game_exit_start_col + EXIT_COLS;
}

int game_layout_get_board_cell(int row, int col) {
    if (row < game_board_start_row + 1 || row > game_board_start_row + BOARD_ROWS - 2 ||
        col < game_board_start_col + 1 || col > game_board_start_col + BOARD_COLS - 2) {
        return -1;
    }

    row -= game_board_start_row;
    col -= game_board_start_col;

    if (row % CELL_WALL_SIZE == 0 || col % CELL_WALL_SIZE == 0) {
        return -1;
    }

    int board_row = row / CELL_WALL_SIZE;
    int board_col = col / CELL_WALL_SIZE;

    return position_to_index(position_create(board_row, board_col), BOARD_SIZE);
}

bool game_layout_is_play_again(int row, int col) {
    return row >= game_play_again_start_row && row < game_play_again_start_row + PLAY_AGAIN_ROWS &&
           col >= game_play_again_start_col && col < game_play_again_start_col + PLAY_AGAIN_COLS;
}
