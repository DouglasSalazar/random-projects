#include <stdio.h>
#include <stdlib.h>

float main(void)
{
    float n,notas,resultado;
    int m,resposta;
    m=0;
    notas=-1;
    printf("Calcular a M�dia\n");
        do{
            printf ("Informe a nota\n");
            scanf ("%f",&n);
            if ((n<0)|| (n>10)){
                printf ("Nota Invalida Valor negativo ou maior que 10\n");
                }
            else {
            notas = notas+n;
            m = m+1;
            printf ("Deseja Informar mais notas?\nSe Sim 1 se nao 2 \n");
            scanf ("%i", &resposta);
            }
            }while ((resposta==1));
    resultado=notas/m;
    printf ("A m�dia �:%f\n", resultado);
    system ("pause");
}
