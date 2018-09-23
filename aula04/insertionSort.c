#include <stdio.h>
#include <stdlib.h>

int * insertionSort(int *vetor, int length)
{
	int aux, j;
	for (int i = 1; i < length; ++i)
	{
		j = i;
		while(vetor[j - 1] > vetor[j] && j > 0)
		{	
			//if (j > 0) break;
			aux = vetor[j - 1];
			vetor[j - 1] = vetor[j];
			vetor[j] = aux;	 
			j = j - 1;   
		}
	}
	return vetor;
}

int main(int argc, char const *argv[])
{
	int *vetor, length = 5;

	vetor = (int *) malloc(length * sizeof(int));

	vetor[0] = 1, vetor[1] = 2, vetor[2] = 5, vetor[3] = 8, vetor[4] = 6;

	insertionSort(vetor, length);

	for (int i = 0; i < length; ++i) printf("%i\n", vetor[i]);

	free(vetor);

	return 0;
}