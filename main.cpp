#include <iostream>
#include "RSA.cpp"

int main() {
	long nbits = 500;
	RSA r(nbits);
	vector<ZZ> v = r.encrypt("hello, world!");
	string s = r.decrypt(v);
	cout << s << endl;
	r.getAttributes();
	
	return 0;
}
