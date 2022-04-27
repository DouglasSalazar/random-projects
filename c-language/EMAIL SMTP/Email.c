/**********************************************************************************
    Programa desenvolvido por: Douglas Correia Salazar
    Disciplina: Redes de Computaroes
    Prof Dr: Rubens
    
    Criacao de email smtp com conexao criptografada

    para execucao de programa necessario instalacao da gtk+-2.0

    1) sudo apt-get install gtk+-2.0
    2) make clen
    3) make
    4) ./Email

**********************************************************************************/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <gtk/gtk.h>

#define closesocket      close       /* Número de porta protocolo padrão - Poderia ser qualquer outro número */

extern int               errno;

char *emailgtk=NULL; /*armazena valor campo email*/
char *senhagtk=NULL;/*armazena valor campo senha*/
char *assuntogtk=NULL;/*armazena valor campo assunto*/
char *destinatariogtk=NULL;/*armazena valor destinatario*/
char *mensagemgtk=NULL;/*armazena valor campo mensagem*/
char *from=NULL;/*armazena valor campo De*/
char *to=NULL;/*armazena valor campo Para*/

int tipo=1;/*variavel botao radio*/


void gmail() {
    tipo=1;/*opacao 1 gmail*/
}

void enter_callback_from(GtkWidget *entry1){/*funcao para leitura DE*/
    gchar * aux;
    
    aux=(gchar *)gtk_entry_get_text(GTK_ENTRY(entry1));/*leitura buffer teclado e conversao para char*/
    from=aux;    
    fflush(stdout);
}

void enter_callback_to(GtkWidget *entry1){/*funcao para leitura PARA*/
    gchar * aux;
    
    aux=(gchar *)gtk_entry_get_text(GTK_ENTRY(entry1));/*leitura buffer teclado e conversao para char*/
    to=aux;    
    fflush(stdout);
}

void enter_callback_email(GtkWidget *entry1){/*funcao para leittura de email*/
    gchar * aux;
    
    aux=(gchar *)gtk_entry_get_text(GTK_ENTRY(entry1));/*leitura buffer teclado e conversao para char*/
    emailgtk=aux;    
    fflush(stdout);
}

void enter_callback_senha(GtkWidget *entry1){/*funcao para leitura campo senha*/
    gchar * aux;
    
    aux=(gchar *)gtk_entry_get_text(GTK_ENTRY(entry1));/*leitura buffer teclado e conversao para char*/
    senhagtk=aux;    
    fflush(stdout);
}

void enter_callback_destinatario(GtkWidget *entry1){/*leitura de destinatario*/
    gchar * aux;
    
    aux=(gchar *)gtk_entry_get_text(GTK_ENTRY(entry1));/*leitura buffer teclado e conversao para char*/
    destinatariogtk=aux;    
    fflush(stdout);
}

void enter_callback_assunto(GtkWidget *entry1){/*funcao para leitura de assunto*/
    gchar * aux;

    aux=(gchar *)gtk_entry_get_text(GTK_ENTRY(entry1));/*leitura buffer teclado e conversao para char*/
    assuntogtk=aux;    
    fflush(stdout);
}

void enter_callback_mensagem(GtkWidget *entry1,gpointer data){/*funcao para leitura de mensagem*/
    gchar * aux;
    GtkTextIter start, end;/*variavel inicio e fim de buffertexte*/
    GtkTextBuffer *buffer=(GtkTextBuffer *)data;/*buffertext armazena valores teclado*/
    

    buffer=gtk_text_view_get_buffer (GTK_TEXT_VIEW (entry1));/*leitura do teclado para buffer*/

    gtk_text_buffer_get_start_iter(buffer, &start);/*inicio do buffer*/
    gtk_text_buffer_get_end_iter(buffer, &end);/*final do buffer*/
    aux=(char*)gtk_text_buffer_get_text(buffer, &start,&end, FALSE);/*conversao do buffer inicio ate o final para char*/
    mensagemgtk=aux;   
}

void sair() {/*sair as janela inicial e email*/
    gtk_main_quit();
}

