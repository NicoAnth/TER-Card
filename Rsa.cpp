#include "Include/Rsa.h"
using namespace std;

// find gcd
long long gcd(long long a, long long b) {
   long long t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}

//Check that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
bool checkProperty(pair<long long,long long> publicKey, tuple<long long,long long,long long> privateKey){

   long long phi = (get<0>(privateKey)-1)*(get<1>(privateKey)-1);
   long long track;
   while(publicKey.second<phi) {
      track = gcd(publicKey.second,phi);
      if(track==1)
         return true;
      else
         publicKey.second++;
   }
   return false;
}

//RSA signature encryption
long long encrypt(long long msg, pair<long long,long long> publicKey,tuple<long long,long long,long long> privateKey){

   return modpow(msg,get<2>(privateKey),publicKey.first);
}

//RSA signature decryption
long long decrypt(long long msg,pair<long long,long long> publicKey ){

   return modpow(msg,get<1>(publicKey),publicKey.first);  
}

//Compute base^exp mod modulus for large numbers
long long modpow(long long base, long long exp, long long modulus) {
  base %= modulus;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

long long generatePrimeNumber(){

   long long nb;
   bool isPrime= false;
   
   //Peut-être implémenter Miller-Rabin, ce sera plus sérieux
   while(isPrime == false){
      
      //Rand between 10 000 and 20 000
      nb = rand()% 10000 + 10000;
      for (int i = 2; i <= nb / 2; ++i) {
         if (nb % i == 0) {
            isPrime = false;
            break;
         }
         isPrime=true;
      }
   }
   return nb;
}

//Compute inverse modular of a mod m
long long modInverse(long long a, long long m)
{
    long long m0 = m;
    long long y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1) {
        // q is quotient
        long long q = a / m;
        long long t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}

//Create both private and public key for RSA
void createKeys(std::pair<long long, long long> &publicKey, std::tuple<long long, long long, long long> &privateKey){

   srand (time(NULL));
  long long p = generatePrimeNumber();
  long long q = generatePrimeNumber();
  long long n = p*q;
  long long e = generatePrimeNumber();
  long long phi = (p-1) * (q-1);
  while(gcd(p-1,e) != 1 || gcd(q-1,e) !=1 || e>=phi){
    e = generatePrimeNumber();
  }
  long long d = modInverse(e,phi);

  publicKey = std::make_pair(n,e);
  privateKey = std::make_tuple(p,q,d);
}
