#ifndef RSA_H
#define RSA_H
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ find_large_prime(int nbits);
ZZ mdc(ZZ &p, ZZ &q);
ZZ cipherkey_generator(ZZ p, ZZ q);
ZZ decipherkey_generator(ZZ p, ZZ q);
string encrypt(string text);
string decrypt(string text);

#endif