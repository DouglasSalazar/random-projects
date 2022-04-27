#include"../include/grupo.h"


LGrupos * aloca_grupo(LGrupos *Grupos, int convert){
LGrupos * aux=Grupos;/*Ponteiro para caminhar na lista*/
LGrupos * novo;/*alocaçao de um novo no*/
    if(aux!=NULL){/*Grupos nao estiver vazio*/
        while(aux->prox!=NULL){
            if(aux->numero==convert){       /*validação de de id ser diferente*/     
                return NULL;         
            }       
            aux=aux->prox;
        }
        if(aux->numero!=convert){/*Alocaçao sempre final da lista*/
            novo=(LGrupos*)malloc(sizeof(LGrupos));
            novo->numero=convert;
            novo->prox=NULL;
            novo->Ncont=0;
            aux->prox=novo;
            return Grupos;
        }else{
            return NULL;
        }
    }else{/*alocação inicio da lista quando estiver vazia*/
        novo=(LGrupos*)malloc(sizeof(LGrupos));
        novo->numero=convert;
        novo->prox=NULL;
        novo->Ncont=0;
        return novo;
    }
}

void CadastroGrupo(LGrupos **Grupos){
int cod=0;
char nome[50];
LGrupos *aux=NULL;
    do{
        printf("\nInforme o codigo do grupos a ser cadastrado: Obs: Para sair digite um numero negativo\n");
        scanf("%d",&cod);/*Codigo do grupo a ser cadastrado caso seja negativo retornara menu principal*/
        if(cod>=0){
            aux=aloca_grupo(*Grupos,cod);
            if(aux==NULL){/*caso nulo grupo ja cadastrado*/
                printf("\nGRUPO JA CADASTRADO\n");  
            }else{
                *Grupos=aux;/*Grupo recebe retorno ja alterado*/
                printf("\nInforme a descrição do grupo\n");
                scanf("%s",nome);                
                while(aux!=NULL){/*validaçao de que grupos tenham nome unico*/
                    if(strcmp(aux->descricao,nome)==0)
                        cod=-9;                    
                    aux=aux->prox;
                }
                if(cod>=0){/*caso negativo sinal que grupo ja tem nome cadastrado*/
                    aux=*Grupos;                       
                    while(aux->prox!=NULL)/*percorrer lista ate o final para novo grupo ser cadastrado*/
                       aux=aux->prox;                    
                    strcpy(aux->descricao,nome);/*copia de nome do grupo*/
                    cod=-9;
                    printf("\nGRUPO CADASTRADO COM SUCESSO\n");
                }else{
                     while(aux->prox!=NULL)/*caso nome seja invalido e posicionado no final e desalocado*/
                       aux=aux->prox; 
                    free(aux);
                    printf("\nERRO GRUPO JA CADASTRADO\n");
                    cod=10;
                }
            }        
        }
    }while(cod>=0);
}

void removegrupo(LGrupos **Grupos, int Ncontatos, LContato *Contatos){
LGrupos *aux=*Grupos;
LGrupos *aux1=NULL;
LRela *rela=NULL;
LRela *relaaux=NULL;
int i=0,j=0;
int cod=0;
    do{
        printf("\nInforme o codigo do grupo a ser removido: Obs Para sair digite numeros negativos\n");
        scanf("%d",&cod);
        if(*Grupos!=NULL && cod>=0){/*caso grupo nao seja Nulo e o valor nao seja negativo*/
            j=0;
            while(j<Ncontatos){/*remove a relacao dos contatos que estao no grupo a ser removido*/
                rela=Contatos[j].Grupos;
                if(rela!=NULL){ 
                   if(rela->grupo->numero==cod){/*em caso de ser o primeiro elemente*/
                            relaaux=rela;
                            rela=rela->prox;
                            free(relaaux);
                            Contatos[j].Grupos=rela;
                     }else{                                
                        while(rela->prox!=NULL){/*enquanto a relacao nao for diferente de nulo*/
                            if(rela->prox->grupo->numero==cod){/*caso encontrar remove o grupo e ajeita o no*/
                                relaaux=rela->prox;
                                rela->prox=rela->prox->prox;
                                free(relaaux);
                            }
                            if(rela->prox!=NULL){
                                rela=rela->prox;
                            }                        
                        }
                    }
                }    
                j++;        
            }
            if(aux->prox==NULL && aux->numero==cod){/*apos ser retirado todas as relacoes dos contatos remocao do grupo*/
                free(*Grupos);/*caso grupo seja primeiro elemento*/
                cod=-9;
                printf("\nGRUPO REMOVIDO COM SUCESSO\n");
            }else{
                while(i==0 && aux->prox!=NULL){/*Enquanto grupo a ser removido nao ser encontrado ou a lista terminar*/
                    if(aux->prox!=NULL){
                        if(aux->prox->numero!=cod){
                            aux=aux->prox;
                        }else{
                            aux1=aux->prox;
                            aux->prox=aux->prox->prox;
                            free(aux1);
                            printf("\nGRUPO REMOVIDO COM SUCESSO\n");
                            i=1;
                            cod=-9;
                        }
                    }else{
                        printf("\nCodigo invalido!! Nenhum grupo encontrado\n");
                    }
                }
            }
        }else{
            printf("\nNENHUM GRUPO CADASTRADO\n");
        }
    }while(cod>=0);
}


void procuragrupo(LGrupos *Grupos){
LGrupos *aux=NULL;
int j=0;
char nome[50];

        printf("\nInforme o Descricao do grupo\n\n");/*Listar grupo por nome*/
        scanf("%s",nome);
        if(aux!=NULL){
            aux=Grupos;
            while(aux!=NULL){
                if(strcmp(aux->descricao,nome)==0){                                                        
                    printf("Codigo Grupo: %d\n",aux->numero);
                    printf("Descricao Grupo: %s\n",aux->descricao);
                    aux=aux->prox;
                    j=1;
                }
            }
        }
        if(j==0){
            printf("\nGrupo nao Encontrado\n");
        }
}


void listagrupos(LContato *Contatos,int Ncontatos){
int i=0,ver=0,ver1=0;
char nome[50];
LRela * aux=NULL;
LRela * aux1=NULL;

    printf("Informe o nome do grupos a ser listados os contatos\n");
    scanf("%s",nome);
    for(i=0;i<Ncontatos;i++){
        aux=Contatos[i].Grupos;
        if(aux!=NULL){
            ver=0;
            while(aux!=NULL && ver!=1){                      /*Lista contatos por grupo*/                                  
                if(strcmp(aux->grupo->descricao,nome)==0){
                    printf("\nNumero: %d\n",Contatos[i].Numero);    
                    printf("Nome: %s\n",Contatos[i].Nome);
                    printf("Sobrenome: %s\n",Contatos[i].sobrenome);
                    printf("Telefone: %s\n",Contatos[i].Telefone);
                    printf("Email: %s\n",Contatos[i].Email);
                    aux1=Contatos[i].Grupos;
                    if(aux1!=NULL){
                        printf("Grupos Pertecentes:\n");
                        while(aux1!=NULL){                                                        
                            printf("Codigo Grupo: %d\n",aux1->grupo->numero);
                            printf("Descricao Grupo: %s\n",aux1->grupo->descricao);
                            aux1=aux1->prox;
                        }
                    }
                    printf("\n");
                    ver=1;
                    ver1=1;
                }
                aux=aux->prox;
            }
        }
        printf("\n");
    }
    if(ver1==0)
        printf("\nGrupo inexistente ou nenhum contato cadastrado\n");
}
    
