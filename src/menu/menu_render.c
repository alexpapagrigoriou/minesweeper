#include "menu_render.h"

#include <ncurses.h>

#include "../ui/colors.h"
#include "../ui/layout.h"
#include "../ui/menu_layout.h"
#include "../ui/render.h"

static void render_title(void) {
    int title_start_row = win_start_row + TITLE_TOP_OFFSET;
    int title_start_col = (term_cols - TITLE_COLS) / 2;

    render_filled_box(title_start_row, title_start_col, TITLE_ROWS, TITLE_COLS, CP_TITLE);
    render_text_centered_col(title_start_row + (TITLE_ROWS / 2), "Minesweeper", CP_TITLE, A_BOLD);
}

static void render_buttons(void) {
    char* button_texts[] = {"Play", "Credits", "Quit"};
    int button_color_pairs[] = {CP_BUTTON_PLAY, CP_BUTTON_CREDITS, CP_BUTTON_QUIT};

    for (int i = 0; i < BUTTONS; i++) {
        int row = buttons_start_row + ((int)i * (BUTTON_ROWS + BUTTONS_OFFSET));

        render_filled_box(row, buttons_start_col, BUTTON_ROWS, BUTTON_COLS, button_color_pairs[i]);
        render_text_centered_col(row + (BUTTON_ROWS / 2), button_texts[i], button_color_pairs[i], A_BOLD);
        render_box(row, buttons_start_col, BUTTON_ROWS, BUTTON_COLS, button_color_pairs[i]);
    }
}

void menu_render(void) {
    clear();

    render_window();
    render_title();
    render_buttons();

    refresh();
}
