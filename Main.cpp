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

  User toto;
  cout << "n: " << toto.publicKey.first << " e: " << toto.publicKey.second <<endl;
  cout << "p: " << get<0>(toto.getPrivateKey()) << " q: " << get<1>(toto.getPrivateKey()) << " d: " << get<2>(toto.getPrivateKey()) << endl;
  long long enc = encrypt(15,toto.publicKey,toto.getPrivateKey());
  cout << enc <<endl;
  cout << decrypt(enc,toto.publicKey)<<endl;
  auto myWindow=new QWidget() ;
  auto myButton = new QPushButton(myWindow);
  myWindow->show();
  return 0;
}
