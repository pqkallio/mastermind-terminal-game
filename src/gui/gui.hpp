#ifndef GUI_HPP
#define GUI_HPP

#include "../gamelogic/user_interface.hpp"
#include "feedback.hpp"
#include "playfield.hpp"
#include "secretfield.hpp"

class GUI: public UserInterface {
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
