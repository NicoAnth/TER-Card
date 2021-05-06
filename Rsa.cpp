#include "Include/Rsa.h"

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

//for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
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

//Encrypt RSA signature
long long encrypt(long long msg, pair<long long,long long> publicKey,tuple<long long,long long,long long> privateKey ){

   long long c = pow(msg,get<2>(privateKey));
   c = fmod(c,publicKey.first);
   return c;
}

//Decrypt RSA signature
long long decrypt(long long msg,pair<long long,long long> publicKey ){

   long long d = pow(msg,get<1>(publicKey));
   d = fmod(d,publicKey.first);
   return d;   
}

long long generatePrimeNumber(){

   //Rand between 10 000 and 10 000 000
   long long nb = rand()% 1000 + 10000;
   bool isPrime= false;

   //Peut-être implémenter Miller-Rabin plus tard ce serait plus sérieux
   while(isPrime == false){
      nb = rand()% 1000 + 10000;
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

