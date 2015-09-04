#include <iostream>
#include "read.h"
#include "RSA.h"

int main(int argc, char const *argv[]) {
	if (argc != 3) {
		cout << "Enter a number of bits and a input file." << endl;
		return -1;
	}

	string plaintext = readText(argv[1]);
	if (plaintext.empty()) {
		cerr << "File not found!" << endl;
		return -2;
	}

	long nbits = atoi(argv[2]);
	if (nbits < 2) {
		cerr << "Enter a valid number of bits!" << endl;
		return -3;
	}

	cout << nbits << " bits" << endl;
	cout << "Generating keys" << endl;
	RSA r(nbits);

	cout << "Encrypting" << endl;
	vector<ZZ> cipher = r.encrypt(plaintext);

	for (unsigned int i = 0; i < cipher.size(); ++i) {
		writeTextOnFile(cipher[i], "cipher.txt");
	}

	cout << "Decrypting" << endl;
	string decipher = r.decrypt(cipher);

	writeTextOnFile(decipher, "decipher.txt");
	cout << "Done!" << endl;

	// cout << decipher << endl;
	// r.getAttributes();
	
	return 0;
}
