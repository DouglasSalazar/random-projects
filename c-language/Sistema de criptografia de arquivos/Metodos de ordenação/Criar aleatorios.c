#include <stdio.h>
#include <stdlib.h>

int main(){
FILE* arq;
FILE* arq1;
FILE* arq2;
int i=0,aux=0,j=500000000;
    arq = fopen("500000000aleatorio.txt", "wt");
    srand( time(NULL) );
    for(i=0;i<500000000;i++){
        aux= rand() %5000000000;
        fprintf(arq,"%d ",aux);
    }
    fclose(arq);
    arq1 = fopen("500000000crescente.txt", "wt");
    for(i=0;i<500000000;i++){
        fprintf(arq1,"%d ",i+1);
    }
    fclose(arq1);
    arq2 = fopen("500000000decrecente.txt", "wt");
    for(i=0;i<500000000;i++){
        fprintf(arq2,"%d ",j);
        j--;
    }
    fclose(arq2);
    return 0;
}
