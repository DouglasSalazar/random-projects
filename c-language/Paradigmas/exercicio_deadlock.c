/*
	Exercicio deadlock.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

#define boolean   unsigned
#define true      1
#define false     0

int main(int argc, char **argv){
	int rank,size,i;
	double a[10], b[10];
	MPI_Status status;
	MPI_Request request;
	
	MPI_Init(&argc, &argv);
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		
		if(rank == 0){
			MPI_Recv(b,10,MPI_DOUBLE,1,3,MPI_COMM_WORLD,&status);
			printf("Maquina 0 recebe: ");
			for(i=0;i<10;i++)
				printf("(%.2f)",b[i]);
			printf("\n");
			MPI_Send(a,10,MPI_DOUBLE,1,3,MPI_COMM_WORLD);
			printf("Maquina 0 envia: ");
			for(i=0;i<10;i++)
				printf("(%.2f)",a[i]);
			printf("\n");
		}else{  //Maquina 1
			MPI_Send(a,10,MPI_DOUBLE,0,3,MPI_COMM_WORLD);
			printf("Maquina 1 envia: ");
			for(i=0;i<10;i++)
				printf("(%.2f)",a[i]);
			printf("\n");
			MPI_Recv(b,10,MPI_DOUBLE,0,3,MPI_COMM_WORLD,&status);
			printf("Maquina 1 recebe: ");
			for(i=0;i<10;i++)
				printf("(%.2f)",b[i]);
			printf("\n");
		}
		
		
	MPI_Finalize();	
	return 0;
}
































