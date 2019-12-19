#include <stdlib.h>
#include <algorithm>
#include "gamelogic.hpp"

GameLogic::GameLogic(int n_same_color) {
  n_same_color = std::max(1, n_same_color);

  int secret[len_row] = {0};
  int occurences[8] = {0};

  for (int i = 0; i < len_row;) {
    bool insertable = true;
    int r_choice = rand() % 8 + 1;

    occurences[i]++;

    if (occurences[i] <= n_same_color) {
      secret[i] = r_choice;
      i++;
    }
  }

  GameState *state = new GameState(secret);
  this->state = state;
}
