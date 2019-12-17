#ifndef PLAYFIELD_HPP
#define PLAYFIELD_HPP

#include <ncurses.h>
#include "window.hpp"
#include "../visualpiece.hpp"

#define BLACK   1
#define WHITE   2
#define YELLOW  3
#define ORANGE  4
#define RED     5
#define PURPLE  6
#define BLUE    7
#define CYAN    8
#define GREEN   9

class Playfield: public Window {
  const int           START_ROW   = LINES - 3;
  const int           START_COL   = 2;
  const int           ROW_INC     = -2;
  const int           COL_INC     = 2;
  const int           WIN_WIDTH   = 11;
  const int           WIN_HEIGHT  = 21;

  private:
    WINDOW* playfield;
    int current_row;
    VisualPiece visualPieces[4];
    void init_color_pairs();
    void init_window();

  public:
    Playfield();
    ~Playfield();
    void refresh();
    void add_row();
};

#endif /* PLAYFIELD_HPP */
