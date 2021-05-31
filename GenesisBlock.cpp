#include <Include/GenesisBlock.hpp>
#include <Include/Node.hpp>
#include <QCryptographicHash>
#include <QString>
#include <QPainter>
#include <QSize>

GenesisBlock::GenesisBlock(){
    QString hash_0("42");
    hash_cur = QCryptographicHash::hash(hash_0.toLocal8Bit(),QCryptographicHash::Sha256);
    positionx = 0;
    positiony = 100;
    setCursor(Qt::PointingHandCursor);
    setGeometry(positionx,0,100,100);
    count += 1;
}

QList<std::pair<long,long>> const GenesisBlock::getPublicKeys(){
    return publicKey;
}
QList<std::pair<NodeClass*,float>> const GenesisBlock::getStakers(){
    return stakers;
}

void GenesisBlock::addStaker(NodeClass* node, float stake){
    stakers.append(std::make_pair(node,stake));
}

void GenesisBlock::addPublicKey(std::pair<long,long> pK){
    publicKey.append(pK);
}