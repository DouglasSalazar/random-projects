/******************************************************************/
/*Douglas Correia Salazar*/
/*RGM */
/*AED-II*/
/*****************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_AVL{
	int chave;
	int bal:4;
    char Nome[50];
    char sobrenome[50];
    char Telefone[20];
	char Email[50];
	struct s_AVL* esq;
	struct s_AVL* dir;
}AVL;

typedef struct s_Bin{
	int chave;
    char Nome[50];
    char sobrenome[50];
    char Telefone[20];
	char Email[50];
	struct s_Bin* esq;
	struct s_Bin* dir;
}Bin;
/**********************************************************************************************************************************************/
/*Arvore Binaria*/

void ocupa(Bin** pt,int x,char Nome[50],char sobrenome[50],char Telefone[20],char Email[50]){
	Bin* Binvo = (Bin*)malloc(sizeof(Bin));
	Binvo->esq=NULL;
	Binvo->dir=NULL;
	Binvo->chave=x;
	strcpy(Binvo->Nome,Nome);
	strcpy(Binvo->sobrenome,sobrenome);
	strcpy(Binvo->Telefone,Telefone);
	strcpy(Binvo->Email,Email);
	*pt=Binvo;
}

void insercao(Bin **pt,int x,char Nome[50],char sobrenome[50],char Telefone[20],char Email[50]){/*INserçao maior para direita menor para esquerda*/

    if((*pt)!=NULL){
        if(x==(*pt)->chave){
            printf("no ja inserido\n");
        }else{
            if(x>(*pt)->chave){
                insercao(&(*pt)->dir,x,Nome,sobrenome,Telefone,Email);
            }else{
                insercao(&(*pt)->esq,x,Nome,sobrenome,Telefone,Email);
            }
        }
    }else{
        ocupa(&*pt,x,Nome,sobrenome,Telefone,Email);
    }
}

Bin * busca_maior(Bin *ptcopy){/*Acha maior menor */
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
        if((*ptv)->dir->chave==x){/*se chave esta para direita*/
            aux=(*ptv)->dir;
            if(aux->esq==NULL){/*esquerda igual a null*/
                (*ptv)->dir=aux->dir;
                free(aux);
            }else if(aux->dir==NULL){/*direita ighual a null*/
                (*ptv)->dir=aux->esq;
                free(aux);
            }else if(aux->dir!=NULL && aux->esq!=NULL){/*tem os dois nos chama a função de escolha de maior*/
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
            if(aux->esq==NULL){/*esquerda igual a NULL*/
                (*ptv)->esq=aux->dir;
                free(aux);
            }else if(aux->dir==NULL){/*direita igual a NULL*/
                (*ptv)->esq=aux->esq;
                free(aux);
            }else if(aux->dir!=NULL && aux->esq!=NULL){/*contendo os dois nso*/
                ptcopy=ptcopy->esq;
                aux1=busca_maior(ptcopy);/*chama funçao maior menor*/
                (*ptv)->esq=aux1->dir;
                aux1->dir=NULL;
                (*ptv)->esq->esq=aux->esq;
                (*ptv)->esq->dir=aux->dir;
                free(aux);
            }
        }
    }
}

