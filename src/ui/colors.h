#pragma once

enum {
    CP_MINE = 9,
    CP_REVEALED_MINE,

    CP_FLAG,
    CP_WRONG_FLAG,

    CP_REVEALED,

    CP_BKGD,

    CP_EXIT,
    CP_BOX,
    CP_GRID,
    CP_CELL,

    CP_TERM_SMALL,
    CP_WON,
    CP_LOST,
    CP_PLAY_AGAIN
};

void colors_init(void);
