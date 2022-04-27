#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_AVL{
	int chave:28;
	int bal:4;
	struct s_AVL* esq;
	struct s_AVL* dir;
}AVL;

void ocupaAVL(AVL** pt,int x,int* h){
	AVL* AVLvo = (AVL*)malloc(sizeof(AVL));
	AVLvo->esq=NULL;
	AVLvo->dir=NULL;
	AVLvo->chave=x;
	AVLvo->bal=0;
	*pt=AVLvo;
	*h=1;
}


/*caso 1 balanco da insercao*/
AVL * caso1(AVL* pt, int *h){
AVL* ptu=NULL;
AVL* ptv=NULL;
ptu=pt->esq;

	if(ptu->bal == -1){
		pt->esq=ptu->dir;
		ptu->dir=pt;
		pt->bal=0;
		pt=ptu;
	}else{
		ptv=ptu->dir;
		ptu->dir=ptv->esq;
		ptv->esq=ptu;
		pt->esq=ptv->dir;
		ptv->dir=pt;
		if(ptv->bal == -1){
			pt->bal=1;
		}else{
			pt->bal=0;
		}
		if(ptv->bal == 1){
			ptu->bal=-1;
		}else{
			ptu->bal=0;
		}
		pt=ptv;
	}
pt->bal=0;
*h=0;
return (pt);
}

/*caso 2 balanco da insercao*/
AVL * caso2(AVL* pt, int *h){
AVL* ptu=NULL;
AVL* ptv=NULL;
ptu=pt->dir;
	if(ptu->bal == 1){
		pt->dir=ptu->esq;
		ptu->esq=pt;
		pt->bal=0;
		pt=ptu;
	}else{
		ptv=ptu->esq;
		ptu->esq=ptv->dir;
		ptv->dir=ptu;
		pt->dir=ptv->esq;
		ptv->esq=pt;
		if(ptv->bal==1){
			pt->bal=-1;
		}else{
			pt->bal=0;
		}
		if(ptv->bal==-1){
			ptu->bal=1;
		}else{
			ptu->bal=0;
		}
		pt=ptv;
	}
pt->bal=0;
*h=0;
	return (pt);
}

/*insercao*/
void insercaoAVL (AVL** pt,int x,int* h){
	if (*pt == NULL){
		ocupaAVL(&*pt,x,&*h);
        *h=1;
	}else if(x != ((*pt)->chave)){
			if(x < ((*pt)->chave)){
				insercaoAVL(&(*pt)->esq,x,&*h);
				if(*h==1){
					switch ((*pt)->bal){
						case 1:
							(*pt)->bal=0;
							*h=0;
						break;
						case 0:
							(*pt)->bal=-1;
						break;
						case -1:
							*pt=caso1(*pt,&*h);
						break;
					}
				}			
			}else{ 
				insercaoAVL(&(*pt)->dir,x,&*h);		
				if(*h==1){
					switch ((*pt)->bal){
						case -1:
							(*pt)->bal=0;
							*h=0;
						break;
						case 0:
							(*pt)->bal=1;
						break;
						case 1:
							*pt=caso2(*pt,&*h);
						break;	
					}
				}
			}		
	}else{
		printf("\nValor ja existente!!\n\n");
	}	
	
}

void impressao(AVL * pt){
    if(pt!=NULL){
        printf("%d ",pt->chave);
        impressao(pt->esq);
        impressao(pt->dir);
    }
}

int main(){
int x=0;
int h=0;/*h=0 FALSO      h=1   VERDADEIRO*/
AVL* pt=NULL;
    do{
	    printf("\nInforme o Chave da sua alocacao\n");
	    scanf("%d",&x);
	    insercaoAVL(&pt,x,&h);
        impressao(pt);
    }while(x>=0);

    return 0;
}

