// Usar funções send e receive enviando e recebendo uma mensagem

#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv){
	int rank, size, origem, destino, tag = 0;
	char mensagem[30];
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		
		switch(rank){
			case 0:
				for(origem=1;origem < size; origem++){
					MPI_Recv(mensagem, 30, MPI_CHAR, origem, tag, MPI_COMM_WORLD, &status);
					printf("%s\n",mensagem);
				}
				break;
			/*case 1:
				
				break;*/	
			default:
				sprintf(mensagem, "Maquina %d esta viva!", rank);
				destino = 0;
				MPI_Send(mensagem, strlen(mensagem), MPI_CHAR, destino, tag, MPI_COMM_WORLD);
				break;
		}
	
	MPI_Finalize();

	return 0;
}
