#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <math.h>


char Pilula=250, PilulaG=248,Fruta=14, Parede1=201, Parede2=200, Parede3=187, Parede4= 188, Parede5=205, Parede6=186;

typedef struct personagem{
    char nome;
    int posi;
    int posj;
    int direcao;
}Personagem;

//Calcula a distancia do fantasma e do pacman
int Calcula_dist(int X, int Y, int x, int y){
    return sqrt(pow(X-x,2) + pow(Y-y,2));
}

//Adiciona a fruta no mapa
void adionarFruta(char Mapa[31][29],int * posi_Fruta, int *posj_Fruta){

    int i=0,x,y;

    do{
        x=rand()%31;
        y=rand()%29;
        if((Mapa[x][y]!=Parede1) && (Mapa[x][y]!=Parede2) && (Mapa[x][y]!=Parede3) && (Mapa[x][y]!=Parede4) && (Mapa[x][y]!=Parede5) && (Mapa[x][y]!=Parede6)&&(Mapa[x][y]!=32)){
            Mapa[x][y]=14;
            i=1;
            *posi_Fruta=x;
            *posj_Fruta=y;
        }
    }while(i==0);
}

//Efetua a leitura do Mapa de um arquivo
void lerMapa(char Mapa[31][29]){
    int i=0,j=0, aux;
    FILE * Arq = fopen("Pacman.txt", "r");

    if(Arq!= NULL){
        for(i=0;i<31;i++){
            for(j=0;j<28;j++){
                fscanf(Arq, "%d ", &aux);
                Mapa[i][j]=aux;
            }
        }
    }
    fclose(Arq);
}

//Imprimi mapa completo inclusive persanagens
void Imprimi_Mapa(char Mapa[31][29],Personagem Pac,Personagem Fant1,Personagem Fant2,Personagem Fant3,Personagem Fant4, int cont){
    int i,j,aux;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    system("cls");
    printf("                         Para jogar utilize as teclar\n");
    printf("                                     Cima\n");
    printf("                                      ---\n");
    printf("                                  ---| w |---\n");
    printf("                        Esquerda | a |---| d | Direita\n");
    printf("                                  ---| s |---   \n");
    printf("                                      ---\n");
    printf("                                     Baixo\n");
    for(i=0;i<31;i++){
        printf("                         ");
        for(j=0;j<28;j++){
            if(Pac.posi==i && Pac.posj==j){
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY); //Cor amarela
                printf("%c",Pac.nome);
            }else if(Fant1.posi==i && Fant1.posj==j){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); //Cor branca
                if(cont==0)//Se o fantasma não está em modo fuga
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED| FOREGROUND_INTENSITY);//Pinta de vermelho
                printf("%c",Fant1.nome);
            }else if(Fant2.posi==i && Fant2.posj==j){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);//Cor branca
                if(cont==0)//Se o fantasma não está em modo fuga
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE| FOREGROUND_INTENSITY);//Cor azul
                printf("%c",Fant2.nome);
            }else if(Fant3.posi==i && Fant3.posj==j){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);//branco
                if(cont==0)
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Cor rosa
                printf("%c",Fant3.nome);
            }else if(Fant4.posi==i && Fant4.posj==j){
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);//branco
                if(cont==0)
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//ciano
                printf("%c",Fant4.nome);
            }else{
                if(Mapa[i][j]==Pilula || Mapa[i][j]==PilulaG){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);//amarelo
                    printf("%c",Mapa[i][j]);
                }else if(Mapa[i][j]==Parede1 || Mapa[i][j]==Parede2 || Mapa[i][j]==Parede3 || Mapa[i][j]==Parede4 || Mapa[i][j]==Parede5 || Mapa[i][j]==Parede6){
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);//azul
                    printf("%c",Mapa[i][j]);
                }else if(Mapa[i][j]==Fruta){
                    aux=rand()%3;//Cor da fruta aleatório
                    if(aux==0)
                        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    if(aux==1)
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    if(aux==2)
                        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

                    printf("%c",Mapa[i][j]);
                }else{
                    printf("%c",Mapa[i][j]);
                }

            }
        }
        printf("\n");
    }
}

