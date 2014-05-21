#include <NTL/ZZ.h>

using namespace NTL;
using namespace std;

class RSA {
public:
	ZZ key;

	RSA(ZZ key) {
		this->key = key;
	}

	~RSA() {}
	
	string encrypt(string text, ZZ key, ZZ mod) {
	}

	string decrypt(string text, ZZ key, ZZ mod) {
	}

	ZZ mdc(ZZ &a, ZZ &b)	{
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

		cout << b << endl;

		return b;
	}
};
