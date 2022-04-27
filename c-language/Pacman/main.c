#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Pacman.h"
#include <conio.h>
#include <windows.h>

/**********************************************
    Desenvolvido por Douglas Correia Salazar
    Data: 17/11/2018

    Software tem como intuito abordar o jogo
    PACMAN desempenhar as principais funciona-
    lidades. Apresenta também algumas regras,
    historia e objetivo.
***********************************************
*/

int JogoPacman(){
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

            char vidas[3]={2,2,2};
            char Mapa[31][29];
            Personagem Pac, Fant1, Fant2, Fant3, Fant4;/*Personagens*/
            int x/*Recebe valor -1 quanto pacman perde vida*/, Ponto=0/*Controla a pontuaçao do jogo*/, i=0/*Controla a ordem de liberação dos fantasmas*/, MovFantasma=0/*Controla se o fantasma deve fugir e quantos foram consumidos pelo pacman*/;
            int Contador_panico=0/*Tempo para retornar ao normal*/, Velocidade=0/*Diminui a velocidade dos fantasmas*/, contVidas=2/*contador de vidas*/,contTempoVida=-1/*Controla 3 piscada pacman*/, contFruta=0/*Contador de pilulas consumidas*/, contTempoFruta=0/*tempo de permanencia da fruta no mapa*/,posi_Fruta,posj_Fruta/*Posição da fruta*/;

            lerMapa(Mapa);
            inicializaPersonagem(&Pac, &Fant1, &Fant2, &Fant3, &Fant4);
            Imprimi_Mapa(Mapa,Pac, Fant1, Fant2, Fant3, Fant4,Contador_panico);

            do{
                //coleta dados do teclado
                /*
                W Cima: 119
                S Baixo: 115
                A Esquerda: 97
                D Direita: 100
                */

                if(kbhit()){
                    Pac.direcao=getch();
                }
                //Perseguir pacman i responsavel por liberar um fantasma de cada vez
                if(MovFantasma==0){
                    Fant1=movimentoFant(Mapa, Fant1, Pac, Fant2, Fant3, Fant4);
                    if(i>5)
                        Fant2=movimentoFant(Mapa, Fant2, Pac, Fant1, Fant3, Fant4);
                    if(i>10)
                        Fant3=movimentoFant(Mapa, Fant3, Pac, Fant2, Fant1, Fant4);
                    if(i>15)
                        Fant4=movimentoFant(Mapa, Fant4, Pac, Fant2, Fant3, Fant1);
                //Fugir do pacman
                }else if(Velocidade==2){
                    Fant1=movimentoFantInv(Mapa, Fant1, Pac, Fant2, Fant3, Fant4);
                    if(i>5)
                        Fant2=movimentoFantInv(Mapa, Fant2, Pac, Fant1, Fant3, Fant4);
                    if(i>10)
                        Fant3=movimentoFantInv(Mapa, Fant3, Pac, Fant2, Fant1, Fant4);
                    if(i>15)
                        Fant4=movimentoFantInv(Mapa, Fant4, Pac, Fant2, Fant3, Fant1);
                    Velocidade=0;
                }
                i++;
                //Movimenta pacman de acordo com tecla pressionada
                x=movimentoPacman(Mapa, &Pac, &Ponto, &Fant1, &Fant2, &Fant3, &Fant4,&MovFantasma, &contFruta);

                //Se o pacman coletou pilula energia diminui a velocidade do fantasma e comeca a contar o tempo
                if(MovFantasma>0){
                    Contador_panico++;
                    Velocidade++;
                }
                //Volta fantasma ao normal
                if(Contador_panico==15){
                    MovFantasma=0;
                    Contador_panico=0;
                    Velocidade=0;
                }
                //Controle 3 piscadas quando perde a vida
                if(contTempoVida==0 || contTempoVida==2 || contTempoVida==4){
                    Pac.nome=2;
                    contTempoVida++;
                }else if(contTempoVida==1 || contTempoVida==3){
                    Pac.nome=1;
                    contTempoVida++;

                }
                //Controle de vidas
                if(x==-1){
                    vidas[contVidas]=' ';
                    contVidas--;
                    inicializaPersonagem(&Pac, &Fant1, &Fant2, &Fant3, &Fant4);
                    i=0;
                    contTempoVida=0;
                    Pac.nome=1;
                    Beep(786,100);
                    Beep(786,200);
                    Beep(786,300);
                    Beep(786,400);
                    Beep(786,500);

                }

                /*Coletou 50 pilulas aciona o contator de tempo e coloca a fruta no mapa*/
                if(contFruta == 50){
                    adionarFruta(Mapa,&posi_Fruta,&posj_Fruta);
                    contFruta = 0;
                    contTempoFruta=1;
                }
                if(contTempoFruta>0){
                    contTempoFruta++;
                    if(contTempoFruta==30){
                        Mapa[posi_Fruta][posj_Fruta]=250;
                    }
                }

                Sleep(400);
                Imprimi_Mapa(Mapa,Pac, Fant1, Fant2, Fant3, Fant4, Contador_panico);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
                printf("\n                         Pontos: %d     Vidas: %c %c %c",Ponto,vidas[0], vidas[1], vidas[2]);

                //Digitou P pausa o jogo
                if(Pac.direcao==112){
                    system("pause");
                    Pac.direcao=119;
                }
            }while(contVidas!=-1 && Pac.direcao!=27);
            printf("\nGame Over!\n");
            Beep(784,100);
            Sleep(1);
            Beep(784,600);
            Beep(784,600);
            Beep(622,600);
            Beep(698,600);
            Beep(784,200);
            Sleep(2);
            Beep(698,200);
            Beep(784,800);
            system("pause");
    return Ponto;
}


