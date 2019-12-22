#include "util.hpp"

void render_piece(WINDOW* win, int y, int x, int c) {
  wattron(win, COLOR_PAIR(c));

  mvwaddch(win, y, x, ACS_CKBOARD);
  mvwaddch(win, y, x + 1, ACS_CKBOARD);

  wattroff(win, COLOR_PAIR(c));
}
