#pragma once

typedef enum {
    SOUND_TICK,
    SOUND_WIN,
    SOUND_LOSE,

    SOUND_COUNT
} Sound;

void sound_init(void);
void sound_play(Sound sound);
void sound_cleanup(void);
