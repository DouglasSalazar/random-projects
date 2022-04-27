#ifndef contato_H

#define contato_H   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"../include/relacao.h"
#include"../include/grupo.h"

#define CODIGO 123

void removecontato(LContato *Contatos,int *Ncontatos);
void procuracontato(LContato *Contatos,int Ncontatos);
void listatodoscontatos(LContato *Contatos,int Ncontatos);
void CadastroContato(LContato *Contatos, int *Ncontatos,LGrupos *Grupos);

#endi
