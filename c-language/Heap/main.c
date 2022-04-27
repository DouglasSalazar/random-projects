#include <stdio.h>
#include <stdlib.h>

typedef struct hp{
    int chave;
}Heap;

void subir(int i,Heap T[200]){
int j=0;
Heap aux;

    j=i/2;
    if(j>=0){
        if(T[i].chave>T[j].chave){
            aux=T[i];
            T[i]=T[j];
            T[j]=aux;
            subir(j,T);
        }
    }
}

void descer(int i,int n,Heap T[200]){
int j=0;
Heap aux;

    j=2*i;
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

void Insecao(int *n,int M,Heap novo,Heap T[200]){
    if(*n<M){
        T[*n+1]=novo;
        *n=*n+1;
        subir(*n,T);
    }else{
        system("cls");
        printf("\nOverflow\n");
        system("pause");
    }
}

void remocao(int *n,Heap T[200]){
    if(*n!=0){
        system("cls");
        printf("\nChave a ser Removida:  %d\n\n",T[0].chave);
        system("pause");
        T[0]=T[*n];
        *n=*n-1;
        descer(0,*n,T);
    }else{
        system("cls");
        printf("\nUnderflow\n");
        system("pause");
    }
}

void construir(int n,Heap T[200]){
int i=0;
    for(i=2;i<n;i++){
        subir(i,T);
    }
}

void arranjar(int n,Heap T[200]){
int i=0;

    for(i=n/2;i>0;i=i-1){
        descer(i,n,T);
    }
}

void ordena(int n,Heap T[200]){
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
    Heap T[200];
    Heap novo;
    int M=200,n=0,menu=0,aux=0,aux1=0,ord=0;

    do{
        system("cls");
        printf("    Heap\n\n 1>Insercao de Heap\n 2>Remocao\n 3>Ordenacao\n 4>Construcao de Heap\n 5>Heap Aleatorio\n 6>Imprimir\n 7>Sair\n\n>>>");
        scanf("%d",&menu);
        switch(menu){
        case 1:
            do{
                system("cls");
                printf("\nZero para sair\nInfome as chaves do Heap: ");
                scanf("%d",&aux1);
                if(aux1>0){
                    novo.chave=aux1;
                    Insecao(&n,M,novo,T);
                }
            }while(aux1!=0);
        break;
        case 2:
            remocao(&n,T);
        break;
        case 3:
            if(ord!=0){
                ordena(n,T);
                ord=0;
            }else{
                system("cls");
                printf("\nHeap ja esta ordenado\n");
                system("pause");
            }
        break;
        case 4:
            if(ord!=1){
                construir(n,T);
                ord=1;
            }else{
                system("cls");
                printf("\nHeap ja esta construido\n");
                system("pause");
            }
        break;
        case 5:
            aux1=0;
            do{
                aux=rand();
                if(aux > 0 && aux < 100){
                    novo.chave=aux;
                    Insecao(&n,M,novo,T);
                    aux1++;
                }
            }while(aux1!=6);
        break;
        case 6:
            system("cls");
            for(aux1=0;aux1<n;aux1++){
                printf("| %d ",T[aux1].chave);
            }
            printf("\n");
            system("pause");
        break;
        }

    }while(menu!=7);

    return 0;
}
