#include "menu_render.h"

#include <ncurses.h>

#include "../ui/render.h"

void menu_render(void) {
    clear();

    render_window();
    // TODO: Implement menu render

    refresh();
}
