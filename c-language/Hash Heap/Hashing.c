#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct ha{
	unsigned chave,prox,ocupado;
}Hash;


void insercao(unsigned x, Hash H[256]){
	unsigned indice=0,i=200,aux=0,aux1=0;

	indice=x%200;/*Função de disperção*/
	if(H[indice].chave!=x){
		if(H[indice].ocupado==0){/*caso nao deu colisao insere*/
			H[indice].ocupado=1;
			H[indice].chave=x;
		}else{
			while(H[i].ocupado!=0 && i<256)/*ocorrei colisao procura espaço vago*/
				i++;
			if(i<=355 && H[i].ocupado==0){/*se encontrou local valido insere*/
				if(H[i].chave!=x){
					if(H[indice].prox==0 && H[indice].chave!=x){/*caso nao tenha nenhum elemento proximo insere*/
						H[indice].prox=i;
						H[i].chave=x;
						H[i].ocupado=1;
						H[i].prox=0;
					}else{
						aux=indice;/*percorre ate achar o ultimo para inserir*/
						while(H[aux].prox!=0){
							aux1=H[aux].prox;
							aux=aux1;
						}
						if(H[i].chave!=x){
							H[aux].prox=i;
							H[i].chave=x;
							H[i].ocupado=1;
							H[i].prox=0;
						}
					}
				}
			}else{
				system("clear");
				printf("Overflow!!\n");
				__fpurge(stdin);
				getchar(); 

			}
		}
	}
	
}

void remocao(unsigned x, Hash H[256]){
	unsigned indice=0, aux=0,aux1=0,i=0,ant=0;
	
	indice=x%200;/*funcao de disperção*/
	if(H[indice].prox==0 && H[indice].chave==x){/*Caso elemento esta na tabela principal e nao tem proximo exclui*/
		H[indice].ocupado=0;
		H[indice].chave=0;
		H[indice].prox=0;
	}else if(H[indice].prox!=0 && H[indice].chave==x){/*caso tenha proximo e somente substitui o proximo no atual*/
		i=H[indice].prox;
		H[indice].ocupado=H[i].ocupado;
		H[indice].chave=H[i].chave;
		H[indice].prox=H[i].prox;
		H[i].ocupado=0;
		H[i].chave=0;
		H[i].prox=0;
	}else{
		aux=indice;
		while(H[aux].prox!=0 && H[aux].chave!=x){/*caso elemento nao esteja na principal percorre proximos ate achar*/
			ant=aux;
			aux1=H[aux].prox;
			aux=aux1;
		}
		if(H[aux].chave==x){/*caso achou elementos substitui*/
			H[ant].prox=H[aux].prox;
			H[aux].prox=0;
			H[aux].ocupado=0;
			H[aux].chave=0;
		}else{
			system("clear");
			printf("Valor Nao encontrado");
			__fpurge(stdin);
			getchar(); 
		}
	}
}

void busca(unsigned x, Hash H[256]){
	unsigned aux1=0,aux=0;
	aux=x%200;/*Função de disperção*/
	while(H[aux].prox!=0 && H[aux].chave!=x){/*percorre ate achar elemento ou chegar ao final*/
		aux1=H[aux].prox;
		aux=aux1;
	}
	if(H[aux].chave==x){
			system("clear");
			printf("ID:%d Chave: %d Ocupado: %d Prox: %d\n",aux,H[aux].chave, H[aux].ocupado, H[aux].prox);
			__fpurge(stdin);
			getchar(); 
	}else{
		system("clear");
		printf("Valor Nao encontrado");
		__fpurge(stdin);
		getchar(); 
	}
}

void impressao(Hash H[256]){
	unsigned i=0,aux1=0,aux=0;
	system("clear");
	while(i<256){
		if(H[i].ocupado==1){
			printf("ID:%d Chave: %d Ocupado: %d Prox: %d\n",i,H[i].chave, H[i].ocupado, H[i].prox);
			if(H[i].prox!=0){
				aux=i;
				while(H[aux].prox!=0){
					aux1=H[aux].prox;
					aux=aux1;
					printf("ID:%d Chave: %d Ocupado: %d Prox: %d\n",aux,H[aux].chave, H[aux].ocupado, H[aux].prox);
				}
			}
		}
		i++;
	}	
	__fpurge(stdin);
	getchar(); 	

}

int main(){
	int menu=0;
	Hash H[256];
	unsigned i=0,n=0;
	int x=0;
	FILE *arq=NULL;
	char nome[100];

	bzero(H,sizeof(H));
	do{
		system("clear");
		printf("Hashing\n\n 0>Inserir pelo arquivo\n 1>Insercao\n 2>Remoção\n 3>Imprimir\n 4>Busca\n 5>Sair\n>>>");
		scanf("%d",&menu);

		switch(menu){
		
		case 0:
			system("clear");
			printf("\nInforme o nome do arquivo\n");
			scanf("%s",nome);
			arq=fopen(nome,"rb");
			if(arq!=NULL){
				fscanf(arq,"%d",&x);
				n=x;
				i=0;
				while(i<n){
					fscanf(arq,"%d",&x);
					insercao(x,H);
					i++;
				}
				fclose(arq);
			}else{
				system("clear");
				printf("\nErro ao abrir o arquivo\n");
				__fpurge(stdin);
				getchar(); 
			}
		break;
		case 1:
			system("clear");
			printf("\nInforme o Valor a ser inserido\n");
			scanf("%d",&x);
			insercao(x,H);
		break;
		case 2:
			system("clear");
			printf("\nInforme a chave a ser removida\n");
			scanf("%d",&x);
			remocao(x,H);
		break;
		case 3:
			impressao(H);
		break;
		case 4:
			system("clear");
			printf("\nInforme o Valor a ser buscado\n");
			scanf("%d",&x);
			busca(x,H);
		break;


		}

	}while(menu!=5);

	return 0;
}
