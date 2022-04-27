#include <stdio.h>
#include <stdlib.h>


void transicao(int transicao_afn[20][20][20],int tabela[20][20],int aux_tab[20],int alfabeto_afn,int *a,int b){
int i,j,x=0,y=0,k=0;
int aux[20];


    for(j=0;j<=alfabeto_afn;j++){
        while(transicao_afn[tabela[*a][b]][j][x]>0){
            aux[x]=transicao_afn[tabela[*a][b]][j][x];
            x=x+1;
        }
    }
    for(i=0;i<=*a;i++){
      y=0;
      for(j=0;j<=aux_tab[i];j++){
            if(tabela[i][j]==aux[j]){
               y++;
            }
        }
        if(aux_tab[i]!=0){
            if(x==y && y==aux_tab[i]){
                y=-1;
            }
        }
    }
    if(y!=-1){
        *a=*a+1;
        for(i=0;i<x;i++){
            tabela[*a][i]=aux[i];
        }
    }
}

int main(){
    int transicao_afn[20][20][20];
    int estados_afn;
    int alfabeto_afn;
    int estado_Final_afn[20];
    int estados_Inical_afn;

    int transicao_afd[20][20][20];
    int estados_afd [20];
    int alfabeto_afd[20];
    int estado_Final_afd[20];
    int estados_Inical_afd;

    int tabela[20][20];
    int aux_tab[20];
    int aux[20];

    int i=0,j=0,k=0,a=-1,b=0;


    for(i=0;i<20;i++){
         for(k=0;k<20;k++){
                tabela[i][k]=-1;
                for(k=0;k<20;k++){
                    transicao_afn[i][j][k]= -1;
                }
        }
    }
    transicao_afn[0][1][0]=1;
    transicao_afn[0][2][0]=2;
    transicao_afn[0][3][0]=3;
    transicao_afn[1][0][0]=1;
    transicao_afn[2][0][0]=2;
    transicao_afn[1][1][0]=1;
    transicao_afn[1][1][1]=2;
    transicao_afn[1][2][0]=2;
    transicao_afn[2][2][0]=1;

    estados_afn=2;
    alfabeto_afn=2;

    if(transicao_afn[1][0][1]<0){
        tabela[0][0]=transicao_afn[1][0][0];
        aux_tab[0]=aux_tab[0]+1;
        while(transicao_afn[1][alfabeto_afn][i]>0){
            i++;
            tabela[0][i]=transicao_afn[1][alfabeto_afn][i-1];
            aux_tab[0]=aux_tab[0]+1;
        }
        a=a+1;
    }
    for(j=0;j<=3;j++){
        for(i=0;i<=aux_tab[j];i++){
            b=tabela[a][i];
            transicao(transicao_afn,tabela,aux_tab,alfabeto_afn,&a,b);
        }
    }
    return 0;
}
