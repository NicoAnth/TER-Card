#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "Include/Node.hpp"
#include "Include/User.hpp"
#include "Include/Rsa.h"
#include "Include/GenesisBlock.hpp"
#include "Include/Simulation.hpp"
#include <QPaintEvent>

using namespace std;

int main (int argc, char **argv )
{
  QApplication app(argc, argv);

  //Init
  GenesisBlock geBlock;
  QList <Block*> blockChain;
  QList<Transaction> transaction;
  blockChain.append(&geBlock);
  User toto(geBlock),Lolo(geBlock);

  //Give money
  giveMoney(toto,1000);
  giveMoney(Lolo,500);


  //Create Node
  NodeClass firstNode(&toto,blockChain, transaction,0);
  firstNode.setSlotLeader(true);

  //Create transact'
  firstNode.receiveTransactionRequest(toto.createTransaction(&Lolo,50));
  firstNode.receiveTransactionRequest(Lolo.createTransaction(&toto,20));
  firstNode.receiveTransactionRequest(toto.createTransaction(&Lolo,40));

  firstNode.createBlock();


  auto myWindow= new QWidget();
  myWindow->setMinimumHeight(1000);
  myWindow->setMinimumWidth(2000);

  QPaintEvent hey(QRect(10,20,200,200));
  geBlock.paintEvent(&hey);
  geBlock.setParent(myWindow);
  myWindow->show();
  return app.exec();
}