//inicializa personagem na posição inicial
void inicializaPersonagem(Personagem *Pac,Personagem *Fant1,Personagem *Fant2,Personagem *Fant3,Personagem *Fant4){

    Pac->nome = 2;
    Pac->posi = 5;
    Pac->posj = 14;

    Fant1->nome = 5;
    Fant1->posi = 11;
    Fant1->posj = 15;

    Fant2->nome = 5;
    Fant2->posi = 15;
    Fant2->posj = 13;

    Fant3->nome = 5;
    Fant3->posi = 15;
    Fant3->posj = 14;

    Fant4->nome = 5;
    Fant4->posi = 15;
    Fant4->posj = 15;

    Pac->direcao=97;
}

//movimento pacman
int movimentoPacman(char Mapa[31][29], Personagem *Pac, int *Ponto,Personagem *Fant1,Personagem *Fant2,Personagem *Fant3,Personagem *Fant4, int * MovFantasma, int * contFruta){

    if(Pac->direcao == 119){ //Cima
        //Verifica se a colisão com a parede
        if((Mapa[Pac->posi-1][Pac->posj]!=Parede1) && (Mapa[Pac->posi-1][Pac->posj]!=Parede2) && (Mapa[Pac->posi-1][Pac->posj]!=Parede3) && (Mapa[Pac->posi-1][Pac->posj]!=Parede4) && (Mapa[Pac->posi-1][Pac->posj]!=Parede5) && (Mapa[Pac->posi-1][Pac->posj]!=Parede6)){
            Pac->posi--;
            //Verifica se é pilula pequena
            if(Mapa[Pac->posi][Pac->posj]==Pilula){
                *contFruta = *contFruta+1;//Contador de pilulas para acionar fruta
                *Ponto=*Ponto+10;
                printf("\7");//beep
                Mapa[Pac->posi][Pac->posj]=32;//Espaço em branco
            //Verifica se é pilula grande
            }else if(Mapa[Pac->posi][Pac->posj]==PilulaG){
                *contFruta = *contFruta+1;
                *Ponto=*Ponto+50;
                printf("\7");
                *MovFantasma = 1;
                Mapa[Pac->posi][Pac->posj]=32;
            //Verifica se é fruta
            }else if(Mapa[Pac->posi][Pac->posj]==Fruta){
                *contFruta = *contFruta+1;
                *Ponto=*Ponto+500;
                printf("\7");
                Mapa[Pac->posi][Pac->posj]=32;
            }
        }
    }else if(Pac->direcao == 115){ //Baixo
        if(Mapa[Pac->posi+1][Pac->posj]!=Parede1 && Mapa[Pac->posi+1][Pac->posj]!=Parede2 && Mapa[Pac->posi+1][Pac->posj]!=Parede3 && Mapa[Pac->posi+1][Pac->posj]!=Parede4 && Mapa[Pac->posi+1][Pac->posj]!=Parede5 && Mapa[Pac->posi+1][Pac->posj]!=Parede6){
            Pac->posi++;
            if(Mapa[Pac->posi][Pac->posj]==Pilula){
                *Ponto=*Ponto+10;
                *contFruta = *contFruta+1;
                printf("\7");
                Mapa[Pac->posi][Pac->posj]=32;
            }else if(Mapa[Pac->posi][Pac->posj]==PilulaG){
                *Ponto=*Ponto+50;
                *contFruta = *contFruta+1;
                printf("\7");
                *MovFantasma = 1;
                Mapa[Pac->posi][Pac->posj]=32;
            }else if(Mapa[Pac->posi][Pac->posj]==Fruta){
                *contFruta = *contFruta+1;
                *Ponto=*Ponto+500;
                printf("\7");
                Mapa[Pac->posi][Pac->posj]=32;
            }
        }
    }else if(Pac->direcao == 97){ //Esquerda
        if(Mapa[Pac->posi][Pac->posj-1]!=Parede1 && Mapa[Pac->posi][Pac->posj-1]!=Parede2 && Mapa[Pac->posi][Pac->posj-1]!=Parede3 && Mapa[Pac->posi][Pac->posj-1]!=Parede4 && Mapa[Pac->posi][Pac->posj-1]!=Parede5 && Mapa[Pac->posi][Pac->posj-1]!=Parede6){
            Pac->posj--;
            if(Mapa[Pac->posi][Pac->posj]==Pilula){
                *Ponto=*Ponto+10;
                *contFruta = *contFruta+1;
                printf("\7");
                Mapa[Pac->posi][Pac->posj]=32;
            }else if(Mapa[Pac->posi][Pac->posj]==PilulaG){
                *Ponto=*Ponto+50;
                *contFruta = *contFruta+1;
                printf("\7");
                *MovFantasma = 1;
                Mapa[Pac->posi][Pac->posj]=32;
            }else if(Mapa[Pac->posi][Pac->posj]==Fruta){
                *contFruta = *contFruta+1;
                *Ponto=*Ponto+500;
                printf("\7");
                Mapa[Pac->posi][Pac->posj]=32;
            }
        }
    }else if(Pac->direcao == 100){//Direita
        if(Mapa[Pac->posi][Pac->posj+1]!=Parede1 && Mapa[Pac->posi][Pac->posj+1]!=Parede2 && Mapa[Pac->posi][Pac->posj+1]!=Parede3 && Mapa[Pac->posi][Pac->posj+1]!=Parede4 && Mapa[Pac->posi][Pac->posj+1]!=Parede5 && Mapa[Pac->posi][Pac->posj+1]!=Parede6){
            Pac->posj++;
            if(Mapa[Pac->posi][Pac->posj]==Pilula){
                *Ponto=*Ponto+10;
                *contFruta = *contFruta+1;
                printf("\7");
                Mapa[Pac->posi][Pac->posj]=32;
            }else if(Mapa[Pac->posi][Pac->posj]==PilulaG){
                *Ponto=*Ponto+50;
                *contFruta = *contFruta+1;
                printf("\7");
                *MovFantasma = 1;
                Mapa[Pac->posi][Pac->posj]=32;
            }else if(Mapa[Pac->posi][Pac->posj]==Fruta){
                *contFruta = *contFruta+1;
                *Ponto=*Ponto+500;
                printf("\7");
                Mapa[Pac->posi][Pac->posj]=32;
            }
        }
    }
    //Passagem secreta
    if(Pac->posi == 14 && Pac->posj == 0){
        Pac->posi = 14;
        Pac->posj = 28;
    }else if(Pac->posi == 14 && Pac->posj == 28){
        Pac->posi = 14;
        Pac->posj = 0;
    }
    //Verifica se tem colisão com fantasma
    if(((Pac->posi == Fant1->posi && Pac->posj == Fant1->posj) || (Pac->posi == Fant2->posi && Pac->posj == Fant2->posj) || (Pac->posi == Fant3->posi && Pac->posj == Fant3->posj) || (Pac->posi == Fant4->posi && Pac->posj == Fant4->posj)) && *MovFantasma==0){
        return -1;
    //Fantasma estão em modo fuga
    } else if(*MovFantasma>=1){
        //Verifica qual fantasma veio a colidir
        if(Pac->posi == Fant1->posi && Pac->posj == Fant1->posj){
            Fant1->posi = 15;
            Fant1->posj = 14;
            *MovFantasma=*MovFantasma+1;
            //Verifica a quantidade de vezes que foi colidido e soma aos pontos
            if(*MovFantasma==1){
                *Ponto=*Ponto+200;
            }else if(*MovFantasma==2){
                *Ponto=*Ponto+400;
            }else if(*MovFantasma==3){
                *Ponto=*Ponto+800;
            }else if(*MovFantasma==4){
                *Ponto=*Ponto+1600;
            }

        }else if(Pac->posi == Fant2->posi && Pac->posj == Fant2->posj){
            Fant2->posi = 15;
            Fant2->posj = 14;
            *MovFantasma=*MovFantasma+1;
            if(*MovFantasma==1){
                *Ponto=*Ponto+200;
            }else if(*MovFantasma==2){
                *Ponto=*Ponto+400;
            }else if(*MovFantasma==3){
                *Ponto=*Ponto+800;
            }else if(*MovFantasma==4){
                *Ponto=*Ponto+1600;
            }

        }else if(Pac->posi == Fant3->posi && Pac->posj == Fant3->posj){
            Fant3->posi = 15;
            Fant3->posj = 14;
            *MovFantasma=*MovFantasma+1;
            if(*MovFantasma==1){
                *Ponto=*Ponto+200;
            }else if(*MovFantasma==2){
                *Ponto=*Ponto+400;
            }else if(*MovFantasma==3){
                *Ponto=*Ponto+800;
            }else if(*MovFantasma==4){
                *Ponto=*Ponto+1600;
            }

        }else if(Pac->posi == Fant4->posi && Pac->posj == Fant4->posj){
            Fant4->posi = 15;
            Fant4->posj = 14;
            *MovFantasma=*MovFantasma+1;
            if(*MovFantasma==1){
                *Ponto=*Ponto+200;
            }else if(*MovFantasma==2){
                *Ponto=*Ponto+400;
            }else if(*MovFantasma==3){
                *Ponto=*Ponto+800;
            }else if(*MovFantasma==4){
                *Ponto=*Ponto+1600;
            }
        }
    }
    return 0;
}

