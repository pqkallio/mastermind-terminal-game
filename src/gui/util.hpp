#ifndef UTIL_H
#define UTIL_H

#include <ncurses.h>

void render_piece(WINDOW* win, int y, int x, int c);
void render_piece_row(WINDOW* win, int y, int x, int n, int* colors);

#endif /* UTIL_H */
