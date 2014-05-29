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
	receiver = sender;
	string decipher = receiver.decrypt(v);
	writeTextOnFile(decipher, "decipher.txt");

	// sender.getAttributes();
	
	return 0;
}