//movimento fantasma atras do pacman
Personagem movimentoFant(char Mapa[31][29], Personagem Fant, Personagem Pac, Personagem Fant2,Personagem Fant3,Personagem Fant4){
    int dist_menor = Calcula_dist(Fant.posi,Fant.posj,Pac.posi,Pac.posj), posi_menor = Fant.posi, posj_menor = Fant.posj;

    // Escolha do menor caminho atraves do calculo de distancia
    // Validação de colizão na parede e fantasma
    //Esquerda
    if((Mapa[Fant.posi-1][Fant.posj]!=Parede1 && Mapa[Fant.posi-1][Fant.posj]!=Parede2 && Mapa[Fant.posi-1][Fant.posj]!=Parede3 && Mapa[Fant.posi-1][Fant.posj]!=Parede4 && Mapa[Fant.posi-1][Fant.posj]!=Parede5 && Mapa[Fant.posi-1][Fant.posj]!=Parede6) && (Calcula_dist(Fant.posi-1,Fant.posj,Pac.posi,Pac.posj)<dist_menor) && (!(Fant.posi-1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi-1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi-1==Fant4.posi && Fant.posj==Fant4.posj))){
        posi_menor = Fant.posi-1;
        posj_menor = Fant.posj;
    }else
    //direita
    if((Mapa[Fant.posi+1][Fant.posj]!=Parede1 && Mapa[Fant.posi+1][Fant.posj]!=Parede2 && Mapa[Fant.posi+1][Fant.posj]!=Parede3 && Mapa[Fant.posi+1][Fant.posj]!=Parede4 && Mapa[Fant.posi+1][Fant.posj]!=Parede5 && Mapa[Fant.posi+1][Fant.posj]!=Parede6) && (Calcula_dist(Fant.posi+1,Fant.posj,Pac.posi,Pac.posj)<dist_menor)&&(!(Fant.posi+1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi+1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi+1==Fant4.posi && Fant.posj==Fant4.posj))){
        posi_menor = Fant.posi+1;
        posj_menor = Fant.posj;
    }else
    //Cima
    if((Mapa[Fant.posi][Fant.posj-1]!=Parede1 && Mapa[Fant.posi][Fant.posj-1]!=Parede2 && Mapa[Fant.posi][Fant.posj-1]!=Parede3 && Mapa[Fant.posi][Fant.posj-1]!=Parede4 && Mapa[Fant.posi][Fant.posj-1]!=Parede5 && Mapa[Fant.posi][Fant.posj-1]!=Parede6) && (Calcula_dist(Fant.posi,Fant.posj-1,Pac.posi,Pac.posj)<dist_menor)&&(!(Fant.posi==Fant2.posi && Fant.posj-1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj-1==Fant3.posj)&&!(Fant.posi==Fant4.posi && Fant.posj-1==Fant4.posj))){
        posi_menor = Fant.posi;
        posj_menor = Fant.posj-1;
    }else
    //Baixo
    if((Mapa[Fant.posi][Fant.posj+1]!=Parede1 && Mapa[Fant.posi][Fant.posj+1]!=Parede2 && Mapa[Fant.posi][Fant.posj+1]!=Parede3 && Mapa[Fant.posi][Fant.posj+1]!=Parede4 && Mapa[Fant.posi][Fant.posj+1]!=Parede5 && Mapa[Fant.posi][Fant.posj+1]!=Parede6) && (Calcula_dist(Fant.posi,Fant.posj+1,Pac.posi,Pac.posj)<dist_menor)&&(!(Fant.posi==Fant2.posi && Fant.posj+1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj+1==Fant3.posj)&&!(Fant.posi==Fant4.posi && Fant.posj+1==Fant4.posj))){
        posi_menor = Fant.posi;
        posj_menor = Fant.posj+1;
    }
    //Caminho alternativo
    if(Fant.posi == posi_menor && Fant.posj == posj_menor){
        if((Mapa[Fant.posi-1][Fant.posj]!=Parede1 && Mapa[Fant.posi-1][Fant.posj]!=Parede2 && Mapa[Fant.posi-1][Fant.posj]!=Parede3 && Mapa[Fant.posi-1][Fant.posj]!=Parede4 && Mapa[Fant.posi-1][Fant.posj]!=Parede5 && Mapa[Fant.posi-1][Fant.posj]!=Parede6) && (pow( ((Fant.posi)-1) - (Pac.posi) ,2) < pow( ((Fant.posi) - (Pac.posi)) ,2))&&(!(Fant.posi-1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi-1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi-1==Fant4.posi && Fant.posj==Fant4.posj))){
            posi_menor = Fant.posi-1;
        }else
        if((Mapa[Fant.posi+1][Fant.posj]!=Parede1 && Mapa[Fant.posi+1][Fant.posj]!=Parede2 && Mapa[Fant.posi+1][Fant.posj]!=Parede3 && Mapa[Fant.posi+1][Fant.posj]!=Parede4 && Mapa[Fant.posi+1][Fant.posj]!=Parede5 && Mapa[Fant.posi+1][Fant.posj]!=Parede6) && (pow( ((Fant.posi)+1) - (Pac.posi) ,2) < pow( ((Fant.posi) - (Pac.posi)) ,2))&&(!(Fant.posi+1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi+1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi+1!=Fant4.posi && Fant.posj==Fant4.posj))){
            posi_menor = Fant.posi+1;
        }else
        if((Mapa[Fant.posi][Fant.posj-1]!=Parede1 && Mapa[Fant.posi][Fant.posj-1]!=Parede2 && Mapa[Fant.posi][Fant.posj-1]!=Parede3 && Mapa[Fant.posi][Fant.posj-1]!=Parede4 && Mapa[Fant.posi][Fant.posj-1]!=Parede5 && Mapa[Fant.posi][Fant.posj-1]!=Parede6) && (pow( ((Fant.posj)-1) - (Pac.posj) ,2) < pow( ((Fant.posj) - (Pac.posj)) ,2))&&(!(Fant.posi==Fant2.posi && Fant.posj-1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj-1==Fant3.posj)&&!(Fant.posi==Fant4.posi && Fant.posj-1==Fant4.posj))){
            posj_menor = Fant.posj-1;
        }else
        if((Mapa[Fant.posi][Fant.posj+1]!=Parede1 && Mapa[Fant.posi][Fant.posj+1]!=Parede2 && Mapa[Fant.posi][Fant.posj+1]!=Parede3 && Mapa[Fant.posi][Fant.posj+1]!=Parede4 && Mapa[Fant.posi][Fant.posj+1]!=Parede5 && Mapa[Fant.posi][Fant.posj+1]!=Parede6) && (pow( ((Fant.posj)+1) - (Pac.posj) ,2) < pow( ((Fant.posj) - (Pac.posj)) ,2))&&(!(Fant.posi==Fant2.posi && Fant.posj+1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj+1==Fant3.posj)&&!(Fant.posi==Fant4.posi && Fant.posj+1==Fant4.posj))){
            posj_menor = Fant.posj+1;
        }
    }
    if(Fant.posi == posi_menor && Fant.posj == posj_menor){

        if((Mapa[Fant.posi+1][Fant.posj]!=Parede1 && Mapa[Fant.posi+1][Fant.posj]!=Parede2 && Mapa[Fant.posi+1][Fant.posj]!=Parede3 && Mapa[Fant.posi+1][Fant.posj]!=Parede4 && Mapa[Fant.posi+1][Fant.posj]!=Parede5 && Mapa[Fant.posi+1][Fant.posj]!=Parede6) &&(!(Fant.posi+1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi+1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi+1==Fant4.posi && Fant.posj==Fant4.posj))){
            posi_menor = Fant.posi+1;
        }else if((Mapa[Fant.posi][Fant.posj-1]!=Parede1 && Mapa[Fant.posi][Fant.posj-1]!=Parede2 && Mapa[Fant.posi][Fant.posj-1]!=Parede3 && Mapa[Fant.posi][Fant.posj-1]!=Parede4 && Mapa[Fant.posi][Fant.posj-1]!=Parede5 && Mapa[Fant.posi][Fant.posj-1]!=Parede6) &&(!(Fant.posi==Fant2.posi && Fant.posj-1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj-1==Fant3.posj)&&!(Fant.posi==Fant4.posi && Fant.posj-1==Fant4.posj))){
            posj_menor = Fant.posj-1;
        }else if((Mapa[Fant.posi-1][Fant.posj]!=Parede1 && Mapa[Fant.posi-1][Fant.posj]!=Parede2 && Mapa[Fant.posi-1][Fant.posj]!=Parede3 && Mapa[Fant.posi-1][Fant.posj]!=Parede4 && Mapa[Fant.posi-1][Fant.posj]!=Parede5 && Mapa[Fant.posi-1][Fant.posj]!=Parede6) &&(!(Fant.posi-1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi-1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi-1==Fant4.posi && Fant.posj==Fant4.posj))){
            posi_menor = Fant.posi-1;
        }else
        if((Mapa[Fant.posi][Fant.posj+1]!=Parede1 && Mapa[Fant.posi][Fant.posj+1]!=Parede2 && Mapa[Fant.posi][Fant.posj+1]!=Parede3 && Mapa[Fant.posi][Fant.posj+1]!=Parede4 && Mapa[Fant.posi][Fant.posj+1]!=Parede5 && Mapa[Fant.posi][Fant.posj+1]!=Parede6) &&(!(Fant.posi==Fant2.posi && Fant.posj+1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj+1==Fant3.posj)&&!(Fant.posi!=Fant4.posi && Fant.posj+1!=Fant4.posj))){
            posj_menor = Fant.posj+1;
        }
    }
    Fant.posi = posi_menor;
    Fant.posj = posj_menor;

    //Passagem secreta
    if(Fant.posi == 14 && Fant.posj == 0){
        Fant.posi = 14;
        Fant.posj = 28;
    }else if(Fant.posi == 14 && Fant.posj == 28){
        Fant.posi = 14;
        Fant.posj = 0;
    }
    return Fant;
}

