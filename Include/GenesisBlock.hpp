#ifndef GENESIS_BLOCK_H
#define GENESIS_BLOCK_H
#include "Block.hpp"
#include "User.hpp"
#include <QList>
#include <QMap>

#define TRANSACTION_MAX 10

class GenesisBlock : public Block {

    private:
        QList<std::pair<long,long>> publicKey;
        QMap<User,int> stakers;
    public:
       QList<std::pair<long,long>> getPublicKeys();
       QMap<User,int> getStakers();

};
#endif