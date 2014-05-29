#include <iostream>
#include "RSA.cpp"
#include "read.cpp"

int main() {
	long nbits = 500;
	string plaintext = readText("plaintext.txt");

	if (plaintext.empty()) {
		cout << "File not found!" << endl;
		return -1;
	}

	RSA r(nbits);
	vector<ZZ> v = r.encrypt(plaintext);

	for (int i = 0; i < v.size(); ++i) {
		writeTextOnFile(v[i], "cipher.txt");
	}

	string s = r.decrypt(v);
	writeTextOnFile(s, "decipher.txt");

	// r.getAttributes();
	
	return 0;
}
