#pragma once

#include <stdbool.h>

void draw_text_term_small_msg(void);
void draw_text_state_msg(bool won);
void draw_text_play_again(void);

void draw_box(int row, int col, int rows, int cols, int color_pair);
void draw_filled_box(int row, int col, int rows, int cols, int color_pair);

void draw_grid(int row, int col, int rows, int cols, int spacing, int color_pair);