void destroi(GtkWidget *widget){/*destroi janela de erro*/
    gtk_widget_destroy(widget);
}
void erro(char *erro){
    GtkWidget *janela, *tabela,*label;
    
    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);/*criacao de janela*/
    gtk_widget_set_usize(janela, 350, 150);/*redimensionamento*/
    g_signal_connect(janela, "destroy", G_CALLBACK (destroi), NULL);/*opcao de destroy*/
    gtk_window_set_resizable(GTK_WINDOW(janela),FALSE);/*definicao de janela fixa sem ser redimensionada pelo usuario*/

    tabela = gtk_table_new(4, 4, TRUE);/*divisao em tabela 4x4*/

    gtk_container_add(GTK_CONTAINER (janela), tabela);/*conteiner englobando a tabela*/

    label=gtk_label_new(erro);/*impressao de erro na janela*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), label, 0, 4, 1, 3);/*linha e coluna posicionada a escrita*/
    gtk_widget_show(label); /*execucao da escrita*/
   
    gtk_widget_show(tabela);
    gtk_widget_show(janela);
    gtk_main();
}

void janelaemail(){
    GtkWidget *janela, *tabela, *botao, *texto,*label;
    GtkTextBuffer *buffer;
    
    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);/*criacao de janela*/
    gtk_widget_set_usize(janela, 750, 500);/*redimensionamento de janela*/
    gtk_signal_connect(GTK_OBJECT (janela), "destroy", GTK_SIGNAL_FUNC (sair), NULL);/*opcao de destruir janela*/
    gtk_window_set_resizable(GTK_WINDOW(janela),FALSE);/*definicao de janela fixa sem ser redimensionada pelo usuario*/

    tabela = gtk_table_new(25, 20, TRUE);/*criacao de tabela 25x20*/

    gtk_container_add(GTK_CONTAINER (janela), tabela);/*adiciona tabela em conteiner*/

    label=gtk_label_new("De:");/*impressao em janela DE*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), label, 1, 2, 0, 1);/*posicionamento da escrita na tabela*/
    gtk_widget_show(label); /*escrevendo na tabela*/
    
    texto=gtk_entry_new();/*criacao de um campo de uma linha digitavel*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), texto, 1, 6, 1,2);/*posicionamento do campo na tabela*/
    gtk_widget_show(texto);/*colocacao da janela*/
    gtk_widget_grab_focus(texto);
    g_signal_connect(G_OBJECT(texto), "key-release-event", G_CALLBACK(enter_callback_from), NULL);/*chamada para  funcal callback_from para leitura do teclado*/

    
    label=gtk_label_new("Remetente");/*impressao na janela REMETENTE*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), label, 1, 2, 3, 4);/*posicionamento da escrita na tabela*/
    gtk_widget_show(label); /*escrevendo na tabela*/
    
    texto=gtk_entry_new();/*criacao de um campo de uma linha digitavel*/
    gtk_entry_set_text ((GtkEntry*) texto,emailgtk);/*definicao para que a janela inicie com uma escrita no caso o email*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), texto, 1, 15, 4,5);/*posicionamento na tabela*/
    gtk_widget_show(texto);/*colocacao do campo na janela*/
    gtk_widget_grab_focus(texto);
    g_signal_connect(G_OBJECT(texto), "key-release-event", G_CALLBACK(enter_callback_email), NULL);/*chamada para funcao callback_email para leitura do teclado*/

    label=gtk_label_new("Para:");/*impressao na janela PARA*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), label, 1, 3, 6, 7);/*posicionamento na tabela*/
    gtk_widget_show(label); /*impressao na tabela*/
    
    texto=gtk_entry_new();/*criacao de um campo de uma linha digitavel*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), texto, 1, 6, 7,8);/*posicionamento na tabela*/
    gtk_widget_show(texto);/*colocacao de campo na janela*/
    gtk_widget_grab_focus(texto);
    g_signal_connect(G_OBJECT(texto), "key-release-event", G_CALLBACK(enter_callback_to), NULL);/*chamada para funcao callback_to para leitura do teclado*/

    label=gtk_label_new("Destinatario");/*impressao na janela DESTINATARIO*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), label, 1, 4, 9, 10);/*posicionamento na tabela*/
    gtk_widget_show(label);/*escrevendo na janela*/
 
    texto=gtk_entry_new();/*criacao de um campo de uma linha digitavel*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), texto, 1, 15, 10,11);/*posicionamento na tabela*/
    gtk_widget_show(texto);/*colocacao do campo na tabela*/
    gtk_widget_grab_focus(texto);
    g_signal_connect(G_OBJECT(texto), "key-release-event", G_CALLBACK(enter_callback_destinatario), NULL);/*chamada para funcao callback_destinatario para leitura do telclado*/

    label=gtk_label_new("Assunto");
    gtk_table_attach_defaults(GTK_TABLE (tabela), label, 1, 3, 12, 13);
    gtk_widget_show(label);
 
    texto=gtk_entry_new();
    gtk_table_attach_defaults(GTK_TABLE (tabela), texto, 1, 6, 13,14);
    gtk_widget_show(texto);
    gtk_widget_grab_focus(texto);
    g_signal_connect(G_OBJECT(texto), "key-release-event", G_CALLBACK(enter_callback_assunto), NULL);

    label=gtk_label_new("Mensagem");/*impressao na janela digitavel*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), label, 1, 3, 15, 16);/*posicionamento na tabela*/
    gtk_widget_show(label);
 
    texto=gtk_text_view_new();/*criacao de campo com mais de uma linha*/
    buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (texto));/*criacao de buffertext*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), texto, 1, 19, 16,24);/*posicionamento na tabela*/
    gtk_widget_show(texto);/*colocacao do campo na janela*/
    gtk_widget_grab_focus(texto);
    g_signal_connect(G_OBJECT(texto), "key-release-event", G_CALLBACK(enter_callback_mensagem), buffer);/*chammada para funcao callback_mensagem para leitura do teclado*/

    botao = gtk_button_new_with_label("Enviar");/*criacao de um botao ENVIAR*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), botao, 0, 20, 24, 25);    /*posicionameno em tabela*/
    gtk_signal_connect(GTK_OBJECT (botao), "clicked", GTK_SIGNAL_FUNC (sair), "sair");/*chamada da funcao sair*/
    gtk_widget_show(botao);
    
    gtk_widget_show(tabela);/*conclusao tabela*/
    gtk_widget_show(janela);/*conclusao janela*/
    gtk_main();
}


