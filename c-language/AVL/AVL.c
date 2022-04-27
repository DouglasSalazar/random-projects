#include "gfx.h"
#include <stdio.h>  
#include <unistd.h>
#include <stdlib.h> 
 
typedef struct s_AVL{
	int chave:28;
	int bal:4;
	struct s_AVL* esq;
	struct s_AVL* dir;
}AVL;

void ocupa(AVL** pt,int x,int* h){
	AVL* AVLvo = malloc(sizeof(AVL));
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
*h=1;
	return (pt);
}

/*insercao*/
void insercao (AVL** pt,int x,int* h){
	if (*pt == NULL){
		ocupa(&*pt,x,&*h);
	}else if(x != ((*pt)->chave)){
			if(x < ((*pt)->chave)){
				insercao(&(*pt)->esq,x,&*h);
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
				insercao(&(*pt)->dir,x,&*h);		
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


void coleta_dados(AVL** pt){
int x=0;
int h=0;/*h=0 FALSO      h=1   VERDADEIRO*/
	printf("\nInforme o Chave da sua alocacao\n");
	scanf("%d",&x);
	insercao(&*pt,x,&h);
}
void line(int x1,int y1,int x2,int y2){
	gfx_line(x1,y1,x2,y2);
}

/*Balanço para direita da remocao*/
AVL * baldir ( AVL* pt, int *h ){
	AVL* ptu;
	AVL* ptv;

    switch ( pt->bal ){
        case -1:
            pt->bal = 0 ;
            break;
	case 0:
            pt->bal = 1 ;
            *h  = 0;
	    break;
	case 1:
            ptu = pt->dir ;
            if ( ptu->bal >= 0 ){
            	pt->dir = ptu->esq ;
                ptu->esq = pt ;
                if ( ptu->bal == 0 ){
                    pt->bal = 1 ;
                    ptu->bal = -1 ;
                }else{
                    pt->bal = 0;
		    ptu->bal = 0 ;
                }
                pt = ptu ;
            }else{
                ptv = ptu->esq ;
                ptu->esq = ptv->dir ;
                ptv->dir = ptu ;
                pt->dir = ptv->esq ;
                ptv->esq = pt ;

                if ( ptv->bal == 1 ){
                    pt->bal = -1 ;
                }else{
                    pt->bal = 0 ;
		}
		if ( ptv->bal == -1 ){
                    ptu->bal = 1 ;
		}else{
                    ptu->bal = 0 ;
		}
		pt = ptv ;
                ptv->bal = 0 ;
            }
	    break;
    }
    return ( pt ) ;
}

/* Balanço para a esquerda da remocao */
AVL* balesq ( AVL * pt, int *h ){
	 AVL* ptu;
	 AVL* ptv;

    switch ( pt->bal ){
        case 1:
            pt->bal = 0 ;
            break ;

        case 0:
            pt->bal = -1 ;
            *h = 0 ;
            break ;

        case -1:
            ptu = pt->esq ;
            if ( ptu->bal <= 0 ){
                pt->esq = ptu->dir ;
                ptu->dir = pt ;
                if ( ptu->bal == 0 ){
                    pt->bal = -1 ;
                    ptu->bal = 1 ;
                    *h = 0 ;
                }else{
                    pt->bal = ptu->bal = 0 ;
                }
                pt = ptu ;
            }else{
                ptv = ptu->dir ;
                ptu->dir = ptv->esq ;
                ptv->esq = ptu ;
                pt->esq = ptv->dir ;
                ptv->dir = pt ;

                if ( ptv->bal == -1 ){
                    pt->bal = 1 ;
               	}else{
                    pt->bal = 0 ;
		}
		if ( ptv->bal == 1 ){
                    ptu->bal = -1 ;
                }else{
                    ptu->bal = 0 ;
		}
		pt = ptv ;
                ptv->bal = 0 ;
            }
	    break;
    }
    return ( pt ) ;
}


/*funcao auxiliar para pai*/
AVL* del ( AVL* prox, AVL* pai, int *h ){
	AVL* temp = prox ;
	if ( prox->esq != NULL ){
	    	prox->esq = del ( prox->esq,pai,h) ;
	    	if (*h == 1){
		    prox = baldir ( prox, h ) ;
		}
	}else{
		temp = prox ;
		pai->chave = prox->chave ;
		prox = prox->dir;
		free (temp) ;
		*h = 1;
    	}
    return ( prox ) ;
}
/*remocao de no*/
AVL * exclui ( AVL * pt, int chave, int *h ){
    AVL * pai ;

    if ( pt == NULL ){
        printf ( "\nArvore vazia ou AVL nao encontrado.") ;
        return ( pt ) ;
    }else{
        if ( chave < pt->chave){
        	pt->esq = exclui ( pt->esq,chave, h) ;
        	if (*h){
                	pt = baldir (pt,h) ;
		}
	}else{
		if ( chave > pt->chave ){
		       	pt ->dir = exclui ( pt->dir,chave, h) ;
			if (*h){
			    pt = balesq (pt,h) ;
			}
		}else{
		       	pai = pt ;
		       	if ( pai->dir == NULL ){
		        	pt = pai->esq;
		            	*h = 1 ;
		           	free (pai) ;
		        }else{
		            	if (pai->esq == NULL ){
		                	pt = pai->dir ;
		                	*h = 1 ;
		                	free (pai) ;
		            	}else{
		                	pai->dir = del ( pai->dir,pai, h) ;
				        if ( *h){
				               	pt = balesq (pt, h) ;
				       }
				}
		        }
		 }
       	}
    }
   return (pt) ;
}

/*impressao arvore pre ordem*/
void imprimi(AVL* pt,int x1,int x2 ,int y1){
char A [6];	
int altura=0,largura=0;

	printf("%d ",pt->chave);	
	gfx_set_color(0, 255, 0);
	sprintf(A,"%d",pt->chave);	
	gfx_filled_rectangle(((x1+x2)/2)-20, y1, ((x1+x2)/2)+20, y1+20);
	gfx_set_color(0, 0, 255);
	/*pegar tamanho da chave*/	
	gfx_get_text_size(A,&largura,&altura);	
	/*imprimindo texto*/	
	gfx_text(((x1+x2)/2)-(largura/2), y1,A);	
	if (pt->esq!=NULL){
		if(pt->esq!=NULL){	
			line(((x1+x2)/2),y1+20,(x1+((x1+x2)/2))/2,y1+50);
		}
		imprimi(pt->esq,x1,(x1+x2)/2,y1+50);
	}
	if (pt->dir!=NULL){	
		if(pt->dir!=NULL){		
			line(((x1+x2)/2),y1+20,(x2+((x1+x2)/2))/2,y1+50);
		}
		imprimi(pt->dir,(x1+x2)/2,x2,y1+50);
	}
	gfx_paint();
}
/*gravação em arquivo*/
void grava_AVL(FILE *ArvoreAvl, AVL *pt,AVL *opc){	
	fwrite(&opc, sizeof(AVL),1,ArvoreAvl);
	if (pt->esq!=NULL){
		grava_AVL(ArvoreAvl,pt->esq,opc);
	}
	if (pt->dir!=NULL){			
		grava_AVL(ArvoreAvl,pt->dir,opc);
	}
}

void leitura_arquivo(AVL *opc,AVL **pt){
		if(opc->chave < (*pt)->chave){
			if((*pt)->esq!=NULL){
				leitura_arquivo(opc,&(*pt)->esq);
			}else{
				(*pt)->esq=opc;
			}
		}	
		if(opc-> chave > (*pt)->chave){
			if((*pt)->dir!=NULL){
				leitura_arquivo(opc,&(*pt)->dir);
			}else{
				(*pt)->dir=opc;
			}
		}

}

int main(){
AVL* arvore=NULL;
AVL* pt=NULL;
AVL* opc=NULL;
FILE *ArvoreAvl;
int x=0,x1=0,y1=50, x2=1300, chav=0,h=0;

	do{
		printf("\n1> Cadastrar NO\n2> Remover NO \n3> Guardar AVL em arquivo\n4> Ler AVL do arquivo\n5> Sair\n");
		scanf("%d",&x);	
		switch (x){	
			case 1:	
				pt=arvore;	
				coleta_dados(&pt);
				arvore=pt;
				gfx_init(1300, 700, "Árvore AVL");	
				gfx_set_color(255, 255, 255);				
				gfx_filled_rectangle(0, 0, 1300, 700);			
				gfx_set_font_size(30);	
				gfx_set_color(255, 0, 0);			
				gfx_text(580, 10, " Arvore AVL " );				
				gfx_set_font_size(15);				
				imprimi(pt,x1,x2,y1);
			break;	
			case 2:
				h=0;				
				pt=arvore;
				printf("\nInforme a chave a ser removida\n\n");			
				scanf("%d",&chav);
				if(pt!=NULL && pt->esq == NULL && pt->dir == NULL){
					if(pt->chave == chav)
						arvore=NULL;	
						pt=NULL;			
				}else{
						arvore=exclui(pt,chav,&h);
				}
				gfx_init(1300, 700, "Árvore AVL");	
				gfx_set_color(255, 255, 255);				
				gfx_filled_rectangle(0, 0, 1300, 700);			
				gfx_set_font_size(30);	
				gfx_set_color(255, 0, 0);			
				gfx_text(580, 10, " Arvore AVL ");				
				gfx_set_font_size(15);				
				gfx_paint();
				if(pt!=NULL){
					imprimi(pt,x1,x2,y1);		
				}			
				break;
			case 3:
				pt=arvore;
				ArvoreAvl=fopen("ArvoreAvl","wb");
				if(ArvoreAvl == NULL){
					printf("\nErro ao abrir o arquivo\n");
				}else{
					grava_AVL(ArvoreAvl, pt, opc);
				}
				if(fclose(ArvoreAvl)== EOF){
					printf("\nERRO AO FECHAR O ARQUIVO!\n");
				}
			break;		
			case 4:
				if((ArvoreAvl = fopen("ArvoreAvl","wb"))== NULL){
        					printf("\nERRO AO ABRIR O ARQUIVO!\n");
        			}else{
					fseek(ArvoreAvl,0,SEEK_SET);
					do{	
						fread((&opc),sizeof(AVL),1,ArvoreAvl);
						if (pt==NULL){
							pt=opc;
						}else{
							leitura_arquivo(opc,&pt);
						}			
							
					}while(!feof(ArvoreAvl));				
				}				
				if(fclose(ArvoreAvl)== EOF){
					printf("\nERRO AO FECHAR O ARQUIVO!\n");
				}				
				gfx_init(1300, 700, "Árvore AVL");	
				gfx_set_color(255, 255, 255);				
				gfx_filled_rectangle(0, 0, 1300, 700);			
				gfx_set_font_size(30);	
				gfx_set_color(255, 0, 0);			
				gfx_text(580, 10, " Arvore AVL ");				
				gfx_set_font_size(15);				
				imprimi(pt,x1,x2,y1);			
				arvore=pt;				
			break;
		}
	}while(x!=5);

	return 0;
}
