#include "Include/Node.hpp"
#include "Include/StakePool.hpp"
#include <QCryptographicHash>

using namespace std;

int NodeClass::electSlotLeader(void)
{
  return 0;
}

Block NodeClass::createBlock(int Uid)
{
  
}

Block NodeClass::createBlock(StakePool& SP)
{
  return createBlock(SP.getOwner().id);
}

void NodeClass::execTransaction(User sender, User receiver, int amount)
{
  sender.useableStakes -= amount;
  receiver.useableStakes += amount;
}

bool NodeClass::verifySignature( User m_user,Transaction t, long long encryptedHash){

  QString s = s.fromStdString(t.toString());
  QByteArray hash = QCryptographicHash::hash(s.toLocal8Bit(),QCryptographicHash::Sha256);
  std::string hashString = hash.toHex(0).toStdString();
  long long ll = std::stoll(hashString);
  long long decryptedHash = decrypt(encryptedHash,m_user.publicKey);
  
  return ll == decryptedHash; 
}
