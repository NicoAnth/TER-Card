#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class User;
class Transaction {

public:

  User& sender;
  User& receiver;
  int amount;
  int id;
  int fees;
  std::string date; //temporary
  std::string toString();

  /* Constructor */
  Transaction(User& sender, User& receiver, int amount, int id);
};
#endif