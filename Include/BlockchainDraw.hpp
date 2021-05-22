#ifndef BLOCKCHAINDRAW_H
#define BLOCKCHAINDRAW_H
#include <QList>
#include <QWidget>
#include <QGraphicsWidget>
#include "Block.hpp"

class BlockchainDraw: public QWidget {

Q_OBJECT 

private:
  QList<Block*>* m_blockChain;

protected:


public:

  //Constructor
  BlockchainDraw(QList<Block*>* blockchain);
  void appendBlockchain(Block* blockToAppend);
  void paintEvent(QPaintEvent *);

};
#endif
