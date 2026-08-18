#include "sound.h"

#define INCBIN_PREFIX asset_
#define INCBIN_STYLE INCBIN_STYLE_SNAKE
#include "../vendor/incbin.h"

#define MINIAUDIO_IMPLEMENTATION
#include "../vendor/miniaudio.h"

INCBIN(tick_wav, "assets/sounds/tick.wav");
INCBIN(win_wav, "assets/sounds/win.wav");
INCBIN(lose_wav, "assets/sounds/lose.wav");

typedef struct {
    const unsigned char* data;
    unsigned int size;
} SoundAsset;

static ma_engine engine;
static ma_decoder decoders[SOUND_COUNT];
static ma_sound sounds[SOUND_COUNT];
static ma_bool32 initialized = MA_FALSE;

static SoundAsset sound_assets[SOUND_COUNT];

static void sound_assets_init(void) {
    sound_assets[SOUND_TICK].data = asset_tick_wav_data;
    sound_assets[SOUND_TICK].size = asset_tick_wav_size;

    sound_assets[SOUND_WIN].data = asset_win_wav_data;
    sound_assets[SOUND_WIN].size = asset_win_wav_size;

    sound_assets[SOUND_LOSE].data = asset_lose_wav_data;
    sound_assets[SOUND_LOSE].size = asset_lose_wav_size;
}

void sound_init(void) {
    if (initialized) {
        return;
    }

    if (ma_engine_init(NULL, &engine) != MA_SUCCESS) {
        initialized = MA_FALSE;
        return;
    }

    sound_assets_init();

    initialized = MA_TRUE;

    for (int i = 0; i < SOUND_COUNT; i++) {
        if (ma_decoder_init_memory(sound_assets[i].data, sound_assets[i].size, NULL, &decoders[i]) != MA_SUCCESS ||
            ma_sound_init_from_data_source(&engine, &decoders[i], 0, NULL, &sounds[i]) != MA_SUCCESS) {
            sound_cleanup();
            return;
        }
    }
}

void sound_play(Sound sound) {
    if (!initialized) {
        return;
    }

    ma_sound_seek_to_pcm_frame(&sounds[sound], 0);
    ma_sound_start(&sounds[sound]);
}

void sound_cleanup(void) {
    if (!initialized) {
        return;
    }

    for (int i = 0; i < SOUND_COUNT; i++) {
        ma_sound_uninit(&sounds[i]);
        ma_decoder_uninit(&decoders[i]);
    }

    ma_engine_uninit(&engine);

    initialized = MA_FALSE;
}
