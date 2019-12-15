#ifndef GAMESTATE_H
#define GAMESTATE_H

const int n_rows = 10;
const int len_row = 4;
typedef struct status_t {
  int hit;
  int near;
} Status;

class GameState {
  private:
    int secret[len_row] = {0};
    int rows[n_rows][len_row] = {0};
    int current_row = 0;

  public:
    GameState();

    int get_matches();
    int get_correct();
    void set(int place, int color);
    Status *finalize();
};

#endif /* GAMESTATE_H */
