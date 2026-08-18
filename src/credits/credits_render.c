#include "credits_render.h"

#include <ncurses.h>

#include "../ui/colors.h"
#include "../ui/credits_layout.h"
#include "../ui/layout.h"
#include "../ui/render.h"

static void render_credits_box(void) {
    int credits_start_row = win_start_row + CREDITS_ROW_OFFSET;
    int credits_start_col = win_start_col + CREDITS_COL_OFFSET;

    int credits_rows = WIN_ROWS - CREDITS_ROW_OFFSET * 2 - BACK_BUTTON_ROWS - BACK_BUTTON_BOTTOM_OFFSET;
    int credits_cols = WIN_COLS - CREDITS_COL_OFFSET * 2;

    render_box(credits_start_row, credits_start_col, credits_rows, credits_cols, CP_BOX);

    credits_start_row++;
    credits_start_col++;

    credits_rows -= 2;
    credits_cols -= 2;

    render_filled_box(credits_start_row, credits_start_col, credits_rows, credits_cols, CP_CREDITS);

    credits_start_col++;

    credits_start_row++;
    render_text_centered_col(credits_start_row, "Credits", CP_CREDITS, A_BOLD | A_UNDERLINE);

    credits_start_row += 5;
    render_text_centered_col(credits_start_row, "Created by", CP_CREDITS, A_UNDERLINE);
    credits_start_row++;
    render_text_centered_col(credits_start_row, "Alexandros", CP_CREDITS, A_BOLD);
    credits_start_row++;
    render_text_centered_col(credits_start_row, "Papagrigoriou", CP_CREDITS, A_BOLD);

    credits_start_row += 5;
    render_text_centered_col(credits_start_row, "GitHub", CP_CREDITS, A_UNDERLINE);
    credits_start_row++;
    render_text_centered_col(credits_start_row, "https://github.com/", CP_CREDITS, A_BOLD);
    credits_start_row++;
    render_text_centered_col(credits_start_row, "alexpapagrigoriou", CP_CREDITS, A_BOLD);
}

static void render_back_button(void) {
    render_filled_box(back_button_start_row, back_button_start_col, BACK_BUTTON_ROWS, BACK_BUTTON_COLS, CP_BACK_BUTTON);
    render_text_centered_col(back_button_start_row + (BACK_BUTTON_ROWS / 2), "Back to Menu", CP_BACK_BUTTON, A_BOLD);
}

void credits_render(void) {
    clear();

    render_window();
    render_credits_box();
    render_back_button();

    refresh();
}
