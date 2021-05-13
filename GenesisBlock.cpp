#include <Include/GenesisBlock.hpp>

QList<std::pair<long,long>> GenesisBlock::getPublicKeys(){
    return publicKey;
}
QMap<User,int> GenesisBlock::getStakers(){
    return stakers;
}