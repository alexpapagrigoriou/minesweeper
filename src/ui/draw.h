#pragma once

void draw_text_term_small_msg(void);
void draw_text_won_msg(void);
void draw_text_lost_msg(void);

void draw_box(int row, int col, int rows, int cols, int color_pair);
void draw_filled_box(int row, int col, int rows, int cols, int color_pair);

void draw_grid(int row, int col, int rows, int cols, int spacing, int color_pair);