void ShowCerts(SSL* ssl)
{   X509 *cert;
    char *line;
 
    cert = SSL_get_peer_certificate(ssl); /* leitura do certificate */
    if ( cert != NULL )
    {
        printf("Server certificates:\n");
        line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
        printf("Subject: %s\n", line);
        free(line);       /* desalocando string */
        line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
        printf("Issuer: %s\n", line);
        free(line);       /* desalocando string */
        X509_free(cert);     /* desalocando copia certificado */
    }
    else
        printf("No certificates.\n");
}


int create_socket(int port,char *host){
    struct  hostent  *ptrh;   /* ponteiro para a tabela de entrada do host       */
    struct  protoent *ptrp;   /* ponteiro para a tabela de entrada do protocolo     */
    struct  sockaddr_in sad;  /* estrutura para manter o endereço do servidor  */
    int sd; /**/


    memset((char *)&sad,0,sizeof(sad));  /* Limpa a estrutura sockaddr */
    sad.sin_family = AF_INET;            /* Configura a familia de protocolos internet  */


    if (port > 0) sad.sin_port = htons((u_short)port);/*conexao na porta se erro return -1*/
    else 
    { 
        return -1;
    }

    ptrh = gethostbyname(host);/*conexao com host caso erro return -1*/
    if( ((char *)ptrh) == NULL)
    { 
    return -1;
    }

    memcpy(&sad.sin_addr, ptrh->h_addr, ptrh->h_length);/*criacao ao tcp caso erro return -1*/

    if ( ((int*)(ptrp = getprotobyname("tcp"))) == 0)
    { 
        return -1;
    }

    sd = socket(PF_INET, SOCK_STREAM, ptrp->p_proto);/*criacao de socket caso erro return -1*/
    if (sd < 0)
    { 
        return -1;
    }

    if (connect(sd, (struct sockaddr *)&sad, sizeof(sad)) < 0){/*conexao de socket*/ 
      
        return -1;
    }
    return sd;
}


