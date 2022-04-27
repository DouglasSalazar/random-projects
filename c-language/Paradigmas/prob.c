/*
	Mostrar como usar a função probe e get_count para achar o tamanho
	de uma mensagem enviada (mensagem que vai chegar na "sua" máquina).
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

#define boolean   unsigned
#define true      1
#define false     0

int main(int argc, char **argv){
	int rank, size;
	int tag, iErr, contador, *i, j;
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		printf("Oi da maquina [%d] de um total de [%d]\n",rank, size);
		
		tag = 123;
		
		if(rank == 0){
			j = 200;
			contador = 10;
			iErr = MPI_Send(&j,contador,MPI_INT,1,tag,MPI_COMM_WORLD);
		}else{
			if(rank == 1){
				iErr = MPI_Probe(0,tag,MPI_COMM_WORLD,&status);
				iErr = MPI_Get_count(&status,MPI_INT,&contador);
				i = (int*)malloc(contador*sizeof(int));
				printf("Chegando [%d]\n",contador);
				iErr = MPI_Recv(i,contador,MPI_INT,0,tag,MPI_COMM_WORLD,&status);
				printf("i = ");
				for(j=0;j<contador;j++)
					printf("%d ",i[j]);
				
				free(i);
			}
		}
		
		
	MPI_Finalize();	
	return 0;
}
































