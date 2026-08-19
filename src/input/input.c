#include "input.h"

#include <ncurses.h>
#include <stdbool.h>

#include "../ui/layout.h"
#include "../util/signals.h"

static Action action_create(int row, int col, bool is_left_click) {
    Action action;

    action.row = row;
    action.col = col;
    action.is_left_click = is_left_click;

    return action;
}

Action input_get(void) {
    while (1) {
        if (should_quit) {
            return action_create(-1, ACTION_QUIT, false);
        }

        int ch = getch();

        if (ch == 'q') {
            return action_create(-1, ACTION_BACK, false);
        }

        if (ch == KEY_RESIZE) {
            layout_update();
            return action_create(-1, ACTION_RESIZE, false);
        }

        if (ch == KEY_MOUSE) {
            MEVENT event;

            if (getmouse(&event) != OK) {
                continue;
            }

            if (event.bstate & BUTTON1_CLICKED) {
                return action_create(event.y, event.x, true);
            }

            if (event.bstate & BUTTON3_CLICKED) {
                return action_create(event.y, event.x, false);
            }

            continue;
        }
    }
}