void busca_remocao(Bin** pt,int x,Bin** ptv,Bin* ptcopy){/*busca remocao*/
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
/**********************************************************************************************************************************************/
/*AVL*/
void ocupaAVL(AVL** pt,int x,int* h, char Nome[50],char sobrenome[50],char Telefone[20],char Email[50]){
	AVL* AVLvo = (AVL*)malloc(sizeof(AVL));
	AVLvo->esq=NULL;
	AVLvo->dir=NULL;
	AVLvo->chave=x;
	AVLvo->bal=0;
	strcpy(AVLvo->Nome,Nome);
	strcpy(AVLvo->sobrenome,sobrenome);
	strcpy(AVLvo->Telefone,Telefone);
	strcpy(AVLvo->Email,Email);
	*pt=AVLvo;
	*h=1;
}


/*caso 1 balanco da insercao*/
AVL * caso1(AVL* pt, int *h){
AVL* ptu=NULL;
AVL* ptv=NULL;
ptu=pt->esq;

	if(ptu->bal == -1){
        printf("\nRotacao simples a direita\n");
        printf("\nNo desbalanceado\nId: %d \nNome:%s %s \nTelefone:%s \nEmail:%s\n",ptu->chave,ptu->Nome,ptu->sobrenome,ptu->Telefone,ptu->Email);
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
        printf("\nRotacao Dupla a direita\n");
        printf("\nNo desbalanceado\nId: %d \nNome:%s %s \nTelefone:%s \nEmail:%s\n",ptv->chave,ptv->Nome,ptv->sobrenome,ptv->Telefone,ptv->Email);
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
        printf("\nRotacao simples a esquerda\n");
        printf("\nNo desbalanceado\nId: %d \nNome:%s %s \nTelefone:%s \nEmail:%s\n",ptu->chave,ptu->Nome,ptu->sobrenome,ptu->Telefone,ptu->Email);
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
        printf("\nRotacao Dupla a esquerda\n");
        printf("\nNo desbalanceado\nId: %d \nNome:%s %s \nTelefone:%s \nEmail:%s\n",ptv->chave,ptv->Nome,ptv->sobrenome,ptv->Telefone,ptv->Email);
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


void insercaoAVL (AVL** pt,int x,int* h,char Nome[50],char sobrenome[50],char Telefone[20],char Email[50]){/*insercao AVL*/
	if (*pt == NULL){
		ocupaAVL(&*pt,x,&*h,Nome,sobrenome,Telefone,Email);
        *h=1;
	}else if(x != ((*pt)->chave)){
			if(x < ((*pt)->chave)){
				insercaoAVL(&(*pt)->esq,x,&*h,Nome,sobrenome,Telefone,Email);
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
				insercaoAVL(&(*pt)->dir,x,&*h,Nome,sobrenome,Telefone,Email);		
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
/**********************************************************************************************************************************************/

void inicializaArv(AVL **pt,int *h,Bin **ptv,int x){/*Leitura do arquivo Contatos.txt para arvore*/
int chave;
char Nome[50];
char sobrenome[50];
char Telefone[20];
char Email[50];
FILE* arq=NULL;

    arq=fopen("contatos.txt","r");
    if(arq!=NULL){
        if(x==1){/*Insere AVL*/
            while(!feof(arq)){
                if(fscanf(arq,"%d %s %s %s %s",&chave,Nome,sobrenome,Telefone,Email)>0)
			        insercaoAVL(&*pt,chave,&*h,Nome,sobrenome,Telefone,Email);   
            }
        }else{/*Insere Binaria */
            while(!feof(arq)){
                if(fscanf(arq,"%d %s %s %s %s",&chave,Nome,sobrenome,Telefone,Email)>0)
			        insercao(&*ptv,chave,Nome,sobrenome,Telefone,Email);   
            }
        }
    }
    fclose(arq);
}

void grava(AVL * pt,Bin * ptv,int x, FILE**arq){/*Gravação no arquivo contatos.txt após finalizar a consuta*/

    if(x==1){
        if(pt!=NULL){
            fprintf(*arq,"%d %s %s %s %s\n",pt->chave,pt->Nome,pt->sobrenome,pt->Telefone,pt->Email);
            grava(pt->esq,ptv,x,&*arq);
            grava(pt->dir,ptv,x,&*arq);
        }
    }else{
        if(pt!=NULL){
            fprintf(*arq,"%d %s %s %s %s\n",ptv->chave,ptv->Nome,ptv->sobrenome,ptv->Telefone,ptv->Email);
            grava(pt,ptv->esq,x,&*arq);
            grava(pt,ptv->dir,x,&*arq);
        }
    }
}

void desalocando(AVL* pt, Bin* ptv,int x){/*desaloca arvore em pos ordem caso 1 avl caso 2 binaria*/

    if(x==1){
        if(pt!=NULL){                
            desalocando(pt->esq,ptv,x);
            desalocando(pt->dir,ptv,x);
            if(pt!=NULL)        
                free(pt);
        }
    }else{
        if(ptv!=NULL){        
            desalocando(pt,ptv->esq,x);
            desalocando(pt,ptv->dir,x);
            if(ptv!=NULL)            
                free(ptv);
        }
    }
}

void impressao(AVL * pt,Bin * ptv, int x){/*impressao de arvores caso 1 avl caso 2 binarias*/
    if(x==1){
        if(pt!=NULL){
            impressao(pt->esq,ptv,x);
            printf("\nId: %d \nNome:%s %s \nTelefone:%s \nEmail:%s\n",pt->chave,pt->Nome,pt->sobrenome,pt->Telefone,pt->Email);
            impressao(pt->dir,ptv,x);
        }
    }else{
        if(ptv!=NULL){
            impressao(pt,ptv->esq,x);
            printf("\nId: %d \nNome:%s %s \nTelefone:%s \nEmail:%s\n",ptv->chave,ptv->Nome,ptv->sobrenome,ptv->Telefone,ptv->Email);
            impressao(pt,ptv->dir,x);
        }
    }
}

AVL *BuscaAVL(AVL* pt, int chave){/*Busca AVL*/
    if(pt!=NULL){
        if(chave<pt->chave){
            BuscaAVL(pt->esq,chave);
        }else if(chave>pt->chave){
            BuscaAVL(pt->dir,chave);
        }else{
            return pt;
        }
    }
    return NULL;
}

Bin *BuscaBin(Bin* pt, int chave){/*Busca BIn*/
    if(pt!=NULL){
        if(chave<pt->chave){
            BuscaBin(pt->esq,chave);
        }else if(chave>pt->chave){
            BuscaBin(pt->dir,chave);
        }else{
            return pt;
        }
    }
    return NULL;
}

int main(){
int x=0,x1=0;
int h=0;/*h=0 FALSO      h=1   VERDADEIRO*/
int chave;
char Nome[50];
char sobrenome[50];
char Telefone[20];
char Email[50];
AVL* pt=NULL;
Bin* ptv=NULL;
Bin* ptaux=NULL;
Bin* ptcopy=NULL;
AVL* aux=NULL;
Bin* auxv=NULL;
FILE *arq;

     do{
        do{
	        printf("\nDigite uma das opcoes abaixo\n1>Arvore AVL\n2>Arvore Binaria\n3>Sair\n>>");
	        scanf("%d",&x);
            if(x<1 || x>3){
                printf("\nOpcao Invalida!!\n");
            }
        }while(x<1 || x>3);
        switch (x){
            case 1:
                inicializaArv(&pt,&h,&ptv,x);
                do{    
                    h=0;
                    do{
	                    printf("\nDigite uma das opcoes abaixo\n1>Busca\n2>Insercao\n3>Imprimir Contatos\n4>Sair\n>>");
	                    scanf("%d",&x1);
                        if(x1<1 || x1>4){
                            printf("\nOpcao Invalida!!\n");
                        }
                    }while(x1<1 || x1>4);
                    switch (x1){
                        case 1:
                            printf("Informe o ID a ser buscado\n");
                            scanf("%d",&chave);
                            aux=BuscaAVL(pt,chave);
                            if(aux!=NULL){
                                printf("Id: %d \nNome:%s %s \nTelefone:%s \nEmail:%s\n",aux->chave,aux->Nome,aux->sobrenome,aux->Telefone,aux->Email);
                            }else{
                                printf("Contato nao encontrado\n");
                            }
                        break;
                        case 2:
                            printf("\nInforme o ID do novo contato\n");
                            scanf("%d",&chave);
                            printf("\nInforme o Nome do novo contato\n");
                            scanf("%s",Nome);
                            printf("\nInforme o Sobrenome do novo contato\n");
                            scanf("%s",sobrenome);
                            printf("\nInforme o Telefone do novo contato\n");
                            scanf("%s",Telefone);
                            printf("\nInforme o Email do novo contato\n");
                            scanf("%s",Email);
                            insercaoAVL(&pt,chave,&h,Nome,sobrenome,Telefone,Email);
                        break;
                        case 3:
                            impressao(pt,ptv,x);
                        break;                        
                        case 4:
                            x1=4;
                            arq=fopen("contatos.txt","w");
                            if(arq!=NULL){
                                grava(pt,ptv,x, &arq);
                            }
                            fclose(arq);
                            desalocando(pt, ptv,x);
                        break;                    
                    }
                }while(x1!=4);
            break;
            case 2:
                inicializaArv(&pt,&h,&ptv,x);
                do{    
                    do{
	                    printf("\nDigite uma das opcoes abaixo\n1>Busca\n2>Insercao\n3>Remocao\n4>Imprimir Contatos\n5>Sair\n>>");
	                    scanf("%d",&x1);
                        if(x1<1 || x1>5){
                            printf("\nOpcao Invalida!!\n");
                        }
                    }while(x1<1 || x1>5);
                    switch (x1){
                        case 1:
                            printf("Informe o ID a ser buscado\n");
                            scanf("%d",&chave);
                            auxv=BuscaBin(ptv,chave);
                            if(auxv!=NULL){
                                printf("Id: %d \nNome:%s %s \nTelefone:%s \nEmail:%s\n",auxv->chave,auxv->Nome,auxv->sobrenome,auxv->Telefone,auxv->Email);
                            }else{
                                printf("Contato nao encontrado\n");
                            }
                        break;
                        case 2:
                            printf("\nInforme o ID do novo contato\n");
                            scanf("%d",&chave);
                            printf("\nInforme o Nome do novo contato\n");
                            scanf("%s",Nome);
                            printf("\nInforme o Sobrenome do novo contato\n");
                            scanf("%s",sobrenome);
                            printf("\nInforme o Telefone do novo contato\n");
                            scanf("%s",Telefone);
                            printf("\nInforme o Email do novo contato\n");
                            scanf("%s",Email);
                            insercao(&ptv,chave,Nome,sobrenome,Telefone,Email);
                        break;
                        case 3:
                            printf("\nInforme a Chave a ser removida\n");
                            scanf("%d",&chave);
                            ptcopy=ptv;
                            ptaux=ptv;
                            busca_remocao(&ptv,chave,&ptaux,ptcopy);
                        break;
                        case 4:
                            impressao(pt,ptv,x);
                        break;       
                        case 5:
                            x1=5;
                            arq=fopen("contatos.txt","w");
                            if(arq!=NULL){
                                grava(pt,ptv,x, &arq);
                            }
                            fclose(arq);
                            desalocando(pt, ptv,x);
                        break;    
                    }
                }while(x1!=5);
            break;
            case 3:
                x=3;
            break;
        }
    }while (x!=3);
    return 0;
}
