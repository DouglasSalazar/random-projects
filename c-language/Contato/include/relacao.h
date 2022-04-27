#ifndef relacao_H

#define relacao_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define CODIGO 123
typedef struct Rela{/*Struct com as relações um ponteiro apontando para o grupo em que o contato esta cadastrado*/
    struct Grupo *grupo;
    struct Rela *prox;
}LRela;
typedef struct Grupo{
    int numero;
    char descricao[50];
    int Ncont;
    struct Grupo *prox;
}LGrupos;
typedef struct Contato{	/*Struct contato*/
    int Numero;    
    char Nome[50];
    char sobrenome[50];
    char Telefone[20];
	char Email[50];
    struct Rela *Grupos;    /*Relações dos grupos*/
}LContato;

LRela * aloca_relacao(LRela *Relacao, int convert, LGrupos * Grupos);
void CadastroContatoGrupo(int Ncontatos,LContato *Contatos, LGrupos* Grupos);
#endif
