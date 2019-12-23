#include "gui.hpp"
#include "colors.hpp"

GUI::GUI() {
  init_colors();

  int tw = PF_WIDTH + FB_WIDTH;
  int th = PF_HEIGHT + SF_HEIGHT;
  int pfx = (COLS - tw) / 2;
  int pfy = (LINES - th) / 2;

  this->pf = new Playfield(pfy + SF_HEIGHT - 1, pfx, PF_HEIGHT, PF_WIDTH);
  this->fb = new Feedback(pfy + SF_HEIGHT - 1, pfx + PF_WIDTH - 1, FB_HEIGHT, FB_WIDTH);
  this->sf = new SecretField(pfy, pfx, SF_HEIGHT, SF_WIDTH);

  this->pf->refresh();
  this->sf->refresh();
  this->fb->refresh();
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
  int colors[] = {secret[0] + 1, secret[1] + 1, secret[2] + 1, secret[3] + 1};
  this->sf->endgame(rules::LEN_ROW, colors);
}
