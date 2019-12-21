#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include "game.hpp"

Game::Game(int n_same_color, UserInterface* ui) {
  n_same_color = std::max(1, n_same_color);
  int occurences[8] = {0};
  srand(time(NULL));

  for (int i = 0; i < LEN_ROW;) {
    bool insertable = true;
    int r_choice = rand() % 8;

    occurences[i]++;

    if (occurences[i] <= n_same_color) {
      this->secret[i] = r_choice;
      i++;
    }
  }

  this->round = 0;
  this->ui = ui;
}

Game::~Game() {
  delete this->ui;
}

void Game::run() {
  while (this->round < 10) {
    std::vector<int> selection = this->ui->get_selection(this->round);

    if (selection.size() != 4) {
      exit(1);
    }

    int n_hits = 0;
    int n_near = 0;

    for (std::vector<int>::size_type i = 0; i != selection.size(); i++) {
      for (int j = 0; j < LEN_ROW; j++) {
        if (selection[i] == this->secret[j]) {
          if (i == j) {
            n_hits++;
          } else {
            n_near++;
          }
        }
      }
    }

    this->ui->set_score(this->round, n_hits, n_near);

    if (n_hits == LEN_ROW) {
      this->ui->finish_game();
      break;
    }

    this->round++;
  }
}
