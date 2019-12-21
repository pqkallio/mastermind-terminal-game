#ifndef PLAYFIELD_HPP
#define PLAYFIELD_HPP

#include <vector>
#include <ncurses.h>
#include "colors.hpp"
#include "../gamelogic/game.hpp"

static const int N_PIECE_COLORS               = 9;
static const int PIECE_COLORS[N_PIECE_COLORS] = {
  BLACK_PIECE, WHITE_PIECE, YELLOW_PIECE, ORANGE_PIECE,
  RED_PIECE, PURPLE_PIECE, BLUE_PIECE, CYAN_PIECE, GREEN_PIECE
};

namespace PF {
  const int WIN_WIDTH   = 15;
  const int WIN_HEIGHT  = rules::MAX_ROUNDS * 2 + 3;
}

class Playfield {
  const int START_ROW   = PF::WIN_HEIGHT - 3;
  const int START_COL   = 2;
  const int ROW_FACTOR  = -2;
  const int COL_FACTOR  = 3;
  const int ROW_INC     = 1;
  const int COL_INC     = 1;

  private:
    WINDOW* playfield;
    int current_row;
    int current_col;
    int pieces[rules::LEN_ROW];
    int unselected;
    void init_window(int y, int x);
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
    Playfield(int y, int x);
    ~Playfield();
    void refresh();
    std::vector<int> get_selection(int round);
};

#endif /* PLAYFIELD_HPP */
