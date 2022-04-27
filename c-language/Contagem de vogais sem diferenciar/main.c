/*2. Implemente um programa que receba uma frase e calcule e
mostre a quantidade de vogais da frase. A contagem não deve
diferenciar vogais maiúsculas de minúsculas.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int j,i,cont=0;
    char frase[1000];
    printf("Contando as vogais de uma frase!\n\n");
    printf("Entre com a frase desejada\n");
    scanf("%999[^\n]",frase);
    j=strlen(frase);
    for(i=0;i<=j;i++)
    {
        if(frase[i]=='a' || frase[i]=='e' || frase[i]=='i' || frase[i]=='o' || frase[i]=='u' || frase[i]=='A' || frase[i]=='E' || frase[i]=='I' || frase[i]=='O' || frase[i]=='U')
        {
            cont++;
        }
    }
    printf("\n\nHa %d Vogais na frase [%s]\n",cont,frase);
    return(0);
    system("pause");
}
