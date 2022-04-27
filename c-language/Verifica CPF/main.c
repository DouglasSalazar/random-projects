#include <stdio.h>
#include <string.h>

int validaCPF(char stringCPF[12]);
int ctoi(char ch);


void main(void)
{
char cpf[12];
printf("Digite um CPF: ");
scanf("%s", cpf);
if(validaCPF(cpf))
printf("CPF valido");
else
printf("CPF invalido");

getch();

}

int validaCPF(char stringCPF[12])
{
int i, soma1, soma2, digito1, digito2;

if(strlen(stringCPF) != 11)
return 0;

if( (!strcmp(stringCPF, "00000000000")) || (!strcmp(stringCPF, "11111111111")) ||
(!strcmp(stringCPF, "22222222222")) || (!strcmp(stringCPF, "33333333333")) ||
(!strcmp(stringCPF, "44444444444")) || (!strcmp(stringCPF, "55555555555")) ||
(!strcmp(stringCPF, "66666666666")) || (!strcmp(stringCPF, "77777777777")) ||
(!strcmp(stringCPF, "88888888888")) || (!strcmp(stringCPF, "99999999999")) )
return 0;

//Calcula primeiro dígito
soma1 = 0;
for(i=0; i<=8; i++)
soma1 = soma1 + ctoi(stringCPF[i]) * (10 - i);
if(soma1 % 11 < 2)
digito1 = 0;
else
digito1 = 11 - (soma1 % 11);

//Calcula segundo dígito
soma2 = 0;
for(i=0; i<=9; i++)
soma2 = soma2 + ctoi(stringCPF[i]) * (11 - i);
if(soma2 % 11 < 2)
digito2 = 0;
else
digito2 = 11 - (soma2 % 11);

//Se os dígitos forem compatíveis retorna TRUE
if((digito1 == ctoi(stringCPF[9])) && (digito2 == ctoi(stringCPF[10])))
return 1;

return 0;
}

int ctoi(char ch)
{
switch (ch) {
case '0':
return 0;
break;
case '1':
return 1;
break;
case '2':
return 2;
break;
case '3':
return 3;
break;
case '4':
return 4;
break;
case '5':
return 5;
break;
case '6':
return 6;
break;
case '7':
return 7;
break;
case '8':
return 8;
break;
case '9':
return 9;
break;
}

return -1;

}
