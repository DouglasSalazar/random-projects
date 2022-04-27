#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#define BACKSPACE 8

typedef struct no{
	char c[80];
	struct no *ant,*prox;

}ls;

void inicializa(ls * lista){
int i;

	for(i=0;i<=80;i++){
		lista->c[i]=32;
	}
	lista->prox=NULL;
}

void imprimi(WINDOW *janela1, ls *lista,int x,int y){
int i;
	wmove(janela1,y,x);
	for(i=0;i<=5;i++){
		wprintw(janela1,"%c",lista->c[i]);
	}
}

int main(){
WINDOW *janela1; /*Variavel ncurses*/
int key;
int x=0;
int y=0;
ls *lista=NULL;
ls *aux=NULL;
ls *raiz=NULL;

	initscr();      /* initialize the curses library */
	raw();
	noecho();
 	keypad(stdscr, TRUE);  /* enable keyboard mapping */
	janela1=newwin(15,80,0,0);
	wmove(janela1,x,y); /*posiciona cursor*/
	scrollok(janela1, TRUE);
	start_color();
	lista=malloc(sizeof(ls));
	raiz=lista;
	lista->prox=NULL;
	lista->ant=NULL;
	inicializa(lista);
    while(key!=27){
        init_pair(1,COLOR_BLACK,COLOR_WHITE);
        wbkgd(janela1,COLOR_PAIR(1));
        key=0;
        fflush(stdin);
        key=mvgetch(y,x);
      /*  if(lista->prox!=NULL){
            printf("%d",x);
            exit(1);
        }*/
            switch(key){
                case KEY_LEFT:
                    wmove(janela1,y,x--);
                break;
	            case KEY_RIGHT:
	                wmove(janela1,y,x++);
                break;
	            case KEY_UP:
                    if(y>1){
                        wmove(janela1,y--,x);
                        lista=lista->ant;
                    }
                break;
	            case KEY_DOWN:
	                wmove(janela1,y++,x);
                    if(lista->prox!=NULL){
                        lista = lista->prox;
                    }else{
                        aux=malloc(sizeof(ls));
                        lista->prox=aux;
                        aux->ant=lista;
                        lista = lista->prox;
                        inicializa(lista);
                    }
                break;
                case BACKSPACE:
                    if(x>=0){
                        wmove(janela1,y,x--);
                        lista->c[x] = 32;
                        wprintw(janela1,"%c",lista->c[x]);
                    }else{
                        if(y>0){
                            lista->c[x] = 32;
                            wprintw(janela1,"%c",lista->c[x]);
                            wmove(janela1,y,x--);
                            x=80;
                            y--;
                            lista= lista->ant;
                        }
                    }
                    if(x==0 && y>=1){
                        scrl(-1);
                        x=80;
                        y--;
                        lista=lista->ant;
                        imprimi(janela1,lista,x,y);
                    }
                break;
                case KEY_ENTER:
                    if(x==80){
                        scrl(1);
                        y++;
                        x=0;
                        if(lista->prox!=NULL){
                            lista= lista->prox;
                        }else{
                            aux=malloc(sizeof(ls));
                            lista->prox=aux;
                            aux->ant=lista;
                            lista = lista->prox;
                            inicializa(lista);
                        }
                    }
                break;
		}
		if ((key != KEY_UP) && (key != KEY_DOWN) && (key != KEY_LEFT) && (key != KEY_RIGHT) && (key != BACKSPACE) && (key != 27)){
			lista->c[x]=key;
			wprintw(janela1,"%c",lista->c[x]);
			x++;
			wmove(janela1,y,x);
			if(x>80){
				x=0;
				y++;
				if(lista->prox==NULL){
					aux=malloc(sizeof(ls));
					lista->prox=aux;
					aux->ant=lista;
					lista = lista->prox;
					inicializa(lista);
				}else{
					lista = lista->prox;
				}
				wmove(janela1,y,x);
			}
		}
		wrefresh(janela1);/*atualiza a tela*/
	}
    do{
        do{
            if(aux->prox != NULL){
                aux=aux->prox;
            }
        }while(aux->prox!=NULL);
        free(aux);
        aux=raiz;
    }while(raiz!=NULL);
	endwin();/*Finaliza a Ncurses*/
	return 0;
}
