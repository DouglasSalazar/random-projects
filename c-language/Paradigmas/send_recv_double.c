// Programa MPI usando os argumentos mpi_status, mpi_source, mpi_tag e a função mpi_get_count no envio de um double

#include <stdio.h>
#include <mpi.h>
#include <math.h>

#define PI 3.1415

int main(int argc, char **argv){
	int meu_rank, i, cont;
	MPI_Status status;
	double a[10], b[10];
	
	MPI_Init(&argc, &argv);
		MPI_Comm_rank(MPI_COMM_WORLD, &meu_rank);
		
		if(meu_rank == 0){
			for(i=0; i < 10;i++){
				a[i] = (i*2)*PI;
			}
			MPI_Send(a, 10, MPI_DOUBLE, 1, 17, MPI_COMM_WORLD);
		}else if(meu_rank == 1){
			MPI_Recv(b, 10, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			printf("P: %d, mensagem veio do rank %d\n",meu_rank, status.MPI_SOURCE);
			printf("P: %d, mensagem possui tag %d\n",meu_rank, status.MPI_TAG);
			printf("P: %d, mensagem possui tamanho %d\n",meu_rank, cont);
			for(i=0;i<10;i++){
				printf("Valores do tipo double recebidos da maquina n0: %f\n",b[i]);
			}
		}	
		
	MPI_Finalize();
	
	return 0;
}
