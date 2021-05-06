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
  /* QApplication app(argc, argv); */

  User toto;
  std::cout << toto.publicKey.first << " " << toto.publicKey.second<<endl;
  std::cout << std::get<0>(toto.getPrivateKey()) << " " << std::get<1>(toto.getPrivateKey())<< " "<<std::get<2>(toto.getPrivateKey())<<endl;
  /* auto myWindow=new QWidget() ;
  auto myButton = new QPushButton(myWindow);
  myWindow->show(); */
  return 0;
}
