#include <NTL/ZZ.h>
#include <vector>

using namespace NTL;
using namespace std;

class RSA {
public:
	RSA(long nbits);
	~RSA();
	vector<ZZ> encrypt(const string text);
	string decrypt(const vector<ZZ> v);
	void getAttributes();

private:
	ZZ p, q;
	ZZ publickey;
	ZZ privatekey;
	ZZ n;
	ZZ phi;

	void generate_keys(long nbits);
	ZZ publickey_generator();
	ZZ privatekey_generator(const ZZ &e, const ZZ &phi);
};