#include "playfield.hpp"

void Playfield::init_color_pairs() {
  init_pair(BLACK,  COLOR_BLACK,  COLOR_BLACK);
  init_pair(WHITE,  COLOR_WHITE,  COLOR_WHITE);
  init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(ORANGE, COLOR_YELLOW, COLOR_RED);
  init_pair(RED,    COLOR_RED,    COLOR_RED);
  init_pair(PURPLE, COLOR_RED,    COLOR_BLUE);
  init_pair(BLUE,   COLOR_BLUE,   COLOR_BLUE);
  init_pair(CYAN,   COLOR_CYAN,   COLOR_CYAN);
  init_pair(GREEN,  COLOR_GREEN,  COLOR_GREEN);
}

void Playfield::init_window() {
  int y = (LINES - Playfield::WIN_HEIGHT) / 2;
  int x = (COLS - Playfield::WIN_WIDTH) / 2;

  this->playfield = newwin(Playfield::WIN_HEIGHT, Playfield::WIN_WIDTH, y, x);
  keypad(this->playfield, true);
  box(this->playfield, 0, 0);
}

Playfield::Playfield() {
  this->init_color_pairs();
  this->init_window();

  int PIECE_COLORS_LEN = 9;

  for (int i = 1; i <= PIECE_COLORS_LEN; i++) {
    wattron(this->playfield, COLOR_PAIR(i));
    mvwaddch(this->playfield, 1, i, ACS_CKBOARD);
    wattroff(this->playfield, COLOR_PAIR(i));
  }
}

Playfield::~Playfield() {
  delwin(this->playfield);
}

void Playfield::refresh() {
  wrefresh(this->playfield);
}

void Playfield::add_row() {
  for (auto &visualPiece : this->visualPieces) {
    visualPiece.color = 0;
    visualPiece.selected = false;
  }

  this->visualPieces[0].selected = true;

  this->current_row += Playfield::ROW_INC;
}
