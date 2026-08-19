#include "credits_update.h"

#include "../ui/credits_layout.h"
#include "credits_render.h"

void credits_update(AppState* state, Action action) {
    if (action.row == -1) {
        if (action.col == ACTION_QUIT) {
            *state = APP_QUIT;
        } else if (action.col == ACTION_BACK) {
            *state = APP_MENU;
        } else if (action.col == ACTION_RESIZE) {
            credits_render();
        }

        return;
    }

    if (credits_layout_is_back_button(action.row, action.col)) {
        *state = APP_MENU;
        return;
    }
}
