#pragma once

void render_window(void);

void render_text(int row, int col, const char* msg, int color_pair, int attrs);
void render_text_centered(const char* msg, int color_pair, int attrs);
void render_text_centered_col(int row, const char* msg, int color_pair, int attrs);

void render_box(int row, int col, int rows, int cols, int color_pair);
void render_filled_box(int row, int col, int rows, int cols, int color_pair);
void render_grid(int row, int col, int rows, int cols, int spacing, int color_pair);
