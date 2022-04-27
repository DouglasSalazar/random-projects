#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

void vec(int *l,int *aux, int j){
int i;
	for(i=0;i<j;i++){
            aux[i]=l[i];
        }
}

void troca(int i, int y, int *l){
int aux;
    aux=l[i];
    l[i]=l[y];
    l[y]=aux;
}

void bubble(int n, int *l){
int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=(n-1);j++){
            if(l[j]>l[j+1]){
                troca(j,j+1,l);
            }
        }
    }
}

void bubble_melhorado(int n, int *l){
int i,n1=0,guarda=0,mudou=0;

    mudou=1;
    n1=n;
    guarda=n;
    while(mudou==1){
        i=0;
        mudou=0;
        while(i<n1){
            if(l[i]>l[i+1]){
                troca(i,i+1,l);
                mudou = 1;
                guarda=i;
            }
            i=i+1;
        }
        n1=guarda;
    }
}

void insertion(int n, int *l){
int prov;
int i,valor=0,j=0;
    for(i=1;i<=n;i++){
        prov=l[i];
        valor=l[i];
        j=i-1;
        while(j>=0 && valor<l[j]){
            l[j+1]=l[j];
            j=j-1;
        }
        l[j+1]=prov;
    }
}

void intercala(int *l,int ini1,int ini2,int fim2,int *Temp){
int fim1=0,nro=0,ind=0,aux=0,i;
    fim1=ini2-1;
    ind = ini1;
    aux=ini1;
        while(ini1<=fim1 && ini2<=fim2){
            if(l[ini1]<l[ini2]){
                Temp[ind]=l[ini1];
                ini1=ini1+1;
            }else{
                Temp[ind]=l[ini2];
                ini2=ini2+1;
            }
            ind=ind+1;
            nro=nro+1;
        }
        while(ini1<=fim1){
            Temp[ind]=l[ini1];
            ini1=ini1+1;
            ind=ind+1;
            nro=nro+1;
        }
        while(ini2<=fim2){
            Temp[ind]=l[ini2];
            ini2=ini2+1;
            ind=ind+1;
            nro=nro+1;
        }
        for(i=0;i<=nro;i++){
            l[i+aux-1]=Temp[i+aux-1];
        }
}

void mergesort(int esq, int dir,int *l,int *Temp){
int centro=0;
    if (esq<dir){
        centro=(esq+dir)/2;
        mergesort(esq,centro,l,Temp);
        mergesort(centro+1,dir,l,Temp);
        intercala(l,esq,centro+1,dir,Temp);
    }
}

void pivo(int ini,int fim,int *mediana,int *l){
int med=(ini+fim)/2;
    if(l[med]>l[ini] && l[med]<l[fim]){
            *mediana=med;
    }
    if(l[fim]>l[ini] && l[fim]<l[med]){
        *mediana=fim;
    }
    if(l[fim]>l[med] && l[fim]<l[ini]){
        *mediana=fim;
    }
    if(l[ini]>l[med] && l[ini]<l[fim]){
        *mediana=ini;
    }
    if(l[ini]>l[fim] && l[ini]<l[med]){
        *mediana=ini;
    }
    if(l[med]>l[fim] && l[med] <l[ini] ){
        *mediana=med;
    }
}

void quicksort_mediana(int *l,int ini,int fim){
int mediana=0,i=0,j=0,key=0;
    if((fim-ini)<2){
        if((fim-ini)==1){
            if(l[ini] >l[fim] ){
                troca(ini,fim,l);
            }
        }
    }else{
        pivo(ini,fim,&mediana,l);
        troca(mediana,fim,l);
        i=ini;
        j=fim-1;
        key=l[fim] ;
        while(j>=i){
            while(l[i] <key){
                i=i+1;
            }
            while(l[j] >key){
                j=j-1;
            }
            if(j>=i){
                troca(i,j,l);
                i=i+1;
                j=j-1;
            }
        }
        troca(i,fim,l);
        quicksort_mediana(l,ini,i-1);
        quicksort_mediana(l,i+1,fim);
    }
}

void quicksort_primeiro(int *l,int ini,int fim){
int i=0,j=0,key=0;
    if((fim-ini)<2){
        if((fim-ini)==1){
            if(l[ini] >l[fim] ){
                troca(ini,fim,l);
            }
        }
    }else{
        troca(ini,fim,l);
        i=ini;
        j=fim-1;
        key=l[fim] ;
        while(j>=i){
            while(l[i] <key){
                i=i+1;
            }
            while(l[j] >key){
                j=j-1;
            }
            if(j>=i){
                troca(i,j,l);
                i=i+1;
                j=j-1;
            }
        }
        troca(i,fim,l);
        quicksort_primeiro(l,ini,i-1);
        quicksort_primeiro(l,i+1,fim);
    }
}

