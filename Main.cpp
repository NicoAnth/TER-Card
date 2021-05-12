#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "Include/Node.hpp"
#include "Include/User.hpp"
#include "Include/Rsa.h"

using namespace std;

int main (int argc, char **argv )
{
  QApplication app(argc, argv);

  User toto,Lolo;
  NodeClass node;
  Transaction transaction(toto,Lolo,30,5);
  cout << "n: " << toto.publicKey.first << " e: " << toto.publicKey.second <<endl;
  cout << "p: " << get<0>(toto.getPrivateKey()) << " q: " << get<1>(toto.getPrivateKey()) << " d: " << get<2>(toto.getPrivateKey()) << endl;

  //Fonctionne jusqu'a 200 000 000 exclu
  long long enc = encrypt(10,toto.publicKey,toto.getPrivateKey());
  cout << enc <<endl;
  cout << decrypt(enc,toto.publicKey)<<endl;
  pair<Transaction,long long> tsend = toto.sendTransaction(transaction);
  cout << "Encrypt hash: " << tsend.second <<endl;
  cout << "Bool: " << node.verifySignature(toto,tsend.first,tsend.second) <<endl;
  auto myWindow= new QWidget();
  auto myButton = new QPushButton(myWindow);
  myWindow->show();
  return app.exec();
}