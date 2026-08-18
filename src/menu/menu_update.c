#include "menu_update.h"

#include "../ui/menu_layout.h"

void menu_update(AppState* state, Action action) {
    if (menu_layout_is_play_button(action.row, action.col)) {
        *state = APP_GAME;
        return;
    }

    if (menu_layout_is_credits_button(action.row, action.col)) {
        *state = APP_CREDITS;
        return;
    }

    if (menu_layout_is_quit_button(action.row, action.col)) {
        *state = APP_QUIT;
        return;
    }
}
