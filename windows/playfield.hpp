#ifndef PLAYFIELD_HPP
#define PLAYFIELD_HPP

#include <ncurses.h>
#include "window.hpp"

class Playfield: public Window {
  private:
    WINDOW* playfield;

  public:
    Playfield();
    ~Playfield();
    void refresh();
};

#endif /* PLAYFIELD_HPP */
