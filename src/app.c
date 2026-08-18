#include "app.h"

#include <ncurses.h>

#include "game/game.h"
#include "menu/menu.h"
#include "ui/colors.h"
#include "ui/layout.h"
#include "util/sound.h"

void app_init(App* app) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(FALSE);

    colors_init();
    layout_update();
    sound_init();

    app->state = APP_MENU;
    app->render = true;
}

void app_run(App* app) {
    while (app->state != APP_QUIT) {
        switch (app->state) {
            case APP_MENU:
                app->state = menu_run();
                break;
            case APP_GAME:
                app->state = game_run();
                break;
            case APP_CREDITS:
                // app->state = credits_run();
                break;
            case APP_QUIT:
                break;
        }
    }
}

void app_cleanup(void) {
    endwin();
}
