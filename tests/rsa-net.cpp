// Programa que gera os elementos necessarios para
// um esquema RSA.
//
// Entrada: tamanho (em digitos decimais) dos
// primos, semente para aleatorio
//
// Saida: p, q, b, e, f

#include <iostream>		// cin, cout, etc.
#include <stdlib.h>		// atoi
#include <MLCG.h>		// multiplicative linear congruential
				// random number generator
#include <RndInt.h>		// random integer generator
#include <Integer.h>

//--------------------------------------------------
// constantes

const int NARGS = 2;
const int BASE = 10;

MLCG gen;
// rnd vai gerar digitos decimais
RandomInteger rnd(BASE-1,&gen);

//========================================================
// funcoes

//----------------------------------------
// retorna numero aleatorio

Integer aleatorio (int ndigitos) {
  Integer a = 0;
  for(int i=0; i<ndigitos; i++) {
    int digit = rnd.asInt();
    a = BASE*a + digit;
  }
  return a;
}

//----------------------------------------
// exponenciacao modular

Integer expMod (Integer a, Integer e, Integer b) {
  Integer p = a;
  Integer r = 1;
  while (e != 0) {
    if ( e % 2 == 1) {
      r = (r*p) % b;
    }
    p = (p*p) % b;
    e = e/2;
  }

  return r;
}

//----------------------------------------
// ve se e' primo

int primo (Integer c) {
  const int VEZES = 10;

  if (c == 1 || even(c)) {
    return 0;
  }
  if (c < 9) {
    return 1;
  }

  for(int i=0; i<VEZES; i++) {
    Integer a = aleatorio(1+lg(c)/3) % c;
    while ( a <= 1 || a == c-1 )
      a = aleatorio(1+lg(c)/3) % c;
    Integer power = expMod(a,(c-1)/2,c);
    if (abs(power) != 1 && abs(power) != c-1) {
      return 0;
    }
  }
  return 1;
}

//----------------------------------------
// retorna primo aleatorio

Integer primo (const int ndigitos) {
  Integer a = aleatorio(ndigitos);

  while (! primo(a)) {
    a = aleatorio(ndigitos);
  }
  return a;
}

//----------------------------------------
// calcula mdc estendido
// ef + kn = d = mdc(e,n)
// Ah!  Retorna f positivo tambem

void mdcEstendido (Integer e, Integer n,
		   Integer& f, Integer& k, Integer& d) {
  if ( e == 0 ) {
    f = 0;
    k = 1;
    d = n;
  } else {
    mdcEstendido(n % e, e, f, k, d);
    Integer t = f;
    f = k - f * (n / e);
    k = t;
    // para garantir f >= 0
    // (sabemos que f nao vai ser menor que -n)
    if (f < 0) {
      f += n;
      k -= e;
    }
  }
}

//==================================================
// programa principal

main(int argc, char ** argv) {

  //----------------------------------------
  // le parametros e inicializa
  
  if (argc <= NARGS) {
    cerr << "Usage: " << argv[0] <<
      " <ndigitos> <semente>\n";
    exit(1);
  }
  
  int ndigitos = atoi(argv[1]);
  int seed     = atoi(argv[NARGS]);

  gen.reseed(seed,1);
  
  //----------------------------------------
  // gera primos

  Integer p = primo(ndigitos);
  Integer q = primo(ndigitos);

  Integer b = p*q;

  //----------------------------------------
  // gera chaves

  Integer f, k, d;
  
  Integer e = aleatorio(ndigitos+ndigitos) % b;
  mdcEstendido(e,b-p-q+1,f,k,d);
  while (d != 1) {
    e = aleatorio(ndigitos+ndigitos) % b;
    mdcEstendido(e,b-p-q+1,f,k,d);
  }

  cout << "p: " << p << "\n";
  cout << "q: " << q << "\n";
  cout << "b: " << b << "\n";
  cout << "e: " << e << "\n";
  cout << "f: " << f << "\n";

  exit(0);
}