#ifndef PLAYFIELD_HPP
#define PLAYFIELD_HPP

#include <ncurses.h>
#include "window.hpp"
#include "../visualpiece.hpp"

#define BLACK_PIECE     1
#define WHITE_PIECE     2
#define YELLOW_PIECE    3
#define ORANGE_PIECE    4
#define RED_PIECE       5
#define PURPLE_PIECE    6
#define BLUE_PIECE      7
#define CYAN_PIECE      8
#define GREEN_PIECE     9
#define WHITE_ON_BLACK  10

static const int N_PIECES                     = 4;
static const int N_PIECE_COLORS               = 9;
static const int PIECE_COLORS[N_PIECE_COLORS] = {
  BLACK_PIECE, WHITE_PIECE, YELLOW_PIECE, ORANGE_PIECE,
  RED_PIECE, PURPLE_PIECE, BLUE_PIECE, CYAN_PIECE, GREEN_PIECE
};

class Playfield: public Window {
  const int WIN_WIDTH   = 11;
  const int WIN_HEIGHT  = 21;
  const int START_ROW   = WIN_HEIGHT - 3;
  const int START_COL   = 2;
  const int ROW_INC     = -2;
  const int COL_INC     = 2;

  private:
    WINDOW* playfield;
    int current_row;
    int current_col;
    VisualPiece visualPieces[N_PIECES];
    void init_color_pairs();
    void init_window();
    void highlight(int y, int x);
    void handle_input(char ch);

  public:
    Playfield();
    ~Playfield();
    void refresh();
    void add_row();
    void run();
};

#endif /* PLAYFIELD_HPP */
