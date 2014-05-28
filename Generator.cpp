
ZZ long_number_generator(long nbits) {
	ZZ minimum, a, b;
	a = 2;
	b = 500;
	minimum = Power(a, b);
	ZZ random = RandomLen_ZZ(nbits);

	return random;
}

ZZ large_prime_generator(long nbits) {
	ZZ prime = long_number_generator(nbits);

	while (!MillerRabin().isPrime(prime)) {
		prime = long_number_generator(nbits);
	}
	
	return prime;
}

ZZ BlumBlumShub(long nbits) {
	ZZ p, q;
	do p = large_prime_generator(nbits);
	while (p % 4 != 3);
	do q = large_prime_generator(nbits);
	while (p % 4 != 3);

	ZZ n, s;
	n = p*q;
	do s = long_number_generator(nbits);
	while (mdc(n, s) != 1);

	vector<ZZ> X;
	vector<bool> B;
	X.push_back((s*s) % n);

	for (int i = 1; i < nbits; ++i) {
		X.push_back(X[i-1]*X[i-1] % n);
		int bit = ZZtoi(X[i] & 1);
		B.push_back(bit);
	}

	ZZ num;
	for (int i = 0; i < B.size(); ++i) {
		ZZ j; j = i;
		num += Power(2, B[i]*j);
	}

	cout << num << endl;
	return num;
}
