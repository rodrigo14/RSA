
ZZ long_number_generator(long nbits) {
	ZZ minimum, a, b;
	a = 2;
	b = 500;
	minimum = Power(a, b);
	ZZ random = RandomBits_ZZ(nbits);

	return random;
}

ZZ large_prime_generator(long nbits) {
	ZZ prime = RandomLen_ZZ(nbits);
	while (!MillerRabin().isPrime(prime)) {
		prime = RandomLen_ZZ(nbits);
	}

	return prime;
}

