#include <NTL/ZZ.h>
#include <iostream>
#include "RSA.cpp"

using namespace std;
using namespace NTL;


int main() {
	ZZ a, b, c;

	cin >> a;
	cin >> b;
	c = pow(a, b);
	cout << c << endl;
	
	/*
	ZZ a, b, key;


	cin >> key;	
	cin >> a;
	cin >> b;
	RSA r(key);
	r.mdc(a, b);

	*/
	return 0;
}