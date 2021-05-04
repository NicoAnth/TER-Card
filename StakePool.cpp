#ifndef SP
#define SP
#include "Include/StakePool.hpp"
#endif

User StakePool::getOwner()
{
  return this->poolOwner;
}
