#include "RSA.h"

class RSA {
private:
	ZZ privatekey;
	ZZ phi;

public:
	ZZ publickey;
	ZZ mod;

	RSA(int nbits) {
		ZZ p = find_large_prime(nbits);
		ZZ q = find_large_prime(nbits);
		this->mod = p * q;
		this->phi = (p-1) * (q-1);

		this->publickey = publickey_generator(this->phi);
		this->privatekey = privatekey_generator(this->privatekey, this->phi);
	}

	string encrypt(string text) {
		string out;
		for (int i = 0; i < text.size(); i++) {
			ZZ C, M;
			M = text[i];
			C = PowerMod(M, publickey, mod);
			//out += C;
		}

		return out;
	}

	string decrypt(string text) {
		string out;
		for (int i = 0; i < text.size(); i++) {
			ZZ C, M;
			C = text[i];
			M = PowerMod(C, privatekey, mod);
			//out += M;
		}

		return out;
	}

private:
	ZZ find_large_prime(int nbits) {

	}

	ZZ generate_long_number(int nbits) {

	}

	ZZ publickey_generator(ZZ phi) {
		ZZ e;
		return e;
	}

	ZZ privatekey_generator(ZZ e, ZZ phi) {
		ZZ d;
		// algoritmo estendido de Euclides
		return d;
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

	/*
	// returns: res = a^b mod(n)
	ZZ modular_exponentiation(ZZ &a, ZZ &b, ZZ &n) {
		ZZ res;
		res = 1;

		while (b > 0) {
			cout << b << endl;
			if (compare(b&1, 0) > 0) {
				res = (res*a)%n;
			}
			b >>= 1;
			a = (a*a)%n;
		}

		return res;
	}
	*/

};
