#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fareni,cont;
    float cent;
    fareni = 50;
    printf("Conversão de graus Farenheit para centígrados\n");
    for (cont=1; cont<=101 ;cont++){
        cent = (5*(fareni-32))/9;
        printf ("A conversão de %d Farenheit para Centígrados é: %2.f\n",fareni,cent);
        fareni = fareni + 1;
    }
        getchar();
        return 0;
}
