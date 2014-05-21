#include "RSA.h"

class RSA {
private:
	ZZ key, mod;

public:
	RSA(ZZ key) {
		this->key = key;
		this->mod = mod;
	}

	~RSA() {}
	
	string encrypt(string text) {
	}

	string decrypt(string text) {
	}

	ZZ mdc(ZZ &a, ZZ &b) {
		ZZ r = a%b;

		if (a < b) {
			a ^= b;
			b ^= a;
			a ^= b;
		}

		while (r > 0) {
			a = b;
			b = r;
			r = a%b;
		}

		return b;
	}
};
