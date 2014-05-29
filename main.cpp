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

	RSA emissor(nbits);
	vector<ZZ> v = emissor.encrypt(plaintext);

	for (int i = 0; i < v.size(); ++i) {
		writeTextOnFile(v[i], "cipher.txt");
	}

	RSA receptor(nbits);
	receptor = emissor;
	string s = receptor.decrypt(v);
	writeTextOnFile(s, "decipher.txt");

	// emissor.getAttributes();
	
	return 0;
}
