#include "feedback.hpp"
#include "colors.hpp"

Feedback::Feedback(int y, int x, int h, int w) {
  this->feedback = newwin(h, w, y, x);
  this->start_row = h - 3;

  wborder(
    this->feedback,
    ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
    ACS_TTEE, ACS_URCORNER, ACS_BTEE, ACS_LRCORNER
  );
}

Feedback::~Feedback() {
  delwin(this->feedback);
}

void Feedback::refresh() {
  wrefresh(this->feedback);
}

void Feedback::insert(int y, int x, int n, int c) {
  wattron(this->feedback, COLOR_PAIR(c));

  for (int i = 0; i < n; i++) {
    mvwaddch(this->feedback, y, x, ACS_DIAMOND);
    x++;
  }

  wattroff(this->feedback, COLOR_PAIR(c));
}

void Feedback::print_result(int round, int n_hits, int n_near) {
  int y = this->start_row + this->row_inc * round;
  int x = 1;

  this->insert(y, x, n_hits, RED_ON_BLACK);

  x += n_hits;

  this->insert(y, x, n_near, WHITE_ON_BLACK);

  this->refresh();
}
