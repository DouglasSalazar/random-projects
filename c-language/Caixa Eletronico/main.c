/*Implemente em linguagem C uma solução para:
Você foi contratado para desenvolver um sistema para saques de um caixa
eletrônico que deverá liberar o menor número de cédulas possível para um
valor solicitado pelo cliente. As cédulas armazenadas no caixa são de 1.000,
500, 300, 150, 100, 50, 25, 20, 10, 5, 2 e 1 real.
Sempre que solicitado pelo gerente, o caixa eletrônico pode ser abastecido,
cabendo no máximo 500 cédulas de um a cem reais e para as demais cédulas
no máximo de 50 cédulas, totalizando R$ 204.000,00 reais.
Quando um cliente for sacar, o sistema deve informar a quantidade de cada
cédula liberada.
Para o gerente o sistema deve informar o total sacado, o valor do saldo existente
e a quantidade de cada cédula armazenada no caixa eletrônico, após várias
transações efetuadas.*/

// A SENHA DO ADMINISTRADOR E 1213

//Douglas Correia Salazar RGM
//Michel Roberto de Souza RGM 
//Renan Augusto de Brito Malaguti rgm 
//Data 27/05/2013

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int resp,resp2,resp3,nd,colocarnotas,notas,cont=0,senha;
    long int saque,saquetotal,quardarvalor,valortotalnotas=204000;
    long int n1000=50000,n500=25000,n300=15000,n150=7500,n100=50000,n50=25000,n25=12500,n20=10000,n10=5000,n5=2500,n2=1000,n1=500;
    //menu inical
    do{
    printf("Bem Vindo a nossa Agencia!\n");
    printf("Este Caixa apenas executa Saques\n\n");
        do
        {
            printf("1-Cliente\n");
            printf("2-Administrador\n");
            printf("3-Sair\n");
            scanf ("%i", &resp);
            if ((resp != 1) && (resp != 2)&&(resp != 3)){
                    printf("Opcao Invalida! Por Favor escolher uma das opcoes acima!\n\n\a");
            }
        }while ((resp!=1) && (resp!=2)&&(resp!=3));
            system ("cls");
            if ((resp == 1)){
                do
                    {
                        //aonde será digitado valor a ser sacado
                        do{
                            printf ("Informe o Valor a ser Sacado!\n");
                            scanf ("%li",&saque);
                                if((saque<0)||(saque>204000)){ //verificação do saque
                                    printf("Valor a ser sacado Invalido!\n\a");
                                }
                            if(saque > valortotalnotas){ //verificação se saque e maior do que o valor que esta em caixa
                                printf("Valor indisponivel!\n\a");
                            }
                        }while((saque<0)||(saque>204000));
                            if(valortotalnotas>saque || valortotalnotas==saque){
                                if(n1000>0 &&  n1000<=50000){
                                    if(saque>=1000){ //verificação de entrada paras notas de mil
                                        saquetotal = (saque/1000);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%1000;
                                        n1000 = n1000-(saquetotal*1000);// retirada das notas sacadas do total de notas de mil
                                        if(n1000<0){// verificação em caso da quantidade de notas de mil for negativa
                                            //correção das notas negativas
                                            do{
                                                n1000 = n1000+1000;
                                                cont = cont+1;
                                            }while((n1000<0));
                                            saquetotal = saquetotal - cont;//diminuição de notas de 500 a ser emitidas
                                            saque = saque + (cont*1000);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                        printf("Voce recebera %li notas de R$1000,00\n",saquetotal);
                                    }
                                }
                                if(n500>0 &&  n500<=25000){
                                    if (saque>=500 && saque<1000 || n1000==0){//verificação de entrada paras notas de 500 e se caso quantidades de notas de mil for 0
                                        saquetotal = (saque/500);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%500;
                                        n500 = n500-(saquetotal*500);// retirada das notas sacadas do total de notas de 500
                                        if(n500<0){// verificação em caso da quantidade de notas de 500 for negativa
                                            cont = 0;
                                            //correção das notas negativas
                                            do{
                                                n500 = n500+500;
                                                cont = cont+1;
                                            }while((n500<0));
                                            saquetotal = saquetotal - cont;//diminuição de notas de 500 a ser emitidas
                                            saque = saque + (cont*500);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                            printf("Voce recebera %li notas de R$500,00\n",saquetotal);
                                    }
                                }
                                if(n300>0 &&  n300<=15000){
                                    if(saque>=300 && saque<500 || n500==0){//verificação de entrada paras notas de 300 e se caso quantidades de notas de 500 for 0
                                        saquetotal = (saque/300);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%300;
                                        n300 = n300-(saquetotal*300);// retirada das notas sacadas do total de notas de 300
                                        if(n300<0){// verificação em caso da quantidade de notas de 300 for negativa
                                            cont = 0;
                                            //correção das notas negativas
                                            do{
                                                n300 = n300+300;
                                                cont = cont+1;
                                            }while((n300<0));
                                            saquetotal = saquetotal - cont;//diminuição de notas de 300 a ser emitidas
                                            saque = saque + (cont*300);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                        printf("Voce recebera %li notas de R$300,00\n",saquetotal);
                                    }
                                }
                                if(n150>0 &&  n150<=7500){
                                    if(saque>=150 && saque<300 || n300==0){//verificação de entrada paras notas de 150 e se caso quantidades de notas de 300 for 0
                                        saquetotal = (saque/150);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%150;
                                        n150 = n150-(saquetotal*150);// retirada das notas sacadas do total de notas de 150
                                        if(n150<0){// verificação em caso da quantidade de notas de 150 for negativa
                                            cont = 0;
                                            //correção das notas negativas
                                            do{
                                                n150 = n150+150;
                                                cont = cont+1;
                                            }while((n150<0));
                                            saquetotal = saquetotal - cont;//diminuição de notas de 150 a ser emitidas
                                            saque = saque + (cont*150);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                        printf("Voce recebera %li notas de R$150,00\n",saquetotal);
                                    }
                                }
                                if(n100>0 &&  n100<=50000){
                                    if(saque>=100 && saque<150 || n150==0){//verificação de entrada paras notas de 100 e se caso quantidades de notas de 150 for 0
                                        saquetotal = (saque/100);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%100;
                                        n100 = n100-(saquetotal*100);// retirada das notas sacadas do total de notas de 100
                                        if(n100<0){// verificação em caso da quantidade de notas de 100 for negativa
                                            cont = 0;
                                            //correção das notas negativas
                                            do{
                                                n100 = n100+100;
                                                cont = cont+1;
                                            }while((n100<0));
                                            saquetotal = saquetotal - cont;//diminuição de notas de 100 a ser emitidas
                                            saque = saque + (cont*100);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                        printf("Voce recebera %li notas de R$100,00\n",saquetotal);
                                    }
                                }
                                if(n50>0 &&  n50<=25000){
                                    if(saque>=50 && saque<100 || n100==0){//verificação de entrada paras notas de 50 e se caso quantidades de notas de 100 for 0
                                        saquetotal = (saque/50);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%50;
                                        n50 = n50-(saquetotal*50);// retirada das notas sacadas do total de notas de 50
                                        if(n50<0){// verificação em caso da quantidade de notas de 50 for negativa
                                            cont = 0;
                                            //correção das notas negativas
                                            do{
                                                n50 = n50+50;
                                                cont = cont+1;
                                            }while((n50<0));
                                            saquetotal = saquetotal - cont;//diminuição de notas de 50 a ser emitidas
                                            saque = saque + (cont*50);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                        printf("Voce recebera %li notas de R$50,00\n",saquetotal);
                                    }
                                }
                                if(n25>0 &&  n25<=12500){
                                    if(saque>=25 && saque<40 || saque>44 && saque<50 || n50==0){//verificação de entrada paras notas de 25 e se caso quantidades de notas de 50 for 0
                                        saquetotal = (saque/25);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%25;
                                        n25 = n25-(saquetotal*25);// retirada das notas sacadas do total de notas de 25
                                        if(n25<0){// verificação em caso da quantidade de notas de 25 for negativa
                                            cont = 0;
                                            //correção das notas negativas
                                            do{
                                                n25 = n25+25;
                                                cont = cont+1;
                                            }while(n25<0);
                                            saquetotal = saquetotal - cont;//diminuição de notas de 25 a ser emitidas
                                            saque = saque + (cont*25);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                        printf("Voce recebera %li notas de R$25,00\n",saquetotal);
                                    }
                                }
                                if(n20>0 &&  n20<=10000){
                                    if(saque>=20 && saque<45 || n25==0){//verificação de entrada paras notas de 20 e se caso quantidades de notas de 25 for 0 e para o menor numero de notas a serem entregues de 40
                                        saquetotal = (saque/20);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%20;
                                        n20 = n20-(saquetotal*20);// retirada das notas sacadas do total de notas de 20
                                        if(n20<0){// verificação em caso da quantidade de notas de 20 for negativa
                                            cont = 0;
                                            //correção das notas negativas
                                            do{
                                                n20 = n20+20;
                                                cont = cont+1;
                                            }while((n20<0));
                                            saquetotal = saquetotal - cont;//diminuição de notas de 25 a ser emitidas
                                            saque = saque + (cont*20);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                        printf("Voce recebera %li notas de R$20,00\n",saquetotal);
                                    }
                                }
                                if(n10>0 &&  n10<=5000){
                                    if(saque>=10 && saque<20 ||n20==0){//verificação de entrada paras notas de 10 e se caso quantidades de notas de 20 for 0
                                        saquetotal = (saque/10);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%10;
                                        n10 = n10 - (saquetotal*10);// retirada das notas sacadas do total de notas de 10
                                        if(n10<0){// verificação em caso da quantidade de notas de 10 for negativa
                                            cont = 0;
                                            //correção das notas negativas
                                            do{
                                                n10 = n10+10;
                                                cont = cont+1;
                                            }while((n10<0));
                                            saquetotal = saquetotal - cont;//diminuição de notas de 10 a ser emitidas
                                            saque = saque + (cont*10);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                        printf("Voce recebera %li notas de R$10,00\n",saquetotal);
                                    }
                                }
                                if(n5>0 &&  n5<=2500){
                                    if(saque>=5 && saque<10 || n10==0){//verificação de entrada paras notas de 5 e se caso quantidades de notas de 10 for 0
                                        saquetotal = (saque/5);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%5;
                                        n5 = n5-(saquetotal*5);// retirada das notas sacadas do total de notas de 5
                                        if(n5<0){// verificação em caso da quantidade de notas de 5 for negativa
                                            cont = 0;
                                            //correção das notas negativas
                                            do{
                                                n5 = n5+5;
                                                cont = cont+1;
                                            }while((n5<0));
                                            saquetotal = saquetotal - cont;//diminuição de notas de 5 a ser emitidas
                                            saque = saque + (cont*5);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                        printf("Voce recebera %li notas de R$5,00\n",saquetotal);
                                    }
                                }
                                if(n2>0 &&  n2<=1000){
                                    if((saque>=2)&&(saque<5)||(n5==0)){//verificação de entrada paras notas de 2 e se caso quantidades de notas de 5 for 0
                                        saquetotal = (saque/2);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%2;
                                        n2 = n2-(saquetotal*2);// retirada das notas sacadas do total de notas de 2
                                        if(n2<0){// verificação em caso da quantidade de notas de 2 for negativa
                                            cont = 0;
                                            //correção das notas negativas
                                            do{
                                                n2 = n2+2;
                                                cont = cont+1;
                                            }while((n2<0));
                                            saquetotal = saquetotal - cont;//diminuição de notas de 2 a ser emitidas
                                            saque = saque + (cont*2);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                        printf("Voce recebera %li notas de R$2,00\n",saquetotal);
                                    }
                                }
                                if(n1>0 &&  n1<=500){
                                    if((saque>=1)&&(saque<2)||(n2==0)){//verificação de entrada paras notas de 1 e se caso quantidades de notas de 2 for 0
                                        saquetotal = (saque/1);//divisão do valor do saque pelas notas para saber quantidade de notas a ser emitidas
                                        saque = saque%1;
                                        n1 = n1-(saquetotal*1);// retirada das notas sacadas do total de notas de 1
                                        if(n1<0){
                                            cont = 0;
                                            //correção das notas negativas
                                            do{
                                                n1 = n1+1;
                                                cont = cont+1;
                                            }while((n1<0));
                                            saquetotal = saquetotal - cont;//diminuição de notas de 1 a ser emitidas
                                            saque = saque + (cont*1);//aumento de notas ao saque que foram retiradas quando o caixa ficou negativo
                                        }
                                        printf("Voce recebera %li notas de R$1,00\n",saquetotal);
                                    }
                                }
                            }
                                    valortotalnotas = n1000+n500+n300+n150+n100+n50+n25+n20+n10+n5+n2+n1;//ajuste de caixa
                                    printf("\n");
                                    if (valortotalnotas == 0){//condição quando acabar notas
                                        printf("\n");
                                        printf("Caixa esta sem cedulas\n\n\a");
                                        resp2 = 2;
                                    }
                                    if (valortotalnotas > 0 ){//Pergunta para continuação de saque
                                        printf("Deseja continuar Sacando?\n");
                                        printf("1-Sim\n");
                                        printf("2-Não\n\n");
                                        scanf("%i",&resp2);
                                        system("cls");
                                    }
                                    if (resp2 == 2){
                                        printf("Obrigado pela preferencia!\n\a");
                                    }
                        }while(resp2 == 1);//laço de repetição de saques
                }
            if ((resp == 2)){//bloco administrador
                do{
                    printf("Digite sua senha\n");//senha do administrador para acesso a abastecimeto de notas
                    scanf("%i",&senha);
                    if ((senha!=1213)){
                        printf("Senha Invalida!\n\n\a");
                    }
                }while ((senha!=1213));
            system ("cls");
            do{
                //laço de repetição para menu de adicionar ou relatorio de notas
                do{
                    printf("Escolha a opcao desejada\n\n");
                    printf("1-Relatorio de notas no caixa\n");
                    printf("2-Adicionar notas\n");
                    printf("3-Sair\n");
                    scanf("%i",&notas);
                }while ((notas!=1)&&(notas!=2)&&(notas!=3));
                    system ("cls");
                    //Relatorio de notas em caixa
                    if (notas == 1){
                            nd=0;
                            printf("Relatorio de Notas\n");
                            printf ("Ha %li notas de R$1000,00\n\n" ,nd=(n1000/1000));
                            printf ("Ha %li notas de R$500,00 \n\n" ,nd=(n500/500));
                            printf ("Ha %li notas de R$300,00 \n\n" ,nd=(n300/300));
                            printf ("Ha %li notas de R$150,00 \n\n" ,nd=(n150/150));
                            printf ("Ha %li notas de R$100,00 \n\n" ,nd=(n100/100));
                            printf ("Ha %li notas de R$50,00 \n\n" ,nd=(n50/50));
                            printf ("Ha %li notas de R$25,00 \n\n" ,nd=(n25/25));
                            printf ("Ha %li notas de R$20,00 \n\n" ,nd=(n20/20));
                            printf ("Ha %li notas de R$10,00 \n\n" ,nd=(n10/10));
                            printf ("Ha %li notas de R$5,00 \n\n" ,nd=(n5/5));
                            printf ("Ha %li notas de R$2,00 \n\n" ,nd=(n2/2));
                            printf ("Ha %li notas de R$1,00 \n\n" ,nd=(n1/1));
                    }
                    //Laço de repetição menu para escolha de qual nota sera adicionada
                    if (notas == 2){
                        do{
                            printf ("1-Para adicionar notas de R$1000,00\n\n");
                            printf ("2-Para adicionar notas de R$500,00 \n\n");
                            printf ("3-Para adicionar notas de R$300,00 \n\n");
                            printf ("4-Para adicionar notas de R$150,00 \n\n");
                            printf ("5-Para adicionar notas de R$100,00 \n\n");
                            printf ("6-Para adicionar notas de R$50,00 \n\n");
                            printf ("7-Para adicionar notas de R$25,00 \n\n");
                            printf ("8-Para adicionar notas de R$20,00 \n\n");
                            printf ("9-Para adicionar notas de R$10,00 \n\n");
                            printf ("10-Para adicionar notas de R$5,00 \n\n");
                            printf ("11-Para adicionar notas de R$2,00 \n\n");
                            printf ("12-Para adicionar notas de R$1,00 \n\n");
                            printf ("13-Sair\n\n");
                            scanf ("%i",&resp3);
                            if ((resp3<= 0)||(resp3>13)){//Em caso de erro nas opções acima
                                    printf("Opcao invalida\n\a");
                            }
                            system ("cls");
                            if (resp3==1){//condição escolhida pelo gerente
                                do{
                                    quardarvalor = n1000;//variavel que guarda a quantidade de notas de 1000 antes de adicionar
                                    printf("Insira a quantidade de notas de R$1000,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<0 || colocarnotas>50){//em caso de valor digitado errado
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=50){//execução de abastecimento
                                        colocarnotas = colocarnotas * 1000;//multiplicação da quantidade de notas para o valor em reais
                                        n1000 = n1000+colocarnotas;//notas reabastecidas
                                    }
                                    if (n1000<0 || n1000>50000){//em caso das notas atingir o valor maximo
                                        printf("Valor maximo ultrapassado!\n\n\a");
                                        n1000 = n1000 - colocarnotas;//correção da variavel de notas voltando ela ao o que estava antes
                                            if (n1000==50000){//aviso de notas ultrapaçadas
                                                printf("Notas de R$1000,00 atingiram sua capacidade maxima!\n\n\a");
                                            }
                                    }
                                    colocarnotas = colocarnotas/1000;//ajuste de variavel para condição do laço
                                }while(n1000==quardarvalor && quardarvalor!=50000 || colocarnotas<0 || colocarnotas>50);
                            }
                            if (resp3==2){
                                do{
                                    quardarvalor = n500;
                                    printf("Insira a quantidade de notas de R$500,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<0 || colocarnotas>50){
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=50){
                                        colocarnotas = colocarnotas * 500;
                                        n500 = n500+colocarnotas;
                                    }
                                    if (n500<0 || n500>25000){
                                        printf("Valor maximo ultrapassado!\n\a");
                                        n500 = n500 - colocarnotas;
                                        if (n500==25000){
                                            printf("Notas de R$500,00 atingiram sua capacidade maxima!\n\n\a");
                                        }
                                    }
                                    colocarnotas = colocarnotas/500;
                                }while(n500==quardarvalor && quardarvalor!=25000 || colocarnotas<0 || colocarnotas>50);
                            }
                            if (resp3==3){
                                do{
                                    quardarvalor = n300;
                                    printf("Insira a quantidade de notas de R$300,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<=0 || colocarnotas>50){
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=50){
                                        colocarnotas = colocarnotas * 300;
                                        n300 = n300+colocarnotas;
                                    }
                                    if (n300<0 || n300>15000){
                                        printf("Valor maximo ultrapassado!\n\a");
                                        n1000 = n1000 - colocarnotas;
                                        if (n300==15000){
                                            printf("Notas de R$300,00 atingiram sua capacidade maxima!\n\n\a");
                                        }
                                    }
                                    colocarnotas = colocarnotas/300;
                                }while(n300==quardarvalor && quardarvalor!=15000 || colocarnotas<0 || colocarnotas>50);
                            }
                            if (resp3==4){
                                do{
                                    quardarvalor = n150;
                                    printf("Insira a quantidade de notas de R$150,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<0 || colocarnotas>50){
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=50){
                                        colocarnotas = colocarnotas * 150;
                                        n150 = n150+colocarnotas;
                                    }
                                    if (n150<0 || n150>7500){
                                        printf("Valor maximo ultrapassado!\n\n\a");
                                        n150 = n150 - colocarnotas;
                                        if (n150==7500){
                                            printf("Notas de R$150,00 atingiram sua capacidade maxima!\n\n\a");
                                        }
                                    }
                                    colocarnotas = colocarnotas/150;
                                }while(n150==quardarvalor && quardarvalor!=7500 || colocarnotas<0 || colocarnotas>50);
                            }
                            if (resp3==5){
                               do{
                                    quardarvalor = n100;
                                    printf("Insira a quantidade de notas de R$100,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<0 || colocarnotas>500){
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=500){
                                        colocarnotas = colocarnotas * 100;
                                        n100 = n100+colocarnotas;
                                    }
                                    if (n100<0 || n100>50000){
                                        printf("Valor maximo ultrapassado!\n\n\a");
                                        n100 = n100 - colocarnotas;
                                        if (n100==50000){
                                            printf("Notas de R$100,00 atingiram sua capacidade maxima!\n\n\a");
                                        }
                                    }
                                    colocarnotas = colocarnotas/100;
                                }while(n100==quardarvalor && quardarvalor!=50000 || colocarnotas<0 || colocarnotas>500);
                            }
                            if (resp3==6){
                                do{
                                    quardarvalor = n50;
                                    printf("Insira a quantidade de notas de R$50,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<0 || colocarnotas>500){
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=500){
                                        colocarnotas = colocarnotas * 50;
                                        n50 = n50+colocarnotas;
                                    }
                                    if (n50<0 || n50>25000){
                                        printf("Valor maximo ultrapassado!\n\n\a");
                                        n50 = n50 - colocarnotas;
                                        if (n50==25000){
                                            printf("Notas de R$50,00 atingiram sua capacidade maxima!\n\n\a");
                                        }
                                    }
                                    colocarnotas = colocarnotas/50;
                                }while(n50==quardarvalor && quardarvalor!=25000 || colocarnotas<0 || colocarnotas>500);
                            }
                            if (resp3==7){
                                do{
                                    quardarvalor = n25;
                                    printf("Insira a quantidade de notas de R$25,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<0 || colocarnotas>500){
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=500){
                                        colocarnotas = colocarnotas * 25;
                                        n25 = n25+colocarnotas;
                                    }
                                    if (n25<0 || n25>12500){
                                        printf("Valor maximo ultrapassado!\n\n\a");
                                        n25 = n25 - colocarnotas;
                                        if (n25==12500){
                                            printf("Notas de R$25,00 atingiram sua capacidade maxima!\n\n\a");
                                        }
                                    }
                                    colocarnotas = colocarnotas/25;
                                }while(n25==quardarvalor && quardarvalor!=12500 || colocarnotas<0 || colocarnotas>500);
                            }
                            if (resp3==8){
                                do{
                                    quardarvalor = n20;
                                    printf("Insira a quantidade de notas de R$20,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<0 || colocarnotas>500){
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=500){
                                        colocarnotas = colocarnotas * 20;
                                        n20 = n20+colocarnotas;
                                    }
                                    if (n20<0 || n20>10000){
                                        printf("Valor maximo ultrapassado!\n\n\a");
                                        n20 = n20 - colocarnotas;
                                        if (n20==10000){
                                            printf("Notas de R$20,00 atingiram sua capacidade maxima!\n\n\a");
                                        }
                                    }
                                    colocarnotas = colocarnotas/20;
                                }while(n20==quardarvalor && quardarvalor!=10000 || colocarnotas<0 || colocarnotas>500);
                            }
                            if (resp3==9){
                                do{
                                    quardarvalor = n10;
                                    printf("Insira a quantidade de notas de R$10,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<0 || colocarnotas>500){
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=500){
                                        colocarnotas = colocarnotas * 10;
                                        n10 = n10+colocarnotas;
                                    }
                                    if (n10<0 || n10>5000){
                                        printf("Valor maximo ultrapassado!\n\n\a");
                                        n10 = n10 - colocarnotas;
                                        if (n10==5000){
                                            printf("Notas de R$10,00 atingiram sua capacidade maxima!\n\n\a");
                                        }
                                    }
                                    colocarnotas = colocarnotas/10;
                                }while(n10==quardarvalor && quardarvalor!=5000 || colocarnotas<0 || colocarnotas>500);
                            }
                            if (resp3==10){
                                do{
                                    quardarvalor = n5;
                                    printf("Insira a quantidade de notas de R$5,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<0 || colocarnotas>500){
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=500){
                                        colocarnotas = colocarnotas * 5;
                                        n5 = n5+colocarnotas;
                                    }
                                    if (n5<0 || n5>2500){
                                        printf("Valor maximo ultrapassado!\n\n\a");
                                        n5 = n5 - colocarnotas;
                                        if (n5==2500){
                                            printf("Notas de R$5,00 atingiram sua capacidade maxima!\n\n\a");
                                        }
                                    }
                                    colocarnotas = colocarnotas/5;
                                }while(n5==quardarvalor && quardarvalor!=2500 || colocarnotas<0 || colocarnotas>500);
                            }
                            if (resp3==11){
                                do{
                                    quardarvalor = n2;
                                    printf("Insira a quantidade de notas de R$2,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<0 || colocarnotas>500){
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=500){
                                        colocarnotas = colocarnotas * 2;
                                        n2 = n2+colocarnotas;
                                    }
                                    if (n2<0 || n2>1000){
                                        printf("Valor maximo ultrapassado!\n\n\a");
                                        n2 = n2 - colocarnotas;
                                        if (n2==1000){
                                            printf("Notas de R$2,00 atingiram sua capacidade maxima!\n\n\a");
                                        }
                                    }
                                    colocarnotas = colocarnotas/2;
                                }while(n2==quardarvalor && quardarvalor!=1000 || colocarnotas<0 || colocarnotas>500);
                            }
                            if (resp3==12){
                                do{
                                    quardarvalor = n1;
                                    printf("Insira a quantidade de notas de R$1,00 a ser colocadas\n");
                                        scanf("%i",&colocarnotas);
                                    if (colocarnotas<0 || colocarnotas>500){
                                        printf("Valor Invalido! Valor Negativo ou acima da capacidade do caixa\n\n\a");
                                    }
                                    if (colocarnotas>=0 && colocarnotas<=500){
                                        colocarnotas = colocarnotas * 1;
                                        n1 = n1+colocarnotas;
                                    }
                                    if (n1<0 || n1>500){
                                        printf("Valor maximo ultrapassado!\n\n\a");
                                        n1 = n1 - colocarnotas;
                                        if (n1==500){
                                            printf("Notas de R$1,00 atingiram sua capacidade maxima!\n\n\a");
                                        }
                                    }
                                    colocarnotas = colocarnotas/1;
                                }while(n1==quardarvalor && quardarvalor!=500 || colocarnotas<0 || colocarnotas>500);
                            }
                        }while (resp3!=13);
                }
            }while(notas!=3);
            }
    printf("\n");
    }while(resp!=3);
}
