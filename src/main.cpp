#include <iostream>
#include "RSA.cpp"

int main() {
	long nbits;
	cout << "Number of bits: ";
	cin >> nbits;

	string plaintext = readText("plaintext.txt");
	if (plaintext.empty()) {
		cout << "File not found!" << endl;
		return -1;
	}

	cout << "Generating keys..." << endl;
	RSA r(nbits);

	cout << "Encrypting..." << endl;
	vector<ZZ> cipher = r.encrypt(plaintext);

	for (int i = 0; i < cipher.size(); ++i) {
		writeTextOnFile(cipher[i], "cipher.txt");
	}

	cout << "Decrypting..." << endl;
	string decipher = r.decrypt(cipher);

	writeTextOnFile(decipher, "decipher.txt");
	cout << "Done!" << endl;
	cout << decipher << endl;

	// r.getAttributes();
	
	return 0;
}
