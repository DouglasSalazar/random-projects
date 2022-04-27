#include "gfx.h"
#include <stdio.h>  /* printf */
#include <unistd.h> /* sleep  */

/*Aluno: Douglas Correia Salazar
RGM:
2 Ano CC
*/

/* -----------------------------------------------------------------------------------------------------------------------------------------Faça um programa que utilize um procedimento recursivo para desenhar um Triângulo de Sierpinski (veja Figura 1). Considere que cada triângulo que compõe o Triângulo de Sierpinski é equilátero. Observe que, nessa figura geométrica, cada triângulo origina outros três: na parte superior, no lado direito e no lado esquerdo. O tamanho de cada lado de cada um desses três é metade do tamanho de cada lado do triângulo original.

Seu programa deverá apresentar interface com usuário para: Desenhar/redesenhar o Triângulo de Sierpinski usando a biblioteca gfx; Aumentar/reduzir o tamanho desse triângulo; Apagar o triângulo desenhado. O código deve estar devidamente organizado, identado, comentado e sem warnings usando as opções -Wall -Wextra -pedantic do gcc
---------------------------------------------------------------------------------------------------------------------------------------------
*/

/*função aonde usa as coordenadas x e y para desenhar o triangula*/
void desenhotriangulo(int x1, int y1, int x2, int x3, int y2){

	gfx_line(x1,y1,x2,y2);
	gfx_line(x1,y1,x3,y2);
	gfx_line(x2,y2,x3,y2);
}	

int triangulo(int x, int y , int base){
	if(base<=0){
		return 0;	
	}
	/* x equivale a primeira coordena q e no meio, base e o tamanho do triangulo do meio, e y segundo ponto de ligacao*/
	if(base > 0){
		/*primeiro triangulo*/
		desenhotriangulo(x, y+((base*1.732050808)/2), x-(base/2), x+(base/2),y);
		/*lado direito chamada recursiva*/
		triangulo(x+(base/2),y+(((base*1.732050808)/2)/2),base/2);
		/*lado esquerdo chamada recursiva*/		
		triangulo(x-(base/2),y+(((base*1.732050808)/2)/2),base/2);
		/*para cima chamada recursiva*/		
		triangulo(x,y-(((base*1.732050808)/2)/2),base/2);	
		gfx_paint();	
	}
	return 0;	
}

void lertamanho(int *x, int *y, int *base, int *cm){
	do{	
		printf("Informe o tamanho em Pixel!Obs: valor entre 1 e 1500\n");	
		scanf("%d",&*cm);
		if(*cm < 1 || *cm > 1500){
			printf("\nValor informado invalido favor informar entre 1 e 1500\n");
		}
	}while(*cm <1 || *cm > 1500);
	*base=*cm; /*Tamanho do triangulo maior*/	
	*cm=*cm+184; /*Tamanho da Janela*/
	*base=*base/2;/*tamanho triangulo meio*/
	*x=*cm/2;/*y e x comecao no meio para centralizar o triangulo*/
	*y=*cm/2;
}
void menu(){
int m=0,x=0,y=0,base=0,cm=0;
	do{
		do{
			printf("\n\nDesenho do Triangulo de Sierpinski\n");
			printf("\n\n Digite uma das opcao abaixo\n\n");
			printf("1>Desenhar/Redezenhar Triangulo\n2>Aumentar/Reduzir o tamnho do triangulo\n3>Apagar o Triangulo Desenhado\n4>Sair\n\n>>");
			scanf("%d",&m);
			if(m<1 || m>4){
				printf("Opcao Invalida!!\n");
			}
		}while(m<1 || m>4);
		/*controle para que nao desenhe antes de informar o tamanho*/		
		if(m==1 && cm==0){
			printf("\nEntre primeiro na opcao 2 para entrar na opcao 1\n\n");	
			m=0;		
		}		
		if(m==1 && cm>0){		
			/*abrindo quadro e chamando funcao de desenho triangulo*/
			gfx_init(cm, cm, "Triangulo ");
			triangulo(x,y,base);
			m=0;
		}
		if(m==2){
			/*leitura de datos*/
			lertamanho(&x, &y, &base, &cm);
			m=0;	
		}	
		if(m==3){
			/*apagar triangulo*/
			gfx_clear();
			gfx_paint();
			m=0;
		}	
		if(m==4){	
			gfx_quit();			
		}
	}while(m<1 || m>4);
}	

int main()
{
	menu();

	return 0;
}
