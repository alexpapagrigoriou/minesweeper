#include "menu_update.h"

#include "../ui/menu_layout.h"
#include "menu_render.h"

void menu_update(AppState* state, Action action) {
    if (action.row == -1) {
        if (action.col == ACTION_QUIT) {
            *state = APP_QUIT;
        } else if (action.col == ACTION_BACK) {
            *state = APP_QUIT;
        } else if (action.col == ACTION_RESIZE) {
            menu_render();
        }

        return;
    }

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
