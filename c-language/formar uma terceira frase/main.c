/*5. Implemente um programa que receba duas frases e gere uma
terceira armazenada em uma variável string e depois imprima
a frase gerada.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
char Frase[1000];
char Frase2[1000];
printf("Juntando as frases recebidas\n");
printf("Entre com a frase!\n");
scanf("%999[^\n]",Frase);
fflush(stdin);
printf("Entre com a segunda frase!\n");
scanf("%999[^\n]",Frase2);
printf("a frase junta e");
printf(Frase);
printf(Frase2);
}
