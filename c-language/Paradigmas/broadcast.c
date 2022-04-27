#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
	int rank, buffer;
	const int mestre = 4;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	
	if(rank == mestre){
		buffer = 999;
	}
	printf("[%d]: Antes do broadcast, o buffer esta com %d\n",rank,buffer);
	MPI_Bcast(&buffer,1,MPI_INT,mestre,MPI_COMM_WORLD);
	
	printf("[%d]: Depois do broadcast, o buffer esta com %d\n",rank,buffer);

	MPI_Finalize();	
	return 0;
}
