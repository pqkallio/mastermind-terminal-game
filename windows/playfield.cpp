#include "playfield.hpp"

Playfield::Playfield() {
  int w = 9;
  int y = 0;
  int x = (COLS - w) / 2;

  this->playfield = newwin(LINES, w, y, x);
  box(this->playfield, 0, 0);
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_BLACK, COLOR_BLUE);
  init_pair(3, COLOR_BLACK, COLOR_RED);
  init_pair(4, COLOR_BLACK, COLOR_YELLOW);

  wattrset(this->playfield, COLOR_PAIR(1));
  mvwaddch(this->playfield, LINES - 2, 1, ' ');
  wattrset(this->playfield, COLOR_PAIR(2));
  mvwaddch(this->playfield, LINES - 2, 3, ' ');
  wattrset(this->playfield, COLOR_PAIR(3));
  mvwaddch(this->playfield, LINES - 2, 5, ' ');
  wattrset(this->playfield, COLOR_PAIR(4));
  mvwaddch(this->playfield, LINES - 2, 7, ' ');
  wattrset(this->playfield, COLOR_PAIR(3));
  mvwaddch(this->playfield, LINES - 4, 1, ' ');
  wattrset(this->playfield, COLOR_PAIR(4));
  mvwaddch(this->playfield, LINES - 4, 3, 'X');
}

Playfield::~Playfield() {
  delwin(this->playfield);
}

void Playfield::refresh() {
  wrefresh(this->playfield);
}
