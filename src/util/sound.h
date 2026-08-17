#pragma once

typedef enum {
    SOUND_TICK,
    SOUND_WIN,
    SOUND_LOSE
} Sound;

void sound_init(void);
void sound_play(Sound sound);
