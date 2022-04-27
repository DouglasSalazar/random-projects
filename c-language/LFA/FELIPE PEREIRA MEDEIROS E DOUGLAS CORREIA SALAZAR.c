/*NOMES: FELIPE PEREIRA MEDEIROS RGM: 
         DOUGLAS CORREIA SALAZAR RGM:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void imprimi(char st[100]){
    printf("\nNumero: %s    Valor: %s\n",st,st);

}
/* Funcao para imprimir caracteres numericos*/
void Crack_file (FILE *File){
    char ant,x,Ci,Cf;/*Declaração de variaveis utilizadas, x sera a variavel que ira percorrer o arquivo, as variaveis Ci e Cf são respectivamente "Caractere inicial" e "Caractere final" que serão utilizados na verificacao do comentario em uma das situacoes, "ant" eh a variavel utilizada para a segunda verificação de comentario.*/
    char st[100];/*String que armazenara todo caractere numerico encontrado no arquivo*/
    int ver,i=0;/*contador e variavel verificadora de comentario na segunda situação*/
    do{
        fscanf(File,"%c",&x);/*Leitura do primeiro caractere do arquivo*/
        if (x==' '||feof(File)||x=='\n'){ /*Verificaçao para imprimir os caracteres numericos armazenados*/
            st[i]='\0';
            if(i!=0){
                imprimi(st);
                i=0;
            }
        }
        if (x!=' '){/*Verificacao para excluir comentarios ( Primeiro caso)*/
            if(x=='/'|| ver==1){
                fscanf(File,"%c",&x);
                if((x=='*')||(ver ==1)){
                    do{
                        ver =0;
                        fscanf(File,"%c",&Ci);
                        fscanf(File,"%c",&Cf);
                    }while ((Ci!= '*' && Cf!='/') || (Ci != '*' && Cf != ' '));
                    fscanf(File,"%c",&x);
                    fscanf(File,"%c",&x);
                }
            }
        }
        if((x >47 && x<58) || x==46 || x==45 ){/*Verificação para captar caracteres numericos*/
                    st[i]=x;
                    i=i+1;
            }else{/*Caso nao seja numerico o caractere sera indentificador (tendo em vista que ja excluimos os comentarios no primeiro caso*/
                if(x!='\n'&& x!= ' '){
                    printf("\nIndentificador: ");
                    do{
                        ant = x;
                        printf("%c",x);
                        fscanf(File,"%c",&x);
                        if((ant=='/'&&x=='*')){
                            ver = 1;/*Caso haja um comentario no meio do indentificador ( Segundo caso)*/
                        }
                    }while(x != ' '&& x!= '\n'&&!feof(File)&& ver!= 1);
                    printf("\n");
                }
            }
    }while(!feof(File));/*O processo de Leitura do arquivo ocorre ate ele ser finalizado*/
}
/*Funcao para identificar o arquivo texto.*/
int main(){
    FILE *File;
    if ((File = fopen("Text.txt","r+"))!=NULL){
    ;}else{
        File = fopen("Text.txt","w+");
    }/*Abertura do arquivo*/
    Crack_file(File);/*Chamada da funcao para leitura do arquivo*/
    fclose(File);/*Fechar do arquivo*/
    return 0;
}
/*Chamada principal.*/
