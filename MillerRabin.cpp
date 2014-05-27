#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class MillerRabin {
public:
	MillerRabin() {}
	
	bool isPrime(int n) {
		int k = 0, temp = 0;
		do {
			temp = (n-1) % (int) pow(2, ++k);
		} while (temp == 0);
		int q = (n-1)/(int) pow(2,--k);

		int a = 2;//rand()%(n-1) + 1;

		if ((int) pow(a, q) % n == 1)
			return 1;

		for (int i = 0; i < k-1; ++i) {
			if ((int) pow(a, (int) pow(2, i)*q) % n == n-1)
				return 1;
		}

		return 0;
	}
};

int main(int argc, char const *argv[])
{
	int res = MillerRabin().isPrime(101);

	if (res)
		cout << "provavel primo" << endl;
	else
		cout << "composto" << endl;

	return 0;
}