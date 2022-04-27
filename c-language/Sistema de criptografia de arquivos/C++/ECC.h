#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include <string.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif
DLL_EXPORT typedef struct Us{
	mpz_t x;
	mpz_t y;
}Pontos;

DLL_EXPORT typedef struct U{
	mpz_t x;
	mpz_t y;
	uint32_t key;
}Chave;

DLL_EXPORT typedef struct Eli{
	mpz_t a;
	mpz_t b;
	mpz_t field;
}Curva;

DLL_EXPORT void Duplicacao(Pontos P,Curva Equa_Cryp, mpz_t *P_3x, mpz_t *P_3y);
DLL_EXPORT void Adicao(Pontos P,Curva Equa_Cryp,mpz_t Q_x, mpz_t Q_y, mpz_t *P_3x, mpz_t *P_3y);
DLL_EXPORT void Criptografando(Chave Alice,char c1,char c2, int *x1, int *x2, Curva Equa_Cryp);
DLL_EXPORT void Descriptografando(Chave Alice,char *c1,char *c2, int x1, int x2,Curva Equa_Cryp);
DLL_EXPORT void Calculo_Chaves_Alice(Chave *Alice,Chave Bob, Curva Equa_Cryp);
DLL_EXPORT void Calculo_Chaves_Bob(Pontos P, Chave *Bob, Curva Equa_Cryp);
#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
