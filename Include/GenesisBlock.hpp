#ifndef GENESIS_BLOCK_H
#define GENESIS_BLOCK_H
#include "Block.hpp"
#include "User.hpp"
#include <QList>
#include <QMap>

#define TRANSACTION_MAX 3

class GenesisBlock : public Block {

    private:
        QList<std::pair<long,long>> publicKey;
        QMap<NodeClass,int> stakers;
    public:
        GenesisBlock();
        ~GenesisBlock(){};
        QList<std::pair<long,long>> const getPublicKeys();
        QMap<NodeClass,int> const getStakers();
        
};
#endif