#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "Include/Node.hpp"
#include "Include/User.hpp"
#include "Include/Rsa.h"
#include "Include/GenesisBlock.hpp"

using namespace std;

int main (int argc, char **argv )
{
  QApplication app(argc, argv);

  User toto,Lolo;
  auto myWindow= new QWidget();
  auto myButton = new QPushButton(myWindow);
  myWindow->show();
  return app.exec();
}