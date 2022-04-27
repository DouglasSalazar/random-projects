/*1. Implemente um programa que receba uma frase e calcule e
mostre a quantidade de vogais da frase. A contagem deve
diferenciar vogais maiúsculas de minúsculas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int l=0,j=0,i2,i,cont;
    char frase[1000];
    printf("Contando as vogais de uma frase!\n\n");
    printf("Entre com a frase desejada\n");
    scanf("%1000[^\n]",frase);
    j=strlen(frase);
    for(i=0;i<=j;i++)
    {
    cont=0;
    l=frase[i];
        i2=i;
        while (i2<=j){
            if (l==frase[i2+1]&&frase[i2+1]!=' '){
                cont++;
            }
        i2++;
        }
    cont++;
    printf("\n\nHa %d letras %c na frase [%s]",cont,frase[i],frase);
    }
    return(0);
    system("pause");
}

