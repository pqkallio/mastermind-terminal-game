#include <stdlib.h>
#include "gamelogic.hpp"

GameLogic::GameLogic() {
  int secret[len_row] = {0};

  for (int i = 0; i < len_row; i++) {
    bool insertable = true;
    int r_choice = rand() % 8 + 1;

    for (int j = 0; j < i; j++) {
      if (secret[j] == r_choice) {
        insertable = false;
        i--;
        break;
      }
    }

    if (insertable) {
      secret[i] = r_choice;
    }
  }

  GameState *state = new GameState(secret);
  this->state = state;
}
