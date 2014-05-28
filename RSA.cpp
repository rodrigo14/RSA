#include <vector>
#include "MillerRabin.cpp"

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
		this->p = large_prime_generator(nbits);
		this->q = large_prime_generator(nbits);

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
			C = powerMod(M, this->publickey, this->mod);
			out.push_back(C);
		}

		return out;
	}

	string decrypt(const vector<ZZ> v) {
		string out;
		for (int i = 0; i < v.size(); i++) {
			ZZ C, M;
			C = v[i];
			M = powerMod(C, this->privatekey, this->mod);
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
	// return e = 65537
	ZZ publickey_generator(const ZZ &phi) {
		ZZ e, a, b;
		a = 2;
		b = 16;
		e = Power(a, b) + 1;

		return e;
	}

	// return d = e^{-1} mod(phi)
	ZZ privatekey_generator(const ZZ &e, const ZZ &phi) {
		ZZ d;
		InvModStatus(d, e, phi);
		
		return d;
	}


	ZZ long_number_generator(long nbits) {
		ZZ minimum, a, b;
		a = 2;
		b = 500;
		minimum = Power(a, b);
		ZZ random = RandomLen_ZZ(2*nbits);

		return random;
	}

	ZZ large_prime_generator(long nbits) {
		ZZ prime;
		prime = long_number_generator(nbits);

		while (!MillerRabin().isPrime(prime)) {
			prime = long_number_generator(nbits);
		}
		
		return prime;
	}

};
