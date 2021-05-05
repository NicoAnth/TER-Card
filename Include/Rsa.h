#ifndef RSA_H
#define RSA_H

#include<iostream>
#include<math.h>
#include <tuple>
#include <stdlib.h> 
#include <time.h>
#define ll long long
using namespace std;

int gcd(int a, int b);
bool checkProperty(pair<ll,ll> publicKey, tuple<ll,ll,ll> b);
ll encrypt(ll msg, pair<ll,ll> publicKey, tuple<ll,ll,ll> b );
ll decrypt(ll msg,pair<ll,ll> publicKey );
ll generatePrimeNumber();
ll mulmod(ll a, ll b, ll m);
ll modulo(ll base, ll e, ll m);
bool Miller(ll p, int iteration);
#endif