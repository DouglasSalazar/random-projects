#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <cryptlib.h>
#include <aes.h>
#include <osrng.h>
#include <modes.h>
#include <gtk/gtk.h>

using namespace CryptoPP;
using namespace std;
GtkWidget *janela, *label;

char aux[100];

byte* gerador_divisao_bloco(void) {
    AutoSeededRandomPool rnd;
    byte* iv = new byte[AES::MAX_KEYLENGTH+1];
    rnd.GenerateBlock(iv, AES::MAX_KEYLENGTH);
    iv[AES::MAX_KEYLENGTH] = '\0';
    return iv;
}

byte* gerador_chave(void) {
    AutoSeededRandomPool rnd;
    byte* chave = new byte[AES::MAX_KEYLENGTH+1];
    rnd.GenerateBlock(chave, AES::MAX_KEYLENGTH);
    chave[AES::MAX_KEYLENGTH] = '\0';
    return chave;
}

struct thread_data{
 int m_id;
 thread_data(int id) : m_id(id) {}
};

DWORD WINAPI thread_func(LPVOID lpParameter){
    thread_data *td = (thread_data*)lpParameter;
    GtkWidget *janela, *label;
    gtk_init(NULL,NULL);

    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW (janela),200,100);
    gtk_window_set_title(GTK_WINDOW (janela), "TrueCipher");
    gtk_window_set_position(GTK_WINDOW (janela),GTK_WIN_POS_CENTER_ALWAYS);
    gtk_window_set_deletable(GTK_WINDOW (janela), FALSE);
    label = gtk_label_new (aux);
    gtk_container_add (GTK_CONTAINER (janela), label);
    gtk_widget_show (label);
    gtk_widget_show(janela);

    gtk_main();
}

void convert(char* Entrada){
  int i,cmp=strlen(Entrada);
  for(i=0; i<cmp;i++){
    if(Entrada[i]=='\n' || Entrada[i]=='\a'){
        Entrada[i]='\0';
    }else if(Entrada[i]=='\\'){
        Entrada[i]='/';
   }
  }
}

int criptografa_AES(char * Entrada, char * Saida, char * iv_aux, char *chave_aux){
    byte * iv = (byte*)iv_aux;
    byte * chave = (byte*)chave_aux;
	char c='\0';
	char buffer[10];
    uint8_t buffer2[20];
    uint32_t tamanho_arq=0,i=0, divisao = 0 ;
	FILE *menssagem; //Arquivo Descriptografado
	FILE *crypto_menssagem; //Arquivo Criptografado

	if ((menssagem=fopen(Entrada, "rb"))==NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO MENSAGEM\n");
		return -1;
    }else{
        if ((crypto_menssagem=fopen(Saida, "w+b"))==NULL){
            printf("ERRO NA ABERTURA DO ARQUIVO CRYPTOTOMSG\n");
            return -2;
        }else{
            fseek(menssagem, 0, SEEK_END);
            tamanho_arq = ftell(menssagem);
            fseek(menssagem, 0, SEEK_SET);
            divisao=tamanho_arq/10;

            if((tamanho_arq%10)!=0)
                divisao--;
            fwrite(&divisao, sizeof(uint32_t), 1, crypto_menssagem);
            c=' ';
            for(i=0;i<divisao;i++){
                memset(&buffer,0,sizeof(buffer));
                if(fread(&buffer,sizeof(char),10,menssagem)>0){

                    CFB_Mode<AES>::Encryption cfbEncryption(chave, AES::MAX_KEYLENGTH, iv);
                    cfbEncryption.ProcessData((byte*)buffer, (byte*)buffer, 10);

                    fwrite(&c,sizeof(char),1,crypto_menssagem);
                    fwrite(buffer,sizeof(char),10,crypto_menssagem);
                }
            }
            if((tamanho_arq%10)!=0){
                divisao=divisao*10;
                divisao=tamanho_arq-divisao;

                fwrite(&c,sizeof(char),1,crypto_menssagem);
                fwrite(&divisao,sizeof(uint32_t),1,crypto_menssagem);

                memset(&buffer2,0,sizeof(buffer2));
                if(fread(&buffer2,sizeof(char),divisao,menssagem)>0){

                    CFB_Mode<AES>::Encryption cfbEncryption(chave, AES::MAX_KEYLENGTH, iv);
                    cfbEncryption.ProcessData((byte*)buffer2, (byte*)buffer2, divisao);

                    fwrite(&c,sizeof(char),1,crypto_menssagem);
                    fwrite(buffer2,sizeof(char),divisao,crypto_menssagem);
                }
            }
            fclose(crypto_menssagem);
            fclose(menssagem);
        }
    }
    return 0;
}

