#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

void manualBroadcast(void *dados, int cont, MPI_Datatype datatype, int raiz, MPI_Comm comunicador){
	int rank, size, i;
	MPI_Comm_rank(comunicador,&rank);
	MPI_Comm_size(comunicador,&size);
	if(rank == raiz){
		for(i=rank+1;i<size;i++){
			MPI_Send(dados,cont,datatype,i,0,comunicador);
		}
	}else{
		MPI_Recv(dados,cont,datatype,raiz,0,comunicador,MPI_STATUS_IGNORE);
	}
}

int main(int argc, char **argv){
	int rank, dados;
	
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	
	if(rank == 0){
		dados = 100;
		printf("Processo %d esta fazendo broadcast de dados: %d\n",rank,dados);
		manualBroadcast(&dados,1,MPI_INT,0,MPI_COMM_WORLD);
	}else{
		manualBroadcast(&dados,1,MPI_INT,0,MPI_COMM_WORLD);
		printf("Processo %d recebeu dados: %d do processo raiz\n",rank,dados);
	}

	MPI_Finalize();
	
	return 0;
}
