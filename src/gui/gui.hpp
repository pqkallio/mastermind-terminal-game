#ifndef GUI_HPP
#define GUI_HPP

#include "../gamelogic/user_interface.hpp"
#include "feedback.hpp"
#include "playfield.hpp"

class GUI: public UserInterface {
  private:
    Feedback* fb;
    Playfield* pf;

  public:
    GUI();
    ~GUI();
    std::vector<int> get_selection(int round);
    void set_score(int round, int n_hits, int n_near);
    void finish_game();
};

#endif /* GUI_HPP */
