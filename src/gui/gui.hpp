#ifndef GUI_HPP
#define GUI_HPP

#include "../gamelogic/user_interface.hpp"
#include "feedback.hpp"
#include "playfield.hpp"
#include "secretfield.hpp"


class GUI: public UserInterface {
  const int FB_HEIGHT = 2 * rules::MAX_ROUNDS + 3;
  const int FB_WIDTH  = 6;
  const int PF_HEIGHT = 2 * rules::MAX_ROUNDS + 3;
  const int PF_WIDTH  = 15;
  const int SF_HEIGHT = 5;
  const int SF_WIDTH  = 15;

  private:
    Feedback* fb;
    Playfield* pf;
    SecretField* sf;

  public:
    GUI();
    ~GUI();
    std::vector<int> get_selection(int round);
    void set_score(int round, int n_hits, int n_near);
    void finish_game(int n, int* secret);
};

#endif /* GUI_HPP */
