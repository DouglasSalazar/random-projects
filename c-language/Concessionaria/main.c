/*No cadastro de uma revenda de automóveis temos os seguintes dados:
CARRO
- fabricante
- modelo
- placa (única em todo cadastro)
- ano de fabricação
- combustível
- cor
- opcionais
- preço de compra
CLIENTE
- nome
- cpf (único em todo cadastro)
- endereço (rua, nº, bairro, cidade, estado, cep)
- telefone residencial
- telefones celulares
- renda salarial mensal
VENDA
- placa do carro
- cpf do cliente
- preço de venda
- data da venda
O programa deve oferecer as funcionalidades a seguir através de menus de opção:
1. Carro
a. Inserir um carro no cadastro
b. Excluir um carro do cadastro, usando a placa para pesquisa
c. Listar os carros disponíveis para a venda ordenados crescentemente por fabricante e modelo
d. Listar os carros disponíveis para a venda por seleção de um ou mais opcionais
e. Listar os carros disponíveis para a venda por seleção da faixa de ano de fabricação

2. Cliente
a. Inserir um cliente no cadastro
b. Excluir um cliente do cadastro, usando o cpf para pesquisa
c. Listar os clientes do cadastro ordenados crescentemente pelo nome
d. Listar os clientes do cadastro ordenados crescentemente pelo nome por seleção de faixa de renda salarial mensal

3. Venda
a. Inserir uma venda
b. Excluir uma venda, usando a placa do carro para pesquisa
c. Listar os carros vendidos de um determinado fabricante, ordenados crescentemente pelo modelo (as seguintes informações devem aparecer: modelo, placa, ano fabricação e nome cliente )
d. Listar os carros vendidos de um determinado modelo, ordenados crescentemente pelo ano de fabricação (as seguintes informações devem aparecer: ano de fabricação, placa e nome cliente )
e. Informar a quantidade de carros vendidos com o valor totalizado dos preços vendidos
f. Informar o lucro total das vendas
4. sair do programa
*/
/*Instruções para entrega
O programa fonte (com especificação do problema, nome do aluno, data de desenvolvimento e comentários) deverá ser encaminhado para nilton@comp.uems.br. No assunto do e-mail deverá constar 1_CC_AEDI_TRAB_3_2013.
Esta prática vale no máximo 10,0 para compor a nota da 3ª avaliação
Data limite de entrega: 28/09
Trabalho individual
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int validaCPF(char stringCPF[12]); //VERIFICAÇÃO CPF
int ctoi(char ch);
typedef struct TO {
    char Opicionais[20];
}TipoP;
typedef struct TC{ //REGISTRO CARRO
    char Fabricante[20];
    char Modelo[20];
    char placa[9];
    int Anodefabricacao;
    char combustivel[20];
    char Cor [20];
    int opicionais[11];
    float precovenda;
}TIPOCADASTROCARRO;
typedef struct TE{ //REGISTRO ENDEREÇO
    char rua [50];
    int nrua;
    char bairro[50];
    char cidade[50];
    char estado[50];
    char Cep [10];
}TIPOENDERECO;
typedef struct TCC{  //REGISTRO CLIENTE
    char nome[50];
    char cpf[14];
    TIPOENDERECO endereco;
    char telefone[14];
    char celular[14];
    float salario;
}TIPOCLIENTE;
typedef struct TD {  //REGISTRO DATA PARA VENDA
    int dia, mes, ano;
} TIPODATA;
typedef struct TV{ //REGISTRO VENDA
    TIPOCADASTROCARRO VENDIDO;
    TIPOCLIENTE CLIENTEVENDA;
    TIPODATA data_venda;
    int venda;
}TIPOVENDA;
//ZERA CADASTRO
void zeracadastro(TIPOCADASTROCARRO Cadastro_carro[500],TIPOCLIENTE cadastro_cliente [500],TIPOVENDA Cadastro_venda [500]){
int i=0;
    while(i<500){
        Cadastro_carro[i].placa[0]='0';
        cadastro_cliente[i].cpf[0]='0';
    i=i+1;
    }
}
void Cadastro(TIPOCADASTROCARRO Cadastro_carro[500],int c,int *q){
int d=0,j=0,menug=0,z=0,menuf=0;
int opc=0;

                *q=*q+1; //CONTROLE DE CADASTRO CARRO
                char Plac[9];
                do{
                    do{
                            system("cls");
                            printf("Informe a Placa do Veiculo no formato :'AAA-1111'\n");
                            scanf("%s",Plac);           //VERIFICACAO PLACA
                            if((Plac[0]<65 || Plac[0] > 90) ||
                               (Plac[1]<65 || Plac[1] > 90) ||
                               (Plac[2]<65 || Plac[2] > 90) ||
                               (Plac[3]!= 45)||
                               (Plac[4]<48 || Plac[4] > 57) ||
                               (Plac[5]<48 || Plac[5] > 57) ||
                               (Plac[6]<48 || Plac[6] > 57) ||
                               (Plac[7]<48 || Plac[7] > 57) ||
                               (Plac[8]!= '\0')){
                                printf("Placa informada Invalida\a\a\n\n");
                                system("pause");
                            }

                    }while((Plac[0]<65 || Plac[0] > 90) ||
                           (Plac[1]<65 || Plac[1] > 90) ||
                           (Plac[2]<65 || Plac[2] > 90) ||
                           (Plac[3]!= 45)||
                           (Plac[4]<48 || Plac[4] > 57) ||
                           (Plac[5]<48 || Plac[5] > 57) ||
                           (Plac[6]<48 || Plac[6] > 57) ||
                           (Plac[7]<48 || Plac[7] > 57) ||
                           (Plac[8]!= '\0'));
                        j=0;
                        d=0;
                        do{
                            if(strcmp(Cadastro_carro[j].placa,Plac) == 0){ //VERIFICAÇÃO SE Á UMA PLACA
                                d=1;
                            }
                            j=j+1;
                        }while((j < 500) && (d != 1));
                        if(d == 0){
                            strcpy(Cadastro_carro[c].placa,Plac); //COPIA PLACA VALIDA
                        }
                        if(d == 1){
                            printf("\n\nCadastro de placa ja existe informe outra placa\n\n");
                            system("pause");
                        }
                }while(d!=0);
                do{
                    system("cls");
                    printf("Informe o ano de farbicacao do veiculo\n\n");
                    scanf("%d",&Cadastro_carro[c].Anodefabricacao);
                    if(Cadastro_carro[c].Anodefabricacao<1800 || Cadastro_carro[c].Anodefabricacao > 9000){ //VERIFICAÇÃO DE ANO
                        printf("\n\nValor Invalido\n\n\a\a");
                        system("pause");
                    }
                }while(Cadastro_carro[c].Anodefabricacao<1800 || Cadastro_carro[c].Anodefabricacao > 9000);
                do{
                    system("cls");
                    printf("Escolha a opicao de combustivel a baixo\n\n");
                    printf("\n1-Gasolina\n2-Alcool\n3-Diesel\n4-Flex\n\n"); //TIPO DE COMBUSTIVEL
                    scanf("%d",&menug);
                    if (menug<1 || menug >4){
                        printf("Opcao invalida\n\n\a\a");
                        system("pause");
                    }
                }while(menug<1 || menug >4);
                if (menug==1){
                    strcpy (Cadastro_carro[c].combustivel,"Gasolina"); // COPIA DE NOMES DE COMBUSTIVEL PARA CADASTRO
                }
                if (menug==2){
                    strcpy (Cadastro_carro[c].combustivel,"Alcool");
                }
                if (menug==3){
                    strcpy (Cadastro_carro[c].combustivel,"Diesel");
                }
                if (menug==4){
                    strcpy (Cadastro_carro[c].combustivel,"Flex");
                }
                do{
                    system("cls");
                    printf("Escolha a opicao de cor a baixo\n\n");
                    printf("\n1-Prata\n2-Preto\n3-Branco\n4-Outras cores somente por encomenda\n\n"); //TIPO DE COMBUSTIVEL
                    scanf("%d",&menuf);
                    if (menuf<1 || menuf >3){
                        printf("Opcao invalida\a\a\n\n");
                        system("pause");
                    }
                }while(menuf<1 || menuf >3);
                if (menuf==1){
                    strcpy (Cadastro_carro[c].Cor,"Prata"); // COPIA DE NOMES DE COR PARA CADASTRO
                }
                if (menuf==2){
                    strcpy (Cadastro_carro[c].Cor,"Preto");
                }
                if (menuf==3){
                    strcpy (Cadastro_carro[c].Cor,"Branco");
                }
                j=0;
                do{
                Cadastro_carro[c].opicionais[10]=Cadastro_carro[c].opicionais[10]+1;
                d=0;
                z=0;
                    do{                 //ESCOLHA OPICIONAIS
                        menug=0;
                        system("cls");
                        printf("Escolha uma das opicoes abaixo\n\n");
                        printf("1-Ar Condicionado\n\n2-Trava Eletrica\n\n3-Direcao Hidraulica\n\n4-Alarme\n\n5-Vidro Eletrico\n\n6-Cambio Automatico\n\n7-Air Bag\n\n8-Banco de Couro\n\n9-Rodas\n\n10-Basico\n\n");
                        scanf("%d",&opc);
                        if((opc < 1) || (opc > 10)){
                            printf("Valor Invalido\n\n\a\a");
                        }
                        system("pause");
                    }while (opc < 1 || opc > 10);
                    if(opc!=10){  // em caso de básico será cadastrado uma vez so
                        do{
                            if(Cadastro_carro[c].opicionais[d] == opc){  //VERIFICAÇÃO DE OPICIONAIS C JA FOI CADASTRADO
                                printf("\nOpicional ja foi adicionado\n\n\a\a");
                                system("pause");
                                z=1+z;
                            }
                            d=d+1;
                        }while(d != 10);
                        if(z==0 && j!=10){
                            Cadastro_carro[c].opicionais[j] = opc;  //copia de opicionais para cadastro
                        }
                        system("cls");
                        printf("Deseja Informar mais algum opicional?\n\n");
                        printf("1-Sim\n2-Nao\n\n");                        //verificação para cadastrar mais opicionais
                        scanf("%d",&menug);
                        j=j+1;
                    }
                    if(opc==10){ //em caso de basico
                        if(z==0 && j !=10){
                            Cadastro_carro[c].opicionais[0] = opc;
                        }
                    Cadastro_carro[c].opicionais[10]=1;
                    menug=2;
                    }

            }while(menug==1);
            do{
                system("cls");
                printf("Informe o valor de venda do veiculo \n\n"); // valor q foi comprado o veiculo
                scanf("%f",&Cadastro_carro[c].precovenda);
                if(Cadastro_carro[c].precovenda < 0){
                    printf("Valor invalido Valor negativo\n\n\a\a");
                }
                }while(Cadastro_carro[c].precovenda < 0);
}
void Cadastro_de_carro(TIPOCADASTROCARRO Cadastro_carro[500],int *qu){
 int menu=0;

    do{
       int i=0,c=-1;
        system("cls");
        printf("\nInforme o fabricante do veiculo\n\nEscolha a Opcao abaixo\n");    //menu inicial de carro
        printf("\n1-FIAT\n2-GM\n3-VOLKSWAGEM\n4-FORD\n5-HONDA\n6-RENAULT\n7-SAIR\n\n");
        scanf("%d",&menu);
        while(i<=500){
            if(Cadastro_carro[i].placa[0]=='0'){ //verificação de espaço em cadastro
                c=i;
                i=501;
            }
            if (i==500 && c==-1){
                printf("\nNao a mais espaco para cadastros\n\n");
                menu=7;
            }
        i=i+1;
        }
        system("cls");
        if(menu == 1){   //escolha de fabricante
            strcpy(Cadastro_carro[c].Fabricante,"FIAT");        //adicionando nome no cadastro
            int menu1=0;
            do{
                printf("\nInforme um Veiculo abaixo\n");
                printf("\n\n1-PALIO\n2-UNO\n3-STRADA\n4-SIENA\n5-IDEIA\n6-LINEA\n7-STILO\n8-PUNTO\n\n");
                scanf ("%d",&menu1);
            }while(menu1 <1 || menu1 >8 );
            system("cls");
            if(menu1 == 1){  //escolha de modelo e adicionando nome ao cadastro
                strcpy(Cadastro_carro[c].Modelo,"PALIO");
                Cadastro(Cadastro_carro,c,&*qu);    //direcionando para cadastro
            }
            if(menu1 == 2){
                strcpy(Cadastro_carro[c].Modelo,"UNO");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 3){
                strcpy(Cadastro_carro[c].Modelo,"STRADA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 4){
                strcpy(Cadastro_carro[c].Modelo,"SIENA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 5){
                strcpy(Cadastro_carro[c].Modelo,"IDEIA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 6){
                strcpy(Cadastro_carro[c].Modelo,"LINEA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 7){
                strcpy(Cadastro_carro[c].Modelo,"STILO");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 8){
                strcpy(Cadastro_carro[c].Modelo,"PUNTO");
                Cadastro(Cadastro_carro,c,&*qu);
            }

    }
        if(menu == 2){
            strcpy(Cadastro_carro[c].Fabricante,"GM");
            int menu1=0;
            do{
                printf("\nInforme um Veiculo abaixo\n");
                printf("\n\n1-ASTRA\n2-CORSA\n3-CELTA\n4-S-10\n5-AGILE\n6-VECTRA\n7-ZAFIRA\n8-D-20\n\n");
                scanf ("%d",&menu1);
            }while(menu1 <1 || menu1 >8 );
            system("cls");
            if(menu1 == 1){
                strcpy(Cadastro_carro[c].Modelo,"ASTRA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 2){
                strcpy(Cadastro_carro[c].Modelo,"CORSA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 3){
                strcpy(Cadastro_carro[c].Modelo,"CELTA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 4){
                strcpy(Cadastro_carro[c].Modelo,"S-10");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 5){
                strcpy(Cadastro_carro[c].Modelo,"AGILE");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 6){
                strcpy(Cadastro_carro[c].Modelo,"VECTRA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 7){
                strcpy(Cadastro_carro[c].Modelo,"ZAFIRA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 8){
                strcpy(Cadastro_carro[c].Modelo,"D-20");
                Cadastro(Cadastro_carro,c,&*qu);
            }
        }

        if(menu == 3){
            strcpy(Cadastro_carro[c].Fabricante,"VOLKSWAGEM");
            int menu1=0;
            do{
                printf("\nInforme um Veiculo abaixo\n");
                printf("\n\n1-GOL\n2-PARATI\n3-SAVEIRO\n4-GOLF\n5-SANTANA\n6-VOYAGE\n7-AMAROK\n8-FOX\n\n");
                scanf ("%d",&menu1);
            }while(menu1 <1 || menu1 >8 );
            system("cls");
            if(menu1 == 1){
                strcpy(Cadastro_carro[c].Modelo,"GOL");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 2){
                strcpy(Cadastro_carro[c].Modelo,"PARATI");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 3){
                strcpy(Cadastro_carro[c].Modelo,"SAVEIRO");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 4){
                strcpy(Cadastro_carro[c].Modelo,"GOLF");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 5){
                strcpy(Cadastro_carro[c].Modelo,"SANTANA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 6){
                strcpy(Cadastro_carro[c].Modelo,"VOYAGE");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 7){
                strcpy(Cadastro_carro[c].Modelo,"AMAROK");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 8){
                strcpy(Cadastro_carro[c].Modelo,"FOX");
                Cadastro(Cadastro_carro,c,&*qu);
            }

    }
        if(menu == 4){
            strcpy(Cadastro_carro[c].Fabricante,"FORD");
            int menu1=0;
            do{
                printf("\nInforme um Veiculo abaixo\n");
                printf("\n\n1-RANGER\n2-FIESTA\n3-F-250\n4-ECOSPORT\n5-FUSION\n6-KA\n7-VERONA\n8-FOCUS\n\n");
                scanf ("%d",&menu1);
            }while(menu1 <1 || menu1 >8 );
            system("cls");
            if(menu1 == 1){
                strcpy(Cadastro_carro[c].Modelo,"RANGER");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 2){
                strcpy(Cadastro_carro[c].Modelo,"FIESTA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 3){
                strcpy(Cadastro_carro[c].Modelo,"F-250");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 4){
                strcpy(Cadastro_carro[c].Modelo,"ECOSPORT");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 5){
                strcpy(Cadastro_carro[c].Modelo,"FUSION");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 6){
                strcpy(Cadastro_carro[c].Modelo,"KA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 7){
                strcpy(Cadastro_carro[c].Modelo,"VERONA");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 8){
                strcpy(Cadastro_carro[c].Modelo,"FOCUS");
                Cadastro(Cadastro_carro,c,&*qu);
            }

    }
        if(menu == 5){
            strcpy(Cadastro_carro[c].Fabricante,"HONDA");
            int menu1=0;
            do{
                printf("\nInforme um Veiculo abaixo\n");
                printf("\n\n1-CIVIC\n2-FIT\n3-CITY\n4-PRELUDE\n5-CR-V\n6-ACCORD\n\n");
                scanf ("%d",&menu1);
            }while(menu1 <1 || menu1 > 6 );
            system("cls");
            if(menu1 == 1){
                strcpy(Cadastro_carro[c].Modelo,"CIVIC");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 2){
                strcpy(Cadastro_carro[c].Modelo,"FIT");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 3){
                strcpy(Cadastro_carro[c].Modelo,"CITY");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 4){
                strcpy(Cadastro_carro[c].Modelo,"PRELUDE");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 5){
                strcpy(Cadastro_carro[c].Modelo,"CR-V");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 6){
                strcpy(Cadastro_carro[c].Modelo,"ACCORD");
                Cadastro(Cadastro_carro,c,&*qu);
            }

    }
        if(menu == 6){
            strcpy(Cadastro_carro[c].Fabricante,"RENAULT");
            int menu1=0;
            do{
                printf("\nInforme um Veiculo abaixo\n");
                printf("\n\n1-CLIO\n2-MEGANE\n3-LOGAN\n4-FLUENCE\n5-SANDERO\n6-SCENIC\n\n");
                scanf ("%d",&menu1);
            }while(menu1 <1 || menu1 >6 );
            system("cls");
            if(menu1 == 1){
                strcpy(Cadastro_carro[c].Modelo,"CLIO");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 2){
                strcpy(Cadastro_carro[c].Modelo,"MEGANE");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 3){
                strcpy(Cadastro_carro[c].Modelo,"LOGAN");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 4){
                strcpy(Cadastro_carro[c].Modelo,"FLUENCE");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 5){
                strcpy(Cadastro_carro[c].Modelo,"SANDERO");
                Cadastro(Cadastro_carro,c,&*qu);
            }
            if(menu1 == 6){
                strcpy(Cadastro_carro[c].Modelo,"SCENIC");
                Cadastro(Cadastro_carro,c,&*qu);
            }
        }
    }while(menu != 7);
}
void Troca(TIPOCADASTROCARRO *R1, TIPOCADASTROCARRO *R2) {
    TIPOCADASTROCARRO TEMP;
                                //função troca
    TEMP = *R1;
    *R1 = *R2;
    *R2 = TEMP;
}
void excluicadastro(TIPOCADASTROCARRO Cadastro_carro[500],int *q){
char placaex[8];
int i=0,menu=0;
    do{
        printf("Informe a placa do veiculo a ser excluido\n");
        printf("favor informar a placa no modelo: 'AAA-1111'\n\n");
        scanf("%s",placaex);   //recebe placa
        do{
            if(strcmp(placaex,Cadastro_carro[i].placa) == 0 ){ //compara placa
                Cadastro_carro[i].placa[0] = '0'; //zera cadastro
                *q = *q-1;//ajusta contador cadastro
                Troca(&Cadastro_carro[i],&Cadastro_carro[*q]); //troca cadastro apagado pelo ultimo cadastro
                i=500;
            }
            i=i+1;
        }while(i<=500);
        do{
            printf("Deseja excluir mais algum cadastro\n\n");   //exclusao de mais cadastros
            scanf("%d",&menu);
        }while(menu < 1 || menu > 2);
    }while(menu!=2);
}
void ListaFabricante(TIPOCADASTROCARRO Cadastro_carro[500],int quant) {
    int i, j;

    for(i=0;i<quant;i++) {
        for(j=0;j<quant;j++) {
            if(strcmp(Cadastro_carro[j].Fabricante,Cadastro_carro[i].Fabricante)>0) { //ajuste decrecente
                Troca(&Cadastro_carro[j],&Cadastro_carro[i]);
                if(strcmp(Cadastro_carro[j].Fabricante,Cadastro_carro[i].Fabricante)==0) {
                    if(strcmp(Cadastro_carro[j].Modelo,Cadastro_carro[i].Modelo)>0) {
                        Troca(&Cadastro_carro[j],&Cadastro_carro[i]);
                    }
                }
            }
        }
    }
int d=0,c=0,e=0;
    system("cls");
do{  //impressao de cadastro
    printf("Fabricante: %s\n",Cadastro_carro[d].Fabricante);
    printf("Modelo: %s\n",Cadastro_carro[d].Modelo);
    printf("Placa: %s\n",Cadastro_carro[d].placa);
    printf("Ano de Fabricacao: %d\n",Cadastro_carro[d].Anodefabricacao);
    printf("Combustivel: %s\n",Cadastro_carro[d].combustivel);
    printf("Cor: %s\n",Cadastro_carro[d].Cor);
    printf("Opicionais:\n");
    e=0;
    do{
        c=1;
        do{
            if(Cadastro_carro[d].opicionais[e]==c){ //compara numeração para imprimir opicional adequado
                if(c==1){
                    printf("    >Ar Condicionado\n");
                }
                if(c==2){
                    printf("    >Trava Eletrica\n");
                }
                if(c==3){
                    printf("    >Direcao Hidraulica\n");
                }
                if(c==4){
                    printf("    >Alarme\n");
                }
                if(c==5){
                    printf("    >Vidro Eletrico\n");
                }
                if(c==6){
                    printf("    >Cambio Automatico\n");
                }
                if(c==7){
                    printf("    >Air Bag\n");
                }
                if(c==8){
                    printf("    >Banco de Couro\n");
                }
                if(c==9){
                    printf("    >Rodas\n");
                }
                if(c==10){
                    printf("    >Basico\n\n");
                }
            }
                c=c+1;
            }while(c < 10);
            c=0;
            e=e+1;
        }while(e<Cadastro_carro[d].opicionais[10]);
    printf("\nPreco compra: %f\n\n\n",Cadastro_carro[d].precovenda);
d=d+1;
}while(d<quant);
system("pause");
}
void Listaopicionais(TIPOCADASTROCARRO Cadastro_carro[500],int quant){
int menug=0,j=0,d=0,c=0,e=0,z=0;
int opicionais[10];
int opc=0;
opicionais[10]=-1;
            do{
                opicionais[10]=opicionais[10]+1;
                d=0;
                    do{
                        menug=0;                    //oferece ao usuario a opicao de opicional para
                        system("cls");
                        printf("Escolha uma das opicoes abaixo para listar os veiculos\n\n");
                        printf("1-Ar Condicionado\n\n2-Trava Eletrica\n\n3-Direcao Hidraulica\n\n4-Alarme\n\n5-Vidro Eletrico\n\n6-Cambio Automatico\n\n7-Air Bag\n\n8-Banco de Couro\n\n9-Rodas\n\n10-Basico\n\n");
                        scanf("%d",&opc);
                        if(opc < 1 || opc> 10){
                            printf("Favor informar somente numero\n\n");
                        }
                        system("pause");
                    }while (opc< 1 || opc> 10);
                    do{
                    if(opicionais[d] == opc){ //verificação se ja foi adicionado
                        printf("\nOpicional ja foi adicionado\n\n");
                        system("pause");
                        z=1;
                    }
                    d=d+1;
                }while(d < 10);
                if(z==0 && j!=10){
                        opicionais[j] = opc;
                }
                system("cls");
                printf("Deseja Informar mais algum opicional?\n\n");
                printf("1-Sim\n2-Nao\n\n");
                scanf("%d",&menug);
                j=j+1;
            }while(menug==1);
            d=0;
            do{
                j=0;
                do{
                    c=0;
                    do{     //verificação se os opicionais digitados estao de acordo com os carros do cadastro para fazer listagem
                        if (Cadastro_carro[d].opicionais[j]==opicionais[c]){
                         e=e+1;
                        }
                        c=c+1;
                    }while(c<opicionais[10]);
                    j=j+1;
                    system("cls");
                    if(e!=0){ //verificação se realmente a opicionais igual aos do cadastro para ser impresso
                        printf("Fabricante: %s\n",Cadastro_carro[d].Fabricante);
                        printf("Modelo: %s\n",Cadastro_carro[d].Modelo);
                        printf("Placa: %s\n",Cadastro_carro[d].placa);
                        printf("Ano de Fabricacao: %d\n",Cadastro_carro[d].Anodefabricacao);
                        printf("Combustivel: %s\n",Cadastro_carro[d].combustivel);
                        printf("Cor: %s\n",Cadastro_carro[d].Cor);
                        printf("Opicionais:\n");
                        e=0;
                        do{
                            c=1;
                                do{
                                    if(Cadastro_carro[d].opicionais[e]==c){
                                        if(c==1){
                                            printf("    >Ar Condicionado\n");
                                        }
                                        if(c==2){
                                            printf("    >Trava Eletrica\n");
                                        }
                                        if(c==3){
                                            printf("    >Direcao Hidraulica\n");
                                        }
                                        if(c==4){
                                            printf("    >Alarme\n");
                                        }
                                        if(c==5){
                                            printf("    >Vidro Eletrico\n");
                                        }
                                        if(c==6){
                                            printf("    >Cambio Automatico\n");
                                        }
                                        if(c==7){
                                            printf("    >Air Bag\n");
                                        }
                                        if(c==8){
                                            printf("    >Banco de Couro\n");
                                        }
                                        if(c==9){
                                            printf("    >Rodas\n");
                                        }
                                        if(c==10){
                                            printf("    >Basico\n\n");
                                        }
                                    }
                                    c=c+1;
                                }while(c <= 10);
                                c=0;
                                e=e+1;
                        }while(e<Cadastro_carro[d].opicionais[10]);
                        printf("\nPreco compra: %f\n\n\n",Cadastro_carro[d].precovenda);
                    }
                    e=0;
                }while(j<Cadastro_carro[d].opicionais[10]);
            d=d+1;
            }while(d<quant);
            system("pause");
}
void ListaAno(TIPOCADASTROCARRO Cadastro_carro[500],int quant){
int i, j;

    for(i=0;i<quant;i++) {
        for(j=0;j<quant;j++) {
            if(Cadastro_carro[j].Anodefabricacao > Cadastro_carro[i].Anodefabricacao) { //compara e organiza pela fabricação do veiculo
                Troca(&Cadastro_carro[j],&Cadastro_carro[i]);
              }
            }
        }
int d=0,c=0,e=0;
do{
    printf("Fabricante: %s\n",Cadastro_carro[d].Fabricante);
    printf("Modelo: %s\n",Cadastro_carro[d].Modelo);
    printf("Placa: %s\n",Cadastro_carro[d].placa);
    printf("Ano de Fabricacao: %d\n",Cadastro_carro[d].Anodefabricacao);
    printf("Combustivel: %s\n",Cadastro_carro[d].combustivel);
    printf("Cor: %s\n",Cadastro_carro[d].Cor);
    printf("Opicionais:\n");
    e=0;
    do{
        c=1;
        do{
            if(Cadastro_carro[d].opicionais[e]==c){
                if(c==1){
                    printf("    >Ar Condicionado\n");
                }
                if(c==2){
                    printf("    >Trava Eletrica\n");
                }
                if(c==3){
                    printf("    >Direcao Hidraulica\n");
                }
                if(c==4){
                    printf("    >Alarme\n");
                }
                if(c==5){
                    printf("    >Vidro Eletrico\n");
                }
                if(c==6){
                    printf("    >Cambio Automatico\n");
                }
                if(c==7){
                    printf("    >Air Bag\n");
                }
                if(c==8){
                    printf("    >Banco de Couro\n");
                }
                if(c==9){
                    printf("    >Rodas\n");
                }
                if(c==10){
                    printf("    >Basico\n\n");
                }
            }
                c=c+1;
            }while(c < 10);
            c=0;
            e=e+1;
        }while(e<Cadastro_carro[d].opicionais[10]);
    printf("\nPreco compra: %f\n\n\n",Cadastro_carro[d].precovenda);
d=d+1;
}while(d<quant);
system("pause");
}
int validaCPF(char stringCPF[12]){
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
int ctoi(char ch){
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
void endereco(TIPOCLIENTE cadastro_cliente[500],int c){
    system("cls");
    printf("Informe o Bairro\n\n");                         //recebendo indereço
    scanf("%s[^\n]",cadastro_cliente[c].endereco.bairro);
    system("cls");
    printf("Informe a rua\n\n");
    scanf("%s[^\n]",cadastro_cliente[c].endereco.rua);
    system("cls");
    printf("Informe o numero da casa\n\n");
    scanf("%d",&cadastro_cliente[c].endereco.nrua);
    system("cls");
    do{
        printf("Informe o CEP no formato '79999-999'\n\n"); //validação de cep
        scanf("%s",cadastro_cliente[c].endereco.Cep);
        if((cadastro_cliente[c].endereco.Cep[0]<48 || cadastro_cliente[c].endereco.Cep[0] > 57) ||
           (cadastro_cliente[c].endereco.Cep[1]<48 || cadastro_cliente[c].endereco.Cep[1] > 57) ||
           (cadastro_cliente[c].endereco.Cep[2]<48 || cadastro_cliente[c].endereco.Cep[2] > 57) ||
           (cadastro_cliente[c].endereco.Cep[3]<48 || cadastro_cliente[c].endereco.Cep[3] > 57) ||
           (cadastro_cliente[c].endereco.Cep[4]<48 || cadastro_cliente[c].endereco.Cep[4] > 57) ||
           (cadastro_cliente[c].endereco.Cep[5]!= 45)||
           (cadastro_cliente[c].endereco.Cep[6]<48 || cadastro_cliente[c].endereco.Cep[5] > 57) ||
           (cadastro_cliente[c].endereco.Cep[7]<48 || cadastro_cliente[c].endereco.Cep[6] > 57) ||
           (cadastro_cliente[c].endereco.Cep[8]<48 || cadastro_cliente[c].endereco.Cep[7] > 57) ||
           (cadastro_cliente[c].endereco.Cep[9]!= '\0')){
           printf("Formato Invalido\a\a\n\n");
           system("pause");
           }
    }while((cadastro_cliente[c].endereco.Cep[0]<48 || cadastro_cliente[c].endereco.Cep[0] > 57) ||
           (cadastro_cliente[c].endereco.Cep[1]<48 || cadastro_cliente[c].endereco.Cep[1] > 57) ||
           (cadastro_cliente[c].endereco.Cep[2]<48 || cadastro_cliente[c].endereco.Cep[2] > 57) ||
           (cadastro_cliente[c].endereco.Cep[3]<48 || cadastro_cliente[c].endereco.Cep[3] > 57) ||
           (cadastro_cliente[c].endereco.Cep[4]<48 || cadastro_cliente[c].endereco.Cep[4] > 57) ||
           (cadastro_cliente[c].endereco.Cep[5]!= 45)||
           (cadastro_cliente[c].endereco.Cep[6]<48 || cadastro_cliente[c].endereco.Cep[5] > 57) ||
           (cadastro_cliente[c].endereco.Cep[7]<48 || cadastro_cliente[c].endereco.Cep[6] > 57) ||
           (cadastro_cliente[c].endereco.Cep[8]<48 || cadastro_cliente[c].endereco.Cep[7] > 57) ||
           (cadastro_cliente[c].endereco.Cep[9]!= '\0'));
}
void cadastrocpf(TIPOCLIENTE cadastro_cliente[500],int c){
char cpf[14];
int d=0;
    do{
                system("cls");
                printf("Informe o nome do cliente a ser cadastrado\n\n"); //leitura nome de cadastro de cliente
                scanf("%s[^\n]",cadastro_cliente[c].nome);
            do{
                system("cls");
                printf("Informe o CPF somente numeros\n\n");
                scanf("%s",cpf);
            if((cpf[0]<48)||(cpf[0]>57)||
           (cpf[1]<48)||(cpf[1]>57)||
           (cpf[2]<48)||(cpf[2]>57)||
           (cpf[3]<48)||(cpf[3]>57)||
           (cpf[4]<48)||(cpf[4]>57)||
           (cpf[5]<48)||(cpf[5]>57)||
           (cpf[6]<48)||(cpf[6]>57)||
           (cpf[7]<48)||(cpf[7]>57)||
           (cpf[8]<48)||(cpf[8]>57)||
           (cpf[9]<48)||(cpf[9]>57)||                   //validação de cpf
           (cpf[10]<48)||(cpf[10]>57)||
           (cpf[11]!='\0')){
                        printf("Digite no formato indicado\n\n");
                        system("pause");
                        }
            }while((cpf[0]<48)||(cpf[0]>57)||
           (cpf[1]<48)||(cpf[1]>57)||
           (cpf[2]<48)||(cpf[2]>57)||
           (cpf[3]<48)||(cpf[3]>57)||
           (cpf[4]<48)||(cpf[4]>57)||
           (cpf[5]<48)||(cpf[5]>57)||
           (cpf[6]<48)||(cpf[6]>57)||
           (cpf[7]<48)||(cpf[7]>57)||
           (cpf[8]<48)||(cpf[8]>57)||
           (cpf[9]<48)||(cpf[9]>57)||
           (cpf[10]<48)||(cpf[10]>57)||
           (cpf[11]!='\0'));
            if(validaCPF(cpf)){
                strcpy(cadastro_cliente[c].cpf,cpf);
            }else{
                printf("CPF invalido!\a\a\n\n");
                system("pause");
                d=1;
            }
    }while(d!=0);
}
void cidade(TIPOCLIENTE cadastro_cliente[500],int c){
int menu=0,menu1=0,menu2=0;

        do{
            system("cls");                                                                  //regioes a serem digitados
            printf("Escolha umas das regioes abaixo\n\n");
            printf("1-Norte\n2-Nordeste\n3-Centro oeste\n4-Sudeste\n5-Sul\n\n");
            scanf("%d",&menu);
            if(menu<1 || menu>5){
                printf("Opcao Invalida!\a\n\n");
                system("pause");
            }
        }while(menu<1 || menu>5);
        if(menu==1){
            do{
                system("cls");
                printf("Escolha um dos estados a Baixo\n\n");
                printf("1-Amazonas\n2-Para\n3-Tocantins\n\n");                      //estados
                scanf("%d",&menu1);
            if(menu1<1 || menu1>3){
                printf("Opcao Invalida!\a\n\n");
                system("pause");
            }
            }while(menu1<1 || menu1 > 3);
            if(menu1==1){
                strcpy(cadastro_cliente[c].endereco.estado,"Amazonas");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Manaus\n2-Parintins\n\n");
                    scanf("%d",&menu2);                                                 //cidades
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Manaus");
                    endereco(cadastro_cliente,c);                              //chama cadastro cliente
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Parintins");
                    endereco(cadastro_cliente,c);
                }
            }
            if(menu1==2){
                strcpy(cadastro_cliente[c].endereco.estado,"Para");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Belem\n2-Capanema\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Belem");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Capanema");
                    endereco(cadastro_cliente,c);
                }
            }
            if(menu1==3){
            strcpy(cadastro_cliente[c].endereco.estado,"Tocantins");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Palmas\n2-Alvorada\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Palmas");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Alvorada");
                    endereco(cadastro_cliente,c);
                }

            }
        }
        if(menu==2){
            do{
                system("cls");
                printf("Escolha um dos estados a Baixo\n\n");
                printf("1-Piaui\n2-Pernambuco\n3-Bahia\n\n");
                scanf("%d",&menu1);
            if(menu1<1 || menu1>3){
                printf("Opcao Invalida!\a\n\n");
                system("pause");
            }
            }while(menu1<1 || menu1 > 3);
            if(menu1==1){
                strcpy(cadastro_cliente[c].endereco.estado,"Piaui");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Teresina\n2-Bom Jesus\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Teresina");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Bom Jesus");
                    endereco(cadastro_cliente,c);
                }

            }
            if(menu1==2){
                strcpy(cadastro_cliente[c].endereco.estado,"Pernambuco");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Recife\n2-Olinda\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Recife");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Olinda");
                    endereco(cadastro_cliente,c);
                }
            }
            if(menu1==3){
                strcpy(cadastro_cliente[c].endereco.estado,"Bahia");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Salvador\n2-Botupora\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Salvador");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Botupora");
                    endereco(cadastro_cliente,c);
                }

            }
        }
        if(menu==3){
            do{
                system("cls");
                printf("Escolha um dos estados a Baixo\n\n");
                printf("1-Mato Grosso\n2-Mato Grosso do Sul\n3-Goias\n\n");
                scanf("%d",&menu1);
            if(menu1<1 || menu1>3){
                printf("Opcao Invalida!\a\n\n");
                system("pause");
            }
            }while(menu1<1 || menu1 > 3);
            if(menu1==1){
                strcpy(cadastro_cliente[c].endereco.estado,"Mato Grosso");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Cuiaba\n2-Alto Boa Vista\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Cuiaba");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Alto Boa Vista");
                    endereco(cadastro_cliente,c);
                }
            }
            if(menu1==2){
                    strcpy(cadastro_cliente[c].endereco.estado,"Mato Grosso do Sul");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Campo Grande\n2-Dourados\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Campo Grande");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Dourados");
                    endereco(cadastro_cliente,c);
                }

            }
            if(menu1==3){
                strcpy(cadastro_cliente[c].endereco.estado,"Goias");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Goiania\n2-Anapolis\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Goiania");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Anapolis");
                    endereco(cadastro_cliente,c);
                }
            }
        }
        if(menu==4){
            do{
                system("cls");
                printf("Escolha um dos estados a Baixo\n\n");
                printf("1-Sao Paulo\n2-Rio de Janeiro\n3-Minas Gerais\n\n");
                scanf("%d",&menu1);
            if(menu1<1 || menu1>3){
                printf("Opcao Invalida!\a\n\n");
                system("pause");
            }
            }while(menu1<1 || menu1 > 3);
            if(menu1==1){
            strcpy(cadastro_cliente[c].endereco.estado,"Sao Paulo");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Sao Paulo\n2-Guararapes\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Sao Paulo");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Guararapes");
                    endereco(cadastro_cliente,c);
                }

            }
            if(menu1==2){
            strcpy(cadastro_cliente[c].endereco.estado,"Rio de Janeiro");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Rio de Janeiro\n2-Paraty\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
            if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Rio de Janeiro");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Paraty");
                    endereco(cadastro_cliente,c);
                }
            }
            if(menu1==3){
            strcpy(cadastro_cliente[c].endereco.estado,"Minas Gerais");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Belo Horizonte\n2-Angelandia\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Belo Horizonte");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Angelandia");
                    endereco(cadastro_cliente,c);
                }
            }
        }
        if(menu==5){
            do{
                system("cls");
                printf("Escolha um dos estados a Baixo\n\n");
                printf("1-Parana\n2-Rio Grande do Sul\n3-Santa Catarina\n\n");
                scanf("%d",&menu1);
            if(menu1<1 || menu1>3){
                printf("Opcao Invalida!\a\n\n");
                system("pause");
            }
            }while(menu1<1 || menu1 > 3);
            if(menu1==1){
            strcpy(cadastro_cliente[c].endereco.estado,"Parana");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Curitiba\n2-Toledo\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Curitiba");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Toledo");
                    endereco(cadastro_cliente,c);
                }

            }
            if(menu1==2){
            strcpy(cadastro_cliente[c].endereco.estado,"Rio Grande do Sul");
                do{
                    system("cls");
                    printf("Escolha uma das cidades a Baixo\n\n");
                    printf("1-Porto Alegre\n2-Barra Funda\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Porto Alegre");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Barra Funda");
                    endereco(cadastro_cliente,c);
                }
            }
            if(menu1==3){
            strcpy(cadastro_cliente[c].endereco.estado,"Santa Catarina");
                do{
                    system("cls");
                    printf("Escolha um dos estados a Baixo\n\n");
                    printf("1-Florianopolis\n2-Aurora\n\n");
                    scanf("%d",&menu2);
                    if(menu2<1 || menu2>2){
                        printf("Opcao Invalida!\a\n\n");
                        system("pause");
                    }
                }while(menu2<1 || menu2 > 2);
                if(menu2==1){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Florianopolis");
                    endereco(cadastro_cliente,c);
                }
                if(menu2==2){
                    strcpy(cadastro_cliente[c].endereco.cidade,"Aurora");
                    endereco(cadastro_cliente,c);
                }
            }
        }

}
void telefone(TIPOCLIENTE cadastro_cliente[500],int c){
        do{
            system("cls");
            printf("Informe O telefone residencial ' DD*3333-3333 '\n\n");
            scanf("%s",cadastro_cliente[c].telefone);
            if(
           (cadastro_cliente[c].telefone[0]<48 || cadastro_cliente[c].telefone[0] > 57) ||
           (cadastro_cliente[c].telefone[1]<48 || cadastro_cliente[c].telefone[1] > 57) ||
           (cadastro_cliente[c].telefone[2]!= 42) ||
           (cadastro_cliente[c].telefone[3]<48 || cadastro_cliente[c].telefone[3] > 57) ||
           (cadastro_cliente[c].telefone[4]<48 || cadastro_cliente[c].telefone[4] > 57) ||
           (cadastro_cliente[c].telefone[5]<48 || cadastro_cliente[c].telefone[5] > 57) ||    //validação de numeros e ordens no telefone
           (cadastro_cliente[c].telefone[6]<48 || cadastro_cliente[c].telefone[6] > 57) ||
            (cadastro_cliente[c].telefone[7]!= 45)||
           (cadastro_cliente[c].telefone[8]<48 || cadastro_cliente[c].telefone[8] > 57) ||
           (cadastro_cliente[c].telefone[9]<48 || cadastro_cliente[c].telefone[9] > 57) ||
           (cadastro_cliente[c].telefone[10]<48 || cadastro_cliente[c].telefone[10] > 57) ||
           (cadastro_cliente[c].telefone[11]<48 || cadastro_cliente[c].telefone[11] > 57) ||
           (cadastro_cliente[c].telefone[12]!= '\0')){
           printf("Formato Invalido\n\n");
           system("pause");
           }
           }while(
           (cadastro_cliente[c].telefone[0]<48 || cadastro_cliente[c].telefone[0] > 57) ||
           (cadastro_cliente[c].telefone[1]<48 || cadastro_cliente[c].telefone[1] > 57) ||
           (cadastro_cliente[c].telefone[2]!= 42) ||
           (cadastro_cliente[c].telefone[3]<48 || cadastro_cliente[c].telefone[3] > 57) ||
           (cadastro_cliente[c].telefone[4]<48 || cadastro_cliente[c].telefone[4] > 57) ||
           (cadastro_cliente[c].telefone[5]<48 || cadastro_cliente[c].telefone[5] > 57) ||
           (cadastro_cliente[c].telefone[6]<48 || cadastro_cliente[c].telefone[6] > 57) ||
            (cadastro_cliente[c].telefone[7]!= 45)||
           (cadastro_cliente[c].telefone[8]<48 || cadastro_cliente[c].telefone[8] > 57) ||
           (cadastro_cliente[c].telefone[9]<48 || cadastro_cliente[c].telefone[9] > 57) ||
           (cadastro_cliente[c].telefone[10]<48 || cadastro_cliente[c].telefone[10] > 57) ||
           (cadastro_cliente[c].telefone[11]<48 || cadastro_cliente[c].telefone[11] > 57) ||
           (cadastro_cliente[c].telefone[12]!= '\0'));
}
void celular(TIPOCLIENTE cadastro_cliente[500],int c){
do{
            system("cls");
            printf("Informe O celula no formato ' DD*3333-3333 '\n\n");
            scanf("%s",cadastro_cliente[c].celular);
            if(
           (cadastro_cliente[c].celular[0]<48 || cadastro_cliente[c].celular[0] > 57) ||
           (cadastro_cliente[c].celular[1]<48 || cadastro_cliente[c].celular[1] > 57) ||
           (cadastro_cliente[c].celular[2]!= 42) ||
           (cadastro_cliente[c].celular[3]<48 || cadastro_cliente[c].celular[3] > 57) ||
           (cadastro_cliente[c].celular[4]<48 || cadastro_cliente[c].celular[4] > 57) ||
           (cadastro_cliente[c].celular[5]<48 || cadastro_cliente[c].celular[5] > 57) ||
           (cadastro_cliente[c].celular[6]<48 || cadastro_cliente[c].celular[6] > 57) ||
            (cadastro_cliente[c].celular[7]!= 45)||
           (cadastro_cliente[c].celular[8]<48 || cadastro_cliente[c].celular[8] > 57) ||
           (cadastro_cliente[c].celular[9]<48 || cadastro_cliente[c].celular[9] > 57) ||
           (cadastro_cliente[c].celular[10]<48 || cadastro_cliente[c].celular[10] > 57) ||
           (cadastro_cliente[c].celular[11]<48 || cadastro_cliente[c].celular[11] > 57) ||
           (cadastro_cliente[c].celular[12]!= '\0')){
           printf("Formato Invalido\n\n");
           system("pause");
           }
           }while((cadastro_cliente[c].celular[0]<48 || cadastro_cliente[c].celular[0] > 57) ||
           (cadastro_cliente[c].celular[1]<48 || cadastro_cliente[c].celular[1] > 57) ||
           (cadastro_cliente[c].celular[2]!= 42) ||
           (cadastro_cliente[c].celular[3]<48 || cadastro_cliente[c].celular[3] > 57) ||
           (cadastro_cliente[c].celular[4]<48 || cadastro_cliente[c].celular[4] > 57) ||
           (cadastro_cliente[c].celular[5]<48 || cadastro_cliente[c].celular[5] > 57) ||
           (cadastro_cliente[c].celular[6]<48 || cadastro_cliente[c].celular[6] > 57) ||
            (cadastro_cliente[c].celular[7]!= 45)||
           (cadastro_cliente[c].celular[8]<48 || cadastro_cliente[c].celular[8] > 57) ||
           (cadastro_cliente[c].celular[9]<48 || cadastro_cliente[c].celular[9] > 57) ||
           (cadastro_cliente[c].celular[10]<48 || cadastro_cliente[c].celular[10] > 57) ||
           (cadastro_cliente[c].celular[11]<48 || cadastro_cliente[c].celular[11] > 57) ||
           (cadastro_cliente[c].celular[12]!= '\0'));
}
void Cadastrocliente(TIPOCLIENTE cadastro_cliente[500],int *q){
int menu=0,c=0,d=0;

    do{
            *q=*q+1;
            c=*q;
            c=*q-1;
            cadastrocpf(cadastro_cliente, c);               //chama as funçoes acima
            cidade(cadastro_cliente, c);
            telefone(cadastro_cliente,c);
            celular(cadastro_cliente,c);
            do{
                system("cls");
                printf("Informe sua renda mensal\n\n");
                scanf("%f",&cadastro_cliente[c].salario);
                if(cadastro_cliente[c].salario < 1){
                    printf("Informe somente numero positivos\n\n\a\a");
                }
            }while(cadastro_cliente[c].salario < 1);
            system("cls");
            printf("Deseja Cadastrar mais clientes\n\n");
            printf("1-Sim\n2-Nao\n\n");
            scanf("%d",&menu);

    }while(menu != 2);
}
void excluicadastrocliente(TIPOCLIENTE cadastro_cliente[500],int *q){
char cpf[13];
int i=0,menu=0;
    do{
        printf("Informe a cpf do cliente a ser excluido\n");
        scanf("%s",cpf);
        do{
            if(strcmp(cpf,cadastro_cliente[i].cpf) == 0 ){
                cadastro_cliente[i].cpf[0] = '0';
                *q = *q-1;                                                                  //exclusao de cadastro igual carro
                Troca(&cadastro_cliente[i],&cadastro_cliente[*q]);
                i=500;
            }
            i=i+1;
        }while(i<=500);
        do{
            printf("Deseja excluir mais algum cadastro\n\n");
            scanf("%d",&menu);
        }while(menu < 1 || menu > 2);
    }while(menu!=2);
}
void ListaNomecliente(TIPOCLIENTE cadastro_cliente[500],int quant2) {
    int i, j;

    for(i=0;i<quant2;i++) {
        for(j=0;j<quant2;j++) {                                                             //compara e organiza
            if(strcmp(cadastro_cliente[j].nome,cadastro_cliente[i].nome)>0) {
                Troca(&cadastro_cliente[j],&cadastro_cliente[i]);
            }
        }
    }
    printf("%d",quant2);
int d=0;
    system("cls");
    do{
        printf("Nome: %s\n",cadastro_cliente[d].nome);
        printf("CPF: %s\n",cadastro_cliente[d].cpf);
        printf("Endereco:\n");
        printf("        Rua: %s\n",cadastro_cliente[d].endereco.rua);
        printf("        N: %d\n",cadastro_cliente[d].endereco.nrua);
        printf("        Bairro: %s\n",cadastro_cliente[d].endereco.bairro);
        printf("        Cidade: %s\n",cadastro_cliente[d].endereco.cidade);
        printf("        Estado: %s\n",cadastro_cliente[d].endereco.estado);
        printf("        CEP: %s\n",cadastro_cliente[d].endereco.Cep);
        printf("Telefone Residencial: %s\n",cadastro_cliente[d].telefone);
        printf("Telefone Celular: %s\n",cadastro_cliente[d].celular);
        printf("Renda Mensal: %f\n\n",cadastro_cliente[d].salario);
        d=d+1;
    }while(d<quant2);
    system("pause");
}
void ListaNomeclienterenda(TIPOCLIENTE cadastro_cliente[500],int quant2) {
    int i, j;

    for(i=0;i<quant2;i++) {
        for(j=0;j<quant2;j++) {
            if(strcmp(cadastro_cliente[j].nome,cadastro_cliente[i].nome)>0) {
                Troca(&cadastro_cliente[j],&cadastro_cliente[i]);
                if(strcmp(cadastro_cliente[j].nome,cadastro_cliente[i].nome)== 0) {
                    if(cadastro_cliente[j].salario>cadastro_cliente[i].salario){
                        Troca(&cadastro_cliente[j],&cadastro_cliente[i]);
                    }
                }
            }
        }
    }
int d=0;
    system("cls");
    do{
        printf("Nome: %s\n",cadastro_cliente[d].nome);
        printf("CPF: %s\n",cadastro_cliente[d].cpf);
        printf("Endereco:\n");
        printf("        Rua: %s\n",cadastro_cliente[d].endereco.rua);
        printf("        N: %d\n",cadastro_cliente[d].endereco.nrua);
        printf("        Bairro: %s\n",cadastro_cliente[d].endereco.bairro);
        printf("        Cidade: %s\n",cadastro_cliente[d].endereco.cidade);
        printf("        Estado: %s\n",cadastro_cliente[d].endereco.estado);
        printf("        CEP: %s\n",cadastro_cliente[d].endereco.Cep);
        printf("Telefone Residencial: %s\n",cadastro_cliente[d].telefone);
        printf("Telefone Celular: %s\n",cadastro_cliente[d].celular);
        printf("Renda Mensal: %f\n\n",cadastro_cliente[d].salario);
        d=d+1;
    }while(d<quant2);
        system("pause");
}
void cadastrovenda(TIPOVENDA *venda,TIPOCADASTROCARRO Cadastro_carro[500],TIPOCLIENTE cadastro_cliente [500],int *q3,int*q,int *q2){
char placa[9];
char cpf[14];
int i=0,c=0,j=0;
j=*q3;
    do{
        system("cls");
        printf("Informe A Placa do carro a ser vendido no formato 'AAA-1111'\n\n");
        scanf("%s",placa);              //placa de carro ja cadastro
        do{
            if(strcmp(Cadastro_carro[i].placa,placa)==0){ //copia cadastro do carro para vendido
                *q3=*q3+1;
                venda[j].VENDIDO=Cadastro_carro[i];
                Cadastro_carro[i].placa[0] = '0'; //zera cadastro
                *q = *q-1;//ajusta contador cadastro
                Troca(&Cadastro_carro[i],&Cadastro_carro[*q]); //troca cadastro apagado pelo ultimo cadastro
            c=1;
            }
        i=i+1;
        }while(i<=500);
        if(c=0){
            system("cls");
            printf("Placa nao cadastrada\n\n");
            system("pause");
        }
    }while(c!=0);
    c=0;
    i=0;
    do{
        system("cls");
        printf("Informe o cpf do cliente\n\n");
        scanf("%s",cpf);   //cpf de cliente ja cadastrado
        do{
            if(strcmp(cadastro_cliente[i].cpf,cpf)==0){         //copia cadastro do cliente para vendido
                venda[j].CLIENTEVENDA=cadastro_cliente[i];
                c=1;
                cadastro_cliente[i].cpf[0] = '0';
                *q2 = *q2-1;                                                                  //exclusao de cadastro do cliente
                Troca(&cadastro_cliente[i],&cadastro_cliente[*q2]);
            }
        i=i+1;
        }while(i<=500);
        if(c=0){
            system("cls");
            printf("CPF nao cadastrado\n\n");
            system("pause");
        }
    }while(c!=0);
    do{
        system("cls");                                                          //data de venda
        printf("Informe o dia\n\n");
        scanf("%d",&venda[j].data_venda.dia);
        if(venda[j].data_venda.dia<1 || venda[j].data_venda.dia>30){
            printf("Dia Invalido\n\n");
        }
    }while(venda[j].data_venda.dia<1 || venda[j].data_venda.dia>30);
    do{
        system("cls");
        printf("Informe o mes\n\n");
        scanf("%d",&venda[j].data_venda.mes);
        if(venda[j].data_venda.mes<1 || venda[j].data_venda.mes>12){
            printf("mes Invalido\n\n");
        }
    }while(venda[j].data_venda.mes<1 || venda[j].data_venda.mes>12);
    do{
        system("cls");
        printf("Informe o ano\n\n");
        scanf("%d",&venda[j].data_venda.ano);
        if(venda[j].data_venda.ano<1){
            printf("Ano Invalido\n\n");
        }
    }while(venda[j].data_venda.ano<1);
    do{                                                                     //valor da venda
        printf("Informe o valor da venda\n\n");
        scanf("%d",&venda[j].venda);
    }while(venda[j].venda <1);
}
void excluivenda(TIPOVENDA Cadastro_venda[500],int *q){
char placaex[8];
int i=0,menu=0;
    do{
        printf("Informe a placa do veiculo a ser excluido\n");
        printf("favor informar a placa no modelo: 'AAA-1111'\n\n");
        scanf("%s",placaex);
        do{
            if(strcmp(placaex,Cadastro_venda[i].VENDIDO.placa) == 0 ){
                Cadastro_venda[i].VENDIDO.placa[0] = '0';
                *q = *q-1;
                Troca(&Cadastro_venda[i],&Cadastro_venda[*q]);
                i=500;
            }
            i=i+1;
        }while(i<=500);
        do{
            printf("Deseja excluir mais algum cadastro\n\n");
            scanf("%d",&menu);
        }while(menu < 1 || menu > 2);
    }while(menu!=2);
}
void Listavenda(TIPOVENDA Cadastro_venda[500],int quant3) {
    int i, j;

    for(i=0;i<quant3;i++) {
        for(j=0;j<quant3;j++) {
            if(strcmp(Cadastro_venda[j].VENDIDO.Fabricante,Cadastro_venda[i].VENDIDO.Fabricante)>0) { //organiza e imprimi por fabricante
                Troca(&Cadastro_venda[j],&Cadastro_venda[i]);
            }
        }
    }
int d=0;
    system("cls");
    do{
        printf("Nome Cliente: %s\n",Cadastro_venda[d].CLIENTEVENDA.nome);
        printf("Fabricante: %s\n",Cadastro_venda[d].VENDIDO.Fabricante);
        printf("Modelo: %s\n",Cadastro_venda[d].VENDIDO.Modelo);
        printf("Placa: %s\n",Cadastro_venda[d].VENDIDO.placa);
        printf("Ano de Fabricacao: %d\n",Cadastro_venda[d].VENDIDO.Anodefabricacao);
        d=d+1;
    }while(d<quant3);
    system("pause");
}
void Listavendaano(TIPOVENDA Cadastro_venda[500],int quant3){
int i, j;
    for(i=0;i<quant3;i++) {
        for(j=0;j<quant3;j++) {
            if(Cadastro_venda[j].VENDIDO.Anodefabricacao>Cadastro_venda[i].VENDIDO.Anodefabricacao) {
                Troca(&Cadastro_venda[j],&Cadastro_venda[i]);
            }
        }
    }
int d=0;
    do{
        printf("Nome Cliente: %s\n",Cadastro_venda[d].CLIENTEVENDA.nome);
        printf("Fabricante: %s\n",Cadastro_venda[d].VENDIDO.Fabricante);
        printf("Modelo: %s\n",Cadastro_venda[d].VENDIDO.Modelo);
        printf("Placa: %s\n",Cadastro_venda[d].VENDIDO.placa);
        printf("Ano de Fabricacao: %d\n",Cadastro_venda[d].VENDIDO.Anodefabricacao);
        d=d+1;
    }while(d<quant3);
    system("pause");
}
void relacaovenda(TIPOVENDA Cadastro_venda[500],int quant3){
int venda=0;
int i=0;
i=quant3;
i=i-1;
    do{
       venda=Cadastro_venda[i].venda+venda; //valor total de vendidos
       i=i-1;
    }while(i>=0);
    system("cls");
    printf("Foram Vendidos: %d\n",quant3);
    printf("Preco total de venda:R$ %d\n\n",venda);
    system("pause");
}
void lucro(TIPOVENDA Cadastro_venda[500],int quant3){
int venda=0;
int lucr=0;
int i=0;
i=quant3;
i=i-1;
    do{
       venda=Cadastro_venda[i].venda+venda;             //total compra
       lucr=Cadastro_venda[i].VENDIDO.precovenda+lucr; //lucro
       i=i-1;
    }while(i>=0);
    lucr=venda-lucr;
    system("cls");
    printf("Foram Vendidos: %d\n",quant3);
    printf("Preco total de venda:R$ %d\n",venda);
    printf("E o lucro total foi:R$ %d\n\n",lucr);
    system("pause");
}
void carre(){
   int i, j;

   system ("cls");

printf("\n\n                               Carregando Sistema: \n\n");

   for (i = 0; i <= 70; i++)
   {
      printf ("  %d%%\r", i);
      fflush (stdout);

      for (j = 0; j < i; j++)
      {
         if (!j) // Da espaco na barra pra nao enconstar na borda da tela
           printf ("  ");

         printf ("%c", 219);
         Sleep(3);
      }
   }
    system ("cls");
   printf ("\n\nEntrando...");
   Sleep (2000);
   system ("pause");

   return 0;
}
int main(){
    system("color 3f");
    int quant=0;
    int quant2=0;
    int quant3=0;
    int menu=0,menu1=0;
    TIPOCADASTROCARRO Cadastro_carro[500];
    TIPOCLIENTE cadastro_cliente [500];
    TIPOVENDA Cadastro_venda [500];
    carre();
    zeracadastro(Cadastro_carro,cadastro_cliente,Cadastro_venda);
    system("cls");
    printf("===========================================================================\n||                           Concessionaria                              ||\n||                                                                       ||\n==========================================================================\n\n");
    printf("              >Precione ENTER para acessar as opcoes\n\n");
    system("pause");
    do{
        do{
            system("cls");
            printf("===========================================================================\n||                           Concessionaria                              ||\n||                                                                       ||\n==========================================================================\n\n");
            printf("            ESCOLHA UMA DAS OPCOES ABAIXO\n\n");
            printf("1> Carro\n2> Cliente\n3> Venda\n4> Sair\n\n");
            scanf("%d",&menu);
            if(menu<1 || menu>4){
                printf("Opcao Invalida!!\a\a\n");
                system("pause");
            }
        }while(menu<1 || menu>4);
    if(menu==1){
        do{
            do{
                system("cls");
                printf("==========================================================================\n||                           Concessionaria                              ||\n||                                                                       ||\n==========================================================================\n\n");
                printf("1> Cadastro de Carro\n2> Excluir Carro do Cadastro\n3> Listar Carros Disponivel para venda por Fabricante\n4> Listar carros Disponivel para venda por opicionais\n5> Listar carros Disponivel para venda por ano de Fabricacao\n6> Voltar ao menu principal\n\n");
                scanf("%d",&menu1);
                if(menu1 < 1 || menu1 >6){
                    printf("Opcao Invalida!!\a\a\n");
                    system("pause");
                }
            }while(menu1 < 1 || menu1 > 6);
            if(menu1==1){
                Cadastro_de_carro(Cadastro_carro,&quant);
            }
            if(menu1==2){
                excluicadastro(Cadastro_carro,&quant);
            }
            if(menu1==3){
                ListaFabricante(Cadastro_carro,quant);
            }
            if(menu1==4){
                Listaopicionais(Cadastro_carro,quant);
            }
            if(menu1==5){
                ListaAno(Cadastro_carro,quant);
            }
        }while(menu1!=6);
    }
    if(menu==2){
        do{
            do{
                system("cls");
                printf("==========================================================================\n||                           Concessionaria                              ||\n||                                                                       ||\n==========================================================================\n\n");
                printf("1> Cadastro de Cliente\n2> Excluir Cliente do Cadastro\n3> Listar Cliente por nome\n4> Listar Cliente por nome e renda mensal\n5> Voltar ao menu principal\n\n");
                scanf("%d",&menu1);
                if(menu1 < 1 || menu1 >5){
                    printf("Opcao Invalida!!\a\a\n");
                    system("pause");
                }
            }while(menu1 < 1 || menu1 > 5);
            if(menu1==1){
                Cadastrocliente(cadastro_cliente,&quant2);
            }
            if(menu1==2){
                excluicadastrocliente(cadastro_cliente,&quant2);
            }
            if(menu1==3){
                ListaNomecliente(cadastro_cliente,quant2);
            }
            if(menu1==4){
                ListaNomeclienterenda(cadastro_cliente,quant2);
            }
        }while(menu1!=5);
    }
    if(menu==3){
        do{
            do{
                system("cls");
                printf("==========================================================================\n||                           Concessionaria                              ||\n||                                                                       ||\n==========================================================================\n\n");
                printf("1> Cadastro de Venda\n2> Excluir Venda\n3> Listar carros vendidos por fabricante\n4> Listar os carros vendidos pelo ano de fabricacao\n5> Informar a quantidade de carros vendidos com o valor totalizado dos precos vendidos\n6> lucro total das vendas\n7> Voltar ao menu principal\n\n");
                scanf("%d",&menu1);
                if(menu1 < 1 || menu1 >7){
                    printf("Opcao Invalida!!\a\a\n");
                    system("pause");
                }
            }while(menu1 < 1 || menu1 > 7);
            if(menu1==1){
                cadastrovenda(&Cadastro_venda,Cadastro_carro,cadastro_cliente,&quant3,&quant,&quant2);
            }
            if(menu1==2){
                excluivenda(Cadastro_venda,&quant3);
              }
            if(menu1==3){
                Listavenda(Cadastro_venda,quant3);
            }
            if(menu1==4){
                Listavendaano(Cadastro_venda,quant3);
            }
            if(menu1==5){
                relacaovenda(Cadastro_venda,quant3);
            }
            if(menu1==6){
                lucro(Cadastro_venda,quant3);
            }
        }while(menu1!=7);
    }
}while(menu!=4);

return 0;
}
