#include <NTL/ZZ.h>
#include <fstream>

using namespace std;
using namespace NTL;

// return res = a^b
ZZ Power(const ZZ &a, const ZZ &b) {
	ZZ A = a;
	ZZ B = b;
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
	ZZ B = b;
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

long ZZtoi(const ZZ &z) {
	ofstream fout(".temp");
	fout << z << endl;
	ifstream fin(".temp");
	char buff[80];
	fin.getline(buff, 80);
	system("rm .temp");
	return atoi(buff);
}