#ifndef GAME_H
#define GAME_H

#include "user_interface.hpp"

const int LEN_ROW = 4;

class Game {
  private:
    UserInterface* ui;
    int secret[LEN_ROW];
    int round;

  public:
    Game(int n_same_color, UserInterface* ui);
    ~Game();
    void run();
};

#endif /* GAME_H */
