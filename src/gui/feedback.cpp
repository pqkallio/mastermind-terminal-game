#include <stdlib.h>
#include <chrono>
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

  std::chrono::nanoseconds present = std::chrono::system_clock::now().time_since_epoch();
  std::chrono::nanoseconds t = present + std::chrono::seconds(1);
  int i = 0;

  while (i < n) {
    present = std::chrono::system_clock::now().time_since_epoch();
    if (present >= t) {
      double wait_factor = rand() / RAND_MAX;
      int wait_ns = 1000000;
      t = present + std::chrono::nanoseconds(int(wait_ns * wait_factor));

      mvwaddch(this->feedback, y, x, ACS_DIAMOND);
      this->refresh();

      i++;
      x++;
    }
  }

  wattroff(this->feedback, COLOR_PAIR(c));
}

void Feedback::print_result(int round, int n_hits, int n_near) {
  int y = this->start_row + this->row_inc * round;
  int x = 1;

  this->insert(y, x, n_hits, RED_ON_BLACK);

  x += n_hits;

  this->insert(y, x, n_near, WHITE_ON_BLACK);
}
