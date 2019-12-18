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

  this->current_col = 0;
  this->current_row = 0;
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

void Playfield::surround(int y, int x, char l, char r) {
  wattron(this->playfield, COLOR_PAIR(WHITE_ON_BLACK));
  mvwaddch(this->playfield, y, x - 1, l);
  mvwaddch(this->playfield, y, x + 1, r);
  wattron(this->playfield, COLOR_PAIR(WHITE_ON_BLACK));
}

void Playfield::highlight(int y, int x) {
  this->surround(y, x, '[', ']');
}

void Playfield::unhighlight(int y, int x) {
  this->surround(y, x, ' ', ' ');
}

int Playfield::view_col(int x) {
  return START_COL + x * COL_FACTOR;
}

int Playfield::view_row(int y) {
  return START_ROW + y * ROW_FACTOR;
}

void Playfield::rehighlight(int y, int x) {
  int vy = this->view_row(this->current_row);
  int vx = this->view_col(this->current_col);

  this->unhighlight(vy, vx);

  this->current_row = y;
  int nx = x < 0 ? x += 4 : x;
  nx %= 4;
  this->current_col = nx;

  vy = this->view_row(this->current_row);
  vx = this->view_col(this->current_col);

  this->highlight(vy, vx);
}

void Playfield::handle_input(int c) {
  switch (c) {
    case KEY_LEFT:
      this->rehighlight(this->current_row, this->current_col - COL_INC);
      break;
    case KEY_RIGHT:
      this->rehighlight(this->current_row, this->current_col + COL_INC);
      break;
    case 10: /* ENTER KEY */
      this->rehighlight(this->current_row + ROW_INC, 0);
      break;
  }
}

void Playfield::run() {
  int vy = this->view_row(this->current_row);
  int vx = this->view_col(this->current_col);

  this->highlight(vy, vx);
  this->refresh();

  while (1) {
    int c = wgetch(this->playfield);

    this->handle_input(c);

    this->refresh();
  }
}
