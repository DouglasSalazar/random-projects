#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>


int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , ler_tamanho;
    struct sockaddr_in server , client;
    char client_mensagem[2000];
     
    //Criar socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Nao foi possível criar o socket.");
    }
    puts("Socket criado");
     
    //Preparar a estrutura do socket addr
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //Imprimir mensagem de erro.
        perror("bind falhou");
        return 1;
    }
    puts("bind estabelecido");
     
    //Ouvir o canal de comunicação
    listen(socket_desc , 3);
     
    //Aceitar chamadas de conexão
    puts("Esperando por chamadas de conexao...");
    c = sizeof(struct sockaddr_in);
     
    //Aceitar conexão de um cliente
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("falha na conexao");
        return 1;
    }
    puts("Conexao aceita.");
     
    //Receber a mensagem do cliente.
    while( (ler_tamanho = recv(client_sock , client_mensagem , 2000 , 0)) > 0 )
    {
        //Enviar mensagem de volta ao cliente.
        write(client_sock , client_mensagem , strlen(client_mensagem));
    }
     
    if(ler_tamanho == 0)
    {
        puts("Cliente disconectado!");
        fflush(stdout);
    }
    else if(ler_tamanho == -1)
    {
        perror("Falha no recebimento");
    }
     
    return 0;
}
