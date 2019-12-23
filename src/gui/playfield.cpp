#include "playfield.hpp"
#include "colors.hpp"
#include "util.hpp"

void Playfield::init_window(int y, int x, int h, int w) {
  this->playfield = newwin(h, w, y, x);
  noecho();
  keypad(this->playfield, true);
  box(this->playfield, 0, 0);
}

void Playfield::clear_pieces() {
  for (int i = 0; i < rules::LEN_ROW; i++) {
    this->pieces[i] = 0;
  }

  this->unselected = rules::LEN_ROW;
}

Playfield::Playfield(int y, int x, int h, int w) {
  this->init_window(y, x, h, w);
  this->clear_pieces();

  this->start_row = h - 3;

  this->current_col = 0;
  this->current_row = 0;
}

Playfield::~Playfield() {
  delwin(this->playfield);
}

void Playfield::refresh() {
  wrefresh(this->playfield);
}

bool Playfield::add_row() {
  if (this->unselected > 0) {
    return false;
  }

  return true;
}

void Playfield::surround(
  int y, int x,
  int ul, int ll, int ur, int lr,
  int ls, int rs, int ts, int bs
) {
  wattron(this->playfield, COLOR_PAIR(WHITE_ON_BLACK));

  // add corners
  mvwaddch(this->playfield, y - 1, x - 1, ul);
  mvwaddch(this->playfield, y + 1, x - 1, ll);
  mvwaddch(this->playfield, y - 1, x + 2, ur);
  mvwaddch(this->playfield, y + 1, x + 2, lr);

  // add sides
  mvwaddch(this->playfield, y, x - 1, ls);
  mvwaddch(this->playfield, y, x + 2, rs);
  mvwaddch(this->playfield, y - 1, x, ts);
  mvwaddch(this->playfield, y + 1, x, bs);

  wattron(this->playfield, COLOR_PAIR(WHITE_ON_BLACK));
}

void Playfield::highlight(int y, int x) {
  this->surround(
    y, x,
    ACS_ULCORNER, ACS_LLCORNER, ACS_URCORNER, ACS_LRCORNER,
    ' ', ' ', ' ', ' '
  );
}

void Playfield::unhighlight(int y, int x) {
  this->surround(
    y, x,
    ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' '
  );
}

int Playfield::view_col(int x) {
  return START_COL + x * COL_FACTOR;
}

int Playfield::view_row(int y) {
  return this->start_row + y * ROW_FACTOR;
}

void Playfield::rehighlight(int y, int x) {
  int vy = this->view_row(this->current_row);
  int vx = this->view_col(this->current_col);

  this->unhighlight(vy, vx);

  this->current_row = y;
  int nx = x < 0 ? x += rules::LEN_ROW : x;
  nx %= rules::LEN_ROW;
  this->current_col = nx;

  vy = this->view_row(this->current_row);
  vx = this->view_col(this->current_col);

  this->highlight(vy, vx);
}

void Playfield::change_piece_color(int n) {
  int c = this->pieces[this->current_col];
  bool us = c == 0;
  c = c + n;

  if (c < 0) {
    c += N_PIECE_COLORS;
  }

  c = c % N_PIECE_COLORS;

  if (us && c != 0) {
    this->unselected--;
  } else if (!us && c == 0) {
    this->unselected++;
  }

  this->pieces[this->current_col] = c;

  int vy = view_row(this->current_row);
  int vx = view_col(this->current_col);

  render_piece(this->playfield, vy, vx, c + 1);
}

bool Playfield::handle_input(int c) {
  switch (c) {
    case KEY_LEFT:
      this->rehighlight(this->current_row, this->current_col - COL_INC);
      return false;
    case KEY_RIGHT:
      this->rehighlight(this->current_row, this->current_col + COL_INC);
      return false;
    case KEY_UP:
      this->change_piece_color(1);
      return false;
    case KEY_DOWN:
      this->change_piece_color(-1);
      return false;
    case 10: /* ENTER KEY */
      return this->add_row();
    default:
      return false;
  }
}

std::vector<int> Playfield::get_selection(int round) {
  this->current_row = round;
  this->current_col = 0;

  int vy = this->view_row(this->current_row);
  int vx = this->view_col(this->current_col);

  this->highlight(vy, vx);
  this->refresh();

  while (true) {
    int c = wgetch(this->playfield);

    bool selection_done = this->handle_input(c);

    if (selection_done) {
      vy = this->view_row(this->current_row);
      vx = this->view_col(this->current_col);

      this->unhighlight(vy, vx);
      this->refresh();

      break;
    }

    this->refresh();
  }

  std::vector<int> selection = std::vector<int>(rules::LEN_ROW);

  for (int i = 0; i < rules::LEN_ROW; i++) {
    selection[i] = this->pieces[i];
  }

  this->clear_pieces();

  return selection;
}
