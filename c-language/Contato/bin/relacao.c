#include"../include/relacao.h"

LRela * aloca_relacao(LRela *Relacao, int convert, LGrupos * Grupos){
LRela * Rela=Relacao;
LGrupos * Grup=Grupos;
LRela * novo=NULL;

    if(Grup!=NULL){
        while(Grup->prox!=NULL && Grup->numero != convert){/*verificação se o codigo de grupo informado e existente*/
            if(Grup->numero!=convert){      
                if(Grup->prox==NULL){   
                   return NULL;      
                }    
            }
            Grup=Grup->prox;
        }
        if(Grup->numero==convert){/*se existir um grupo*/
            if(Rela==NULL){/*caso nao haja nenhuma relação cadastrada*/
                novo=(LRela*)malloc(sizeof(LRela));
                novo->grupo=Grup;
                Grup->Ncont+=1;
                novo->prox=NULL;
                return novo;
            }else{
                while(Rela->prox!=NULL && Rela->grupo->numero != convert){/*verificaçao se a relação informada nao esta cadastrada*/
                    if(Rela->grupo->numero!=convert){      
                        if(Rela->prox==NULL){   
                           return NULL;     
                        }     
                    }
                    Rela=Rela->prox;
                }
                if(Rela->grupo->numero!=convert){/*inserçao sempre final da lista*/
                    novo=(LRela*)malloc(sizeof(LRela));
                    novo->grupo=Grup;
                    Grup->Ncont+=1;
                    Rela->prox=novo;
                    novo->prox=NULL;
                    return Rela;
                }else{
                    return NULL;
                }
            }
        }else{/*se nao exitir um grupo*/
            return NULL;
        }
    }else{
        return NULL;
    }
}
void CadastroContatoGrupo(int Ncontatos,LContato *Contatos, LGrupos* Grupos){
int grupo=0,contato=0,i=0;
LRela *aux=NULL;

    do{
        printf("\nInforme o codigo do Contato: Obs: Para sair digite numero negativo\n");
        scanf("%d",&contato);
        i=0;
        while(Contatos[i].Numero!=contato && i<Ncontatos)/*Valida codigo de contato se e existente*/
            i++;
        if(contato>=0 && Contatos[i].Numero==contato){
            printf("\nInforme o codigo do grupo Obs: Para sair digite numero negativo\n");
            scanf("%d",&grupo);/*codigo de grupo*/
            if(grupo>=0){ 
                aux=aloca_relacao(Contatos[i].Grupos, grupo,Grupos);
                if(aux==NULL){
                    printf("\nErro! Grupo Inexistente ou ja Cadastrado\n");
                }else{
                    Contatos[i].Grupos=aux;
                    printf("\nRELACAO CADASTRADA COM SUCESSO\n");
                    contato=-9;                
                }
            }else if(contato>=0){
                printf("\nCONTATO NAO EXISTENTE\n");
            }
        }
   }while(contato>=0 && grupo>=0);
}