//movimento fantasma fugindo do pacman
Personagem movimentoFantInv(char Mapa[31][29], Personagem Fant, Personagem Pac, Personagem Fant2,Personagem Fant3,Personagem Fant4){
    int dist_menor = Calcula_dist(Fant.posi,Fant.posj,Pac.posi,Pac.posj), posi_menor = Fant.posi, posj_menor = Fant.posj;

    // Escolha do menor caminho atraves do calculo de distancia
    //Esquerda
    if((Mapa[Fant.posi-1][Fant.posj]!=Parede1 && Mapa[Fant.posi-1][Fant.posj]!=Parede2 && Mapa[Fant.posi-1][Fant.posj]!=Parede3 && Mapa[Fant.posi-1][Fant.posj]!=Parede4 && Mapa[Fant.posi-1][Fant.posj]!=Parede5 && Mapa[Fant.posi-1][Fant.posj]!=Parede6) && (Calcula_dist(Fant.posi-1,Fant.posj,Pac.posi,Pac.posj)>dist_menor) && (!(Fant.posi-1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi-1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi-1==Fant4.posi && Fant.posj==Fant4.posj))){
        posi_menor = Fant.posi-1;
        posj_menor = Fant.posj;
    }else
    //Direita
    if((Mapa[Fant.posi+1][Fant.posj]!=Parede1 && Mapa[Fant.posi+1][Fant.posj]!=Parede2 && Mapa[Fant.posi+1][Fant.posj]!=Parede3 && Mapa[Fant.posi+1][Fant.posj]!=Parede4 && Mapa[Fant.posi+1][Fant.posj]!=Parede5 && Mapa[Fant.posi+1][Fant.posj]!=Parede6) && (Calcula_dist(Fant.posi+1,Fant.posj,Pac.posi,Pac.posj)>dist_menor)&&(!(Fant.posi+1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi+1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi+1==Fant4.posi && Fant.posj==Fant4.posj))){
        posi_menor = Fant.posi+1;
        posj_menor = Fant.posj;
    }else
    //Cima
    if((Mapa[Fant.posi][Fant.posj-1]!=Parede1 && Mapa[Fant.posi][Fant.posj-1]!=Parede2 && Mapa[Fant.posi][Fant.posj-1]!=Parede3 && Mapa[Fant.posi][Fant.posj-1]!=Parede4 && Mapa[Fant.posi][Fant.posj-1]!=Parede5 && Mapa[Fant.posi][Fant.posj-1]!=Parede6) && (Calcula_dist(Fant.posi,Fant.posj-1,Pac.posi,Pac.posj)>dist_menor)&&(!(Fant.posi==Fant2.posi && Fant.posj-1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj-1==Fant3.posj)&&!(Fant.posi==Fant4.posi && Fant.posj-1==Fant4.posj))){
        posi_menor = Fant.posi;
        posj_menor = Fant.posj-1;
    }else
    //Embaixo
    if((Mapa[Fant.posi][Fant.posj+1]!=Parede1 && Mapa[Fant.posi][Fant.posj+1]!=Parede2 && Mapa[Fant.posi][Fant.posj+1]!=Parede3 && Mapa[Fant.posi][Fant.posj+1]!=Parede4 && Mapa[Fant.posi][Fant.posj+1]!=Parede5 && Mapa[Fant.posi][Fant.posj+1]!=Parede6) && (Calcula_dist(Fant.posi,Fant.posj+1,Pac.posi,Pac.posj)<dist_menor)&&(!(Fant.posi==Fant2.posi && Fant.posj+1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj+1==Fant3.posj)&&!(Fant.posi==Fant4.posi && Fant.posj+1==Fant4.posj))){
        posi_menor = Fant.posi;
        posj_menor = Fant.posj+1;
    }
    //Caminho alternativo
    if(Fant.posi == posi_menor && Fant.posj == posj_menor){
        if((Mapa[Fant.posi-1][Fant.posj]!=Parede1 && Mapa[Fant.posi-1][Fant.posj]!=Parede2 && Mapa[Fant.posi-1][Fant.posj]!=Parede3 && Mapa[Fant.posi-1][Fant.posj]!=Parede4 && Mapa[Fant.posi-1][Fant.posj]!=Parede5 && Mapa[Fant.posi-1][Fant.posj]!=Parede6) && (pow( ((Fant.posi)-1) - (Pac.posi) ,2) > pow( ((Fant.posi) - (Pac.posi)) ,2))&&(!(Fant.posi-1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi-1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi-1==Fant4.posi && Fant.posj==Fant4.posj))){
            posi_menor = Fant.posi-1;
        }else
        if((Mapa[Fant.posi+1][Fant.posj]!=Parede1 && Mapa[Fant.posi+1][Fant.posj]!=Parede2 && Mapa[Fant.posi+1][Fant.posj]!=Parede3 && Mapa[Fant.posi+1][Fant.posj]!=Parede4 && Mapa[Fant.posi+1][Fant.posj]!=Parede5 && Mapa[Fant.posi+1][Fant.posj]!=Parede6) && (pow( ((Fant.posi)+1) - (Pac.posi) ,2) > pow( ((Fant.posi) - (Pac.posi)) ,2))&&(!(Fant.posi+1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi+1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi+1!=Fant4.posi && Fant.posj==Fant4.posj))){
            posi_menor = Fant.posi+1;
        }else
        if((Mapa[Fant.posi][Fant.posj-1]!=Parede1 && Mapa[Fant.posi][Fant.posj-1]!=Parede2 && Mapa[Fant.posi][Fant.posj-1]!=Parede3 && Mapa[Fant.posi][Fant.posj-1]!=Parede4 && Mapa[Fant.posi][Fant.posj-1]!=Parede5 && Mapa[Fant.posi][Fant.posj-1]!=Parede6) && (pow( ((Fant.posj)-1) - (Pac.posj) ,2) > pow( ((Fant.posj) - (Pac.posj)) ,2))&&(!(Fant.posi==Fant2.posi && Fant.posj-1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj-1==Fant3.posj)&&!(Fant.posi==Fant4.posi && Fant.posj-1==Fant4.posj))){
            posj_menor = Fant.posj-1;
        }else
        if((Mapa[Fant.posi][Fant.posj+1]!=Parede1 && Mapa[Fant.posi][Fant.posj+1]!=Parede2 && Mapa[Fant.posi][Fant.posj+1]!=Parede3 && Mapa[Fant.posi][Fant.posj+1]!=Parede4 && Mapa[Fant.posi][Fant.posj+1]!=Parede5 && Mapa[Fant.posi][Fant.posj+1]!=Parede6) && (pow( ((Fant.posj)+1) - (Pac.posj) ,2) > pow( ((Fant.posj) - (Pac.posj)) ,2))&&(!(Fant.posi==Fant2.posi && Fant.posj+1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj+1==Fant3.posj)&&!(Fant.posi==Fant4.posi && Fant.posj+1==Fant4.posj))){
            posj_menor = Fant.posj+1;
        }
    }
    if(Fant.posi == posi_menor && Fant.posj == posj_menor){

        if((Mapa[Fant.posi+1][Fant.posj]!=Parede1 && Mapa[Fant.posi+1][Fant.posj]!=Parede2 && Mapa[Fant.posi+1][Fant.posj]!=Parede3 && Mapa[Fant.posi+1][Fant.posj]!=Parede4 && Mapa[Fant.posi+1][Fant.posj]!=Parede5 && Mapa[Fant.posi+1][Fant.posj]!=Parede6) &&(!(Fant.posi+1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi+1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi+1==Fant4.posi && Fant.posj==Fant4.posj))){
            posi_menor = Fant.posi+1;
        }else if((Mapa[Fant.posi][Fant.posj-1]!=Parede1 && Mapa[Fant.posi][Fant.posj-1]!=Parede2 && Mapa[Fant.posi][Fant.posj-1]!=Parede3 && Mapa[Fant.posi][Fant.posj-1]!=Parede4 && Mapa[Fant.posi][Fant.posj-1]!=Parede5 && Mapa[Fant.posi][Fant.posj-1]!=Parede6) &&(!(Fant.posi==Fant2.posi && Fant.posj-1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj-1==Fant3.posj)&&!(Fant.posi==Fant4.posi && Fant.posj-1==Fant4.posj))){
            posj_menor = Fant.posj-1;
        }else if((Mapa[Fant.posi-1][Fant.posj]!=Parede1 && Mapa[Fant.posi-1][Fant.posj]!=Parede2 && Mapa[Fant.posi-1][Fant.posj]!=Parede3 && Mapa[Fant.posi-1][Fant.posj]!=Parede4 && Mapa[Fant.posi-1][Fant.posj]!=Parede5 && Mapa[Fant.posi-1][Fant.posj]!=Parede6) &&(!(Fant.posi-1==Fant2.posi && Fant.posj==Fant2.posj)&&!(Fant.posi-1==Fant3.posi && Fant.posj==Fant3.posj)&&!(Fant.posi-1==Fant4.posi && Fant.posj==Fant4.posj))){
            posi_menor = Fant.posi-1;
        }else
        if((Mapa[Fant.posi][Fant.posj+1]!=Parede1 && Mapa[Fant.posi][Fant.posj+1]!=Parede2 && Mapa[Fant.posi][Fant.posj+1]!=Parede3 && Mapa[Fant.posi][Fant.posj+1]!=Parede4 && Mapa[Fant.posi][Fant.posj+1]!=Parede5 && Mapa[Fant.posi][Fant.posj+1]!=Parede6) &&(!(Fant.posi==Fant2.posi && Fant.posj+1==Fant2.posj)&&!(Fant.posi==Fant3.posi && Fant.posj+1==Fant3.posj)&&!(Fant.posi!=Fant4.posi && Fant.posj+1!=Fant4.posj))){
            posj_menor = Fant.posj+1;
        }
    }
    Fant.posi = posi_menor;
    Fant.posj = posj_menor;
    return Fant;
}
