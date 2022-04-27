#include "main.h"

extern "C" DLL_EXPORT void Adicao(Pontos P,Curva Equa_Cryp,mpz_t Q_x, mpz_t Q_y, mpz_t *P_3x, mpz_t *P_3y){
	mpz_t temp,slope;

	mpz_init(temp);
	mpz_init_set_ui(slope,0);

    mpz_mod(P.x,P.x,Equa_Cryp.field);
	mpz_mod(P.y,P.y,Equa_Cryp.field);
	mpz_mod(Q_x,Q_x,Equa_Cryp.field);
	mpz_mod(Q_y,Q_y,Equa_Cryp.field);

	if(mpz_cmp_ui(P.x,0)==0 && mpz_cmp_ui(P.y,0)==0)
        mpz_set(*P_3x,Q_x); mpz_set(*P_3y,Q_y);

	if(mpz_cmp_ui(Q_x,0)==0 && mpz_cmp_ui(Q_y,0)==0)
        mpz_set(*P_3x,P.x); mpz_set(*P_3y,P.y);

	if(mpz_cmp_ui(Q_y,0)!=0){
        mpz_sub(temp,Equa_Cryp.field,Q_y);mpz_mod(temp,temp,Equa_Cryp.field);
	}
	else{
		mpz_set_ui(temp,0);
	}

	if(mpz_cmp(P.y,temp)==0 && mpz_cmp(P.x,Q_x)==0){
        mpz_set_ui(*P_3x,0); mpz_set_ui(*P_3y,0);
	}
	else{
		mpz_sub(temp,P.x,Q_x);
		mpz_mod(temp,temp,Equa_Cryp.field);
		mpz_invert(temp,temp,Equa_Cryp.field);
		mpz_sub(slope,P.y,Q_y);
		mpz_mul(slope,slope,temp);
		mpz_mod(slope,slope,Equa_Cryp.field);
		mpz_mul(*P_3x,slope,slope);
		mpz_sub(*P_3x,*P_3x,P.x);
		mpz_sub(*P_3x,*P_3x,Q_x);
		mpz_mod(*P_3x,*P_3x,Equa_Cryp.field);
		mpz_sub(temp,P.x,*P_3x);
	    mpz_mul(*P_3y,slope,temp);
		mpz_sub(*P_3y,*P_3y,P.y);
		mpz_mod(*P_3y,*P_3y,Equa_Cryp.field);
	}
}

extern "C" DLL_EXPORT void Duplicacao(Pontos P,Curva Equa_Cryp, mpz_t *P_3x, mpz_t *P_3y){


		mpz_t slope,temp;

		mpz_init(temp);
		mpz_init(slope);


		if(mpz_cmp_ui(P.y,0)!=0){

		/*calcula LAMBIDA*/
		mpz_mul_ui(temp,P.y,2);
		mpz_invert(temp,temp,Equa_Cryp.field);
		mpz_mul(slope,P.x,P.x);
		mpz_mul_ui(slope,slope,3);
		mpz_add(slope,slope,Equa_Cryp.a);
		mpz_mul(slope,slope,temp);
		mpz_mod(slope,slope,Equa_Cryp.field);
		/*calcula X3*/
		mpz_mul(*P_3x,slope,slope);
		mpz_sub(*P_3x,*P_3x,P.x);
		mpz_sub(*P_3x,*P_3x,P.x);
		mpz_mod(*P_3x,*P_3x,Equa_Cryp.field);
		/*calcula Y3*/
		mpz_sub(temp,P.x,*P_3x);
		mpz_mul(*P_3y,slope,temp);
		mpz_sub(*P_3y,*P_3y,P.y);
		mpz_mod(*P_3y,*P_3y,Equa_Cryp.field);

		}
		else{
			mpz_set_ui(*P_3x,0);
			mpz_set_ui(*P_3y,0);
		}
}

