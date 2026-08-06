#include "input.h"

#include <ncurses.h>
#include <stdbool.h>

#include "../ui/layout.h"

#define KEY_ESC 27

static Action action_create(int row, int col, bool is_left_click) {
    Action action;

    action.row = row;
    action.col = col;
    action.is_left_click = is_left_click;

    return action;
}

Action input_get(void) {
    while (1) {
        int ch = getch();

        if (ch == KEY_RESIZE) {
            layout_update();
            continue;
        }

        if (ch == KEY_ESC) {
            return action_create(-1, -1, false);
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
