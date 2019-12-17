#include "playfield.hpp"

Playfield::Playfield() {
  int w = 11;
  int h = 21;
  int y = 0;
  int x = (COLS - w) / 2;

  this->playfield = newwin(h, w, y, x);
  box(this->playfield, 0, 0);
}

Playfield::~Playfield() {
  delwin(this->playfield);
}

void Playfield::refresh() {
  wrefresh(this->playfield);
}