void quicksort_aleatorio(int *l,int ini,int fim){
int ale=0,i=0,j=0,key=0;
    if((fim-ini)<2){
        if((fim-ini)==1){
            if(l[ini] >l[fim] ){
                troca(ini,fim,l);
            }
        }
    }else{
        srand(time(NULL));
        ale=ini+rand()%(fim-ini);
        troca(ale,fim,l);
        i=ini;
        j=fim-1;
        key=l[fim] ;
        while(j>=i){
            while(l[i] <key){
                i=i+1;
            }
            while(l[j] >key){
                j=j-1;
            }
            if(j>=i){
                troca(i,j,l);
                i=i+1;
                j=j-1;
            }
        }
        troca(i,fim,l);
        quicksort_aleatorio(l,ini,i-1);
        quicksort_aleatorio(l,i+1,fim);
    }
}

void descer(int i,int n,int *l){
int j=0;

    j=2*i;
    if(j<=n){
        if(j<n){
            if(l[j+1] >l[j] ){
                j=j+1;
            }
        }
        if(l[i] <l[j] ){
            troca(i,j,l);
            descer(j,n,l);
        }
    }
}

void arranjar(int n, int *l){
int i=0;
    for(i=n/2;i>=0;i--){
        descer(i,n,l);
    }
}

void heap(int n, int *l){
int m=0;
    arranjar(n,l);
    m=n;
    while(m>=1){
        troca(0,m,l);
        m=m-1;
        descer(0,m,l);
    }
}

void time_bubble(int n,int *l,FILE *arq1){
double bub;
struct timeval ti,tf;

    gettimeofday(&ti,NULL);
    bubble(n-1,l);
    gettimeofday(&tf,NULL);
    bub=(tf.tv_sec + tf.tv_usec/1000000.0)-(ti.tv_sec + ti.tv_usec/1000000.0);
    fprintf(arq1,"%f s\n",bub);
}

void time_bubble_me(int n, int *l,FILE *arq1){
double bub_Me;
struct timeval ti,tf;

    gettimeofday(&ti,NULL);
    bubble_melhorado(n-1,l);
    gettimeofday(&tf,NULL);
    bub_Me=(tf.tv_sec + tf.tv_usec/1000000.0)-(ti.tv_sec + ti.tv_usec/1000000.0);
    fprintf(arq1,"%f s\n",bub_Me);
}

void time_inser(int n , int *l,FILE *arq1){
double inse;
struct timeval ti,tf;

    gettimeofday(&ti,NULL);
    insertion(n-1,l);
    gettimeofday(&tf,NULL);
    inse=(tf.tv_sec + tf.tv_usec/1000000.0)-(ti.tv_sec + ti.tv_usec/1000000.0);
    fprintf(arq1,"%f s\n",inse);
}

void time_merg(int n,int *l,FILE *arq1){
double Merg;
struct timeval ti,tf;
int *Temp=NULL;

    gettimeofday(&ti,NULL);
    Temp=(int*)malloc((sizeof(int))*n);
    mergesort(0,n,l,Temp);
    if(Temp!=NULL){
	    	free(Temp);
            Temp=NULL;
    }
    gettimeofday(&tf,NULL);
    Merg=(tf.tv_sec + tf.tv_usec/1000000.0)-(ti.tv_sec + ti.tv_usec/1000000.0);
    fprintf(arq1,"%f s\n",Merg);
}

void time_quick_me(int n,int *l,FILE *arq1){
double quick_med;
struct timeval ti,tf;

    gettimeofday(&ti,NULL);
    quicksort_mediana(l,0,n-1);
    gettimeofday(&tf,NULL);
    quick_med=(tf.tv_sec + tf.tv_usec/1000000.0)-(ti.tv_sec + ti.tv_usec/1000000.0);
    fprintf(arq1,"%f s\n",quick_med);
}

void time_quick_pri(int n,int *l,FILE *arq1){
double quick_pri;
struct timeval ti,tf;

    gettimeofday(&ti,NULL);
    quicksort_primeiro(l,0,n-1);
    gettimeofday(&tf,NULL);
    quick_pri=(tf.tv_sec + tf.tv_usec/1000000.0)-(ti.tv_sec + ti.tv_usec/1000000.0);
    fprintf(arq1,"%f s\n",quick_pri);
}

