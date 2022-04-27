#include <stdio.h>
#include <stdlib.h>
// funcao que retorna data
char *data(void){

   int dia,mes,ano;
   char   var1[100],
      var2[100],
      var3[100],
      var4[100],
      *dataPtr;
   struct tm *local;
   time_t t;

   t = time(NULL);
   local = localtime(&t);

   dia = local -> tm_mday;
   mes = local -> tm_mon + 1;
   ano = local -> tm_year + 1900;

   // por algum motivo precisa converter os valores retornados pelos ponteiros
   // da funcao em variaveis do tipo char
   sprintf(var1,"%s",format(dia));
   sprintf(var2,"%s",format(mes));
   sprintf(var3,"%s",format(ano));

   // cria a variavel de retorno dos dados e cria um ponteiro para essa variavel
   sprintf(var4,"%s/%s/%s",var1,var2,var3);

   // retorna data no formato dd:MM:yyyy com um ponteiro
   dataPtr = var4;
   return dataPtr;
}
int main()
{
    char data[11];
    char data2[11];
    int i=0,m=0,d=0,j=9;
    printf("Ajuste de formato de data!\n\n");
    do{
        printf("Informe a data no formato aaaammdd\n");
        scanf("%8[1234567890\n]",data);
        m = data[4]+ data[5];
        d = data[6]+ data[7];
        if ((m>12) &&(d>31)||(m==2 && d>28))
        {
            printf("Data Invalida!\n");
        }
    }while ((m>12) &&(d>31) ||(m==2 && d>28));

    return 0;
}
