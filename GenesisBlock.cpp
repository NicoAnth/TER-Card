#include <Include/GenesisBlock.hpp>
#include <QCryptographicHash>
#include <QString>

GenesisBlock::GenesisBlock(){
    QString hash_0("0");
    hash_cur = QCryptographicHash::hash(hash_0.toLocal8Bit(),QCryptographicHash::Sha256);
    count += 1;
}

QList<std::pair<long,long>> const GenesisBlock::getPublicKeys(){
    return publicKey;
}
QMap<NodeClass,int> const GenesisBlock::getStakers(){
    return stakers;
}