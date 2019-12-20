#include <stdlib.h>
#include <algorithm>
#include <vector>
#include "game.hpp"

Game::Game(int n_same_color) {
  n_same_color = std::max(1, n_same_color);
  int occurences[8] = {0};

  for (int i = 0; i < LEN_ROW;) {
    bool insertable = true;
    int r_choice = rand() % 8;

    occurences[i]++;

    if (occurences[i] <= n_same_color) {
      this->secret[i] = r_choice;
      i++;
    }
  }

  this->playfield = new Playfield();
  this->round = 0;
}

Game::~Game() {
  delete this->playfield;
}

void Game::run() {
  while (this->round < 10) {
    std::vector<int> selection = this->playfield->get_selection(this->round);
    this->round++;
  }
}
