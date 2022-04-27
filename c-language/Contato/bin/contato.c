#include"../include/contato.h"

void removecontato(LContato *Contatos,int *Ncontatos){
int cod=0,i=0;
LRela *aux;
LRela *aux1;
    if(*Ncontatos>0){
        do{
            printf("\nInforme o codigo do contato a ser removido Obs: Para sair digite numero negativo\n");
            scanf("%d",&cod);
            i=0;
            while(Contatos[i].Numero!=cod && i<*Ncontatos)/*validacao se contato existente*/
                i++;
            if(Contatos[i].Numero!=cod){
                    printf("\nCONTATO NAO CADASTRADO\n");
                    cod=-9;
            }
            if(cod>=0){
                Contatos[i].Numero=0;    
                Contatos[i].Nome[0]='\0';
                Contatos[i].sobrenome[0]='\0';
                Contatos[i].Telefone[0]='\0';
                Contatos[i].Email[0]='\0';
                aux=Contatos[i].Grupos;                
                while(aux!=NULL){/*Desalocação de relacao todo os grupos que o contato pertence*/
                    aux1=aux;
                    aux=aux->prox;
                    free(aux1);
                }                
                Contatos[i].Grupos=NULL;  
                for(i=i;i<*Ncontatos;i++){/*Pucha todos elemntos uma posiçao para frente*/
                    Contatos[i].Numero=Contatos[i+1].Numero;    
                    strcpy(Contatos[i].Nome,Contatos[i+1].Nome);
                    strcpy(Contatos[i].sobrenome,Contatos[i+1].sobrenome);
                    strcpy(Contatos[i].Telefone,Contatos[i+1].Telefone);
                    strcpy(Contatos[i].Email,Contatos[i+1].Email);
                    Contatos[i].Grupos=Contatos[i+1].Grupos;    
                }
                        
                printf("\nCONTATO REMOVIDO COM SUCESSO\n");
                *Ncontatos=*Ncontatos-1;
                cod=-9;
            }
        }while(cod>=0);
    }else{
        printf("\nNENHUM CONTATO CADASTRADO\n");
    }
}
void procuracontato(LContato *Contatos,int Ncontatos){
int menu=0,i=0,j=0;
char nome[50];
LRela* aux;

    do{
        printf("\nDeseja procurar contato por:\n1>Nome\n2>Telefone\n3-Sair\n>>");
        scanf("%d",&menu);
        if(menu<1 || menu>3)
            printf("\nOpção Invalida\n");
    }while(menu<1 || menu>3);
    
    switch(menu){/*caso a busca seja por telefone ou nome*/
        case 1:
            printf("\nInforme o Nome do contato\n");
            scanf("%s",nome);
            i=0;
            j=0;
            while(i<Ncontatos){
                if(strcmp(Contatos[i].Nome,nome)==0){/*se nome informado ser igual algum contato existente sera impresso*/
                        printf("\nNumero: %d\n",Contatos[i].Numero);    
                        printf("Nome: %s\n",Contatos[i].Nome);
                        printf("Sobrenome: %s\n",Contatos[i].sobrenome);
                        printf("Telefone: %s\n",Contatos[i].Telefone);
	                    printf("Email: %s\n",Contatos[i].Email);
                        j=1;                        
                        aux=Contatos[i].Grupos;
                        if(aux!=NULL){/*impressao dos grupos pertencentes*/
                            printf("Grupos Pertecentes:\n");
                            while(aux!=NULL){                                                        
                                printf("Codigo Grupo: %d\n",aux->grupo->numero);
                                printf("Descricao Grupo: %s\n",aux->grupo->descricao);
                                aux=aux->prox;
                            }
                        }
                }     
                i++;
            }
            if(j==0){
                printf("\nNenhum Contato encontrado\n");
            }
        break;
        case 2:
            printf("\nInforme o Numero do telefone do contato\n");
            scanf("%s",nome);
            i=0;
            j=0;
            while(i<Ncontatos){/*se telefone informado for igual a algum dos contatos sera impresso*/
                if(strcmp(Contatos[i].Telefone,nome)==0){
                        printf("\nNumero: %d\n",Contatos[i].Numero);    
                        printf("Nome: %s\n",Contatos[i].Nome);
                        printf("Sobrenome: %s\n",Contatos[i].sobrenome);
                        printf("Telefone: %s\n",Contatos[i].Telefone);
	                    printf("Email: %s\n",Contatos[i].Email);
                        aux=Contatos[i].Grupos;
                        j=1;
                        if(aux!=NULL){/*impressao de grupos pertecentes*/
                            printf("Grupos Pertecentes:\n");
                            while(aux!=NULL){                                                        
                                printf("Codigo Grupo: %d\n",aux->grupo->numero);
                                printf("Descricao Grupo: %s\n",aux->grupo->descricao);
                                aux=aux->prox;
                            }
                        }
                }     
                i++;
            } 
            if(j==0){
                printf("\nNenhum Contato encontrado\n");
            }   
        break;
    }
}

