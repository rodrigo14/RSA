#ifndef RSA_H
#define RSA_H

using namespace std;
using namespace NTL;

ZZ find_large_prime(long nbits);
ZZ mdc(ZZ &p, ZZ &q);
ZZ privatekey_generator(ZZ p, ZZ q);
ZZ publickey_generator(ZZ p, ZZ q);
string encrypt(string text);
string decrypt(string text);

ZZ generate_long_number(long nbits);

#endif