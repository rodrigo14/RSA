#include <fstream>
#include <vector>
#include "RSA.h"

class RSA {
private:
	ZZ p, q;
	ZZ privatekey;
	ZZ phi;

public:
	ZZ publickey;
	ZZ mod;

	RSA() {}

	RSA(long nbits) {
		this->p = generate_large_prime(nbits);
		this->q = generate_large_prime(nbits);

		this->mod = p * q;
		this->phi = (p-1) * (q-1);
		this->publickey = publickey_generator(this->phi);
		this->privatekey = privatekey_generator(this->publickey, this->phi);

		ofstream fout("temp", ios::trunc);
	}

	~RSA() {
		publickey.kill();
		privatekey.kill();
		mod.kill();
		phi.kill();
	}

	vector<ZZ> encrypt(const string text) {
		vector<ZZ> out;
		for (int i = 0; i < text.size(); i++) {
			ZZ C, M;
			M = text[i];
			C = modular_exponentiation(M, this->publickey, this->mod);
			out.push_back(C);
		}

		return out;
	}

	string decrypt(const vector<ZZ> v) {
		string out;
		for (int i = 0; i < v.size(); i++) {
			ZZ C, M;
			C = v[i];
			M = modular_exponentiation(C, this->privatekey, this->mod);
			out += ZZtoi(M);
		}

		return out;
	}

	void getAttributes() {
		cout << "p: " << this->p << endl << endl;
		cout << "q: " << this->q << endl << endl;
		cout << "mod: " << this->mod << endl << endl;
		cout << "phi: " << this->phi << endl << endl;
		cout << "publickey: " << this->publickey << endl << endl;
		cout << "privatekey: " << this->privatekey << endl << endl;
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
		if (a < b)
			a ^= b;	b ^= a;	a ^= b;
		while (r > 0)
			a = b; b = r; r = a%b;

		return b;
	}

public:
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
		ofstream fout("temp");
		fout << z << endl;
		ifstream fin("temp");
		char buff[80];
		fin.getline(buff, 80);
		return atoi(buff);
	}

};
