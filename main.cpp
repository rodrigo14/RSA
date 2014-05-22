#include <NTL/ZZ.h>
#include <iostream>
#include <cstdio>	
#include "RSA.cpp"

using namespace std;
using namespace NTL;


int main() {
	/*
	ZZ a, b, c;

	cin >> a;
	cin >> b;
	c = a * b;
	cout << c << endl;
	
	ZZ key;
	cin >> key;
	cin >> a;
	cin >> b;
	RSA r(key);
	cout << r.mdc(a, b) << endl;

	int num = rand();
	unsigned int *position = (unsigned int*) &num;
	printf("%u\n", position);
	cout << num << " " << position << endl;

	int nbits = 500;
	RSA emissor(nbits);
	RSA receptor(nbits);
	
	int a,b,c,n,res;
	*/
	ZZ a,b,c,n,res;
	a = 1132132;
	b = 2332131231;
	n = 18235327;

	// res = RSA(500).modular_exponentiation(a,b,n);
	RSA r(500);
	r.encrypt("ola mundo");

	//cout << res << endl;
	
	return 0;
}