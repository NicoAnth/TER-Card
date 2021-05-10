#include "Include/Node.hpp"
#include "Include/User.hpp"
#include "Include/Rsa.h"
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>

using namespace std;

int main (int argc, char **argv )
{
  QApplication app(argc, argv);

  User toto;
  cout << "n: " << toto.publicKey.first << " e: " << toto.publicKey.second <<endl;
  cout << "p: " << get<0>(toto.getPrivateKey()) << " q: " << get<1>(toto.getPrivateKey()) << " d: " << get<2>(toto.getPrivateKey()) << endl;
  long long enc = encrypt(15,toto.publicKey,toto.getPrivateKey());
  cout << enc <<endl;
  cout << decrypt(enc,toto.publicKey)<<endl;
  auto myWindow= new QWidget();
  auto myButton = new QPushButton(myWindow);
  myWindow->show();
  return 0;
}
