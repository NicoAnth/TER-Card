#include <Include/GenesisBlock.hpp>
#include <Include/Node.hpp>
#include <QCryptographicHash>
#include <QString>

GenesisBlock::GenesisBlock(){
    QString hash_0("0");
    hash_cur = QCryptographicHash::hash(hash_0.toLocal8Bit(),QCryptographicHash::Sha256);
    positionx = 150;
    positiony = 125;
    count += 1;
}

QList<std::pair<long,long>> const GenesisBlock::getPublicKeys(){
    return publicKey;
}
QList<std::pair<NodeClass,int>> const GenesisBlock::getStakers(){
    return stakers;
}

void GenesisBlock::addStaker(NodeClass node, int stake){
    stakers.append(std::make_pair(node,stake));
}

void GenesisBlock::addPublicKey(std::pair<long,long> pK){
    publicKey.append(pK);
}