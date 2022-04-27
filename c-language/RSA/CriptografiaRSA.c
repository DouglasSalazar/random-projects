#include "RSA.h"
#include <stdio.h>

int main() {
    char FRASE[50];
    int convert=0, i=0;
    mpz_t p;
    mpz_t q;
    mpz_t p1;
    mpz_t q1;
    mpz_t n;
    mpz_t Phin;
    mpz_t cod;
    mpz_t d;
    mpz_t e;
    mpz_init (cod);
    mpz_init (d);
    mpz_init (e);    
    mpz_init (p);
    mpz_init (q);
    mpz_init (n);
    mpz_init (p1);
    mpz_init (q1);
    mpz_init (Phin);
    mpz_init (d);
    mpz_init (e);   
    printf("Informe a frase a ser criptografada: ");
    scanf("%50[^\n]s",FRASE);    
    escolha_primo(&p,&q, &n, &p1, &q1, &Phin);
    calc_e (Phin, &e);
    calc_d (Phin, e ,&d);     
    gmp_printf("N:%Zd\nQ:%Zd\nP:%Zd\nP1:%Zd\nP2:%Zd\nPhin:%Zd\nE:%Zd\nD:%Zd\n",n,q,p,p1,q1,Phin,e,d);
    
    

    i=0;    
    while(FRASE[i]!='\0'){ 
        convert=FRASE[i];
        printf("Letra %c - %d - %d =",FRASE[i],convert,FRASE[i]);        
        mpz_set_ui(cod,convert);
        codifica(&cod, e, n);
        gmp_printf("Criptografado: %Zd ",cod);
        decodifica(&cod, d, n,e);
        gmp_printf("Descriptografado: %Zd\n",cod);
        i++;    
    }
    mpz_clear (p);
    mpz_clear (q);
    mpz_clear (n);
    mpz_clear (p1);
    mpz_clear (q1);
    mpz_clear (Phin);
    mpz_clear (d);
    mpz_clear (e);
     
  return 0;
}
