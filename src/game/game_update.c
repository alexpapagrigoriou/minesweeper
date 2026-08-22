#include "game_update.h"

#include <stdbool.h>

#include "../ui/game_layout.h"
#include "../util/sound.h"
#include "rules/reveal.h"

static void game_won(Game* game) {
    game->board.flagged = game->board.mines;
    game->state = GAME_WON;

    sound_play(SOUND_WIN);
}

static void game_lost(Game* game) {
    game->board.revealed |= game->board.mines & ~game->board.flagged;
    game->board.revealed |= game->board.flagged & ~game->board.mines;
    game->state = GAME_LOST;
    game->render = true;

    sound_play(SOUND_LOSE);
}

void game_update(Game* game, Action action) {
    game->render = false;

    if (action.row == -1) {
        if (action.col == ACTION_RESIZE) {
            game->render = true;
        } else if (action.col == ACTION_QUIT) {
            game->state = GAME_QUIT;
        } else if (action.col == ACTION_BACK) {
            game->state = GAME_EXIT;
        } else if (action.col == ACTION_RESTART) {
            if (!game->first_move) {
                game_init(game);
            }
        }

        return;
    }

    if (action.is_left_click && game_layout_is_exit(action.row, action.col)) {
        game->state = GAME_EXIT;
        return;
    }

    if (game->state != GAME_RUNNING) {
        if (game_layout_is_play_again(action.row, action.col)) {
            game_init(game);
            game->render = true;
        }

        return;
    }

    int index = game_layout_get_board_index(action.row, action.col);

    if (index == -1) {
        return;
    }

    if (game->first_move) {
        board_init(&game->board, game->mines, action.is_left_click ? index : -1);
        game->first_move = false;
    }

    if (board_is_revealed(&game->board, index)) {
        return;
    }

    if (!action.is_left_click) {
        board_toggle_flag(&game->board, index);
        game->render = true;

        sound_play(SOUND_TICK);
        return;
    }

    if (board_is_flagged(&game->board, index)) {
        return;
    }

    if (board_has_mine(&game->board, index)) {
        game->board.cells[index] = REVEALED_MINE;

        game_lost(game);
        return;
    }

    rules_reveal_cell(&game->board, index);
    game->render = true;

    if (!board_is_complete(&game->board)) {
        sound_play(SOUND_TICK);
        return;
    }

    game_won(game);
}
