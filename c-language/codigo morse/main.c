/*10. O código Morse codifica uma mensagem em pontos e traços.
Implemente um programa que receba uma mensagem e
mostre em código Morse.*/

//Douglas Correia Salazar RGM: 
//Renan Augusto RGM 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char mensagem[1000];
    int i=0,j=0;
    //ENTRADA DE DADOS
    printf("Codifica uma mensagem para codigo morse!\n\n");
    printf("Informe a mensagem a ser codificada!\n\n");
    scanf("%998[^\n]",mensagem);
    j=strlen(mensagem);
    printf("A mensagem codificada e:\n\n");
    //VERIFICACAO DE LETRA PARA SER IMPRESSO O CODIGO MORDSE
    while(mensagem[i]!='\0')
    {
        if (mensagem[i]=='A'||mensagem[i]=='a')
        {
            printf(".- ");
        }
        if (mensagem[i]=='B'||mensagem[i]=='b')
        {
            printf("-... ");
        }
        if (mensagem[i]=='C'||mensagem[i]=='c')
        {
            printf("-.-. ");
        }
        if (mensagem[i]=='D'||mensagem[i]=='d')
        {
            printf("-.. ");
        }
        if (mensagem[i]=='E'||mensagem[i]=='e')
        {
            printf(". ");
        }
        if (mensagem[i]=='F'||mensagem[i]=='f')
        {
            printf("..-. ");
        }
        if (mensagem[i]=='G'||mensagem[i]=='g')
        {
            printf("--. ");
        }
        if (mensagem[i]=='H'||mensagem[i]=='h')
        {
            printf(".... ");
        }
        if (mensagem[i]=='I'||mensagem[i]=='i')
        {
            printf(".. ");
        }
        if (mensagem[i]=='J'||mensagem[i]=='j')
        {
            printf(".--- ");
        }
        if (mensagem[i]=='K'||mensagem[i]=='k')
        {
            printf("-.- ");
        }
        if (mensagem[i]=='L'||mensagem[i]=='l')
        {
            printf(".-.. ");
        }
        if (mensagem[i]=='M'||mensagem[i]=='m')
        {
            printf("-- ");
        }
        if (mensagem[i]=='N'||mensagem[i]=='n')
        {
            printf("-. ");
        }
        if (mensagem[i]=='O'||mensagem[i]=='o')
        {
            printf("--- ");
        }
        if (mensagem[i]=='P'||mensagem[i]=='p')
        {
            printf(".--. ");
        }
        if (mensagem[i]=='Q'||mensagem[i]=='q')
        {
            printf("--.- ");
        }
        if (mensagem[i]=='R'||mensagem[i]=='r')
        {
            printf(".-. ");
        }
        if (mensagem[i]=='S'||mensagem[i]=='s')
        {
            printf("... ");
        }
        if (mensagem[i]=='T'||mensagem[i]=='t')
        {
            printf("- ");
        }
        if (mensagem[i]=='U'||mensagem[i]=='u')
        {
            printf("..- ");
        }
        if (mensagem[i]=='V'||mensagem[i]=='v')
        {
            printf("...- ");
        }
        if (mensagem[i]=='W'||mensagem[i]=='w')
        {
            printf(".-- ");
        }
        if (mensagem[i]=='X'||mensagem[i]=='x')
        {
            printf("-..- ");
        }
        if (mensagem[i]=='Y'||mensagem[i]=='y')
        {
            printf("-.-- ");
        }
        if (mensagem[i]=='Z'||mensagem[i]=='z')
        {
            printf("--.. ");
        }
        if (mensagem[i]=='1')
        {
            printf(".---- ");
        }
        if (mensagem[i]=='2')
        {
            printf("..--- ");
        }
        if (mensagem[i]=='3')
        {
            printf("...-- ");
        }
        if (mensagem[i]=='4')
        {
            printf("....- ");
        }
        if (mensagem[i]=='5')
        {
            printf("..... ");
        }
        if (mensagem[i]=='6')
        {
            printf("-.... ");
        }
        if (mensagem[i]=='7')
        {
            printf("--... ");
        }
        if (mensagem[i]=='8')
        {
            printf("---.. ");
        }
        if (mensagem[i]=='9')
        {
            printf("----. ");
        }
        if (mensagem[i]=='0')
        {
            printf("----- ");
        }
        i++;
    }
    return 0;
}
