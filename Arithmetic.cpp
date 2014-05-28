#include <NTL/ZZ.h>
#include <fstream>

using namespace std;
using namespace NTL;

// return res = a^b mod(n)
ZZ powerMod(const ZZ &a, const ZZ &b, const ZZ &n) {
	ZZ A; A = a;
	ZZ B; B = b;
	ZZ res; res = 1;

	while (B > 0) {
		if (IsOne(B&1)) {
			res = (res*A)%n;
		}
		B >>= 1;
		A = (A*A)%n;
	}

	return res;
}

// return res = a^b
ZZ Power(const ZZ &a, const ZZ &b) {
	ZZ A; A = a;
	ZZ B; B = b;
	ZZ res; res = 1;

	while (B > 0) {
		if (IsOne(B&1)) {
			res *= A;
		}
		B >>= 1;
		A *= A;
	}

	return res;
}

// return res = a^b
ZZ Power(const long a, const ZZ &b) {
	ZZ A; A = a;
	ZZ B; B = b;
	ZZ res; res = 1;

	while (B > 0) {
		if (IsOne(B&1)) {
			res *= A;
		}
		B >>= 1;
		A *= A;
	}

	return res;
}

ZZ mdc(const ZZ &a, const ZZ &b) {
	ZZ A; A = a;
	ZZ B; B = b;

	ZZ r = A%B;
	if (A < B)
		A ^= B;	B ^= A;	A ^= B;
	while (r > 0) {
		A = B; B = r; r = A%B;
	}

	return B;
}

long ZZtoi(const ZZ &z) {
	ofstream fout("temp");
	fout << z << endl;
	ifstream fin("temp");
	char buff[80];
	fin.getline(buff, 80);
	return atoi(buff);
}