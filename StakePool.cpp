
#include "Include/StakePool.hpp"
#include "Include/mainwindow.h"
#include <QPainter>

StakePool::StakePool(User* m_owner,QList<Block*> *m_blockChain,QList <Transaction> m_ledger, int stake,QMainWindow* mw):
NodeClass(m_owner,m_blockChain,m_ledger,stake,mw), pledge(1){}

int StakePool::addUser(User* newMember, int stakes)
{
  if(newMember->useableStakes >= stakes+pledge){
    enrolled.insert(newMember,stakes);
    stake += stakes;
    newMember->useableStakes -= stakes + pledge;
    newMember->pooledStakes += stakes;
    ((MainWindow*)m_mw)->addUserToSP(this,newMember);
    return 1;
  }
  else return 0;
}

void StakePool::removeUser(User* member)
{
  member->pooledStakes -= enrolled.find(member).value();
  member->useableStakes += enrolled.find(member).value();
  enrolled.remove(member);
}

int StakePool::updateUser(User* member, int newStake)
{
  if(member->useableStakes >= newStake){
    int diffStake = newStake - enrolled.find(member).value();
    stake -= enrolled.find(member).value();
    enrolled.insert(member, newStake);
    stake += newStake + pledge;
    member->useableStakes -= diffStake + pledge;
    member->pooledStakes += diffStake;
    return 1;
  }
  return 0;
}

void StakePool::setPledge(int vpledge){
  pledge = vpledge;
}

void StakePool::paintEvent(QPaintEvent *){
  QPainter painter(this);
  QPen pen;
  pen.setColor(Qt::black);
  if(isSlotLeader){
    painter.setBrush(QColor(255,195,51));
  }
  else painter.setBrush(QColor(224,80,142));
  painter.drawRect(QRect(0,0,30,30));
  painter.setPen(pen);
  painter.drawText(QRect(7,8,30,30),"SP");
}