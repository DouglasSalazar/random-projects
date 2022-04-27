#ifndef grupo_H

#define grupo_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"../include/contato.h"
#include"../include/relacao.h"

#define CODIGO 123

LGrupos * aloca_grupo(LGrupos *Grupos, int convert);
void CadastroGrupo(LGrupos **Grupos);
void removegrupo(LGrupos **Grupos, int Ncontatos, LContato *Contatos);
void procuragrupo(LGrupos *Grupos);
void listagrupos(LContato *Contatos,int Ncontatos);

#endif
