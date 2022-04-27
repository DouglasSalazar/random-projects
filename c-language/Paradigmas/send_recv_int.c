// Neste programa, a maquina 0 envia um valor inteiro (99999) para a maquina 1
// A maquina 1 recebe o valor 99999, soma 1 ao valor recebido e o devolve a maquinha 0

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char** argv){

	int x, valor, size, rank;
	int tag = 10;
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
		MPI_Comm_size(MPI_COMM_WORLD, &size);
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		// Como estamos fazendo uma comunicao ponto a ponto, precisamos somente de 2 nos
		// Verificar se o programa esta sendo executado com somente 2 nos
		if(size != 2){
			if(rank == 0){
				printf("Usar exatamente duas maquinas nesse programa!\n");
			}
			MPI_Finalize();
			exit(0);
		}
		
		x = 99999;
		if(rank == 0){
			printf("Maquina %d enviando para a maquina 1\n",rank);
			printf("Valor sendo enviado: %d\n",x);
			MPI_Send(&x, 1, MPI_INT, 1, tag, MPI_COMM_WORLD);
			printf("Maquina %d recebendo da maquina 1\n",rank);
			MPI_Recv(&valor, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &status);
			printf("Valor %d recebido da maquina 1\n",valor);
		}else{ // Maquina 1
			MPI_Recv(&valor, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
			valor = valor + 1;
			MPI_Send(&valor, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
		}
		
	MPI_Finalize();	
	
	return 0;
}
