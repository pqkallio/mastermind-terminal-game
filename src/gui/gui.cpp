#include "gui.hpp"
#include "colors.hpp"

GUI::GUI() {
  init_colors();

  int tw = PF::WIN_WIDTH + FB::WIN_WIDTH;
  int pfx = (COLS - tw) / 2;
  int y = (LINES - PF::WIN_HEIGHT) / 2;

  this->pf = new Playfield(y, pfx);
  this->fb = new Feedback(y, pfx + PF::WIN_WIDTH - 1);

  this->pf->refresh();
  this->fb->refresh();
}

GUI::~GUI() {
  delete this->fb;
  delete this->pf;
}

std::vector<int> GUI::get_selection(int round) {
  return this->pf->get_selection(round);
}

void GUI::set_score(int round, int n_hits, int n_near) {
  this->fb->print_result(round, n_hits, n_near);
}

void GUI::finish_game() {}
