#include "gfx.h"
#include <stdio.h>  /* printf */
#include <unistd.h> /* sleep  */
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

#define X 10
#define Y 26
#define X1 200
#define Y1 46

#define X_Pasta 260
#define Y_Pasta 26
#define X1_Pasta 360
#define Y1_Pasta 126

typedef struct pontos{
	float x,x1,y,y1;
}Pontos;

typedef struct direti{
	char name[256];
	unsigned char type;
}diretorio;

void explorer_init(char caminho[100]){
	gfx_set_color(0, 255, 0);
	gfx_rectangle(1, 20, 999, 1);/*Retangulo caminho*/
	gfx_rectangle(1, 20, 999, 1);/*Retangulo caminho*/
	gfx_rectangle(1, 649, 250, 20);/*Retangulo explorer*/
	gfx_rectangle(250, 20, 999, 550);/*Retangulo Pastas*/
	gfx_rectangle(250, 550, 999, 550);/*Retangulo Pastas*/
	gfx_rectangle(250, 550, 999, 650);/*Retangulo Descrição*/
	gfx_text(254, 559, "Descricao:");/*Texto Descrição*/
	gfx_text(943, 2, "Voltar");/*Texto Voltar*/
	gfx_rectangle(940, 20, 999, 1);/*Retangulo Voltar dir*/
	gfx_rectangle(860, 20, 940, 1);/*Retangulo Ordenar*/
	gfx_text(863, 2, "Ordenacao");/*Texto Ordenar*/
	gfx_text(3, 1, caminho);/*Texto Caminho*/
	gfx_paint();
}

void caminho_texto(char caminho[100]){
	gfx_set_color(0, 0, 0);
	gfx_filled_rectangle(1, 20, 790, 1);/*Retangulo caminho*/
	gfx_set_color(0, 255, 0);
	gfx_rectangle(1, 20, 999, 1);/*Retangulo caminho*/
	gfx_text(3, 1, caminho);/*Texto Caminho*/
	gfx_paint();
}

