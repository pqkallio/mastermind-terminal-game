#include "feedback.hpp"

Feedback::Feedback(int y, int x) {
  this->feedback = newwin(FB::WIN_HEIGHT, FB::WIN_WIDTH, y, x);

  wborder(
    this->feedback,
    ACS_VLINE, '|', '-', '-',
    ACS_TTEE, ACS_URCORNER, ACS_BTEE, ACS_LRCORNER
  );
}

Feedback::~Feedback() {
  delwin(this->feedback);
}

void Feedback::refresh() {
  wrefresh(this->feedback);
}

void Feedback::print_result(int round, int n_hits, int n_near) {}
