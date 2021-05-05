#ifndef Node
#include "Include/Node.hpp"
#define Node
#endif

#ifndef Simul
#include "Include/Simulation.hpp"
#define Simul
#endif

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

int main (int argc, char **argv )
{
  QApplication app(argc, argv);
  auto myWindow=new QWidget() ;
  auto myButton = new QPushButton(myWindow);
  myWindow->show();
  return app.exec();
}
