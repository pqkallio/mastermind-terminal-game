#include "gui.hpp"
#include "colors.hpp"

GUI::GUI() {
  init_colors();

  int tw = PF::WIN_WIDTH + FB::WIN_WIDTH;
  int th = PF::WIN_HEIGHT + SF::HEIGHT;
  int pfx = (COLS - tw) / 2;
  int pfy = (LINES - th) / 2;

  this->pf = new Playfield(pfy + SF::HEIGHT - 1, pfx);
  this->fb = new Feedback(pfy + SF::HEIGHT - 1, pfx + PF::WIN_WIDTH - 1);
  this->sf = new SecretField(pfy, pfx);

  this->pf->refresh();
  this->fb->refresh();
  this->sf->refresh();
}

GUI::~GUI() {
  delete this->fb;
  delete this->pf;
  delete this->sf;
}

std::vector<int> GUI::get_selection(int round) {
  return this->pf->get_selection(round);
}

void GUI::set_score(int round, int n_hits, int n_near) {
  this->fb->print_result(round, n_hits, n_near);
}

void GUI::finish_game(int n, int* secret) {
  this->sf->endgame(rules::LEN_ROW, secret);
}
