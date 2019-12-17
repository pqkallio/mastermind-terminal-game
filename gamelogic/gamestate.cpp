#include "gamestate.hpp"

GameState::GameState(int secret[len_row]) {
  for (int i = 0; i < len_row; i++) {
    this->secret[i] = secret[i];
  }

  this->current_row = 0;
}
