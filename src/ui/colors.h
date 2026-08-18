#pragma once

enum {
    CP_MINE = 9,
    CP_REVEALED_MINE,

    CP_FLAG,
    CP_WRONG_FLAG,

    CP_REVEALED,

    CP_BKGD,

    CP_TERM_SMALL,

    CP_EXIT,
    CP_BOX,
    CP_GRID,
    CP_CELL,

    CP_WON,
    CP_LOST,
    CP_PLAY_AGAIN,

    CP_TITLE,
    CP_BUTTON_PLAY,
    CP_BUTTON_CREDITS,
    CP_BUTTON_QUIT,

    CP_CREDITS,
    CP_BACK_BUTTON
};

void colors_init(void);
