#include "../include/arquivo.h"

void inicializacao(int *Ncontatos, LGrupos ** Grupos,LContato * Contatos){
    FILE *arq=NULL;
    LGrupos *Ini=NULL;
    LRela *Init=NULL;
    int Numero=0,j=0,Ncont=0;    
    char Nome[50];
    char sobrenome[50];
    char Telefone[20];
	char Email[50];
    arq=fopen("contatos.txt","r");
    if(arq!=NULL){
        while(!feof(arq)){
            if(fscanf(arq,"%d %s %s %s %s",&Numero,Nome,sobrenome,Telefone,Email)!=EOF){
                j=0;
                while(Contatos[j].Numero != Numero && j<*Ncontatos)
                    j++;
                if(Contatos[j].Numero != Numero && Numero>=0){
                    Contatos[j].Numero = Numero;                            
                    strcpy(Contatos[*Ncontatos].Nome,Nome);                        
                    strcpy(Contatos[*Ncontatos].sobrenome,sobrenome);
                    strcpy(Contatos[*Ncontatos].Telefone,Telefone);
                    strcpy(Contatos[*Ncontatos].Email,Email);
                    Contatos[*Ncontatos].Grupos=NULL;
                    *Ncontatos+=1;
                }
            }
        }
    }
    fclose(arq);
    arq=NULL;
    arq=fopen("grupos.txt","r");
    if(arq!=NULL){
        while(!feof(arq)){
            Ncont=0;
            Numero=0;
            if(fscanf(arq,"%d %s %d\n",&Numero,Nome,&Ncont)!=EOF){
                Ini=*Grupos;
                while(Ini!=NULL){
                    if(strcmp(Ini->descricao,Nome)==0)
                       Numero=-9;
                    Ini=Ini->prox;
                }
                if(Numero>=0){
                    Ini=aloca_grupo(*Grupos,Numero);
                    if(Ini!=NULL){
                        *Grupos=Ini;
                        Ini=*Grupos;
                        while(Ini->prox!=NULL){
                            Ini=Ini->prox;
                        }          
                        strcpy(Ini->descricao,Nome);
                        Ini->Ncont=0;
                    }
                }
            }
        }
    }
    fclose(arq);
    arq=NULL;
    arq=fopen("grupcont.txt","r");
    if(arq!=NULL){
        while(!feof(arq)){
            if(fscanf(arq,"%d %d",&Numero,&Ncont)!=EOF){
                j=0;
                while(Contatos[j].Numero!=Ncont && j < *Ncontatos){
                    j++;
                }
                if(Contatos[j].Numero == Ncont){
                    Init=aloca_relacao(Contatos[j].Grupos, Numero, *Grupos);
                    if(Init!=NULL){
                        Contatos[j].Grupos=Init;
                    }                            
                }
            }
        }
    }
    fclose(arq);
}


void grava(LContato *Contatos, LGrupos *Grupos,int Ncontatos){
FILE *arq=NULL;
FILE *arq1=NULL;
LRela *rela=NULL;
LRela *aux=NULL;
LGrupos* aux1=NULL;
int i=0;

    arq=fopen("contatos.txt","w+");
    arq1=fopen("grupcont.txt","w+");
    if(arq!=NULL && arq1!=NULL){    
        while(i<Ncontatos){
            fprintf(arq,"%d %s %s %s %s\n",Contatos[i].Numero,Contatos[i].Nome, Contatos[i].sobrenome,Contatos[i].Telefone, Contatos[i].Email);
            rela=Contatos[i].Grupos;
            while(rela!=NULL){
                fprintf(arq1,"%d %d\n",rela->grupo->numero,Contatos[i].Numero);
                aux=rela;                
                rela=rela->prox;
                free(aux);
            }
            i++;
        }
    }    
    fclose(arq);
    fclose(arq1);
    arq=fopen("grupos.txt","w+");
    if(arq!=NULL){    
        while(Grupos!=NULL){
            fprintf(arq,"%d %s %d\n",Grupos->numero,Grupos->descricao,Grupos->Ncont);
            aux1=Grupos;
            Grupos=Grupos->prox;
            free(aux1);
        }
    }
    fclose(arq);
    free(Contatos);
}   