int descriptografa_AES(char* Entrada, char * Saida, char * iv_aux, char *chave_aux){
    byte * iv = (byte*)iv_aux;
    byte * chave = (byte*)chave_aux;
	char c='\0';
	char buffer[10];
    char buffer2[20];
    uint32_t divisao=0,i;

	FILE *descrypt_menssagem; //Arquivo Descriptografado
	FILE *crypto_menssagem; //Arquivo Criptografado

	if ((crypto_menssagem=fopen(Entrada, "rb"))==NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO MENSAGEM\n");
		return -1;
    }else{
        if ((descrypt_menssagem=fopen(Saida, "w+b"))==NULL){
            printf("ERRO NA ABERTURA DO ARQUIVO CRYPTOTOMSG\n");
            return -2;
        }else{

            fread(&divisao,sizeof(uint32_t),1,crypto_menssagem);

            for(i=0;i<divisao;i++){
                fread(&c,sizeof(char),1,crypto_menssagem);
                if(!feof(crypto_menssagem)){
                        memset(&buffer,0,sizeof(buffer));
                        if(fread(&buffer,sizeof(char),10,crypto_menssagem)>0){

                            CFB_Mode<AES>::Decryption cfbDecryption(chave, AES::MAX_KEYLENGTH, iv);
                            cfbDecryption.ProcessData((byte*)buffer, (byte*)buffer, 10);

                            fwrite(buffer,sizeof(char),10,descrypt_menssagem);
                        }
                }
            }

            if(!feof(crypto_menssagem)){
                fread(&c,sizeof(char),1,crypto_menssagem);
                fread(&divisao,sizeof(uint32_t),divisao,crypto_menssagem);
                fread(&c,sizeof(char),1,crypto_menssagem);

                memset(&buffer2,0,sizeof(buffer2));
                if(fread(&buffer2,sizeof(char),divisao,crypto_menssagem)>0){

                    CFB_Mode<AES>::Decryption cfbDecryption(chave, AES::MAX_KEYLENGTH, iv);
                    cfbDecryption.ProcessData((byte*)buffer2, (byte*)buffer2, divisao);

                    fwrite(buffer2,sizeof(char),divisao,descrypt_menssagem);
                }
            }

            fclose(crypto_menssagem);
            fclose(descrypt_menssagem);
        }
    }
    return 0;
}

int Compartilhar(char* Entrada, char * Saida, char * iv_aux, char *chave_aux, char * iv_aux_saida, char *chave_aux_saida){
    byte * iv = (byte *) iv_aux;
    byte * chave = (byte *) chave_aux;
    byte * iv_saida = (byte *) iv_aux_saida;
    byte * chave_saida = (byte *) chave_aux_saida;

	char c='\0';
	char buffer[10];
    char buffer2[20];
    uint32_t divisao=0,i;

	FILE *descrypt_menssagem; //Arquivo Descriptografado
	FILE *crypto_menssagem; //Arquivo Criptografado

	if ((crypto_menssagem=fopen(Entrada, "rb"))==NULL){
        return -1;
    }else{
        if ((descrypt_menssagem=fopen(Saida, "w+b"))==NULL){
            return -2;
        }else{

            fread(&divisao,sizeof(uint32_t),1,crypto_menssagem);
            fwrite(&divisao,sizeof(uint32_t),1,descrypt_menssagem);
            for(i=0;i<divisao;i++){
                fread(&c,sizeof(char),1,crypto_menssagem);
                fwrite(&c,sizeof(char),1,descrypt_menssagem);
                if(!feof(crypto_menssagem)){
                        memset(&buffer,0,sizeof(buffer));
                        if(fread(&buffer,sizeof(char),10,crypto_menssagem)>0){
                            CFB_Mode<AES>::Decryption cfbDecryption(chave, AES::MAX_KEYLENGTH, iv);
                            cfbDecryption.ProcessData((byte*)buffer, (byte*)buffer, 10);

                            CFB_Mode<AES>::Encryption cfbEncryption(chave_saida, AES::MAX_KEYLENGTH, iv_saida);
                            cfbEncryption.ProcessData((byte*)buffer, (byte*)buffer, 10);

                            fwrite(buffer,sizeof(char),10,descrypt_menssagem);
                        }
                }
            }

            if(!feof(crypto_menssagem)){
                fread(&c,sizeof(char),1,crypto_menssagem);
                fwrite(&c,sizeof(char),1,descrypt_menssagem);
                fread(&divisao,sizeof(uint32_t),divisao,crypto_menssagem);
                fwrite(&divisao,sizeof(uint32_t),divisao,descrypt_menssagem);
                fread(&c,sizeof(char),1,crypto_menssagem);
                fwrite(&c,sizeof(char),1,descrypt_menssagem);

                memset(&buffer2,0,sizeof(buffer2));
                if(fread(&buffer2,sizeof(char),divisao,crypto_menssagem)>0){

                    CFB_Mode<AES>::Decryption cfbDecryption(chave, AES::MAX_KEYLENGTH, iv);
                    cfbDecryption.ProcessData((byte*)buffer2, (byte*)buffer2, divisao);

                    CFB_Mode<AES>::Encryption cfbEncryption(chave_saida, AES::MAX_KEYLENGTH, iv_saida);
                    cfbEncryption.ProcessData((byte*)buffer2, (byte*)buffer2, 10);

                    fwrite(buffer2,sizeof(char),divisao,descrypt_menssagem);
                }
            }

            fclose(crypto_menssagem);
            fclose(descrypt_menssagem);
        }
    }
    return 0;
}

