#ifndef RSA_H
#define RSA_H

#include <iostream>
#include <math.h>
#include <tuple>
#include <stdlib.h> 
#include <time.h>

using namespace std;

long long gcd(long long a, long long b);
bool checkProperty(pair<long long,long long> publicKey, tuple<long long,long long,long long> b);
long long encrypt(long long msg, pair<long long,long long> publicKey, tuple<long long,long long,long long> b );
long long decrypt(long long msg,pair<long long,long long> publicKey );
long long generatePrimeNumber();
long long mulmod(long long a, long long b, long long m);
long long modulo(long long base, long long e, long long m);
bool Miller(long long p, int iteration);
long long modInverse(long long a, long long m);
void createKeys(std::pair<long long, long long> &publicKey, std::tuple<long long, long long, long long> &privateKey);
#endif