#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "Include/Node.hpp"
#include "Include/User.hpp"
#include "Include/Rsa.h"
#include "Include/GenesisBlock.hpp"
#include <QPaintEvent>

using namespace std;

int main (int argc, char **argv )
{
  QApplication app(argc, argv);

  GenesisBlock geBlock;
  QList <Block*> blockChain;
  QList<Transaction> transaction;
  blockChain.append(&geBlock);
  User toto(geBlock),Lolo(geBlock);
  NodeClass firstNode(&toto,blockChain, transaction,0);
  auto myWindow= new QWidget();
  myWindow->setMinimumHeight(1000);
  myWindow->setMinimumWidth(2000);

  QPaintEvent hey(QRect(10,20,200,200));
  geBlock.paintEvent(&hey);
  geBlock.setParent(myWindow);
  myWindow->show();
  return app.exec();
}