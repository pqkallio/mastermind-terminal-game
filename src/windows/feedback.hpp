#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <ncurses.h>
#include "window.hpp"

namespace FB {
  const int WIN_WIDTH = 6;
  const int WIN_HEIGHT = 23;
}

class Feedback : public Window {
  const int START_ROW = FB::WIN_HEIGHT - 3;

  private:
    WINDOW *feedback;

  public:
    Feedback(int y, int x);
    ~Feedback();
    void refresh();
    void print_result(int round, int hits, int near);
};

#endif /* FEEDBACK_H */
