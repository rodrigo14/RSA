#include <NTL/ZZ.h>
#include <iostream>
#include <cstdio>	
#include "RSA.cpp"

using namespace std;
using namespace NTL;


int main() {
	long nbits = 500;
	RSA r(nbits);
	vector<ZZ> v = r.encrypt("ola mundo");
	r.decrypt(v);
	
	return 0;
}