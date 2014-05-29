
ZZ long_number_generator(long nbits) {
	ZZ minimum, a, b;
	a = 2;
	b = 500;
	minimum = Power(a, b);
	ZZ random = RandomBits_ZZ(nbits);

	return random;
}

vector<ZZ> large_primes_generator(long nbits) {
	vector<ZZ> primes;
	
	for (int i=0; i<2; i++) {
		ZZ prime = RandomLen_ZZ(nbits);
		while (!MillerRabin().isPrime(prime)) {
			prime = RandomLen_ZZ(nbits);
		}
		primes.push_back(prime);
	}

	return primes;
}

ZZ getP(long nbits) {
	vector<ZZ> v = large_primes_generator(nbits);
	ZZ p = v[0];
	return p;
}

ZZ getQ(long nbits) {
	vector<ZZ> v =large_primes_generator(nbits);
	ZZ q = v[1];
	return q;
}