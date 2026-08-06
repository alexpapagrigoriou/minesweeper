#include "game.h"

#include "ui/layout.h"

void game_init(Game* game) {
    board_init(&game->board);
    game->state = PLAYING;
    game->update = true;
}

void game_update(Game* game, Action action) {
    game->update = false;

    if (action.row == -1) {
        if (action.col == -1) {
            game->state = EXITED;
        }

        return;
    }

    if (action.is_left_click && layout_is_exit(action.row, action.col)) {
        game->state = EXITED;
        return;
    }

    int cell = layout_get_board_cell(action.row, action.col);

    if (cell == -1) {
        return;
    }

    if (board_is_revealed(&game->board, cell)) {
        return;
    }

    if (!action.is_left_click) {
        board_toggle_flag(&game->board, cell);
        game->update = true;
        return;
    }

    if (board_is_flagged(&game->board, cell)) {
        return;
    }

    if (board_has_mine(&game->board, cell)) {
        game->board.cells[cell] = LOST_MINE;
        game->state = LOST;
        return;
    }

    board_reveal(&game->board, cell);
    game->update = true;

    if (board_is_complete(&game->board)) {
        game->state = WON;
    }
}
