#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <vector>

class UserInterface {
  public:
    virtual ~UserInterface() {}
    virtual std::vector<int> get_selection(int round) {
      return std::vector<int>();
    }
    virtual void set_score(int round, int n_hits, int n_near) {}
    virtual void finish_game(int n, int* secret) {}
};

#endif /* USER_INTERFACE_H */
