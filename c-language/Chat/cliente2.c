#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>


int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char mensagem[1000] , server_retorno[2000];
     
    //Criar Socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Erro ao criar o socket");
    }
    puts("Socket criado");
     
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    //Conectar ao servidor remoto
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("Erro ao conectar. Falha");
        return 1;
    }
     
    puts("Conectado\n");
     
    //Laço para continuar se comunicando com o servidor.
    while(1)
    {
        printf("Digite a mensagem : ");
        scanf("%s" , mensagem);
         
        //Envio de dados
        if( send(sock , mensagem , strlen(mensagem) , 0) < 0)
        {
            puts("Envio falhou");
            return 1;
        }
         
        //Receber um resposta do servidor
        if( recv(sock , server_retorno , 2000 , 0) < 0)
        {
            puts("resposta falhou");
            break;
        }
         
        puts("Retorno do Servidor :");
        puts(server_retorno);
    }
     
    close(sock);
    return 0;
}
