#include "gamestate.hpp"

GameState::GameState(int secret[LEN_ROW]) {
  for (int i = 0; i < LEN_ROW; i++) {
    this->secret[i] = secret[i];
  }

  this->current_row = 0;
}
