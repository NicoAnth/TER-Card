#ifndef CHAIN_H
#define CHAIN_H
#include "Block.hpp"
#include <QList>

class Chain {
  QList<Block> blockchain;
};
#endif