void listatodoscontatos(LContato *Contatos,int Ncontatos){
int i=0,ver=0;
LRela * aux=NULL;

    for(i=0;i<Ncontatos;i++){/*Impressao de todos os contatos*/
        printf("\nNumero: %d\n",Contatos[i].Numero);    
        printf("Nome: %s\n",Contatos[i].Nome);
        printf("Sobrenome: %s\n",Contatos[i].sobrenome);
        printf("Telefone: %s\n",Contatos[i].Telefone);
        printf("Email: %s\n",Contatos[i].Email);
        aux=Contatos[i].Grupos;
        ver=1;
        if(aux!=NULL){
            printf("Grupos Pertecentes:\n");
            while(aux!=NULL){                                                        
                printf("Codigo Grupo: %d\n",aux->grupo->numero);
                printf("Descricao Grupo: %s\n",aux->grupo->descricao);
                aux=aux->prox;
            }
        }
        printf("\n");
    }
    if(ver==0)
        printf("\nNenhum contato Cadastrado\n");
}


void CadastroContato(LContato *Contatos, int *Ncontatos,LGrupos *Grupos){
char nome[50]; /*Variavel para leitura*/
LRela *aux=NULL;/*Auxiliar para percorrer lista de relação*/
char numero[15];/*auxiliar para leitura de numero telefone*/
int NCont=0,i=0,ver=0,j=0;

    do{
        do{
            printf("\nInforme o codigo do contato a ser Cadastrado: Obs: Somente Numeros positivos\n");
            scanf("%d",&NCont);/*ID somente positivo*/
            if(NCont<0)
                printf("\nVALOR INVALIDO VALOR NEGATIVO\n");
        }while(NCont<0);
        i=0;
        while(Contatos[i].Numero != NCont && i<*Ncontatos)/*Pecorrer contatos para verificar se e valido o id*/
            i++;
        if(Contatos[i].Numero == NCont){/*em caso de id ja cadastrado opção de alterar contato*/
            do{    
                printf("\nContato ja Existente deseja alterar\n1>Sim\n2>Nao\n>>");
                scanf("%d",&ver);
                if(ver <1 || ver>2){/*validação de menu*/
                    printf("\nErro!! Valor invalido. Favor digitar uma das opcoes acima\n");
                }
            }while(ver<1 || ver > 2);        
            if(ver==1){/*Possibilita recadastrar informações se for 2 volta menu acima possibilitando digitar novo id */
                ver=3;
            }
        }else{
            ver=1;
        }            
    }while(ver!=1 && ver!=3);
    if(ver==1 && *Ncontatos<1000){/*se ver ==1 sinal que e um novo contato e Ncontatos tem que ser menor que 1000*/
        Contatos[*Ncontatos].Numero=NCont;
        printf("\nInforme o Nome para do contato\n");
        scanf("%s",nome);
        strcpy(Contatos[*Ncontatos].Nome,nome);
        printf("\nInforme o Sobrenome do contato\n");
        scanf("%s",nome);
        strcpy(Contatos[*Ncontatos].sobrenome,nome);
        ver=0;        
        do{/*Validação para informar somente numeros*/
            printf("\nInforme o numero do contato:(SOMENTE NUMEROS)\n");
            scanf("%s",numero);
            i=0;
            while((numero[i]<48 || 58>numero[i]) && numero[i]!='\0')
                i++;
            if(numero[i]!='\0'){
               ver=0;
            }else{
               ver=1;   
            }
            if(ver==0){
                printf("\nFAVOR INFORMAR SOMENTE NUMEROS\n");
            }
        }while(ver!=1);
        strcpy(Contatos[*Ncontatos].Telefone,numero);/*Cadastro de email*/
        printf("\nInforme o email para o novo contato\n");
        scanf("%s",nome);
        strcpy(Contatos[*Ncontatos].Email,nome);
        do{
            printf("\nDeseja Cadastrar novo contato em algum grupo\n1>Sim\n2>Nao\n>>");/*Cadastro ou nao do novo contato em um grupo*/
            scanf("%d",&ver);            
            if(ver<1|| ver>2)
                printf("\nErro!! Valor invalido. Favor digitar uma das opcoes acima\n");
            if(ver==1){
                do{
                    printf("\nInforme o codigo do grupo\n");/*CODIGO SOMENTE POSITIVO*/
                    scanf("%d",&i);
                    if(i<0)
                        printf("\nVALOR INVALIDO\n");
                }while(i<0);
                aux=aloca_relacao(Contatos[*Ncontatos].Grupos, i,Grupos);/*Em caso de relação for nulo sinal que grupo inixistente ou ja cadastado*/
                if(aux==NULL){
                    printf("\nErro! Grupo Inexistente ou ja Cadastrado\n");
                }else{
                    Contatos[*Ncontatos].Grupos=aux;/*Relaçao de grupo*/
                    ver=2;             
                }
            }else if(ver==2){
                Contatos[*Ncontatos].Grupos=NULL;/*Caso nao deseja cadastrar em um grupo relaçao recebe NULL*/
            }
        }while(ver!=2);
        printf("\nCONTATO CADASTRADO COM SUCESSO\n");
        *Ncontatos+=1;/*Adiciona mais 1 no numero de contatos*/
    }else if(ver==3){/*Caso deseja alterar contao*/
        printf("\nInforme o Nome do contato\n");
        scanf("%s",nome);
        strcpy(Contatos[i].Nome,nome);
        printf("\nInforme o Sobrenome do contato\n");
        scanf("%s",nome);
        strcpy(Contatos[i].sobrenome,nome);
        ver=0;        
        do{/*validação somente numeros */
            printf("\nInforme o numero do contato:(SOMENTE NUMEROS)\n");
            scanf("%s",numero);
            j=0;
            while((numero[j]<48 || 58>numero[j]) && numero[j]!='\0')
                j++;
            if(numero[j]!='\0'){
               ver=0;
            }else{
               ver=1;
            }
            if(ver==0){
                printf("\nFavor informar somente Numeros\n");
            }
        }while(ver!=1);
        strcpy(Contatos[i].Telefone,numero);
        printf("\nInforme o email do contato\n");
        scanf("%s",nome);
        strcpy(Contatos[i].Email,nome);
        do{/*Cadastro ou nao de um grupo para o contato alterado*/
            printf("\nDeseja Cadastrar novo contato em algum grupo\n1>Sim\n2>Nao\n>>");
            scanf("%d",&ver);
            if(ver<1 || ver>2)
                printf("\nErro!! Valor invalido. Favor digitar uma das opcoes acima\n");
            if(ver==1){/*em caso de alterar informar cofigo do grupo*/
                do{
                    printf("\nInforme o codigo do grupo: Obs: Somente numeros positivos\n");
                    scanf("%d",&j);
                    if(j<0)
                        printf("\nValor Invalido\n");
                }while(j<0);
                aux=aloca_relacao(Contatos[i].Grupos, j,Grupos);
                if(aux==NULL){/*caso nulo grupo ja existente ou cadastrado*/
                    printf("\nErro! Grupos Inexistente ou ja Cadastrado\n");
                    ver=0;
                }else{
                    Contatos[i].Grupos=aux;/*adiçao de relação para contato alterado*/
                    ver=2;                
                }
            }else if(ver==2){
                Contatos[i].Grupos=NULL;/*Nao desejar cadastrar grupo*/
            }
        }while(ver!=2);        
        printf("\nCONTATO CADASTRADO COM SUCESSO\n");
    }
}
