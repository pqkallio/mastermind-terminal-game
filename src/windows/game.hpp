#ifndef GAME_H
#define GAME_H

#include "playfield.hpp"
#include "feedback.hpp"

const int LEN_ROW = 4;

class Game {
  private:
    Playfield* playfield;
    Feedback* feedback;
    int secret[LEN_ROW];
    int round;

  public:
    Game(int n_same_color);
    ~Game();
    void run();
};

#endif /* GAME_H */
