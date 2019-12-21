#ifndef GAME_H
#define GAME_H

#include "user_interface.hpp"

namespace rules {
  const int MAX_ROUNDS = 12;
  const int LEN_ROW = 4;
  const int NUM_COLORS = 8;
}

class Game {
  private:
    UserInterface* ui;
    int secret[rules::LEN_ROW];
    int round;

  public:
    Game(int n_same_color, UserInterface* ui);
    ~Game();
    void run();
};

#endif /* GAME_H */
