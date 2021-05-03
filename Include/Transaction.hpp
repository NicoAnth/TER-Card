#include <string>

#ifndef Users
#define Users
#include "User.hpp"
#endif

class Transaction {

public:
  User sender;
  User receiver;
  int amount;
  int id;
  std::string date; //temporary

};
