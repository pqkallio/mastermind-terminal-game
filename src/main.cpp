#include <ncurses.h>
#include <iostream>
#include "windows/game.hpp"

Game *game;

void register_exit_handler(void (*exit_handler)()) {
  int result = std::atexit(exit_handler);

  if (result != 0) {
    std::cerr << "Failed to register cleanup procedures, exiting..." << std::endl;
    return exit(EXIT_FAILURE);
  }
}

void initwin() {
  initscr();

  if (!has_colors()) {
    std::cerr << "Your terminal doesn't support colors." << std::endl;
    exit(EXIT_FAILURE);
  }

  start_color();
  cbreak();
  curs_set(0);

  refresh();

  game = new Game(1);
}

void tidy() {
  if (game != nullptr) {
    delete game;
  }

  endwin();
}

int main(int argc, char* argv[]) {
  register_exit_handler(tidy);

  initwin();

  game->run();

  return 0;
}
