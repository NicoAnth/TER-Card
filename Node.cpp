#include "Include/Node.hpp"
#include "Include/StakePool.hpp"

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

Block NodeClass::createBlock(StakePool& SP)
{
  return createBlock(SP.getOwner().id);
}

void NodeClass::execTransaction(User sender, User receiver, int amount)
{
  sender.useableStakes -= amount;
  receiver.useableStakes += amount;
}
