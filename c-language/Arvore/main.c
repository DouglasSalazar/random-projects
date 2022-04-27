#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ar{
    struct ar * pont[28];
    char info;
}arv;

void buscadig(char x[30],arv *pt,int l, int *a,int m){
	int i=0,j=0,k=0;
	char d[]="-abcdefghijklmnopqrstuvwyxz";
	k = strlen(x);
	if(l < k){
		i = -1;
		while(x[l] != d[i]){
            i++;
			if(x[l] == d[i]){
				j = i;
			}
		}
		if(pt->pont[j] != NULL){
			pt = pt->pont[j];
			l = l+1;
			buscadig(x,pt,l,a,m);
		}
	}else{
		if(pt->info == '*'){
			*a = 1;
		}
	}

}

void inicializa(arv *ptraiz){
int i=0;

    for(i=0;i<28;i++){
        ptraiz->pont[i]=NULL;
    }
}

void insercao(char x[30],arv *ptraiz,int m){
	int i=0,h=0,k=0,j=0,l=0,a=0;
	char d[]="-abcdefghijklmnopqrstuvwyxz";
	arv * ptz;
	arv * pt;
	pt=ptraiz;

	k = strlen(x);
	buscadig(x,pt,l,&a,m);
	if(a==0){
		for(h=l;h<k;h++){
			i = -1;
			while(x[h] != d[i]){
                i++;
                if(x[h] == d[i]){
					j = i;
				}
			}
			ptz = (arv*) malloc(sizeof(arv));
			inicializa(ptz);
			pt->pont[j] = ptz;
			ptz->info = '-';
			pt = ptz;
		}
		pt->info = '*';
		printf("%s\n",x);
	}else{
		printf("\nInclusao Invalida!\n");
	}
}

char ** cria_matriz(){
    char **v;  /* ponteiro para a matriz */

    v = (char **) malloc (36380 * (sizeof(char *)));
    if (v == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return (NULL);
    }
    return (v); /* retorna o ponteiro para a matriz */
}

void preenche_ar(FILE *arq,char ** Def,int m,arv* pt){
int i=0,n=0,j=0,a=0;
char v[1500];
char x[30];
char aux;


    while(!feof(arq)){
        fscanf(arq,"%c",&aux);
        v[i]=aux;
        if(v[i]=='ã' || v[i]== 'á' || v[i]=='à' || v[i]=='â'){
            v[i]='a';
        }
        if(v[i]=='è' || v[i]=='é' || v[i]=='ê'){
            v[i]='e';
        }
        if(v[i]=='í' || v[i]=='ì'){
            v[i]='i';
        }
        if(v[i]=='õ' || v[i]=='ó' || v[i]=='ô'){
            v[i]='o';
        }
        if(v[i]=='ú' || v[i]=='ü' || v[i]=='ù'){
            v[i]='u';
        }
        if(v[i]=='ç'){
            v[i]='c';
        }
        if(v[i]=='\n'){
            v[i]='\0';
            if(v[0]!=':'){
                n=strlen(v);
                Def[j]=(char*) malloc (n*(sizeof (char)));
                Def[j]=v;
                a=0;
                while(Def[j][a]!=' ' || Def[j][a]!=':'){
                    if(Def[j][a]!=':' || (Def[j][a]>= 97 && Def[j][a]<=122) || Def[j][a] == '-'){
                        x[a]=Def[j][a];
                        a++;
                    }
                }
                x[a]='\0';
                if(x[0]!= '\0');
                    insercao(x,pt,m);
            }
            j++;
            i=-1;
        }
        i++;
    }
}

void desaloca(arv * ptraiz){
int i;
    for(i=0;i<=28;i++){
        if(ptraiz->pont[i]!=NULL){
            desaloca(ptraiz->pont[i]);
            free(ptraiz);
        }
    }
}


int main()
{
    arv *ptraiz;
    arv *aux;
    int m=28,i,a=0,l=0;
    char x[30];
    FILE* arq=NULL;
    char ** Def=NULL;

    arq=fopen("T6-dic.txt","r");
    Def=cria_matriz();


    ptraiz = (arv*) malloc (sizeof(arv));
    ptraiz->info=0;
    inicializa(ptraiz);
    aux=ptraiz;

    preenche_ar(arq,Def,m,aux);
    aux=ptraiz;
    do{
        scanf("%s",x);
        buscadig(x,aux,l,&a,m);
        printf("Encontrou\n");
    }while(x[0]!='0');
    desaloca(ptraiz);
    for(i=0;i<36380;i++){
        free(Def[i]);
    }
    free(Def);
    return 0;
}
