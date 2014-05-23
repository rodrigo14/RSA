#include <NTL/ZZ.h>
#include <iostream>
#include <cstdio>	
#include "RSA.cpp"

using namespace std;
using namespace NTL;


int main() {
	long nbits = 500;
	RSA r(nbits);
	string saida = r.encrypt("ola mundo");
	r.decrypt(saida);
	
	return 0;
}