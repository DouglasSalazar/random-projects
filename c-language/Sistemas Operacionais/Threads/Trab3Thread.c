#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

struct cont{/*Struct de indices*/
    uint16_t ini;    
    uint16_t fim;
};

uint16_t N_t; /*Numero de threads*/
uint16_t n;    /*Numero de colunas*/
int16_t **A;/*MAtriz A*/
int16_t **B;/*MAtriz B*/
int16_t **M;/*MAtriz resultado de Multiplicação de A*B*/

int16_t **aloca(uint16_t n){
uint16_t i=0;
int16_t **M;  
    /*Alocação de Matriz*/
    M=(int16_t**)malloc(n*sizeof(int16_t*));
    for(i=0; i<n; i++){
        M[i]=(int16_t*)malloc(n*sizeof(int16_t));
    }
    return M;
}

void desalocam(){/*Desalocação de Matriz*/
    uint16_t i;
    for(i=0;i<n;i++){
        free(M[i]);
        free(A[i]);
        free(B[i]);
    }
    free(B);
    free(A);
    free(M);
}

void *grava(void *par){
    char *nome = ((char*)(par));
    FILE* arq=NULL;        
    uint16_t i,j;    
    arq=fopen(nome,"wb");
    if(arq!=NULL){
        fwrite(&n,sizeof(uint16_t),1,arq);     
            for(j=0; j<n;j++){            /*Inicialização de B*/
                for(i=0; i<n;i++){
                    fwrite(&M[j][i],sizeof(int16_t),1,arq);            
                }
            }
            fclose(arq);
            pthread_exit(0);        
    }else{
        printf("Erro ao criar o arquivo\n");
        exit(0);
    }
}


void *inicializa(void *para){
    char *nome = ((char*)(para));
    FILE* arq=NULL;        
    uint16_t i,j,aux;    
    arq=fopen(nome,"rb");
    if(arq!=NULL){
        fread(&n,sizeof(uint16_t),1,arq);
        if(n>=N_t){        
            A=aloca(n);
            B=aloca(n);
            M=aloca(n);        
            for(i=0;i<n;i++){ /*Inicialização com 0 de Matriz resultado*/
                for(j=0;j<n;j++){
                    M[i][j]=0;                
                }
            }                    
            for(j=0; j<n;j++){            /*inicialização de A*/
                for(i=0; i<n;i++){
                    fread(&aux,sizeof(int16_t),1,arq);    
                    A[j][i]=aux;            
                }
            }
            for(j=0; j<n;j++){            /*Inicialização de B*/
                for(i=0; i<n;i++){
                    fread(&aux,sizeof(int16_t),1,arq);    
                    B[j][i]=aux;            
                }
            }
            fclose(arq);
            pthread_exit(0);        
        }else{
            printf("Erro Parametros Numero de threads maior que ordem\n");
            fclose(arq);
            exit(0);/*return 0 se numero de threads for maior que numero de colunas*/
        }        
    }else{
        printf("Erro ao abrir o arquivo\n");
        exit(0);
    }
}

void *multiplica(void *param){
    struct cont a = *((struct cont*)(param));    
    uint16_t i,j,k;

    for(i=a.ini;i<a.fim;i++){/*multiplicação de valores ate fim limite da thread*/
        for(j=0;j<n;j++){/*ate n numero de posições*/
            for(k=0;k<n;k++){
                M[i][j]=M[i][j]+(A[i][k]*B[k][j]);
            }
        }    
    }
	pthread_exit(0);

}

int main(int argc, char *argv[]){
    char nome[30];
    pthread_t *tid;
	pthread_attr_t *attr;
    uint16_t aux=0,j=0,i=0,k=0;
    struct timeval ti,tf;
    float time_t=0;
    struct cont *indice;

    if(argc >0){
        strcpy(nome,argv[1]);
        N_t=atoi(argv[2]);/*Declaração Numero de threads*/
        tid=(pthread_t *)malloc((N_t+1)*sizeof(pthread_t));
        attr=(pthread_attr_t *)malloc((N_t+1)*sizeof(pthread_attr_t));
        indice=(struct cont*) malloc(N_t*sizeof(struct cont));   /*Struct contendo indices de inicio e final*/
        
        for(i=0; i<(N_t+1); i++)	
		    pthread_attr_init(&attr[i]);   /*Inicialização de atributos*/

        pthread_create(&tid[N_t],&attr[N_t],inicializa,&nome);/*Thread para leitura*/
        pthread_join(tid[N_t],NULL);
       
        aux=n;/*Aux recebe numero de colunas*/
        j=N_t;/*j recebe numero de threads*/
        k=0;/*k controla a proxima posição*/
        for(i=0; i<N_t; i++){                                
            indice[i].fim=k+(aux/j);/*aux/j + k ou seja a parte anterior mais a subdivisao de colunas por threads*/
            k=k+(aux/j);/*Atualiza k*/
            aux=aux-(aux/j);/*aux subtrai valor ja distribuido*/
            j=j-1;/*j subtrai a thread ja utilizada*/   
        }
        for(i=1; i<N_t; i++){                                
                indice[i].ini=indice[i-1].fim;/*inicial recebe o final da thread anterior*/
        }
        gettimeofday(&ti,NULL);	    /*Tempo*/
        k=0;
        for(i=0; i<(N_t-1); i++){           
            pthread_create(&tid[i],&attr[i],multiplica,&indice[i+1]);/*Criação de threads*/
        }
        for(i=0;i<indice[0].fim;i++){/*calculo matriz threads principal*/
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    M[i][j]=M[i][j]+(A[i][k]*B[k][j]);
                }
            }
        }
        for(i=0; i<(N_t-1); i++) 	
	        pthread_join(tid[i],NULL);
        
        gettimeofday(&tf,NULL);
        time_t=(tf.tv_sec + tf.tv_usec/1000.0)-(ti.tv_sec + ti.tv_usec/1000.0);
        printf("%f ms\n",time_t);/*Tempo gasto*/    
              
        strcpy(nome,"M.out");    
        pthread_create(&tid[N_t-1],&attr[N_t-1],grava,&nome);/*Thread para gravação arquivo M.out*/        
        pthread_join(tid[N_t-1],NULL);    
    }
    desalocam();
    free(indice);
    free(attr);        
    free(tid);    
    return 0;
}

