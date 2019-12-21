#include "feedback.hpp"
#include "colors.hpp"

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

void Feedback::print_result(int round, int n_hits, int n_near) {
  int y = START_ROW + ROW_INC * round;
  int x = 1;

  wattron(this->feedback, COLOR_PAIR(RED_ON_BLACK));
  for (int i = 0; i < n_hits; i++) {
    mvwaddch(this->feedback, y, x, ACS_DIAMOND);
    x++;
  }
  wattroff(this->feedback, COLOR_PAIR(RED_ON_BLACK));

  wattron(this->feedback, COLOR_PAIR(WHITE_ON_BLACK));
  for (int i = 0; i < n_near; i++) {
    mvwaddch(this->feedback, y, x, ACS_DIAMOND);
    x++;
  }
  wattroff(this->feedback, COLOR_PAIR(WHITE_ON_BLACK));

  this->refresh();
}
