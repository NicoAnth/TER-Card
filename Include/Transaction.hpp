#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class User;
class Transaction {

private:

  User& sender;
  User& receiver;
  static int count;
  int id;
  int amount;
  int fees;
  long long signature;
  std::string date; //temporary

public:
  
  std::string toString();

  /* Constructor */
  Transaction(User& sender, User& receiver, int amount);

  /* getter */
  long long getSignature();
  User& getSender();
  User& getReceiver();
  int getAmount();
  int getFees();
  
  /* Setter */
  void setSignature(long long signature);
};
#endif