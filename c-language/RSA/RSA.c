#include"RSA.h"

void codifica(mpz_t *b, mpz_t e, mpz_t n){

	char *ebits=(char *)malloc(mpz_sizeinbase(e,2)*sizeof(char));
	int k,i;
	mpz_t r;
	mpz_t mul;
	mpz_init_set(r,*b);
	mpz_get_str(ebits, 2, e);
	k=strlen(ebits);
	mpz_init_set_ui(mul,1);

	for (i = k-1; i >= 0; i--){
		if(ebits[i] == '1'){
			mpz_mul(mul, mul, r);
		}
		mpz_mul(r, r, r);
		mpz_mod(r, r, n);
	}
	mpz_mod(r, mul, n);
    mpz_set(*b,r);
    mpz_clear(r);
	mpz_clear(mul);
    free(ebits);
}

void decodifica(mpz_t *b, mpz_t d, mpz_t n, mpz_t e){

    char *dbits=(char *)malloc(mpz_sizeinbase(d,2)*sizeof(char));
	int k,i;
	mpz_t r;
	mpz_t mul;
	mpz_init_set(r,*b);
	mpz_get_str(dbits, 2, e);
	k=strlen(dbits);
	mpz_init_set_ui(mul,1);

	for (i = k-1; i >= 0; i--){
		if(dbits[i] == '1'){
			mpz_mul(mul, mul, r);
		}
		mpz_mul(r, r, r);
		mpz_mod(r, r, n);
	}
	mpz_mod(r, mul, n);
    mpz_set(*b,r);
	mpz_clear(r);
	mpz_clear(mul);
    free(dbits);
}
s
int primo(mpz_t n){
    
    if(mpz_probab_prime_p (n, 100)>=1){
        return 1;
    }else{
        return 0;
    }

}

void calc_e (mpz_t Phin, mpz_t *e){
    mpz_t gcd;
    mpz_init (gcd);
    mpz_set_ui(*e,65537);
    mpz_gcd(gcd, *e, Phin);
    while(mpz_cmp_ui(gcd, 1)!= 0){
        mpz_add_ui(*e, *e, 2);
        mpz_gcd(gcd, *e, Phin);    
    }
}

void calc_d (mpz_t Phin, mpz_t e ,mpz_t *d){
    
    mpz_t g;
    mpz_t s;
    mpz_init(g);
    mpz_init(s);
    mpz_gcdext (g, s, *d, Phin, e);
    if(mpz_cmp_ui (*d, 0)< 0) mpz_add(*d, Phin, *d);
    mpz_clear(g);
    mpz_clear(s);
}

void escolha_primo(mpz_t *p,mpz_t *q, mpz_t *n, mpz_t *p1, mpz_t *q1, mpz_t * Phin){
    do{
        printf("Informe o primo p: ");
        gmp_scanf("%Zd", &*p);/*leitura do primo p*/
    }while (primo (*p)==0);/*verificação atraves da funçao isprimo do primo p*/

    do{ 
        printf ("Informe o primo q: ");
        gmp_scanf ("%Zd",&*q);
     }while (primo (*q)==0);

     mpz_mul (*n, *p, *q); /*Criação de n=(p*q)*/
     mpz_sub_ui (*p1, *p, 1);/*p-1*/
     mpz_sub_ui (*q1, *q, 1);/*p-1*/
     mpz_mul (*Phin, *p1, *q1);/*Criação de Phin Phin=(p-1)(q-1)*/
}

