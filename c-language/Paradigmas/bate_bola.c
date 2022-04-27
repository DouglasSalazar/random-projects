/*
	2 maquinas
	A maquina de rank zero recebe a bola, incrementa o contador e passa para a maquina 1. 
	A maquina 1 recebe a bola e incrementa o contador e devolve a bola para a maquina zero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv){
	int cont, size, rank, limite = 10;
	int tag = 10;
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);

		if(size != 2){
			if(rank == 0){
				printf("Usar exatamente duas maquinas nesse programa!\n");
			}
			MPI_Finalize();
			exit(0);
		}
		
		cont = 0;
		if(rank == 0){
			while(cont < limite){
				cont += 1;
				printf("0 -> 1 : ");
				printf("Enviado: %d\n",cont);
				MPI_Send(&cont, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
				
				
				
				MPI_Recv(&cont, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &status);
				printf("0 <- 1 : ");
				printf("Recebido: %d\n",cont);
			}
		}else{ // Maquina 1
			while(cont < limite){
				MPI_Recv(&cont, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
				printf("1 <- 0 : ");
				printf("Recebido: %d\n",cont);
				
				cont += 1;
				printf("1 -> 0 : ");
				printf("Enviado: %d\n",cont);
				MPI_Send(&cont, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
			}
		}
		
	MPI_Finalize();	
	return 0;
}
