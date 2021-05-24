#ifndef SP_H
#define SP_H
#include "User.hpp"
#include "Node.hpp"

#include <QMap>
#include <QPaintEvent>

class StakePool: public NodeClass {
  Q_OBJECT
public:

  StakePool(User* m_owner,QList<Block*> *m_blockChain,QList <Transaction> m_ledger, int stake,QMainWindow* mw);
  QMap<User*,int> enrolled;
  int pledge;
  //Return 1 on success, 0 on error
  int addUser(User* newMember, int stake);
  void removeUser(User* newMember);
  //Return 1 on success, 0 on error
  int updateUser(User* newMember, int newStake);
  void setPledge(int newPledge);
  void paintEvent(QPaintEvent*);
  User* getOwner();
};
#endif
