#include <ncurses.h>
#include <iostream>
#include "gui/windows/playfield.hpp"

Window* playfield;

void register_exit_handler(void (*exit_handler)()) {
  int result = std::atexit(exit_handler);

  if (result != 0) {
    std::cerr << "Failed to register cleanup procedures, exiting..." << std::endl;
    return exit(EXIT_FAILURE);
  }
}

Window* init_playfield() {
  auto playfield = new Playfield();
  playfield->refresh();

  return playfield;
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

  playfield = init_playfield();
}

void finwin() {
  if (playfield != nullptr) {
    delete playfield;
  }

  endwin();
}

int main(int argc, char* argv[]) {
  register_exit_handler(finwin);

  initwin();

  getch();

  return 0;
}
