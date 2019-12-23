#include "feedback.hpp"
#include "colors.hpp"

Feedback::Feedback(int y, int x) {
  this->feedback = newwin(FB::WIN_HEIGHT, FB::WIN_WIDTH, y, x);

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
  int y = START_ROW + ROW_INC * round;
  int x = 1;

  this->insert(y, x, n_hits, RED_ON_BLACK);

  x += n_hits;

  this->insert(y, x, n_near, WHITE_ON_BLACK);

  this->refresh();
}
