#include <NTL/ZZ.h>
#include <iostream>
#include "RSA.cpp"

using namespace std;
using namespace NTL;


int main() {
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

	/*
	*/
	return 0;
}