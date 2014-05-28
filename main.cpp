#include <iostream>
#include "RSA.cpp"

int main() {
	long nbits = 1024;
	RSA r(nbits);
	vector<ZZ> v = r.encrypt("hello, world!");
	string s = r.decrypt(v);
	r.getAttributes();
	cout << s << endl;
	
	return 0;
}