void descricao(char nome[256],char tipo[40],char caminho[100],int flag){
struct stat buf;
struct passwd *Prop;
struct group * grupo;
char aux[200];
char * accesses[] = {"---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};
int i;
char perm[9];
	perm[0]='\0';
	stat(caminho,&buf);
 	Prop = getpwuid(buf.st_uid);/*coletando nome proprietario*/
	grupo = getgrgid(buf.st_gid);/*coletando nome do grupo*/
	sprintf(aux,"Tamanho: %d Bytes",(int)buf.st_size);
	gfx_set_color(0, 0, 0);
	gfx_filled_rectangle(250, 550, 999, 650);/*Retangulo Descrição*/
	gfx_set_color(0, 255, 0);
	gfx_rectangle(250, 550, 999, 650);/*Retangulo Descrição*/
	gfx_text(254, 560, "Descricao:");/*Texto Descrição*/
	gfx_text(254, 580, "Nome:");/*Nome arquivo*/
	gfx_text(300, 580, nome);/*Nome arquivo*/
	gfx_text(500, 580, aux);/*Nome nome*/
	gfx_text(700, 580, "Permicoes:");/*Nome permissoes*/
	for(i = 6; i >= 0; i -=3){/*permissoes*/
		sprintf(aux,"%s", accesses[(buf.st_mode >> i) & 7]);
		strcat(perm,aux);
	}
	gfx_text(780, 580, perm);/*Nome arquivo*/
	sprintf(aux,"Proprietario: %s ",Prop->pw_name);
	gfx_text(500, 620, aux);/*Nome Proprietario*/
	sprintf(aux,"Grupo: %s ",grupo->gr_name);
	gfx_text(700, 620, aux);/*Nome Grupo*/
	gfx_text(254, 600, caminho);/*Nome caimho*/
	gfx_text(254, 620, tipo);/*Nome tipo*/

	if(flag==1){
		flag=0;
		gfx_text(400, 250, "Voce nao tem as permissoes necessarias para ver o conteudo");
		gfx_set_font_size(30);
		gfx_text(410, 180, "Nao foi possivel exibir o local");
		gfx_set_font_size(14);
	}
	gfx_paint();
}

void explorer_menu(int *aux,diretorio lista_diretorio[200],int control){/*desenho de menu lateral*/
	gfx_set_color(0, 255, 0);
	gfx_rectangle(X, Y+*aux, X1, Y1+*aux);
	gfx_text(X+2, Y+*aux+2, lista_diretorio[control].name);/*Texto Descrição*/
	*aux=*aux+24;
	gfx_paint();
}

void explorer_pastas(int *aux_pasta, int *aux1_pasta,char nome[256]){/*desenho de pastas*/
char aux[246];
	strcpy(aux,nome);
	if(strlen(aux)>22){
		aux[22]='.';
		aux[23]='.';
		aux[24]='.';
		aux[25]='\0';
	}
	gfx_set_color(0, 255, 0);
	gfx_rectangle(X_Pasta+*aux1_pasta, Y_Pasta+*aux_pasta, X1_Pasta+*aux1_pasta, Y1_Pasta+*aux_pasta);
	gfx_text(X_Pasta+*aux1_pasta+2, Y1_Pasta+*aux_pasta+2, aux);/*Texto Descrição*/
	*aux1_pasta=*aux1_pasta+200;
	if(X1+*aux1_pasta > 993){
		*aux_pasta=*aux_pasta+200;
		*aux1_pasta=0;
	}
	gfx_paint();	

}

void remove_pasta(){/*apaga pastas para resedesenhar*/
	gfx_set_color(0, 0, 0);
	gfx_filled_rectangle(250, 20, 1000, 550);
	gfx_set_color(0, 255, 0);
	gfx_rectangle(250, 20, 1000, 550);/*Atualiza Pastas*/
	gfx_paint();	
}

void type_arq(diretorio list,char tipo[40]){/*verificacao de diretorio*/

	switch(list.type){
		case DT_BLK:
			strcpy(tipo,"This is a block device.");
		break;
	      	case DT_CHR:
			strcpy(tipo,"This is a character device.");
		break;
	      	case DT_DIR:
			strcpy(tipo,"This is a directory.");
		break;
	      	case DT_FIFO:
			strcpy(tipo,"This is a named pipe (FIFO).");
		break;
	      	case DT_LNK:
			strcpy(tipo,"This is a symbolic link.");
		break;
	      	case DT_REG:
			strcpy(tipo,"This is a regular file.");
		break;
	      	case DT_SOCK:
			strcpy(tipo,"This is a UNIX domain socket.");
		break;
	      	case DT_UNKNOWN:
			strcpy(tipo,"The file type is unknown.");
		break;
	}
}

int arquivo(char caminho[100]){
	FILE * arq=NULL;
	uint8_t cabecalho2[8];		
	pid_t pid;

	arq=fopen(caminho,"rb");

	if(arq!=NULL){
		fread(&cabecalho2,sizeof(uint32_t),8,arq);
		
		if(cabecalho2[0]==37 && cabecalho2[1]==80 && cabecalho2[2]==68 && cabecalho2[3]==70){/*executa pdf*/
			if((pid=fork())>=0){
				if(pid==0){
					execl("/usr/bin/evince","./evince",caminho,NULL);
					return 10;
				}else{
					return 10;
				}
			}	
		}else if(cabecalho2[0]==74 && cabecalho2[1]==70 && cabecalho2[2]==73 && cabecalho2[3]==70){/*jpge*/
			if((pid=fork())>=0){
				if(pid==0){
					execl("/usr/bin/eog","./eog",caminho,NULL);
					return 10;	
				}
			}
			return 10;	
		}else if(cabecalho2[0]==127 && cabecalho2[1]==69 && cabecalho2[2]==76 && cabecalho2[3]==70){/*executaveel*/
			if((pid=fork())>=0){
				if(pid==0){
					execl(caminho,"./",NULL);
					return 10;	
				}
			}
			return 10;	
		}else if(cabecalho2[0]==137 && cabecalho2[1]==80 && cabecalho2[2]==78 && cabecalho2[3]==71 && cabecalho2[4]==13 && cabecalho2[5]==10&& cabecalho2[6]==26 && cabecalho2[7]==10){/*png*/
			if((pid=fork())>=0){
				if(pid==0){
					execl("/usr/bin/eog","./eog",caminho,NULL);
					return 10;	
				}
			}
			return 10;	
		}else if(cabecalho2[0]==35 && cabecalho2[1]==33){/*shell*/
			if((pid=fork())>=0){
				if(pid==0){
					execl("/bin/bash","./bash",caminho,NULL);
					return 10;	
				}
			}
			return 10;
		}else{/*arquivos*/
			if((pid=fork())>=0){
				if(pid==0){
					execl("/usr/bin/gedit","./gedit",caminho,NULL);
					return 10;	
				}
			}
			return 10;	
		}
		fclose(arq);
	}else{
		return -1;
	}
	return -1;
}

void barra(int B_cima,int B_baixo){
	gfx_set_color(0, 0, 0);
	gfx_filled_rectangle(980, 20, 999, 550);
	gfx_set_color(0, 255, 0);
	gfx_rectangle(980, 20, 1000, 550);
	gfx_set_color(0, 255, 0);
	gfx_filled_rectangle(985, 40+B_cima, 995, 40+B_baixo);/*rolagem barra lateral*/
	
	gfx_rectangle(980, 20, 999, 40);
	gfx_line(983, 37, 990,20);
	gfx_line(990, 20, 996,37);
	gfx_rectangle(980, 530, 999, 550);
	gfx_line(983, 533, 990,550);
	gfx_line(990, 550, 997,533);
	gfx_paint();
}

void ordena(int pos_pat, diretorio lista_past[10000]){/*ordenaçõa de pasta*/
	int i,j;
	diretorio aux;

	for(i=0;i<pos_pat;i++){
		for(j=0;j<pos_pat-1;j++){
			if(strcmp(lista_past[j].name,lista_past[j+1].name)>0){
				aux=lista_past[j];
				lista_past[j]=lista_past[j+1];
				lista_past[j+1]=aux;
			}
		}
	}
}

int main(){
	char caminho[100];
	char tipo_arquivo[40];
	int aux=0,aux1_pasta=0,aux_pasta=0,i=0,control=0,var=0;
	
	int pos_dir=0,pos_pat=0,pos_caminho=0, max_past=0,min_past=0;

	int B_cima=0,B_baixo=0,B_control_max=0; /*variaveis barra*/

	diretorio lista_diretorio[50];/*diretorio raiz*/
	diretorio lista_caminho[200];/*lista do caminho*/
	diretorio lista_past[10000];/*lista de pasta*/

	Pontos campos_explorer[200];	
	Pontos campo_pasta[12];

	struct dirent *d=NULL;
	DIR * dir=NULL;	
	
	SDL_Event event;

	gfx_init(1000,650, "Explorer");
	dir=opendir("/");
	caminho[0]='/';
	caminho[1]='\0';
	barra(B_cima,B_baixo);
	if(dir!=NULL){
		while((d=readdir (dir))!=NULL){	/*abre diretorio raiz*/	
			if(strcmp(d->d_name,"..")!=0 && strcmp(d->d_name,".")!=0){
				strcpy(lista_diretorio[pos_dir].name,d->d_name);
				lista_diretorio[pos_dir].type=d->d_type;
				pos_dir++;
			}
		}
	}
	closedir(dir);
	while(control<12){/*posiçioes pastas*/
		campo_pasta[control].x=X_Pasta+aux1_pasta;
		campo_pasta[control].y=Y_Pasta+aux_pasta;
		campo_pasta[control].x1=X1_Pasta+aux1_pasta;
		campo_pasta[control].y1=Y1_Pasta+aux_pasta;
		aux1_pasta=aux1_pasta+200;
		if(X1+aux1_pasta > 993){
			aux_pasta=aux_pasta+200;
			aux1_pasta=0;
		}
		control++;
	}
	aux_pasta=0;
	aux1_pasta=0;
	control=0;
	while(aux!=24*pos_dir){/*posicoes explorer lateral*/
		campos_explorer[control].x=X;
		campos_explorer[control].y=Y+aux;
		campos_explorer[control].x1=X1;
		campos_explorer[control].y1=Y1+aux;
		explorer_menu(&aux,lista_diretorio,control);
		control++;
	}
	
	explorer_init(caminho);
	while(var!=1){
		while(gfx_get_event(&event)!=0);
		switch(event.type){
			case SDL_QUIT:
				var=1;
			break;
			case SDL_MOUSEBUTTONUP:
				if(event.button.button==1 && event.button.state == SDL_RELEASED){
					if((float)event.button.x<250){
						while(i<pos_dir){
							if(((float)event.button.x>campos_explorer[i].x && (float)event.button.x<campos_explorer[i].x1)&&((float)event.button.y>campos_explorer[i].y && (float)event.button.y<campos_explorer[i].y1)){/*vericacao menu lateral*/
								caminho[0]='/';
								caminho[1]='\0';
								strcat(caminho,lista_diretorio[i].name);
								pos_caminho=0;
								lista_caminho[pos_caminho]=lista_diretorio[i];/*lista de caminho*/
								type_arq(lista_diretorio[i],tipo_arquivo);
								remove_pasta();								
								dir=opendir(caminho);
								if(dir==NULL){
									if(arquivo(caminho)<0){/*abre arquivo*/
										descricao(lista_diretorio[i].name,tipo_arquivo,caminho,1);/*descricoes*/
										max_past=-1;
										min_past=-1;
									}
								}else
									descricao(lista_diretorio[i].name,tipo_arquivo,caminho,0);		
								caminho_texto(caminho);
								if(dir!=NULL){
									pos_pat=0;
									while((d=readdir (dir))!=NULL){		
										if(strcmp(d->d_name,"..")!=0 && strcmp(d->d_name,".")!=0){
											strcpy(lista_past[pos_pat].name,d->d_name);
											lista_past[pos_pat].type=d->d_type;
											pos_pat++;
										}
									}
									closedir(dir);
									min_past=0;
									max_past=0;
									aux1_pasta=0;
									aux_pasta=0;
									while((max_past-min_past)<12 && max_past<pos_pat){
										explorer_pastas(&aux_pasta,&aux1_pasta,lista_past[max_past].name);
										max_past++;
									}
									if(pos_pat!=12){
										B_control_max=(pos_pat/12)+1;
										B_cima=0;
										B_baixo=490/(B_control_max);
									}else{
										B_control_max=(pos_pat/12);
										B_cima=0;
										B_baixo=490/(B_control_max);
									}
									barra(B_cima,B_baixo);
								}
								i=300;
							}
							i++;		
						}
						i=0;
					}else if(((int)event.button.x>980 && (int)event.button.x<1000)&&((int)event.button.y>530 && (int)event.button.y<550)&& (min_past>=0 && max_past>=0)){/*imprimi pastas down*/
						if(max_past<pos_pat){
							remove_pasta();
							min_past=max_past;
							aux1_pasta=0;
							aux_pasta=0;
							while((max_past-min_past)<12 && max_past<pos_pat){
								explorer_pastas(&aux_pasta,&aux1_pasta,lista_past[max_past].name);
								max_past++;
							}
							B_cima=B_baixo;
							B_baixo+=(490/(B_control_max));
						}
						barra(B_cima,B_baixo);
					}else if(((int)event.button.x>980 && (int)event.button.x<1000)&&((int)event.button.y>20 && (int)event.button.y<40)&& (min_past>=0 && max_past>=0)){/*imprimi pastas up*/
						aux1_pasta=0;
						aux_pasta=0;
						if(min_past-12>=0){
							remove_pasta();
							min_past=min_past-12;
							max_past=min_past;
							while((max_past-min_past)<12 && max_past<pos_pat){
								explorer_pastas(&aux_pasta,&aux1_pasta,lista_past[max_past].name);
								max_past++;
							}
							B_baixo=B_cima;
							B_cima-=(490/(B_control_max));
						}
						barra(B_cima,B_baixo);
					}else if(((int)event.button.x>250 && (int)event.button.x<1000)&&((int)event.button.y>20 && (int)event.button.y<550)){
						while(i<pos_dir){
							if(((float)event.button.x>campo_pasta[i].x && (float)event.button.x<campo_pasta[i].x1)&&((float)event.button.y>campo_pasta[i].y && (float)event.button.y<campo_pasta[i].y1) && (min_past>=0 && max_past>=0)){/*verificao pasta*/
								strcat(caminho,"/");
								strcat(caminho,lista_past[min_past+i].name);
								pos_caminho++;
								lista_caminho[pos_caminho]=lista_past[min_past+i];/*impressao caminho*/
								type_arq(lista_past[min_past+i],tipo_arquivo);
								remove_pasta();
								caminho_texto(caminho);
								dir=opendir(caminho);
								if(dir==NULL){
									if(arquivo(caminho)<0){
										descricao(lista_diretorio[i].name,tipo_arquivo,caminho,1);
										max_past=-1;
										min_past=-1;
									}
								}else
									descricao(lista_diretorio[i].name,tipo_arquivo,caminho,0);		
								caminho_texto(caminho);
								if(dir!=NULL){
									pos_pat=0;
									while((d=readdir (dir))!=NULL){		
										if(strcmp(d->d_name,"..")!=0 && strcmp(d->d_name,".")!=0){
											strcpy(lista_past[pos_pat].name,d->d_name);
											lista_past[pos_pat].type=d->d_type;
											pos_pat++;
										}
									}
									closedir(dir);
									
									min_past=0;
									max_past=0;
									aux1_pasta=0;
									aux_pasta=0;
									while((max_past-min_past)<12 && max_past<pos_pat){
										explorer_pastas(&aux_pasta,&aux1_pasta,lista_past[max_past].name);
										max_past++;
									}
									if(pos_pat!=12){
										B_control_max=(pos_pat/12)+1;
										B_cima=0;
										B_baixo=490/(B_control_max);
									}else{
										B_control_max=(pos_pat/12);
										B_cima=0;
										B_baixo=490/(B_control_max);
									}
									barra(B_cima,B_baixo);
								}
								i=300;
							}
							i++;		
						}
						i=0;
					}else if(((int)event.button.x>940 && (int)event.button.x<999)&&((int)event.button.y>1 && (int)event.button.y<20)){/*opcao voltar*/
						i=strlen(caminho);
						while(caminho[i]!='/' ){	
							i--;	
						}
						if(i>0){
							caminho[i]='\0';					
							remove_pasta();
							caminho_texto(caminho);/*imprimi caminho*/
							dir=opendir(caminho);
							if(dir!=NULL){
								pos_caminho--;
								type_arq(lista_caminho[pos_caminho],tipo_arquivo);/*verifica tipo de arquivo*/
								descricao(lista_caminho[pos_caminho].name,tipo_arquivo,caminho,0);/*descricao caminho*/
								pos_pat=0;
								while((d=readdir (dir))!=NULL){		
									if(strcmp(d->d_name,"..")!=0 && strcmp(d->d_name,".")!=0){
										strcpy(lista_past[pos_pat].name,d->d_name);
										lista_past[pos_pat].type=d->d_type;
										pos_pat++;
									}
								}
								closedir(dir);
								min_past=0;
								max_past=0;
								aux1_pasta=0;
								aux_pasta=0;
								while((max_past-min_past)<12 && max_past<pos_pat){
									explorer_pastas(&aux_pasta,&aux1_pasta,lista_past[max_past].name);
									max_past++;
								}
								if(pos_pat!=12){
									B_control_max=(pos_pat/12)+1;
									B_cima=0;
									B_baixo=490/(B_control_max);
								}else{
									B_control_max=(pos_pat/12);
									B_cima=0;
									B_baixo=490/(B_control_max);
								}
								barra(B_cima,B_baixo);
							}
						}
						i=0;
					}else if(((int)event.button.x>860 && (int)event.button.x<940)&&((int)event.button.y>1 && (int)event.button.y<20)){
						ordena(pos_pat,lista_past);/*ordenacao de pasta*/
						remove_pasta();
						min_past=0;
						max_past=0;
						aux1_pasta=0;
						aux_pasta=0;
						while((max_past-min_past)<12 && max_past<pos_pat){
							explorer_pastas(&aux_pasta,&aux1_pasta,lista_past[max_past].name);
							max_past++;
						}
						if(pos_pat!=12){/*barra de rolagem*/
							B_control_max=(pos_pat/12)+1;
							B_cima=0;
							B_baixo=490/(B_control_max);
						}else{
							B_control_max=(pos_pat/12);
							B_cima=0;
							B_baixo=490/(B_control_max);
						}
						barra(B_cima,B_baixo);
					}
				}
			break; 
		}
		event.type=0;
	}
	gfx_quit();
	return 0;
}
