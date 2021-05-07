#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <cmath>
#include <tuple>
#include <stdlib.h> 
#include <time.h>

using namespace std;

long long gcd(long long a, long long b);
bool checkProperty(pair<long long,long long> publicKey, tuple<long long,long long,long long> b);
long long encrypt(long long msg, pair<long long,long long> publicKey, tuple<long long,long long,long long> privateKey );
long long decrypt(long long msg,pair<long long,long long> publicKey );
long long generatePrimeNumber();
long long modInverse(long long a, long long m);
void createKeys(std::pair<long long, long long> &publicKey, std::tuple<long long, long long, long long> &privateKey);
long long modpow(long long base, long long exp, long long modulus);
#endif