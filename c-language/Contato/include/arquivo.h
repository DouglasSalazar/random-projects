#ifndef arquivo_H

#define arquivo_H   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"../include/relacao.h"
#include"../include/grupo.h"
#include"../include/contato.h"

#define CODIGO 123

void inicializacao(int *Ncontatos, LGrupos ** Grupos,LContato * Contatos);
void grava(LContato *Contatos, LGrupos *Grupos,int Ncontatos);

#endif
