#include "stdio.h"
#include "stdlib.h"

int * selectionSort(int *vetor, int length) {	
 	int least, aux;
	for (int i = 0; i < length - 1; ++i) {	
		least = i;
		for (int j = i + 1; j < length; ++j) 
			if (vetor[j] < vetor[least]) least = j; 

		aux = vetor[least];
		vetor[least] = vetor[i];
		vetor[i] = aux;
	}
	return vetor;
}

int main(int argc, char const *argv[]) {
	
	int *vetor, length = 5;

	vetor = (int*) malloc (length * sizeof(int));

	vetor[0] = 5, vetor[1] = 10, vetor[2] = 1, vetor[3] = 4, vetor[4] = 3;
	
	selectionSort(vetor, length);

	for (int i = 0; i < length; ++i) printf("%i\n", vetor[i]);

	free(vetor);

	return 0;
}