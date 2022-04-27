/*
Esse programa mostra o uso das funções MPT scatter e reduce. Cada processo (ou processador)
obtém diferentes dados a partir do processo (processador raiz) por meio da função MPI_scatter.
Os dados são somados e enviados de volta para o processo (processador) raiz usando MPI_Reduce.
O processo root imprime a soma global.
*/
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int rank, size, retorno;
#define root 0

int main(int argc, char**argv){
	int *meus_dados, *envia_dados, *recebe_dados;
	int contador;
	int tamanho, meu_tamanho, i, k, j, total, gtotal;
	
	retorno = MPI_Init(&argc, &argv);
		retorno = MPI_Comm_size(MPI_COMM_WORLD, &size);
		retorno = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
		// Cada processo receberá um número de elementos do root
		contador = 4;
		meus_dados = (int*)malloc(contador*sizeof(int));
	
		// Criar dados para serem enviados pelo root
		if(rank == root){
			tamanho = contador * size;
			envia_dados = (int*)malloc(tamanho*sizeof(int));
			recebe_dados = (int*)malloc(size*sizeof(int));
		
			for(i=0;i<tamanho;i++){
				envia_dados[i] = i;
			}
		
			free(envia_dados);
			free(recebe_dados);
		}
		// Envia diferentes dados para cada processo (ou processador)
		retorno = MPI_Scatter(envia_dados,contador,MPI_INT,meus_dados,contador,MPI_INT,root,MPI_COMM_WORLD);
	
		// Cada processo (ou processador) realiza a soma local
		total = 0;
		for(i=0;i<contador;i++){
			total += meus_dados[i];
		}
		printf("Minha identificação [%d], soma total = %d\n",rank,total);
		
		// Enviando as somas locais para o root
		retorno = MPI_Reduce(&total,&gtotal,1,MPI_INT,MPI_SUM,root,MPI_COMM_WORLD);
		
		// Impressão da soma pelo root
		if(rank == root){
			printf("Soma de todos os processos = %d\n",gtotal);
		}
	
	
		free(meus_dados);
	retorno = MPI_Finalize();
	
	
	return 0;
}
