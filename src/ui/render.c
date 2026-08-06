#include "render.h"

#include <ncurses.h>

#include "colors.h"
#include "layout.h"

static void render_exit(void) {
    attron(COLOR_PAIR(CP_EXIT) | A_BOLD);
    mvaddstr(get_exit_start_row(), get_exit_start_col(), "  X  ");
    attroff(COLOR_PAIR(CP_EXIT) | A_BOLD);
}

static void render_board(Board* board) {
    (void)board;
}

void render_game(Game* game) {
    clear();

    render_exit();
    render_board(&game->board);

    refresh();
}
