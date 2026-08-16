#pragma once

#include <stdbool.h>

#include "app_state.h"

typedef struct {
    AppState state;
    bool render;
} App;

void app_init(App* app);
void app_run(App* app);
void app_cleanup(void);
