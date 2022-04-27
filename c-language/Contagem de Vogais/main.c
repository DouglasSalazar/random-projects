/*1. Implemente um programa que receba uma frase e calcule e
mostre a quantidade de vogais da frase. A contagem deve
diferenciar vogais maiúsculas de minúsculas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int j,i,cont=0,cont2=0;
    char frase[1000];
    printf("Contando as vogais de uma frase!\n\n");
    printf("Entre com a frase desejada\n");
    scanf("%999[^\n]",frase);
    j=strlen(frase);
    for(i=0;i<=j;i++)
    {
        if(frase[i]=='a' || frase[i]=='e' || frase[i]=='i' || frase[i]=='o' || frase[i]=='u')
        {
            cont++;
        }
        if(frase[i]=='A' || frase[i]=='E' || frase[i]=='I' || frase[i]=='O' || frase[i]=='U')
        {
            cont2++;
        }
    }
    printf("\n\nHa %d vogais Maiusculas e Ha %d vogais Minusculas na frase [%s]",cont2,cont,frase);
    return(0);
    system("pause");
}
