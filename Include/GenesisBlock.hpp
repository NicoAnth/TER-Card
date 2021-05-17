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
        QList<std::pair<NodeClass,int>> stakers;
    public:
        GenesisBlock();
        ~GenesisBlock(){};

        /* getters */
        QList<std::pair<long,long>> const getPublicKeys();
        QList<std::pair<NodeClass,int>> const getStakers();

        /* setters */
        void addStaker(NodeClass node, int stake);
        void addPublicKey(std::pair<long,long>);
        void updateStaker(NodeClass node, int stake, int prec_value);
};
#endif