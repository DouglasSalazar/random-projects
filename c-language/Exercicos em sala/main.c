#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definicao do tipo de registro
typedef struct TD {
    int dia, mes, ano;
} TIPODATA;

typedef struct TR {
    char nome[50];  // "
    char rg[20];
    float salario;
    int idade;
    char sexo;  //´
    TIPODATA data_nascimento;
} TIPOREG;

typedef struct TC {
    TIPOREG Funcionario[100];
    int quant;
} TIPOCADASTRO;

//---------------------------------------------
//Inicializa o controle do cadastro com ZERO
void InicializaCadastro(TIPOCADASTRO *F) {
    F->quant = -1;
}
//---------------------------------------------
//Cadastra dados de funcionarios ate que nome
//nao vazio
void LeFuncionarios(TIPOCADASTRO *F) {
    char nome[50];

    printf("\n\nCadastro de funcionarios, Ao digite 0 em NOME o cadastro sera finalizado\n\n");
    do {
        printf("\nNome: ");
        scanf("%s",nome);
        if( nome[0]!='0' ) {
            F->quant = F->quant + 1;
            strcpy(F->Funcionario[F->quant].nome,nome);
            printf("\nRg: ");
            scanf("%s",F->Funcionario[F->quant].rg);
            printf("\nSalario: ");
            scanf("%f",&F->Funcionario[F->quant].salario);
            printf("\nIdade: ");
            scanf("%d",&F->Funcionario[F->quant].idade);
            printf("\nSexo: ");
            fflush(stdin);
            scanf("%c",&F->Funcionario[F->quant].sexo);
            printf("\nDia nascimento: ");
            scanf("%d",&F->Funcionario[F->quant].data_nascimento.dia);
            printf("\nMes nascimento: ");
            scanf("%d",&F->Funcionario[F->quant].data_nascimento.mes);
            printf("\nAno nascimento: ");
            scanf("%d",&F->Funcionario[F->quant].data_nascimento.ano);
        }
    } while( (nome[0]!= '0') && (F->quant<99) );
}

//---------------------------------------------
//Mostra as informacoes dos funcionarios cadastrados
void ListaFuncionarios(TIPOCADASTRO F) {
    int i;

    printf("\n\nFuncionarios Cadastrados - (%d)",F.quant+1);
    for(i=0;i<=F.quant;i++) {
        printf("\nNome: %s",F.Funcionario[i].nome);
        printf("\nRg: %s",F.Funcionario[i].rg);
        printf("\nSalario: %f",F.Funcionario[i].salario);
        printf("\nIdade: %d",F.Funcionario[i].idade);
        printf("\nSexo: %c",F.Funcionario[i].sexo);
        printf("\nData de Nascimento: %d/%d/%d\n\n",F.Funcionario[i].data_nascimento.dia,F.Funcionario[i].data_nascimento.mes,F.Funcionario[i].data_nascimento.ano);

    }
    printf("\n\n");
}

//---------------------------------------------
//Realiza a troca de conteudo entre duas variaveis
void Troca(TIPOREG *R1, TIPOREG *R2) {
    TIPOREG TEMP;

    TEMP = *R1;
    *R1 = *R2;
    *R2 = TEMP;
}

