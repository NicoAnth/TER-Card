#ifndef Node
#include "Include/Node.hpp"
#define Node
#endif

using namespace std;

int NodeClass::electSlotLeader(void)
{
  return 0;
}

Block NodeClass::createBlock(int Uid)
{
  Block b{};
  return b;
}

Block NodeClass::createBlock(StakePool SP)
{
  return createBlock(SP.getOwner().id);
}

void NodeClass::execTransaction(User sender, User receiver, int amount)
{
  sender.useableStakes -= amount;
  receiver.useableStakes += amount;
}
