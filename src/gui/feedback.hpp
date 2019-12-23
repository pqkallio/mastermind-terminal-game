#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <ncurses.h>
#include "../gamelogic/game.hpp"

class Feedback {
  private:
    WINDOW *feedback;
    void insert(int y, int x, int n, int c);
    int start_row;
    int row_inc = -2;

  public:
    Feedback(int y, int x, int h, int w);
    ~Feedback();
    void refresh();
    void print_result(int round, int hits, int near);
};

#endif /* FEEDBACK_H */
