#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

typedef struct personagem{
    char nome;
    int posi;
    int posj;
    int direcao;
}Personagem;

void lerMapa(char Mapa[31][29]);
void Imprimi_Mapa(char Mapa[31][29], Personagem Pac,Personagem Fant1,Personagem Fant2,Personagem Fant3,Personagem Fant4, int cont);
void inicializaPersonagem(Personagem *Pac,Personagem *Fant1,Personagem *Fant2,Personagem *Fant3,Personagem *Fant4);
int movimentoPacman(char Mapa[31][29], Personagem *Pac, int *Ponto,Personagem *Fant1,Personagem *Fant2,Personagem *Fant3,Personagem *Fant4, int * MovFantasma, int *contFruta);
Personagem movimentoFant(char Mapa[31][29], Personagem Fant, Personagem Pac, Personagem Fant2,Personagem Fant3,Personagem Fant4);
Personagem movimentoFantInv(char Mapa[31][29], Personagem Fant, Personagem Pac, Personagem Fant2,Personagem Fant3,Personagem Fant4);
void adionarFruta(char Mapa[31][29], int * posi_Fruta, int *posj_Fruta);
#endif // PACMAN_H_INCLUDED