void time_quick_ale(int n, int *l,FILE *arq1){
double quick_ale=0;
struct timeval ti,tf;

    gettimeofday(&ti,NULL);
    quicksort_aleatorio(l,0,n-1);
    gettimeofday(&tf,NULL);
    quick_ale=(tf.tv_sec + tf.tv_usec/1000000.0)-(ti.tv_sec + ti.tv_usec/1000000.0);
    fprintf(arq1,"%f s\n",quick_ale);
}

void time_hp(int n,int *l,FILE *arq1){
double hp;
struct timeval ti,tf;
    gettimeofday(&ti,NULL);
    heap(n-1,l);
    gettimeofday(&tf,NULL);
    hp=(tf.tv_sec + tf.tv_usec/1000000.0)-(ti.tv_sec + ti.tv_usec/1000000.0);
    fprintf(arq1,"%f s\n",hp);
}

void chamada1Parte(int n,int *l,FILE *arq1, int *aux){

    aux=(int*)malloc(n*sizeof(int));

	fprintf(arq1,"Bubble: ");
	vec(l,aux,n);
	time_bubble(n,l,arq1);

	fprintf(arq1,"Bubble Melhorado: ");
	vec(l,aux,n);
	time_bubble_me(n,l,arq1);

	fprintf(arq1,"InsertionSort: ");
	vec(l,aux,n);
	time_inser(n ,l,arq1);

	fprintf(arq1,"Mergesort: ");
	vec(l,aux,n);
	time_merg(n,l,arq1);

	fprintf(arq1,"QuickSort Pivo Mediana: ");
	vec(l,aux,n);
	time_quick_me(n,l,arq1);

        fprintf(arq1,"QuickSort Pivo Primeiro: ");
	vec(l,aux,n);
	time_quick_pri(n,l,arq1);

    fprintf(arq1,"QuickSort Pivo Aleatorio: ");
	vec(l,aux,n);
	time_quick_ale(n,l,arq1);

	fprintf(arq1,"HeapSort: ");
	vec(l,aux,n);
	time_hp(n,l,arq1);

    if(aux!=NULL){
        free(aux);
        aux=NULL;
    }
}

void chamada2Parte(int n,int *l,FILE* arq1,int *aux){
    aux=(int*)malloc(n*sizeof(int));


	fprintf(arq1,"Mergesort: ");
	vec(l,aux,n);
	time_merg(n,l,arq1);

	fprintf(arq1,"QuickSort Pivo Mediana: ");
	vec(l,aux,n);
	time_quick_me(n,l,arq1);
	
	fprintf(arq1,"QuickSort Pivo Aleatorio: ");
	vec(l,aux,n);
	time_quick_ale(n,l,arq1);


	fprintf(arq1,"HeapSort: ");
	vec(l,aux,n);
	time_hp(n,l,arq1);

    if(aux!=NULL){
        free(aux);
        aux=NULL;
    }
}

void chamada3Parte(int n,int *l,FILE* arq1,int *aux){
    aux=(int*)malloc(n*sizeof(int));


	fprintf(arq1,"Mergesort: ");
	vec(l,aux,n);
	time_merg(n,l,arq1);
	
	fprintf(arq1,"QuickSort Pivo Aleatorio: ");
	vec(l,aux,n);
	time_quick_ale(n,l,arq1);


	fprintf(arq1,"HeapSort: ");
	vec(l,aux,n);
	time_hp(n,l,arq1);

    if(aux!=NULL){
        free(aux);
        aux=NULL;
    }
}