int main(int argc, char **argv){
    char Entrada_str[1000], Saida_str[1000], iv_aux_str[50],chave_aux_str[50], iv_aux_saida_str[50],chave_aux_saida_str[50], cond[5];
    FILE * arq;
    byte *chave, *iv;

    arq=fopen("d.txt","r+");
    if(arq!=NULL){
        fgets(cond,5,arq);
        if(cond[0] == '1'){
            fgets(Entrada_str,1000,arq);
            fgets(Saida_str,1000,arq);
            fgets(iv_aux_str,1000,arq);
            fgets(chave_aux_str,1000,arq);
            fclose(arq);
            system("del d.txt");
            memset(&iv_aux_str,0,sizeof(iv_aux_str));
            memset(&chave_aux_str,0,sizeof(chave_aux_str));
            convert((char*)Entrada_str);
            convert((char*)Saida_str);
            convert((char*)iv_aux_str);
            convert((char*)chave_aux_str);
            strcpy(aux,"Criptografando...\n      Aguarde...\n");
            CreateThread(NULL, 0, thread_func, new thread_data(0) , 0, 0);
            criptografa_AES((char*)Entrada_str, (char*)Saida_str, (char*)iv_aux_str, (char*)chave_aux_str);
        }else if(cond[0] == '2'){
            fgets(Entrada_str,1000,arq);
            fgets(Saida_str,1000,arq);
            fgets(iv_aux_str,1000,arq);
            fgets(chave_aux_str,1000,arq);
            fclose(arq);
            system("del d.txt");
            memset(&iv_aux_str,0,sizeof(iv_aux_str));
            memset(&chave_aux_str,0,sizeof(chave_aux_str));
            convert((char*)Entrada_str);
            convert((char*)Saida_str);
            convert((char*)iv_aux_str);
            convert((char*)chave_aux_str);
            strcpy(aux,"Descriptografando...\n      Aguarde...\n");
            CreateThread(NULL, 0, thread_func, new thread_data(0) , 0, 0);
            descriptografa_AES((char*)Entrada_str, (char*)Saida_str, (char*)iv_aux_str, (char*)chave_aux_str);
        }else if(cond[0] == '3'){
            fgets(Entrada_str,1000,arq);
            fgets(Saida_str,1000,arq);
            fgets(iv_aux_str,1000,arq);
            fgets(chave_aux_str,1000,arq);
            fgets(iv_aux_saida_str,1000,arq);
            fgets(chave_aux_saida_str,1000,arq);
            fclose(arq);
            system("del d.txt");

            memset(&iv_aux_str,0,sizeof(iv_aux_str));
            memset(&chave_aux_str,0,sizeof(chave_aux_str));
            memset(&iv_aux_saida_str,0,sizeof(iv_aux_saida_str));
            memset(&chave_aux_saida_str,0,sizeof(chave_aux_saida_str));
            convert((char*)Entrada_str);
            convert((char*)Saida_str);
            convert((char*)iv_aux_str);
            convert((char*)chave_aux_str);
            convert((char*)iv_aux_saida_str);
            convert((char*)chave_aux_saida_str);
            CreateThread(NULL, 0, thread_func, new thread_data(0) , 0, 0);
            strcpy(aux,"Compartilhando...\n      Aguarde...\n");
            Compartilhar((char*)Entrada_str, (char*)Saida_str, (char*)iv_aux_str, (char*)chave_aux_str, (char*)iv_aux_saida_str, (char*)chave_aux_saida_str);
        }else if(cond[0] == '4'){
            fseek(arq, 0, SEEK_SET);
            chave=gerador_chave();
            iv=gerador_divisao_bloco();
            fprintf(arq,"%d\n%d\n",(int)chave,(int)iv);
            fclose(arq);
        }
    }
    return 0;
}

