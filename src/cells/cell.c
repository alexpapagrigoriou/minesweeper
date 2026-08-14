#include "cell.h"

#include "../board/board.h"
#include "../ui/colors.h"

char cell_symbol(uint8_t cell) {
    if (cell >= 1 && cell <= 8) {
        return cell + '0';
    }

    switch (cell) {
        case 0:
            return ' ';
        case MINE:
        case REVEALED_MINE:
            return '*';
        case FLAG:
            return 'F';
    }

    return 'e';
}

int cell_color(uint8_t cell) {
    if (cell >= 1 && cell <= 8) {
        return cell;
    }

    switch (cell) {
        case 0:
            return CP_REVEALED;
        case MINE:
            return CP_MINE;
        case REVEALED_MINE:
            return CP_REVEALED_MINE;
        case FLAG:
            return CP_FLAG;
    }

    return 0;
}