int quebra(char *buf){/*funcao para quebra de string recolhe somente os primeiro numeros do erro*/
    char * pch;
    char tes[1000];
    int aux,i=0;

    pch=buf;
    if(pch!=NULL){        
        while (pch[i]>=48 && pch[i]<=57)
        {
            tes[i]=pch[i];
            i++;
        }
        tes[i]='\0';
        aux=atoi(tes);
        return aux;
    }
    return 0;
}

void email_gmail(){
    int  sd;               /* descritor do socket    */
    int  port;             /* Número da porta do protocolo   */
    char *host;            /* ponteiro para o nome do host   */
    int  n,i=0;                /* Número de caracteres lidos    */
    char buf[1000];        /* buffer para os dados recebidos do servidor */
    char mensagem[1000];
    char email[50];
    char senha[50];
    char aux[50];
    char destinatario[50];
    char localhost[] = "smtp.gmail.com"; 
    char *ver;
    
    FILE * arq;
    SSL_CTX * ctx;
    SSL * ssl;
    
    i=0;
    if(emailgtk){        /*copia variavel emailgtk para email */
        while(emailgtk[i]!='\0'){
            email[i]=emailgtk[i];
            i++;
        }
        email[i]='\0';
    }
    i=0;
    if(senhagtk!=NULL){    /*copia variavel senha gtk para senha*/
        while(senhagtk[i]!='\0'){
            senha[i]=senhagtk[i];
            i++;
        }
        senha[i]='\0';
    }

    strcpy(aux,")' echo var echo var > chave.txt");    /*definicao de aux será usado para definir o perl mais a frente*/
    
    SSL_library_init();                 /*inicializacao da funcao openssl*/
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    ctx = SSL_CTX_new(SSLv23_client_method());        /*criacao de um cliente com o protocolo SSLv23 */
    ssl = SSL_new(ctx);    /*criacao de um SLL para conexao criptografada*/
    port=465;/*port para conexao*/
    host=localhost;/*localhost a se conectado*/
    sd=create_socket(port,host);/*criacao do socket*/
    if(sd>0){    
        SSL_set_fd(ssl, sd);/*sincronicaçao da variavel SLL com o socket*/
        if(SSL_connect(ssl)>=0){/*conexao do sll com o servidor*/
            SSL_get_cipher(ssl);/*negociacao de cifras validas*/
            ShowCerts(ssl);/*verificacao de ceertificado*/

            strcpy(buf,"ehlo\r\r\r\n");/*primeira comunicacao ehlo um HELLO PARA O SERVIDOR*/
            SSL_write(ssl, buf, strlen(buf));        /*enviando mensagem*/
            n=SSL_read(ssl, buf, sizeof(buf));/*recebendo um retorno do helo*/
            strcpy(mensagem,buf);
            ver=mensagem;
            n=quebra(ver);
            if(n==220){       /*caso 220 o primeiro numero sinal que tudo deu certo*/
/*******************************************************************************************************/
                /*inicio da organizacao do perl para efetuar a chama e fazer a criptografia*/    
                bzero(buf,sizeof(buf));
                sprintf(buf,"perl -MMIME::Base64 -e 'print encode_base64(");
                n=44;            
                buf[n]=34;
                n++;
                buf[n++]=92;
                buf[n++]='0';
                buf[n++]='0';
                buf[n++]='0';
                i=0;
                while(email[i]!='@' && email[i]!='\0'){
                    buf[n]=email[i];
                    n++;
                    i++;
                }
                buf[n]=92;
                n++;
                while(email[i]!='\0'){
                    buf[n]=email[i];
                    n++;
                    i++;
                }
                buf[n++]=92;      
                buf[n++]='0';
                buf[n++]='0';
                buf[n++]='0';      
                i=0;
                while(senha[i]!='\0'){
                    buf[n]=senha[i];
                    n++;
                    i++;
                }
                buf[n]=34;
                n++;
                i=0;
                while(aux[i]!='\0'){
                    buf[n]=aux[i];
                    n++;
                    i++;
                }
/*****************************************************************************************************************/
                /*FINAL DA ORGANIZACAO DA CRIPTOGRAFIA PERL*/
                system(buf);/*chamada ao sistema perl*/
                arq=fopen("chave.txt","r");
                if(arq!=NULL){
                    fscanf(arq,"%s",buf);/*leitura do email e senha criptografado*/
                    fclose(arq);
                    system("rm chave.txt");/*exclusao do arquivo*/
                    strcpy(mensagem,"auth plain ");
                    strcat(mensagem,buf);
                    strcat(mensagem,"\r\r\r\n");/*envio de mensagem para autenticacao*/
                    SSL_write(ssl, mensagem , strlen(mensagem));
                    n=SSL_read(ssl, buf, sizeof(buf));
                    i=0;
                    if(emailgtk!=NULL){  
                        while(emailgtk[i]!='\0'){
                            email[i]=emailgtk[i];
                            i++;
                        }
                        email[i]='\0';
                    }
                    sprintf(buf,"mail from: <%s>\r\n",email); /*envio de mensagem para autenticaçao de email*/
                    SSL_write(ssl, buf, strlen(buf));        
                    n=SSL_read(ssl, buf, sizeof(buf));

                    if(n>0){          
                        strcpy(mensagem,buf);
                        ver=mensagem;
                        n=quebra(ver);
                        if(n==235){                    
                            janelaemail();/*chamada funcao email interface grafica para coleta de informacoes email*/
                            i=0;
                            if(destinatariogtk!=NULL){
                                while(destinatariogtk[i]!='\0'){
                                    destinatario[i]=destinatariogtk[i];
                                    i++;
                                }
                                destinatario[i]='\0';
                            }
                            sprintf(buf,"rcpt to: <%s>\r\n",destinatario);/*envio de mensagem contento o destinatario*/
                            SSL_write(ssl, buf, strlen(buf));        
                            n=SSL_read(ssl, buf, sizeof(buf));
       

                            strcpy(buf,"data\r\n");/*funcao para inicio da digitacao de email*/
                            SSL_write(ssl, buf, strlen(buf));        
                            n=SSL_read(ssl, buf, sizeof(buf));


                            bzero(buf,sizeof(buf));

                            sprintf(buf,"From: %s <%s> \nTo: %s <%s> \nSubject: %s \n%s.\r\n",from,email,to,destinatario,assuntogtk,mensagemgtk);
                            SSL_write(ssl, buf, strlen(buf));     /*escrecendo email*/   

                            sprintf(buf,".\r\n");/*finalizado escrita de email*/
                            SSL_write(ssl, buf, strlen(buf));        

                            sprintf(buf,"\n\r\n");/*final do email*/
                            SSL_write(ssl, buf, strlen(buf));        
                            n=SSL_read(ssl, buf, sizeof(buf));

                            sprintf(buf,"quit\r\r\n");/*desconectar*/
                            SSL_write(ssl, buf, strlen(buf));        
                            n=SSL_read(ssl, buf, sizeof(buf));
                            
                        }else{
                            erro("Login Invalido!!\nSenha ou Email Invalido\n");
                        }
                    }else{
                        ver=buf;
                        erro(buf);
                    }
                }else{
                    ver=buf;
                    erro(buf);
                }
            }else{
                ver=buf;
                erro(buf);
            }
        }

        closesocket(sd);
    }else{
        erro("Erro Conexão!!\nVerifique sua conexão ou tente novamente mais tarde!!\n");
    }
}

