// Testar em programa substituindo strncpy por memset ou memcpy
// strncpy para no primeiro zero

#include<stdio.h>
#include<sys/socket.h>
#include<errno.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	struct hostent *host;
	int busca, i, sock, inicio, fim;
	char nome_maquina[100];
	struct sockaddr_in servidor;

	//nome da maquina para  escanear
	printf("Entre com o nome da maquina ou seu IP: ");
	fgets(nome_maquina, 100, stdin);

	//Porta de inicio de escaneamento
	printf("\nEntre com o numero inicial da porta: ");
	scanf("%d", &inicio);

	//Porta final de escaneamento
	printf("\nEntre com o numero final da porta: ");
	scanf("%d", &fim);

	//Inicializando a estrutura sockaddr_in
	strncpy((char*)&servidor, "", sizeof(servidor));
	servidor.sin_family = AF_INET;

	//uso do endereço ip direto
	if(isdigit(nome_maquina[0]))
	{
		printf("Executando o inet_addr...");
		servidor.sin_addr.s_addr = inet_addr(nome_maquina);
		printf("Feito\n");
	}

	//Resolver o nome da maquina (hostname) para o endereço IP
	else if( (host = gethostbyname(nome_maquina)) != 0)
	{
		printf("Executando gethostbyname...");
		strncpy((char*)&servidor.sin_addr, (char*)host->h_addr, sizeof(servidor.sin_addr));
		printf("Feito\n");
	}

	else
	{
		herror(nome_maquina);
		exit(2);
	}

	//Comaçando a escanear as portas. Fazer um loop
	printf("Inicio do escaneamento de portas: \n");
	for(i = inicio; i <= fim; i++)
	{
		//preencher o numero da porta
		servidor.sin_port = htons(i);
		
		//Criar uma conexão socket do tipo IP
		sock = socket(AF_INET, SOCK_STREAM, 0);

		//Checar se a conexão socket funcionou
		if(sock < 0)
		{
			perror("\nFalha na conexao socket!");
			exit(1);
		}

		//conectar usando socket e a estrutura sockaddr_in 
		busca = connect(sock, (struct sockaddr*)&servidor, sizeof(servidor));

		//checagem de erro
		if(busca < 0)
		{
			printf("Falha na funcao Connect! - Porta Fechada %d\n", i);
			fflush(stdout);
		}

		else
		{
			printf("%-5d aberta\n", i);
		}

		close(sock);
	}

	printf("\r");
	fflush(stdout);
	return(0);
}
