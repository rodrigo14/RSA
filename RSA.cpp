#include "RSA.h"
#include <fstream>

class RSA {
private:
	ZZ privatekey;
	ZZ phi;

public:
	ZZ publickey;
	ZZ mod;

	RSA(long nbits) {
		ZZ p, q;
		p = generate_large_prime(nbits);
		q = generate_large_prime(nbits);

		this->mod = p * q;
		this->phi = (p-1) * (q-1);
		this->publickey = publickey_generator(this->phi);
		this->privatekey = privatekey_generator(this->privatekey, this->phi);
/*
		cout << "p: " << p << endl << endl;
		cout << "q: " << q << endl << endl;
		cout << "mod: " << mod << endl << endl;
		cout << "phi: " << phi << endl << endl;
		cout << "publickey: " << publickey << endl << endl;
		cout << "privatekey: " << privatekey << endl << endl;
*/
		ofstream fout("out.txt", ios::trunc);
	}

	~RSA() {
		publickey.kill();
		privatekey.kill();
		mod.kill();
		phi.kill();
	}

	string encrypt(const string text) {
		string out;
		for (int i = 0; i < text.size(); i++) {
			ZZ C, M;
			M = text[i];
			C = modular_exponentiation(M, this->publickey, this->mod) % ('z'-'0') + '0';
			out += ZZtoi(C);
		}

		return out;
	}

	string decrypt(const string text) {
		string out;
		for (int i = 0; i < text.size(); i++) {
			ZZ C, M;
			C = text[i];
			M = modular_exponentiation(C, this->privatekey, this->mod) % ('z'-'0') + '0';
			out += ZZtoi(M);
		}

		cout << out << endl;

		return out;
	}

private:
	ZZ generate_large_prime(long nbits) {
		ZZ prime, w;
		prime = RandomPrime_ZZ(nbits);
		w = rand();

		if (MillerWitness(prime, w) > 0)
			return generate_large_prime(nbits);
		
		return prime;

	}

	ZZ generate_long_number(long nbits) {
		ZZ minimum;
		long a = 2;
		long b = 500;
		power(minimum, a, b);
		ZZ random = RandomLen_ZZ(2*nbits);

		return random;
	}

	// return e = 65537
	ZZ publickey_generator(const ZZ &phi) {
		ZZ e, a;
		a = 2;
		long b = 16;
		e = power(a, b) + 1;

		return e;
	}

	// return d = e^{-1} mod(phi)
	ZZ privatekey_generator(const ZZ &e, const ZZ &phi) {
		ZZ d;
		InvModStatus(d, e, phi);
		
		return d;
	}

	ZZ mdc(ZZ &a, ZZ &b) {
		ZZ r = a%b;

		if (a < b) {
			a ^= b;	b ^= a;	a ^= b;
		}

		while (r > 0) {
			a = b; b = r; r = a%b;
		}

		return b;
	}

	// return res = a^b mod(n)
	ZZ modular_exponentiation(const ZZ &a, const ZZ &b, const ZZ &n) {
		ZZ res;
		ZZ A, B;
		res = 1;
		A = a;
		B = b;

		while (B > 0) {
			if (IsOne(B&1)) {
				res = (res*A)%n;
			}
			B >>= 1;
			A = (A*A)%n;
		}


		return res;
	}


	long ZZtoi(const ZZ &z) {
		ofstream fout("out.txt");
		fout << z << endl;
		ifstream fin("out.txt");
		char buff[80];
		fin.getline(buff, 80);
		return atoi(buff);
	}

};
