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
    int* secret;
    WINDOW* secretfield;
  public:
    SecretField(int* secret);
    ~SecretField();
    void endgame();
    void refresh();
};

#endif /* SECRETFIELD_H */
