#include "colors.hpp"

void init_colors() {
  init_pair(BLACK_PIECE,    COLOR_BLACK,  COLOR_BLACK);
  init_pair(WHITE_PIECE,    COLOR_WHITE,  COLOR_WHITE);
  init_pair(YELLOW_PIECE,   COLOR_YELLOW, COLOR_YELLOW);
  init_pair(ORANGE_PIECE,   COLOR_YELLOW, COLOR_RED);
  init_pair(RED_PIECE,      COLOR_RED,    COLOR_RED);
  init_pair(PURPLE_PIECE,   COLOR_RED,    COLOR_BLUE);
  init_pair(BLUE_PIECE,     COLOR_BLUE,   COLOR_BLUE);
  init_pair(CYAN_PIECE,     COLOR_CYAN,   COLOR_CYAN);
  init_pair(GREEN_PIECE,    COLOR_GREEN,  COLOR_GREEN);
  init_pair(WHITE_ON_BLACK, COLOR_WHITE,  COLOR_BLACK);
  init_pair(RED_ON_BLACK,   COLOR_RED,    COLOR_BLACK);
  init_pair(UNKNOWN_PIECE,  COLOR_BLACK,  COLOR_WHITE);
}
