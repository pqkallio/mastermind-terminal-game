#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include "game.hpp"
#include <ncurses.h>

Game::Game(int n_same_color, UserInterface* ui) {
  n_same_color = std::max(1, n_same_color);
  int occurences[rules::NUM_COLORS + 1] = {0};
  srand(time(NULL));

  for (int i = 0; i < rules::LEN_ROW;) {
    int r_choice = rand() % rules::NUM_COLORS + 1;

    occurences[r_choice]++;

    if (occurences[r_choice] <= n_same_color) {
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
  while (this->round < rules::MAX_ROUNDS) {
    std::vector<int> selection = this->ui->get_selection(this->round);

    if (selection.size() != rules::LEN_ROW) {
      exit(1);
    }

    int n_hits = 0;
    int n_near = 0;

    for (size_t i = 0; i != selection.size(); i++) {
      refresh();
      for (size_t j = 0; j < rules::LEN_ROW; j++) {
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

    if (n_hits == rules::LEN_ROW) {
      this->ui->finish_game(rules::LEN_ROW, this->secret);
      break;
    }

    this->round++;
  }
}
