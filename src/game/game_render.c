#include "game_render.h"

#include <ncurses.h>

#include "../ui/colors.h"
#include "../ui/game_layout.h"
#include "../ui/layout.h"
#include "../ui/render.h"
#include "../util/position.h"
#include "cells/cell.h"

static void render_exit(void) {
    attron(COLOR_PAIR(CP_EXIT) | A_BOLD);
    mvaddstr(exit_start_row, exit_start_col, "  X  ");
    attroff(COLOR_PAIR(CP_EXIT) | A_BOLD);
}

#ifdef DEBUG
static void render_answer(Board* board) {
    int debug_start_row = win_start_row + 10;
    int debug_start_col = win_start_col + WIN_COLS + 1;

    int row = 0;
    int col = 0;

    mvaddstr(debug_start_row + row, debug_start_col + col, " [DEBUG ONLY]");

    row++;

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        if (i && i % BOARD_SIZE == 0) {
            row++;
            col = 0;
        }

        uint8_t cell = board->cells[i];

        if (cell == 0) {
            mvaddch(debug_start_row + row * 2, debug_start_col + col * 2, '0');
        } else {
            attron(COLOR_PAIR(cell_color(cell)) | A_BOLD);
            mvaddch(debug_start_row + row * 2, debug_start_col + col * 2, cell_symbol(cell));
            attroff(COLOR_PAIR(cell_color(cell)) | A_BOLD);
        }

        col++;
    }
}
#endif

static void render_board(Board* board) {
    render_filled_box(board_start_row + 1, board_start_col + 1, BOARD_ROWS - 2, BOARD_COLS - 2, CP_CELL);

    render_grid(board_start_row, board_start_col, BOARD_ROWS, BOARD_COLS, CELL_WALL_SIZE, CP_GRID);

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            int index = position_to_index(position_create(row, col), BOARD_SIZE);

            if (board_is_flagged(board, index)) {
                int cell_row = board_start_row + 1 + row * CELL_WALL_SIZE;
                int cell_col = board_start_col + 1 + col * CELL_WALL_SIZE;

                int cell = board_is_revealed(board, index) ? WRONG_FLAG : FLAG;

                render_filled_box(cell_row, cell_col, CELL_SIZE, CELL_SIZE, cell_color(cell));

                attron(COLOR_PAIR(cell_color(cell)) | A_BOLD);
                mvaddch(cell_row + 1, cell_col + 1, cell_symbol(cell));
                attroff(COLOR_PAIR(cell_color(cell)) | A_BOLD);
            } else if (board_is_revealed(board, index)) {
                int cell_row = board_start_row + 1 + row * CELL_WALL_SIZE;
                int cell_col = board_start_col + 1 + col * CELL_WALL_SIZE;

                uint8_t cell = board->cells[index];

                render_filled_box(cell_row, cell_col, CELL_SIZE, CELL_SIZE, cell_color(cell));

                attron(COLOR_PAIR(cell_color(cell)) | A_BOLD);
                mvaddch(cell_row + 1, cell_col + 1, cell_symbol(cell));
                attroff(COLOR_PAIR(cell_color(cell)) | A_BOLD);
            }
        }
    }
}

static void render_won_lost(bool won) {
    if (won) {
        render_text_centered_col(board_start_row - 1, " Victory! ", CP_WON, A_BOLD);
    } else {
        render_text_centered_col(board_start_row - 1, " Game Over! ", CP_LOST, A_BOLD);
    }
}

static void render_play_again(void) {
    render_filled_box(play_again_start_row, play_again_start_col, PLAY_AGAIN_ROWS, PLAY_AGAIN_COLS, CP_PLAY_AGAIN);
    render_text_centered_col(play_again_start_row + (PLAY_AGAIN_ROWS / 2), "Play Again", CP_PLAY_AGAIN, A_BOLD);
}

void game_render(Game* game) {
    if (!game->render) {
        return;
    }

    clear();

#ifdef DEBUG
    render_answer(&game->board);
#endif

    render_window();

    render_exit();
    render_board(&game->board);

    if (game->state != GAME_RUNNING) {
        render_won_lost(game->state == GAME_WON);
        render_play_again();
    }

    refresh();
}
