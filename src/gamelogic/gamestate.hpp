#ifndef GAMESTATE_H
#define GAMESTATE_H

const int n_rows = 10;
const int LEN_ROW = 4;
typedef struct status_t {
  int hit;
  int near;
} Status;

class GameState {
  private:
    int secret[LEN_ROW] = {0};
    int rows[n_rows][LEN_ROW] = {0};
    int current_row;

  public:
    GameState(int secret[LEN_ROW]);

    int get_matches();
    int get_correct();
    void set(int place, int color);
    Status *finalize_round();
};

#endif /* GAMESTATE_H */
