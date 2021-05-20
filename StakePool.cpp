#include "Include/StakePool.hpp"


User* StakePool::getOwner()
{
  return poolOwner;
}

int StakePool::addUser(User* newMember, int stake)
{
  if(newMember->useableStakes >= stake+pledge){
    enrolled.insert(newMember,stake);
    stakes += stake;
    newMember->useableStakes -= stake + pledge;
    newMember->pooledStakes += stake;
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
    stakes -= enrolled.find(member).value();
    enrolled.insert(member, newStake);
    stakes += newStake + pledge;
    member->useableStakes -= diffStake + pledge;
    member->pooledStakes += diffStake;
    return 1;
  }
  return 0;
}

void StakePool::setPledge(int vpledge){
  pledge = vpledge;
}
