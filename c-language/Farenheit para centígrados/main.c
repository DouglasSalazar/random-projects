#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fareni,cont;
    float cent;
    fareni = 50;
    printf("Convers�o de graus Farenheit para cent�grados\n");
    for (cont=1; cont<=101 ;cont++){
        cent = (5*(fareni-32))/9;
        printf ("A convers�o de %d Farenheit para Cent�grados �: %2.f\n",fareni,cent);
        fareni = fareni + 1;
    }
        getchar();
        return 0;
}
