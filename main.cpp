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

	RSA sender(nbits);
	vector<ZZ> cipher = sender.encrypt(plaintext);

	for (int i = 0; i < cipher.size(); ++i) {
		writeTextOnFile(cipher[i], "cipher.txt");
	}

	RSA receiver(nbits);
	string decipher = receiver.decrypt(cipher);
	writeTextOnFile(decipher, "decipher.txt");
	cout << decipher << endl;
	sender.getAttributes();
	receiver.getAttributes();
	
	return 0;
}