int main()
{
    int menu,menu1;
    int Pontuacao[10], Cont=0,i;
    do{
            system("cls");
            printf("                         *****************************\n");
            printf("                         *1-Ajuda                    *\n");
            printf("                         *2-Equipe de desenvolvimento*\n");
            printf("                         *3-Historia do jogo         *\n");
            printf("                         *4-Jogar                    *\n");
            printf("                         *5-Sair                     *\n");
            printf("                         *****************************\n");
            scanf("%d",&menu);

            switch(menu){
            case 1:
                system("cls");
                printf("                         ********************************\n");
                printf("                         *1-Regras do Jogo              *\n");
                printf("                         *2-Oque fazer para marcar Ponto*\n");
                printf("                         *3-Pontuacao                   *\n");
                printf("                         *4-Sair                        *\n");
                printf("                         ********************************\n");
                scanf("%d",&menu1);
                switch (menu1){
                    case 1:
                            system("cls");
                            printf("**************************************************\n");
                            printf("* O pacman tem que evitar os fantasmas,          *\n");
                            printf("* caso colidir com algum, perde uma vida ou      *\n");
                            printf("* acaba o jogo. Caso o pacman comer uma pilula   *\n");
                            printf("* de energia, os fantasma ficam azul por um      *\n");
                            printf("* periodo de tempo, dando possibilidade do       *\n");
                            printf("* pacman come-los. O jogo acaba quando o pacman  *\n");
                            printf("* come todas as pilulas, ou acabam suas vidas.   *\n");
                            printf("**************************************************\n");
                            system("pause");
                    break;
                    case 2:
                            system("cls");
                            printf("**************************************************\n");
                            printf("* -Comer uma Pilula                   10 Pontos  *\n");
                            printf("* -Comer uma Pilula de energia        50 Pontos  *\n");
                            printf("* -Comer uma Fruta                    500 Pontos *\n");
                            printf("* -Comer um fastama                   200 Pontos *\n");
                            printf("* -Comer dois fastamas consecutivos   400 Pontos *\n");
                            printf("* -Comer tres fastamas consecutivos   800 Pontos *\n");
                            printf("* -Comer quatro fastamas consecutivos 1600 Pontos*\n");
                            printf("**************************************************\n");
                            system("pause");
                    break;
                    case 3:
                        system("cls");
                        printf("                         *****************************\n");
                        printf("                                    Pontuacao       \n");
                        printf("                         -----------------------------\n");
                        for(i=0;i<Cont;i++){
                            printf("                         %d Pontos\n", Pontuacao[i]);
                        printf("                         -----------------------------\n");

                        }
                        printf("                         *****************************\n");
                        system("pause");
                    break;
                };
            break;
            case 2:
                        system("cls");
                        printf("                         *****************************\n");
                        printf("                         *  Douglas Correia Salazar  *\n");
                        printf("                         *  Disciplina: LPI-II       *\n");
                        printf("                         *  Engenharia da Computacao *\n");
                        printf("                         *****************************\n");
                        system("pause");
            break;
            case 3:
                system("cls");
                printf("**************************************************\n");
                printf("* O jogo foi lançado em 22 de maio de 1980.      *\n");
                printf("* ideia do desenho original ocorreu durante      *\n");
                printf("* um jantar com amigos, e deve-se a uma pizza    *\n");
                printf("* sem uma fatia,que fazia lembrar uma boca aberta*\n");
                printf("* A personagem e jogo tiveram o nome Puck-Man, do*\n");
                printf("* termo Japonês paku-paku.Em 1980,a Bally comprou*\n");
                printf("* os direitos nos EUA, rebatizando Pac-Man.      *\n");
                printf("**************************************************\n");
                system("pause");
            break;
            case 4:
                Pontuacao[Cont]=JogoPacman();
                Cont++;
            break;
            case 5:

            break;
            case 6:
            break;
            };

    }while(menu!=5);
    return 0;
}
