#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_Bin{
	int chave;
    char Nome[50];
    char sobrenome[50];
    char Telefone[20];
	char Email[50];
	struct s_Bin* esq;
	struct s_Bin* dir;
}Bin;

void ocupa(Bin** pt,int x){
	Bin* Binvo = (Bin*)malloc(sizeof(Bin));
	Binvo->esq=NULL;
	Binvo->dir=NULL;
	Binvo->chave=x;
	*pt=Binvo;
}

void insercao(Bin **pt,int x){

    if((*pt)!=NULL){
        if(x==(*pt)->chave){
            printf("no ja inserido\n");
        }else{
            if(x>(*pt)->chave){
                insercao(&(*pt)->dir,x);
            }else{
                insercao(&(*pt)->esq,x);
            }
        }
    }else{
        ocupa(&*pt,x);
    }
}

Bin * busca_maior(Bin *ptcopy){
    if(ptcopy->dir->dir!=NULL){
        busca_maior(ptcopy->dir);
    }else{
        return ptcopy;
    }   
    return ptcopy;
}


void deleta(Bin **ptv,int x,Bin* ptcopy){
Bin *aux=NULL;
Bin *aux1=NULL;
    
    if((*ptv)->dir!=NULL){    
        if((*ptv)->dir->chave==x){
            aux=(*ptv)->dir;
            if(aux->esq==NULL){
                (*ptv)->dir=aux->dir;
                free(aux);
            }else if(aux->dir==NULL){
                (*ptv)->dir=aux->esq;
                free(aux);
            }else if(aux->dir!=NULL && aux->esq!=NULL){
                ptcopy=ptcopy->esq;
                aux1=busca_maior(ptcopy);
                (*ptv)->dir=aux1->dir;
                aux1->dir=NULL;
                (*ptv)->dir->esq=aux->esq;
                (*ptv)->dir->dir=aux->dir;
                free(aux);
            }
        }else if((*ptv)->esq!=NULL){
            aux=(*ptv)->esq;
            if(aux->esq==NULL){
                (*ptv)->esq=aux->dir;
                free(aux);
            }else if(aux->dir==NULL){
                (*ptv)->esq=aux->esq;
                free(aux);
            }else if(aux->dir!=NULL && aux->esq!=NULL){
                ptcopy=ptcopy->esq;
                aux1=busca_maior(ptcopy);
                (*ptv)->esq=aux1->dir;
                aux1->dir=NULL;
                (*ptv)->esq->esq=aux->esq;
                (*ptv)->esq->dir=aux->dir;
                free(aux);
            }
        }
    }
}

void busca_remocao(Bin** pt,int x,Bin** ptv,Bin* ptcopy){
    if(*pt!=NULL){
        if(x==(*pt)->chave){
            deleta(&(*ptv),x,ptcopy);
        }else if(x<(*pt)->chave){
            *ptv=*pt;
            busca_remocao(&(*pt)->esq,x,&*ptv,ptcopy);
        }else{
            *ptv=*pt;
            busca_remocao(&(*pt)->dir,x,&*ptv,ptcopy);
        }
    }
}

void impressao(Bin * pt){
    if(pt!=NULL){
        printf("%d ",pt->chave);
        impressao(pt->esq);
        impressao(pt->dir);
    }
}

int main(){

int x=0;
Bin* pt=NULL;
Bin* ptv=NULL;
Bin* ptcopy=NULL;
    do{
	    scanf("%d",&x);
        if(x==1){
	        printf("\nInforme a Chave a ser inserida\n");
	        scanf("%d",&x);
	        insercao(&pt,x);
            impressao(pt);
        }else{
            printf("\nInforme a Chave a ser removida\n");
	        scanf("%d",&x);
            ptcopy=pt;
            busca_remocao(&pt,x,&ptv,ptcopy);
            impressao(pt);
        }
    }while(x>=0);

    return 0;
}
