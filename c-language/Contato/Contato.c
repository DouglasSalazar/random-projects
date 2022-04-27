#include"include/relacao.h"
#include"include/arquivo.h"
#include"include/grupo.h"
#include"include/contato.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    LContato *Contatos=NULL;
    LGrupos *Grupos=NULL;
    int Ncontatos=0,Menu=0;
    LGrupos *aux=NULL;
    Contatos=(LContato*)malloc(1000*sizeof(LContato));
    inicializacao(&Ncontatos,&Grupos,Contatos);
    do{        
        do{
            printf("\n1>Cadastrar\n2>Inserir Contato no Grupo\n3>Remover\n4>Procurar\n5>Listar\n6>Sair\n>>");
            scanf("%d",&Menu);
            if(Menu<1 || Menu>6)
                printf("\nErro!! Valor invalido. Favor digitar uma das opcoes acima\n");
        }while(Menu<1 || Menu>6);
        switch(Menu){
            case 1:
                do{
                    printf("\n1>Cadastrar Contato\n2>Cadastrar Grupo\n3>Sair\n>>");        
                    scanf("%d",&Menu);
                    if(Menu<1 || Menu>3){
                        printf("\nErro!! Valor invalido. Favor digitar uma das opcoes acima\n");
                    }
                }while(Menu<1 || Menu>3);
                switch (Menu){
                    case 1:
                        CadastroContato(Contatos, &Ncontatos,Grupos);
                    break;
                    case 2:
                        CadastroGrupo(&Grupos);
                    break;
                    case 3:
                        Menu=100;
                    break;
                }
            break;
            case 2:
                CadastroContatoGrupo(Ncontatos,Contatos,Grupos);
            break;
            case 3:
                do{
                    printf("\n1>Remover Contato\n2>Remover Grupo\n3>Sair\n>>");        
                    scanf("%d",&Menu);
                    if(Menu<1 || Menu>3){
                        printf("\nErro!! Valor invalido. Favor digitar uma das opcoes acima\n");
                    }
                }while(Menu<1 || Menu>3);
                switch (Menu){
                    case 1:
                        removecontato(Contatos,&Ncontatos);
                    break;
                    case 2:
                        removegrupo(&Grupos, Ncontatos, Contatos);
                    break;
                    case 3:
                       Menu=100;
                    break;
                }
            break;
            case 4:
                do{
                    printf("\n1>Procurar Contato\n2>Procurar Grupo\n3>Sair\n>>");        
                    scanf("%d",&Menu);
                    if(Menu<1 || Menu>3){
                        printf("\nErro!! Valor invalido. Favor digitar uma das opcoes acima\n");
                    }
                }while(Menu<1 || Menu>3);
                switch (Menu){
                    case 1:
                        procuracontato(Contatos,Ncontatos);
                    break;
                    case 2:
                        procuragrupo(Grupos);
                    break;
                    case 3:
                        Menu=10;
                    break;
                }
            break;
            case 5:
                do{
                    printf("\n1>Listar Todos Contatos\n2>Listar Contatos de um Grupo\n3>Sair\n>>");        
                    scanf("%d",&Menu);
                    if(Menu<1 || Menu>4){
                        printf("\nErro!! Valor invalido. Favor digitar uma das opcoes acima\n");
                    }
                }while(Menu<1 || Menu>4);
                switch (Menu){
                    case 1:
                        listatodoscontatos(Contatos,Ncontatos);
                    break;
                    case 2:
                        listagrupos(Contatos,Ncontatos);
                    break;
                    case 3:
                        Menu=10;
                    break;
                }
            break;
            case 6:
                grava(Contatos,Grupos,Ncontatos);
            break;
        }
   }while(Menu!=6);
    
	return 0;
}
