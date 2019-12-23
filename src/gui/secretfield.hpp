#ifndef SECRETFIELD_H
#define SECRETFIELD_H

#include <ncurses.h>
#include "../gamelogic/game.hpp"

namespace SF {
  int WIDTH = rules::LEN_ROW * 2 + 3;
  int HEIGHT = 5;
}

class SecretField {
  private:
    const int PSY = 2;
    const int PSX = 2;
    WINDOW* secretfield;
    void render_pieces(int n, int* colors);
  public:
    SecretField(int y, int x);
    ~SecretField();
    void endgame(int n, int* secret);
    void refresh();
};

#endif /* SECRETFIELD_H */
