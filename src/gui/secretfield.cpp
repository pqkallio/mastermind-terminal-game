#include "secretfield.hpp"
#include "util.hpp"
#include "colors.hpp"

SecretField::SecretField(int y, int x) {
  this->secretfield = newwin(SF::HEIGHT, SF::WIDTH, y, x);

  wborder(this->secretfield,
    ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE,
    ACS_ULCORNER, ACS_URCORNER, ACS_LTEE, ACS_RTEE
  );

  int colors[] = {UNKNOWN_PIECE, UNKNOWN_PIECE, UNKNOWN_PIECE, UNKNOWN_PIECE};

  this->render_pieces(4, colors);
}

SecretField::~SecretField() {
  delwin(this->secretfield);
}

void SecretField::render_pieces(int n, int* colors) {
  render_piece_row(this->secretfield, SecretField::PSY, SecretField::PSX, n, colors);

  this->refresh();
}

void SecretField::endgame(int n, int* secret) {
  this->render_pieces(n, secret);
}

void SecretField::refresh() {
  wrefresh(this->secretfield);
}
