#ifndef RSA_H
#define RSA_H

using namespace std;
using namespace NTL;

string encrypt(const string text);
string decrypt(const string text);
ZZ generate_large_prime(long nbits);
ZZ generate_long_number(long nbits);
ZZ publickey_generator(const ZZ p, const ZZ q);
ZZ privatekey_generator(const ZZ p, const ZZ q);
ZZ mdc(ZZ &p, ZZ &q);
ZZ modular_exponential(const ZZ &a, const ZZ &b, const ZZ &n);


#endif