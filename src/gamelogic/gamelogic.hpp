#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include "gamestate.hpp"

class GameLogic {
  private:
    GameState* state;
  public:
    GameLogic(int n_same_color);
};

#endif /* GAMELOGIC_HPP */
