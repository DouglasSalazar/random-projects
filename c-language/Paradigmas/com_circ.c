/*
	2 maquinas
	A maquina de rank zero recebe a bola, incrementa o contador e passa para a maquina 1. 
	A maquina 1 recebe a bola e incrementa o contador e devolve a bola para a maquina zero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char **argv){
	int size, rank, rAtual = 0;
	int tag = 10;
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);

		if(size == 1){
			if(rank == 0){
				printf("Usar mais de uma maquina para esse programa!\n");
			}
			MPI_Finalize();
			exit(0);
		}
		
		if(rank == 0){
			printf("0 -> 1\n");			
			rAtual+=1;
			
			MPI_Send(&rAtual,1,MPI_INT,rAtual,tag,MPI_COMM_WORLD);
			
			MPI_Recv(&rAtual,1,MPI_INT,size-1,tag,MPI_COMM_WORLD,&status);
			printf("0 <- %d\n",size-1);		
		}else{
			while(rank != rAtual)
				;			
						
			MPI_Recv(&rAtual,1,MPI_INT,rAtual-1,tag,MPI_COMM_WORLD,&status);
			printf("%d <- %d\n",rAtual,rAtual-1);
			
			printf("%d -> %d\n",rAtual,rAtual+1);
			if(rAtual < size-1){
				rAtual+=1;
				MPI_Send(&rAtual,1,MPI_INT,rAtual+1,tag,MPI_COMM_WORLD);
			}else{
				MPI_Send(&rAtual,1,MPI_INT,0,tag,MPI_COMM_WORLD);
			}
		}
				
	MPI_Finalize();	
	return 0;
}
