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

  int tw = PF::WIN_WIDTH + FB::WIN_WIDTH;
  int pfx = (COLS - tw) / 2;
  int y = (LINES - PF::WIN_HEIGHT) / 2;

  this->playfield = new Playfield(y, pfx);
  this->feedback = new Feedback(y, pfx + PF::WIN_WIDTH - 1);
  this->round = 0;

  this->playfield->refresh();
  this->feedback->refresh();
}

Game::~Game() {
  delete this->playfield;
  delete this->feedback;
}

void Game::run() {
  while (this->round < 10) {
    std::vector<int> selection = this->playfield->get_selection(this->round);

    if (selection.size() != 4) {
      exit(1);
    }

    this->round++;
  }
}
