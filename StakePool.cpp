#ifndef SP
#define SP
#include "StakePool.hpp"
#endif

User StakePool::getOwner()
{
  return this->poolOwner;
}
