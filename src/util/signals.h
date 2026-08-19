#pragma once

#include <signal.h>

extern volatile sig_atomic_t should_quit;

void signals_init(void);
