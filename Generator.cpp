ZZ long_number_generator(long nbits) {
		ZZ minimum, a, b;
		a = 2;
		b = 500;
		minimum = Power(a, b);
		ZZ random = RandomLen_ZZ(nbits);

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