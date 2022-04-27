
//Bibliotecas utilizadas
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//Declaraçao de registro
struct lista { struct lista *prox;
					char vert;
             };


//Funcao que realiza a leitura do arquivo
void leitura (lista *&VT, lista *PT, lista *ANT, int &N){
	//Declaraçao de prototipo
	void monta_lista(char v1, char v2, lista *VT, lista *PT, lista *ANT);

	//Declaracao de variaveis
	int i = 0,h = 0,cond = 1,cont = 0;
	char *pont,nome[30],caracter,v1,v2;

	FILE *arquivo;//Declaraçao de ponteiro p/ o arquivo

   //Alcaçao de memoria
	pont = new char [5];

	cout<<"Informe o nome do arquivo : ";
	gets(nome);

	//Abertura do arquivo
	if((arquivo = fopen(nome,"r")) == NULL)
	{
		cout<<"ERRO NA ABERTURA DO ARQUIVO!!! ";
 		exit(0);
	}

   //Percorre todo o arquivo lendo caracter por caracter
	while((caracter = getc(arquivo))!= EOF)
	{
   	//Condicao p/ descartar os caracteres antes do sinal de igual
		if(((caracter == '=') && (cond > 0)) || ((caracter == '\n') && (cond < 0)))
			cond *= -1;
		else
		{
			if(cond < 0)//Verifica se o caracter vem depois do sinal de igual
			{
         	//Realiza a leitura do numero de vertices
				if(isdigit(caracter))//Verifica se o caracter eh um numero
				{
					pont[i++] = caracter;

					//Laço p/ ler o numero caso tiver mais de um caracter
					while(isdigit(caracter = getc(arquivo)))
						pont[i++] = caracter;

					if(i > 1)
                        fseek(arquivo, -1, 1);

					pont[i] = '\0';
					N = atoi(pont);//Transforma os caracteres em um valor inteiro

					delete(pont);//Desaloca memoria

					VT = new lista[N];//Aloca memoria p/ o vetor de no cabeças
				}
				else
				{
					//Realiza a leitura do conjunto de vertices
					if((isalpha(caracter)) && (h < N))
					{
						VT[h].vert = caracter;
						VT[h++].prox = NULL;
					}
					else
					{
						//Realiza a leitura dos pares de vertices
						if(isalpha(caracter))//Verifica se o caracter e uma letra
						{
							cont++;
							if(cont == 2)//Condicao p/ ler o par vertices
							{
								v1 = v2;
								v2 = caracter;
								monta_lista(v1, v2, VT, PT, ANT);//Chamada da funcao
								cont = 0;
							}
							else
								v2 = caracter;
						}
					}
				}
			}
		}
	}
	fclose(arquivo);//Fecha o arquivo
}

//Funçao para montar a lista
void monta_lista(char v1, char v2, lista *VT, lista *PT, lista *ANT){
	//Declaracao de variaveis
	int i, cont = 0, cond = 0;
	char aux;

	do
	{
		//Percorre o vetor de vetices ate encontrar o vertice correspondente
		for(i = 0; VT[i].vert != v1; i++);

		//Condicao p/ montar a lista
		if(VT[i].prox != NULL)
		{
			ANT = VT[i].prox;
			//Percorre a lista ate o fim ou ate encontar um vertice repetido
			while((ANT->prox != NULL) && (cond == 0))
			{
				ANT = ANT->prox;

				if(ANT->vert == v2)
					cond = 1;

			}
			//Se nao houver vertice repetido, entao um novo no e inserido na lista
			if((ANT->vert != v2) && (cond == 0))
			{
				PT = new lista; //Alocando memoria p/ os nos
				PT->prox = ANT->prox;
				ANT->prox = PT;
				PT->vert = v2;
			}
		}
		else
		{
			PT = new lista; //Alocando memoria p/ os nos
			PT->prox = VT[i].prox;
			VT[i].prox = PT;
			PT->vert = v2;
		}

      //Inverte os vetices
		aux = v1;
		v1 = v2;
		v2 = aux;
	 //Realiza a simetria repetindo a mesma operacao caso os vertices sejam diferentes
	}while((++cont < 2) && ( v1 != v2) && (cond == 0));

}

int busca_prof(char * Visitado, int *pnum,int v,int *prenum, lista *V,lista *VT){
int i=0;
    if(V!=NULL){
        Visitado[v]='V';
        *pnum +=1;
        prenum[v]=*pnum;
        while(V != NULL){
                i=0;
                while(V->vert != VT[i].vert){
                    i++;
                }
                if(Visitado[i]!='V'){
                    busca_prof(Visitado,*&pnum,i,prenum,VT[i].prox,VT);
                    return 0;
                }else{
                    V=V->prox;
                }
        }
    }else{
        return 0;
    }
}

void busca (lista *VT, int N){
char *Visitado=NULL;
int *prenum=NULL;
int pnum = 0;
int i=0;
    Visitado=(char*)malloc(N*sizeof(char));
    prenum =(int*)malloc(N*sizeof(int));

    for(i=0;i<N;i++){
        Visitado[i]='F';
    }
    for(i=0;i<N;i++){
        if(Visitado[i]=='F'){
            busca_prof(Visitado,&pnum,i,prenum,VT[i].prox,VT);
        }
    }
    for(i=0;i<N;i++){
        printf("VT[%c] = %c Prenum[%d] = %d\n",VT[i].vert,Visitado[i],i,prenum[i]);
    }
    printf("Pnum = %d\n",pnum);
    delete(Visitado);
    delete(prenum);
}

//Programa principal
int main ()
{
	//Declaracao de ponteiros
	struct lista *VT,*PT,*ANT;

	//Declaracao de variavel
	int N;//Quantidade de vertices

	//Chamada das funçoes
	leitura (VT, PT, ANT, N);
	busca(VT,N);

	delete(VT);//Desaloca memoria

	return 0;

}
