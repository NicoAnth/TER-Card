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

  //Return 1 on success, 0 on error
  int addUser(User newMember, int stake);
  void removeUser(User newMember);
  //Return 1 on success, 0 on error
  int updateUser(User newMember, int newStake);
  void setPledge(int newPledge);

  User getOwner();
};