//---------------------------------------------
//Ordena os funciona rios pelo campo nome
void OrdenaNome(TIPOCADASTRO *F) {
    int i, j;

    for(i=0;i<=F->quant;i++) {
        for(j=0;j<=F->quant;j++) {
            if(strcmp(F->Funcionario[j].nome,F->Funcionario[i].nome)>0) {
                Troca(&F->Funcionario[j],&F->Funcionario[i]);
            }
        }
    }
}
void salariointervalo (TIPOCADASTRO *F, float v1, float v2){
    int c=0,i;
    float salario=0;
    for(i=0; i<= F->quant; i++){
        if (F->Funcionario[i].salario >v1 && F->Funcionario[i].salario < v2){
            printf("\nNome: %s",F->Funcionario[i].nome);
            printf("\nRg: %s",F->Funcionario[i].rg);
            printf("\nSalario: %f",F->Funcionario[i].salario);
            printf("\nIdade: %d",F->Funcionario[i].idade);
            printf("\nSexo: %c",F->Funcionario[i].sexo);
            printf("\nData de Nascimento: %d/%d/%d",F->Funcionario[i].data_nascimento.dia,F->Funcionario[i].data_nascimento.mes,F->Funcionario[i].data_nascimento.ano);
            c++;
            salario = salario + F->Funcionario[i].salario;
            salario= salario/c;
            printf("Media salarios listados %f\n",salario);
         if (F->Funcionario[i].salario <v1 || F->Funcionario[i].salario > v2){
             printf("Valor abaixo e 1000 e acima de 1300\n");
         }
        }
    }
}
void calcimposto (float salario, float juros){
    float imposto=0;

    imposto = salario*(juros/100);
    printf("O imposto cobrado sera de:%f\n",imposto);
}
void imprimeimposto (TIPOCADASTRO F){
    int i;
    for (i=0; i<= F.quant; i++){
        printf("\nNome: %s\n\n",F.Funcionario[i].nome);
        if (F.Funcionario[i].salario <=1000){
            printf("Isento\n");
        }
        if (F.Funcionario[i].salario > 1000 && F.Funcionario[i].salario <= 2000){
           calcimposto(F.Funcionario[i].salario,10);
        }
        if (F.Funcionario[i].salario > 2000 && F.Funcionario[i].salario <= 3500){
           calcimposto(F.Funcionario[i].salario,15);
        }
        if (F.Funcionario[i].salario > 3500){
           calcimposto(F.Funcionario[i].salario,25);
        }
    }
}
void atualizasalario(TIPOCADASTRO *F){
    char rg[20];
    int i;
    float salario=0;
    printf("\n\nEncontre pessoa atraves do rg\n\n");
    scanf("%s",rg);
    for(i=0; i<=F->quant;i++){
        if (strcmp(F->Funcionario[i].rg,rg)== 0){
            do{
                printf("\n\nInforme o novo salario\n\n");
                scanf("%f",&salario);
            }while(F->Funcionario[i].salario<0);
            F->Funcionario[i].salario = salario;
        }
        if (strcmp(F->Funcionario[i].rg,rg) != 0){
            printf("\n\n Rg nao encontrado\n\n");
        }
    }
}
void buscanome (TIPOCADASTRO F, char nome_pesquisa[20],TIPOREG *TEMP){
    int i=-1;
   strcpy(TEMP->nome," ");
    do{
        i++;
        if (F.quant >=i){
            if (strcmp(F.Funcionario[i].nome,nome_pesquisa) == 0){
                *TEMP = F.Funcionario[i];
            }
        }
    }while (i<=F.quant || strcmp(TEMP->nome," ")==0);
}
void listamaraja (TIPOCADASTRO F, TIPOREG *MARAJA){
    int i;
    float sal_maior;

    MARAJA->salario=0;
    sal_maior=0;
    for (i=0;i<=F.quant;i++){
        if(F.Funcionario[i].salario > sal_maior){
            sal_maior = F.Funcionario[i].salario;
            *MARAJA = F.Funcionario[i];
        }
    }
}
void removeregistro(TIPOCADASTRO *F, char rg[20]){
    int i, pos=0;

    for(i=0;i<=F->quant;i++){
        if (strcmp(F->Funcionario[i].rg,rg)==0){
            pos=i;
        }
    }
    if (pos != 0){
        for (i=0;pos+1<=F->quant;i++){
            F->Funcionario[i-1]=F->Funcionario[i];
        }
    F->quant=F->quant-1;
    }
}
int main()
{
    //declaracado de variaveis locais
    TIPOCADASTRO Func;
    TIPOREG Reg;
    TIPOREG Ma;
    char nome_pesquisa [50];
    char rg [20];
    int menu=0;
    InicializaCadastro(&Func);
    do{
        printf("Cadastro de Funcionarios\n\n");
        printf("1-Cadastrar Funcionario\n");
        printf("2-Listar Funcionarios Cadastrados\n");
        printf("3-Listar Funcionarios Cadastrados em Ordem de nome\n");
        printf("4-Imprimir Media Salarial de funcionarios entre 1000 e 1300\n");
        printf("5-Imprimir Imposto sobre o salario do funcionarios\n");
        printf("6-Atualizar Salario\n");
        printf("7-Buscar Funcionario pelo Nome\n");
        printf("8-Funcionario com Maior salario\n");
        printf("9-Remover Cadastro do Sistema\n");
        printf("10-Sair\n");
        scanf("%d",&menu);
    if(menu==1){
        LeFuncionarios(&Func);
        system("pause");
        system("cls");
    }
    if (menu==2){
        ListaFuncionarios(Func);
        system("pause");
        system("cls");
    }
    if(menu==3){
        OrdenaNome(&Func);
        ListaFuncionarios(Func);
        system("pause");
        system("cls");
    }
    if(menu==4){
         salariointervalo (&Func,1000,1300);
        system("pause");
        system("cls");
    }
    if (menu==5){
            imprimeimposto(Func);
            system("pause");
            system("cls");
    }
    if (menu==6){
        atualizasalario(&Func);
        system("pause");
        system("cls");
    }
    if (menu==7){
        printf("\n\nDigite nome a ser pesquisado\n");
        scanf("%s",nome_pesquisa);
        buscanome(Func,nome_pesquisa,&Reg);
    if (strcmp(Reg.nome," ") == 0)
        printf("\n\nCadastro nao encontrado\n");
    else
        printf("\nNome: %s",Reg.nome);
        printf("\nRg: %s",Reg.rg);
        printf("\nSalario: %f",Reg.salario);
        printf("\nIdade: %d",Reg.idade);
        printf("\nSexo: %c",Reg.sexo);
        printf("\nDia Nascimento: %d",Reg.data_nascimento.dia);
        printf("\nMes Nascimento: %d",Reg.data_nascimento.mes);
        printf("\nAno Nascimento: %d\n\n",Reg.data_nascimento.ano);
    system("pause");
    system("cls");
    }
    if(menu==8){
        listamaraja(Func,&Ma);
        if (Ma.salario > 0) {
            printf("\n\nFuncionario com maior salario\n\n");
            printf("\nNome: %s",Ma.nome);
            printf("\nRg: %s",Ma.rg);
            printf("\nSalario: %f",Ma.salario);
            printf("\nIdade: %d",Ma.idade);
            printf("\nSexo: %c",Ma.sexo);
            printf("\nDia Nascimento: %d",Ma.data_nascimento.dia);
            printf("\nMes Nascimento: %d",Ma.data_nascimento.mes);
            printf("\nAno Nascimento: %d\n\n",Ma.data_nascimento.ano);
        }
    system("pause");
    system("cls");
    }
    if (menu ==9){
            printf("\n\nInforme o Rg para procurar o cadastro\n\n");
        scanf("%s",rg);
        removeregistro(&Func,rg);
        system("cls");
        system("pause");
    }
    }while(menu!=10);
    return 0;
}
