//Neste programa e identificado cada processo e sua quantidade
#include <stdio.h>
#include <mpi.h>

int size, rank; //size para identificar a quantdade de processos e rank para identificar o processo

int main(int argc, char** argv){
	
	MPI_Init(&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		printf("Processo [%d] de [%d]\n",rank,size);
	MPI_Finalize();
	
	return 0;
}
