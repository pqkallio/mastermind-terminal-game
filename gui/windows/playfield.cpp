#include "playfield.hpp"

void Playfield::init_color_pairs() {
  init_pair(BLACK_PIECE,    COLOR_BLACK,  COLOR_BLACK);
  init_pair(WHITE_PIECE,    COLOR_WHITE,  COLOR_WHITE);
  init_pair(YELLOW_PIECE,   COLOR_YELLOW, COLOR_YELLOW);
  init_pair(ORANGE_PIECE,   COLOR_YELLOW, COLOR_RED);
  init_pair(RED_PIECE,      COLOR_RED,    COLOR_RED);
  init_pair(PURPLE_PIECE,   COLOR_RED,    COLOR_BLUE);
  init_pair(BLUE_PIECE,     COLOR_BLUE,   COLOR_BLUE);
  init_pair(CYAN_PIECE,     COLOR_CYAN,   COLOR_CYAN);
  init_pair(GREEN_PIECE,    COLOR_GREEN,  COLOR_GREEN);
  init_pair(WHITE_ON_BLACK, COLOR_WHITE,  COLOR_BLACK);
}

void Playfield::init_window() {
  int y = (LINES - Playfield::WIN_HEIGHT) / 2;
  int x = (COLS - Playfield::WIN_WIDTH) / 2;

  this->playfield = newwin(Playfield::WIN_HEIGHT, Playfield::WIN_WIDTH, y, x);
  noecho();
  keypad(this->playfield, true);
  box(this->playfield, 0, 0);
}

Playfield::Playfield() {
  this->init_color_pairs();
  this->init_window();

  this->current_col = START_COL;
  this->current_row = START_ROW;
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

void Playfield::highlight(int y, int x) {
  wattron(this->playfield, COLOR_PAIR(WHITE_ON_BLACK));
  mvwaddch(this->playfield, y, x - 1, '[');
  mvwaddch(this->playfield, y, x + 1, ']');
  wattron(this->playfield, COLOR_PAIR(WHITE_ON_BLACK));

  this->refresh();
}

void Playfield::handle_input(char ch) {

}

void Playfield::run() {
  while (1) {
    this->highlight(current_row, current_col);

    char ch = wgetch(this->playfield);

    this->handle_input(ch);
  }
}
