/*3. Implemente um programa que receba uma frase e calcule e
mostre a quantidade de palavras existentes.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int j=0,i=0,cont=0,cont2=0;
    char frase[1000];
    printf("Contando as palavras de uma frase!\n\n");
    printf("Entre com a frase desejada\n");
    scanf("%999[^\n]",frase);
    j=strlen(frase);
    while(frase[i]!='\0')
    {
        if(frase[i]==' '&& frase[i+1]!= '\0' && frase [i+1]!= ' ')
        {
            cont++;
        }
    i++;
    }
    cont++;
    if(frase[0]==' '){
        cont--;
    }
    printf("\n\nHa %d palavras na frase [%s]",cont,frase);
    return(0);
    system("pause");
}
