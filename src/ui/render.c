#include "render.h"

#include <ncurses.h>

#include "colors.h"
#include "draw.h"
#include "layout.h"

static void render_window(void) {
    clear();
    draw_filled_box(get_win_start_row(), get_win_start_col(), WIN_ROWS, WIN_COLS, CP_BOX);
    refresh();
}

static void render_exit(void) {
    attron(COLOR_PAIR(CP_EXIT) | A_BOLD);
    mvaddstr(get_exit_start_row(), get_exit_start_col(), "  X  ");
    attroff(COLOR_PAIR(CP_EXIT) | A_BOLD);
}

static void render_board(Board* board) {
    int row = get_board_start_row();
    int col = get_board_start_col();

    draw_filled_box(row + 1, col + 1, BOARD_ROWS - 2, BOARD_COLS - 2, CP_CELL);

    draw_grid(row, col, BOARD_ROWS, BOARD_COLS, CELL_WALL_SIZE, CP_GRID);

    // TODO: render cells
    (void)board;
}

void render_game(Game* game) {
    if (!game->render) {
        return;
    }

    clear();

    render_window();
    render_exit();
    render_board(&game->board);

    refresh();
}

void render_end(Game* game) {
    if (game->state == EXITED) {
        return;
    }

    game->render = true;

    render_game(game);

    if (game->state == WON) {
        draw_text_won_msg();
    } else if (game->state == LOST) {
        draw_text_lost_msg();
    }

    refresh();

    getch();
}
