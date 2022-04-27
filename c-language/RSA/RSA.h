#ifndef RSA_H

#define RSA_H 1

#include <gmp.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define CODIGO 123

void codifica(mpz_t *b, mpz_t e, mpz_t n);
void decodifica(mpz_t *b, mpz_t d, mpz_t n, mpz_t e);
int primo(mpz_t n);
void calc_e (mpz_t Phin, mpz_t *e);
void calc_d (mpz_t Phin, mpz_t e ,mpz_t *d);
void escolha_primo(mpz_t *p,mpz_t *q, mpz_t *n, mpz_t *p1, mpz_t *q1, mpz_t * Phin);

#endif
