#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <vector>

class UserInterface {
  public:
    virtual std::vector<int> get_selection(int round) {}
    virtual void set_score(int round, int n_hits, int n_near) {}
    virtual void finish_game() {}
};

#endif /* USER_INTERFACE_H */
