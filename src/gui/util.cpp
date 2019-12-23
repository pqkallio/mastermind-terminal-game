#include "util.hpp"

void render_piece(WINDOW* win, int y, int x, int c) {
  wattron(win, COLOR_PAIR(c));

  mvwaddch(win, y, x, ACS_CKBOARD);
  mvwaddch(win, y, x + 1, ACS_CKBOARD);

  wattroff(win, COLOR_PAIR(c));
}

void render_piece_row(WINDOW* win, int y, int x, int n, int* colors) {
  for (int i = 0; i < n; i++) {
    render_piece(win, y, x, colors[i]);

    x += 3;
  }
}
