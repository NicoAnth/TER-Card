#ifndef Users
#define Users
#include "User.hpp"
#endif

#include <QMap>

class StakePool {

public:
  QMap<User,int> enrolled;
  int pledge;
  User poolOwner;
  int stakes;

  void addUser(User newMember);
  void removeUser(User newMember);
  void updateUser(User newMember);
  void setPledge(int newPledge);

  User getOwner();
};
