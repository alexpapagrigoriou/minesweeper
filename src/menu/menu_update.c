#include "menu_update.h"

#include "../ui/menu_layout.h"

void menu_update(AppState* state, Action action) {
    if (menu_layout_is_button(BUTTON_PLAY, action.row, action.col)) {
        *state = APP_GAME;
        return;
    }

    if (menu_layout_is_button(BUTTON_CREDITS, action.row, action.col)) {
        *state = APP_CREDITS;
        return;
    }

    if (menu_layout_is_button(BUTTON_QUIT, action.row, action.col)) {
        *state = APP_QUIT;
        return;
    }
}
