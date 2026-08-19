#include "signals.h"

#include <stddef.h>

volatile sig_atomic_t should_quit = 0;

static void handle_sigint(int sig) {
    (void)sig;
    should_quit = 1;

    signal(SIGINT, handle_sigint);
}

void signals_init(void) {
    signal(SIGINT, handle_sigint);
}