int main(){
	FILE *arq;
	FILE *arq1;
	int *l=NULL;
	int *aux=NULL;
	char s[30];
	int n=0,i,j=0,a=10,b=0,c=0;

	for(b=0;b<=8;b++){
		if(b==4 || b==8){
			c=0;
			a=a*5;
			c=1;
		}else{
			if(c==1){
				a=a/5;
				a=a*10;
				c=0;
			}else{
				a=a*10;
            		}
        	}
		if(b<=4){
			l=(int*)malloc((sizeof(int))*a-1);
			n=0;
			sprintf(s,"%d",a);
			strcat(s,"aleatorio.txt");
			if((arq=fopen(s,"r"))!=NULL){
				for(i=0;i<a;i++){
					j=0;
					fscanf(arq,"%d",&j);
					l[i] =j;
					n++;
                		}
            		}
            		if(arq!=NULL){
               			 fclose(arq);
               			 arq=NULL;
            		}
           		sprintf(s,"Dados%d",a);
           		strcat(s,".txt");
           		if((arq1=fopen(s,"wt"))!=NULL){
               			sprintf(s,"%d",a);
               			strcat(s," NUMEROS ALEATORIOS");
				fprintf(arq1,"%s \n\n",s);
                		chamada1Parte(n,l,arq1,aux);
            		}

           		n=0;
           		sprintf(s,"%d",a);
           		strcat(s,"crescente.txt");
          		if((arq=fopen(s,"r"))!=NULL){
		       		 for(i=0;i<a;i++){
					j=0;
				        fscanf(arq,"%d",&j);
		         		l[i] =j;
		            		n++;
		               	 }
            		}
            
			if(arq!=NULL){
		        	fclose(arq);
		    		arq=NULL;
            		}
            		sprintf(s,"%d",a);
            		strcat(s," NUMEROS CRECENTES");
            		fprintf(arq1,"\n%s \n\n",s);
            		chamada1Parte(n,l,arq1,aux);

           		n=0;
            		sprintf(s,"%d",a);
            		strcat(s,"decrescente.txt");
            		if((arq=fopen("10decrecente.txt","r"))!=NULL){
            			for(i=0;i<a;i++){
                			j=0;
                			fscanf(arq,"%d",&j);
                			l[i] =j;
               				n++;
            			}
            		}
            		if(arq!=NULL){
           			fclose(arq);
            			arq=NULL;
            		}
            		sprintf(s,"%d",a);
            		strcat(s," NUMEROS DECRECENTES");
            		fprintf(arq1,"\n%s \n\n",s);
            		chamada1Parte(n,l,arq1,aux);
            		if(arq1 != NULL){
            			fclose(arq1);
            			arq1=NULL;
            		}
            		if(l!=NULL){
                		free(l);
            			l=NULL;
            		}
        	}else{
                        l=(int*)malloc((sizeof(int))*a-1);
            		n=0;
            		sprintf(s,"%d",a);
            		strcat(s,"aleatorio.txt");
            		if((arq=fopen(s,"r"))!=NULL){
                		for(i=0;i<a;i++){
                    			j=0;
                    			fscanf(arq,"%d",&j);
                    			l[i] =j;
                    			n++;
                		}
            		}
            		if(arq!=NULL){
                		fclose(arq);
                		arq=NULL;
            		}
           		sprintf(s,"Dados%d",a);
           		strcat(s,".txt");
           		if((arq1=fopen(s,"wt"))!=NULL){
                		sprintf(s,"%d",a);
                		strcat(s," NUMEROS ALEATORIOS");
                		fprintf(arq1,"%s \n\n",s);
                		chamada3Parte(n,l,arq1,aux);
            		}

            		n=0;
            		sprintf(s,"%d",a);
            		strcat(s,"crescente.txt");
            		if((arq=fopen(s,"r"))!=NULL){
                		for(i=0;i<a;i++){
                    			j=0;
                    			fscanf(arq,"%d",&j);
                    			l[i] =j;
                    			n++;
                		}
            		}
            		if(arq!=NULL){
                		fclose(arq);
                		arq=NULL;
            		}
            		sprintf(s,"%d",a);
            		strcat(s," NUMEROS CRECENTES");
            		fprintf(arq1,"\n%s \n\n",s);
            		chamada2Parte(n,l,arq1,aux);

            		n=0;
            		sprintf(s,"%d",a);
            		strcat(s,"decrescente.txt");
            		if((arq=fopen(s,"r"))!=NULL){
            			for(i=0;i<a;i++){
                			j=0;
                			fscanf(arq,"%d",&j);
                			l[i] =j;
                			n++;
            			}
            		}
            		if(arq!=NULL){
            			fclose(arq);
            			arq=NULL;
            		}
            		sprintf(s,"%d",a);
            		strcat(s," NUMEROS DECRECENTES");
            		fprintf(arq1,"\n%s \n\n",s);
            		chamada2Parte(n,l,arq1,aux);
            		if(arq1 != NULL){
            			fclose(arq1);
            			arq1=NULL;
            		}
            		if(l!=NULL){
                		free(l);
            			l=NULL;
            		}

        	}
	}
	return 0;
}

