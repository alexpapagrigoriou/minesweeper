#pragma once

void draw_text_centered(int term_rows, int term_cols, const char* msg, int color_pair, int attrs);
void draw_text_term_small_msg(int term_rows, int term_cols);

void draw_box(int row, int col, int rows, int cols, int color_pair);
void draw_filled_box(int row, int col, int rows, int cols, int color_pair);

void draw_grid(int row, int col, int rows, int cols, int spacing, int color_pair);
