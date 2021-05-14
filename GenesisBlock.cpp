#include <Include/GenesisBlock.hpp>

GenesisBlock::GenesisBlock(QByteArray m_Hash){
    hash_cur = m_Hash;
    count += 1;
}

QList<std::pair<long,long>> const GenesisBlock::getPublicKeys(){
    return publicKey;
}
QMap<User,int> const GenesisBlock::getStakers(){
    return stakers;
}