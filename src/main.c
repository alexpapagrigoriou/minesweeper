#include "app.h"

int main(void) {
    App app;

    app_init(&app);
    app_run(&app);
    app_cleanup();

    return 0;
}
