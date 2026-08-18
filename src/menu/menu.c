#include "menu.h"

#include "../input/input.h"
#include "menu_render.h"
#include "menu_update.h"

AppState menu_run(void) {
    AppState state = APP_MENU;

    menu_render();

    while (state == APP_MENU) {
        menu_update(&state, input_get());
    }

    return state;
}
