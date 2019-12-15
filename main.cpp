#include <ncurses.h>

void initwin() {
  initscr();
  start_color();
}

void finwin() {
  endwin();
}

int main(int argc, char* argv[]) {
  initwin();
  getch();
  finwin();
  return 0;
}
