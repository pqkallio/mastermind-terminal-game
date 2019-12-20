#ifndef PLAYFIELD_HPP
#define PLAYFIELD_HPP

#include <vector>
#include <ncurses.h>
#include "window.hpp"

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
  const int WIN_WIDTH   = 15;
  const int WIN_HEIGHT  = 23;
  const int START_ROW   = WIN_HEIGHT - 3;
  const int START_COL   = 2;
  const int ROW_FACTOR  = -2;
  const int COL_FACTOR  = 3;
  const int ROW_INC     = 1;
  const int COL_INC     = 1;

  private:
    WINDOW* playfield;
    int current_row;
    int current_col;
    int pieces[N_PIECES];
    int unselected;
    void init_color_pairs();
    void init_window();
    void clear_pieces();
    void highlight(int y, int x);
    void rehighlight(int y, int x);
    void unhighlight(int y, int x);
    bool handle_input(int c);
    int view_col(int x);
    int view_row(int y);
    void change_piece_color(int n);
    void surround(
      int y, int x,
      int ul, int ll, int ur, int lr,
      int ls, int rs, int ts, int bs
    );
    void update_piece();
    bool add_row();

  public:
    Playfield();
    ~Playfield();
    void refresh();
    void run();
    std::vector<int> get_selection(int round);
};

#endif /* PLAYFIELD_HPP */