extern "C" DLL_EXPORT void Criptografando(Chave Alice,char c1,char c2, int *x1, int *x2, Curva Equa_Cryp){
	mpz_t alice_x_aux2, alice_y_aux2;

	mpz_init(alice_x_aux2);
	mpz_init(alice_y_aux2);

    *x1= (int)c1;
    //Calculo Criptografia por x1
    mpz_mul_ui(alice_x_aux2,Alice.x,*x1);
    mpz_mod(alice_x_aux2,alice_x_aux2,Equa_Cryp.field);
    *x1=mpz_get_ui(alice_x_aux2);

    *x2= (int)c2;
    //Calculo Criptografia por x2
    mpz_mul_ui(alice_y_aux2,Alice.y,*x2);
    mpz_mod(alice_y_aux2,alice_y_aux2,Equa_Cryp.field);
    *x2=mpz_get_ui(alice_y_aux2);
}

extern "C" DLL_EXPORT void Descriptografando(Chave Alice,char *c1,char *c2, int x1, int x2,Curva Equa_Cryp){
    mpz_t alice_x_aux, alice_y_aux;
	mpz_t alice_x_aux2, alice_y_aux2;

	mpz_init(alice_x_aux);
	mpz_init(alice_y_aux);
	mpz_init(alice_x_aux2);
	mpz_init(alice_y_aux2);
    mpz_invert(alice_x_aux,Alice.x,Equa_Cryp.field);
    mpz_invert(alice_y_aux,Alice.y, Equa_Cryp.field);

    //Calculo Descriptografando por x1
    mpz_mul_ui(alice_x_aux2,alice_x_aux,x1);
    mpz_mod(alice_x_aux2,alice_x_aux2,Equa_Cryp.field);
    x1=mpz_get_ui(alice_x_aux2);
    *c1=(char)x1;

    //Calculo Descriptografando por x2
    mpz_mul_ui(alice_y_aux2,alice_y_aux,x2);
    mpz_mod(alice_y_aux2,alice_y_aux2,Equa_Cryp.field);
    x2=mpz_get_ui(alice_y_aux2);
    *c2=(char)x2;
}

extern "C" DLL_EXPORT void Calculo_Chaves_Alice(Chave *Alice,Chave Bob, Curva Equa_Cryp){
    mpz_t Q_x;
	mpz_t Q_y;
	mpz_t result_x;
	mpz_t result_y;
	uint32_t i;
	Pontos P;

	mpz_init_set_ui(Q_x, 0);
	mpz_init_set_ui(Q_y, 0);
	mpz_init_set_ui(result_x, 0);
	mpz_init_set_ui(result_y, 0);

	mpz_init_set(P.x, Bob.x);
    mpz_init_set(P.y, Bob.y);
	/* CALCULANDO BP (BOB POINT) (KP=P+P+P+P+P...) (BOB_KEY == 815(static))*/
	Duplicacao(P,Equa_Cryp, &Q_x, &Q_y);
	for (i = 0; i < (Alice->key-2); ++i){
		Adicao(P,Equa_Cryp, Q_x, Q_y, &result_x, &result_y);
		mpz_set(Q_x,result_x);
		mpz_set(Q_y,result_y);
	}

	mpz_set(Alice->x, Q_x);
	mpz_set(Alice->y, Q_y);
}

extern "C" DLL_EXPORT void Calculo_Chaves_Bob(Pontos P, Chave *Bob, Curva Equa_Cryp){
    mpz_t Q_x;
	mpz_t Q_y;
	mpz_t result_x;
	mpz_t result_y;
	uint32_t i;

	mpz_init_set_ui(Q_x, 0);
	mpz_init_set_ui(Q_y, 0);
	mpz_init_set_ui(result_x, 0);
	mpz_init_set_ui(result_y, 0);

	/* CALCULANDO BP (BOB POINT) (KP=P+P+P+P+P...) (BOB_KEY == 815(static))*/
	Duplicacao(P,Equa_Cryp, &Q_x, &Q_y);
	for (i = 0; i < (Bob->key-2); ++i){
		Adicao(P,Equa_Cryp, Q_x, Q_y, &result_x, &result_y);
		mpz_set(Q_x,result_x);
		mpz_set(Q_y,result_y);
	}

	mpz_set(Bob->x, Q_x);
	mpz_set(Bob->y, Q_y);
}