void login(){

    email_gmail();        

}

void janelainicial(){/*janela inicial*/
    GtkWidget *janela, *tabela, *botaologin,*botaosair, *texto,*label,*texto1,*botao;
    GSList *group=NULL;    
    
    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);/*criacao de janela inical login*/
    gtk_widget_set_usize(janela, 400, 250);/*redimensionaemtno de janela*/
    g_signal_connect(janela, "destroy", G_CALLBACK (sair), NULL);/*funcao para destruir janela*/
    gtk_window_set_resizable(GTK_WINDOW(janela),FALSE);/*janela fixa usuario nao pode redimensionar*/

    tabela = gtk_table_new(10, 20, TRUE);/*criacao de uma tabela 10x20*/

    gtk_container_add(GTK_CONTAINER (janela), tabela);/*colocacao de tabela dentro de um conteiner*/
    

    botao = gtk_radio_button_new (group);/*botao radio*/
    botao=gtk_radio_button_new_with_label (group,"Gmail.com");/*criacao do botao gmail*/
/*colocacao do botao gemail grupo de botoes radio*/
    group = gtk_radio_button_group (GTK_RADIO_BUTTON (botao));    
    gtk_signal_connect(GTK_OBJECT (botao), "clicked", GTK_SIGNAL_FUNC (gmail), "gmail");/*chamada a funcao gmail apartir de evento botao*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), botao, 1, 10, 1, 2);   /*posicionamento na janela*/ 
    gtk_widget_show(botao);
    
    label=gtk_label_new("E-mail");/*impressao na janela E-mail*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), label, 0, 2, 2, 3);/*posicionamento em janela*/
    gtk_widget_show(label);     
    
    texto=gtk_entry_new();/*criacao de campo de uma linha*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), texto, 0, 15, 3, 4);/*posicionamento de campo em tabela*/
    gtk_entry_set_text ((GtkEntry*) texto,"nome@dominio.com");/*inicalmento campo possue dome@dominio.com*/
    gtk_widget_show(texto);
    gtk_widget_grab_focus(texto);

    g_signal_connect(G_OBJECT(texto), "key-release-event", G_CALLBACK(enter_callback_email), NULL);/*chamada a funcao callvak_emaol para leitura de teclado*/

    label=gtk_label_new("Senha");/*impressao senha na tel*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), label, 0, 2, 5, 6);/*posicionamento em tabela*/
    gtk_widget_show(label);

    texto1=gtk_entry_new();/*criacao de campo com uma linha so*/
    gtk_entry_set_visibility(GTK_ENTRY(texto1),FALSE);/*nao ver oque usuario digita*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), texto1, 0, 15, 6, 7);/*posicionamento em tabela*/
    gtk_widget_show(texto1);
    gtk_widget_grab_focus(texto1);
    g_signal_connect(G_OBJECT(texto1), "key-release-event", G_CALLBACK(enter_callback_senha), NULL);/*chamada a funcao callback_senha para leitura ed teclado*/

    botaosair = gtk_button_new_with_label("Quit");/*criacao de botao quit*/
    gtk_signal_connect(GTK_OBJECT (botaosair), "clicked", GTK_SIGNAL_FUNC (sair), "Quit");/*chamada funcao sair*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), botaosair, 0, 5, 9, 10);/*posicionamento em tabela*/


    botaologin = gtk_button_new_with_label("Login");/*criacao bota login*/
    gtk_table_attach_defaults(GTK_TABLE (tabela), botaologin, 5, 20, 9, 10);/*posicionamento*/    
    gtk_signal_connect(GTK_OBJECT (botaologin), "clicked", GTK_SIGNAL_FUNC (login), "login");/*chamada a funcao login*/
    gtk_widget_show(botaologin); 

    gtk_widget_show(label);
    gtk_widget_show(botao);

    gtk_widget_show(botaosair);
    gtk_widget_show(tabela);
    gtk_widget_show(janela);
    gtk_main();
}


int main(int argc, char **argv) {
 
    gtk_init(&argc, &argv);
    janelainicial();

 
   return 0;
}   


