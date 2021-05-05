#include "Include/Rsa.h"
#define ll long long

using namespace std;


// find gcd
int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}

//for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
bool checkProperty(pair<ll,ll> publicKey, tuple<ll,ll,ll> privateKey){

   ll phi = (get<0>(privateKey)-1)*(get<1>(privateKey)-1);
   ll track;
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
ll encrypt(ll msg, pair<ll,ll> publicKey,tuple<ll,ll,ll> privateKey ){

   ll c = pow(msg,get<2>(privateKey));
   c = fmod(c,publicKey.first);
   return c;
}

//Decrypt RSA signature
ll decrypt(ll msg,pair<ll,ll> publicKey ){

   ll d = pow(msg,get<1>(publicKey));
   d = fmod(d,publicKey.first);
   return d;   
}

ll generatePrimeNumber(){

   //Rand between 10 000 and 10 000 000
   ll nb = rand()% 1000 + 10000;

   while(Miller(nb,150)){
      nb = rand()% 1000 + 10000;
   }
   return nb;
}

//Compute a*b mod m
ll mulmod(ll a, ll b, ll m){
   ll x = 0,y = a % m;
   while(b > 0) {
      if(b%2 == 1) {
         x = (x+y) % m;
      }
      y = (y*2) % m;
      b /= 2;
   }
   return x % m;
}
// Compute e%m 
ll modulo(ll base, ll e, ll m) {
   ll x = 1;
   ll y = base;
   while(e > 0) {
      if(e%2 == 1){
         x = (x*y) % m;
         y = (y*y) % m;
         e = e/2;
      }
   }
   return x % m;
}

// Miller-Rabin algorithm
bool Miller(ll p, int iteration) {
   if(p<2) {
      return false;
   }
   if(p!=2 && p%2==0) {
      return false;
   }
   ll s = p-1;
   while(s%2 == 0) {
      s/=2;
   }
   for(int i = 0; i < iteration; i++) {
      ll a = rand() % (p-1) + 1, temp = s;
      ll mod = modulo(a, temp, p);
      while(temp != p-1 && mod != 1 && mod != p-1) {
         mod = mulmod(mod, mod, p);
         temp *= 2;
      }
      if(mod != p-1 && temp % 2 == 0) {
         return false;
      }
   }
   return true;
}


