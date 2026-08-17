#include "sound.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool playable;

void sound_init(void) {
    playable = system("command -v paplay >/dev/null 2>&1") == 0;
}

void sound_play(Sound sound) {
    if (!playable) {
        return;
    }

    char* file;
    switch (sound) {
        case SOUND_TICK:
            file = "tick";
            break;
        case SOUND_WIN:
            file = "win";
            break;
        case SOUND_LOSE:
            file = "lose";
            break;
    }

    char command[64];
    snprintf(command, sizeof(command), "paplay assets/audio/%s.wav >/dev/null 2>&1 &", file);
    system(command);
}
