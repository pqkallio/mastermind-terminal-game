#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <ncurses.h>
#include "../gamelogic/game.hpp"

namespace FB {
  const int WIN_WIDTH = 6;
  const int WIN_HEIGHT = 2 * rules::MAX_ROUNDS + 3;
}

class Feedback {
  const int START_ROW = FB::WIN_HEIGHT - 3;
  const int ROW_INC = -2;

  private:
    WINDOW *feedback;
    void insert(int y, int x, int n, int c);

  public:
    Feedback(int y, int x);
    ~Feedback();
    void refresh();
    void print_result(int round, int hits, int near);
};

#endif /* FEEDBACK_H */
