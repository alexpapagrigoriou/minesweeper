#include "credits.h"

#include "../input/input.h"
#include "credits_render.h"
#include "credits_update.h"

AppState credits_run(void) {
    AppState state = APP_CREDITS;

    credits_render();

    while (state == APP_CREDITS) {
        credits_update(&state, input_get());
    }

    return state;
}
