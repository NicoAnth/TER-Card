#ifndef USER_H
#define USER_H
#include <memory>
#include <utility> 
#include "Node.hpp"
#include "Transaction.hpp"
#include "Rsa.h"
#include <QObject>
#include <QMainWindow>
#include <QWidget>
#include <QCryptographicHash>

class GenesisBlock;
class StakePool;
class NodeClass;

class User: public QWidget {
  
  Q_OBJECT
  
  public:

    static int count;
    int id;
    std::pair<long long, long long> publicKey;
    float totalStakes;
    float useableStakes;
    float pooledStakes;
    static QList <NodeClass*> *existingNodes;
    NodeClass* connectedNode;
    StakePool* connectedPool;
    QMainWindow* m_mw;
    int m_graphicLine;


    //Constructor
    User(GenesisBlock& geBlock, QMainWindow* mw, int graphicLine);
    ~User();
    
    std::tuple<long long, long long, long long> const getPrivateKey() const;
    Transaction createTransaction(User* m_receiver, int m_amount);
    NodeClass* createNode(int amount = 10);
    void joinStakePool(StakePool& sp, int stake);
    void addUseableStakes(float addus);
    void addtotalStakes(float addts);
    void paintEvent(QPaintEvent *);
    QString getInfos();

    void setConnectedNode(NodeClass* cNode);
    void setConnectedPool(StakePool* cStakePool);


  private:
   std::tuple<long long, long long, long long> privateKey;

  public slots:
    void ShowContextMenu(const QPoint &pos);
    void createNodeSettings();
};

inline bool operator <(const User &u, const User &u2){
  return u.useableStakes < u2.useableStakes;
}
long long hashtoll(std::string hash);
#endif
