#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio_ext.h>

typedef struct hp{
    int chave;
}Heap;

void subir(int i,Heap T[1000]){/*subir no algoritmo*/
int j=0;
Heap aux;
    if(i%2==0){
	    j=(i/2)-1;
    }else{
	    j=i/2;
    }
    if(j>=0){
        if(T[i].chave>T[j].chave){
            aux=T[i];
            T[i]=T[j];
            T[j]=aux;
            subir(j,T);
        }
    }
}

void descer(int i,int n,Heap T[1000]){/*descer no heap*/
int j=0;
Heap aux;

    j=(2*i)+1;
    if(j<=n){
        if(j<n){
            if(T[j+1].chave > T[j].chave){
                j=j+1;
            }
        }
        if(T[i].chave < T[j].chave){
            aux=T[i];
            T[i]=T[j];
            T[j]=aux;
            descer(j,n,T);
        }
    }


}

void Insecao(int *n,int M,Heap novo,Heap T[1000]){
    if(*n<M){/*inserçao*/
        T[*n+1]=novo;
        *n=*n+1;
        subir(*n,T);
    }else{
        system("clear");  
        printf("\nOverflow\n");
	__fpurge(stdin);
	getchar();         
    }
}

void remocao(int *n,Heap T[1000]){/*remoção heap*/
    if(*n>=0){
        system("clear");
        printf("\nChave a ser Removida:  %d\n\n",T[0].chave);
	if(*n>0){	  
		T[0]=T[*n];
		*n=*n-1;
		descer(0,*n,T);
	}else{/*somente 1 elemento remove*/
		*n=*n-1;
	}	
	__fpurge(stdin);
	getchar();
    }else{
	system("clear");          
        printf("\nUnderflow\n");
	__fpurge(stdin);
	getchar();	 
    }
}
void construir(int n,Heap T[1000]){
int i=0;
    for(i=1;i<=n;i++){
        subir(i,T);
    }
}

void arranjar(int n,Heap T[1000]){/*arranjar para construir*/
int i=0;

    for(i=n/2;i>=0;i=i-1){
        descer(i,n,T);
    }
}

void ordena(int n,Heap T[1000]){/*ordenacao heap*/
int m=0;
Heap aux;

    m=n;
    while(m>0){
        aux=T[0];
        T[0]=T[m];
        T[m]=aux;
        m=m-1;
        descer(0,m,T);
    }
}

int main(){
    Heap T[1000];
    Heap novo;
    FILE *arq=NULL;
    char nome[20];
    int M=1000,n=-1,menu=0,aux=0,aux1=0,ord=0,i=0;

    do{
        system("clear");
        printf("    Heap\n\n 0>Insercao atraves de arquivo\n 1>Insercao de Heap\n 2>Remocao\n 3>Ordenacao\n 4>Construcao de Heap\n 5>Heap Aleatorio\n 6>Imprimir\n 7>Sair\n\n>>>");
        scanf("%d",&menu);
        switch(menu){
	case 0:
		system("clear");
		printf("Informe o nome do arquivo\n");
		scanf("%s",nome);
		arq=fopen(nome,"rb");
		if(arq!=NULL){
			fscanf(arq,"%d",&aux);
			i=0;
			while(fscanf(arq,"%d",&aux1)!=0 && i<aux){
				if(aux1>=0){
					novo.chave=aux1;
					Insecao(&n,M,novo,T);
				}				
				i++;
			}
			fclose(arq);
		}else{
			system("clear");
			printf("Erro ao abrir o arquivo\n");
			__fpurge(stdin);
			getchar();	
		}
	break;
        case 1:
		system("clear");                
	   	i=0;
		do{
			system("clear");
			printf("\nInfome as chaves do Heap: ");
			scanf("%d",&aux1);
			if(aux1>=0){
			    novo.chave=aux1;
			    Insecao(&n,M,novo,T);
			}
			ord=1;
			i++;
		}while(aux1>=0);
        break;
        case 2:
            remocao(&n,T);
        break;
        case 3:
            if(ord!=0){
                ordena(n,T);
                ord=0;
            }else{
                system("clear");  
                printf("\nHeap ja esta ordenado\n");
		__fpurge(stdin);
		getchar();
            }
        break;
        case 4:
            if(ord!=1){
                arranjar(n,T);
                ord=1;
            }else{
                system("clear");
                printf("\nHeap ja esta construido\n");
		__fpurge(stdin);
		getchar();
            }
        break;
        case 5:
            aux1=0;
            srand(time(NULL));
            do{
		aux=rand()%100;
		novo.chave=aux;
		Insecao(&n,M,novo,T);
		aux1++;
            }while(aux1!=6);
	    ord=1;
        break;
        case 6:
	    system("clear");
            for(aux1=0;aux1<=n;aux1++){
                printf("| %d ",T[aux1].chave);
            }
            printf("|\n");
	    __fpurge(stdin);
	    getchar(); 
        break;
        }

    }while(menu!=7);

    return 0;
}
