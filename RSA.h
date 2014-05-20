#ifndef RSA_H
#define RSA_H


ZZ find_large_prime(int nbits);
ZZ mdc(ZZ p, ZZ q);
ZZ cipherkey_generator(ZZ p, ZZ q);
ZZ decipherkey_generator(ZZ p, ZZ q);
string encrypt(string text, ZZ key, ZZ n);
string decrypt(string text, ZZ key, ZZ n);

#endif