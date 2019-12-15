#include "playfield.hpp"

Playfield::Playfield() {
  int w = 8;
  int y = 0;
  int x = (COLS - w) / 2;

  Playfield::playfield = newwin(LINES, w, y, x);
  box(Playfield::playfield, 0, 0);
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);

  wattron(Playfield::playfield, COLOR_PAIR(1));
  mvwprintw(Playfield::playfield, 1, 1, "%s", "o");
  wattroff(Playfield::playfield, COLOR_PAIR(1));

  wattron(Playfield::playfield, COLOR_PAIR(2));
  mvwprintw(Playfield::playfield, 1, 2, "%s", "o");
  wattroff(Playfield::playfield, COLOR_PAIR(2));
}

Playfield::~Playfield() {
  delwin(Playfield::playfield);
}

void Playfield::refresh() {
  wrefresh(Playfield::playfield);
}
