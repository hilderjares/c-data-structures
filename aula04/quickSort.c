#include "stdio.h"
#include "stdlib.h"

void troca(int *a, int *b) {
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int partition(int *vet, int p, int r) {

	int aux, j = p + 1, k = r, pivo = vet[p];
	
	while(j <= k) {
		while(vet[j] <= pivo) j = j + 1;
		while(vet[k] > pivo) k = k - 1;
		if(j < k) troca(&vet[j], &vet[k]);
	}
	troca(&vet[p], &vet[k]);
	return k;
}

int * quickSort(int *vet, int p, int r) {
	if(p < r) {
		int q = partition(vet, p, r);
		quickSort(vet, p, q - 1);
		quickSort(vet, q + 1, r);
	}
	return vet;
}

int main(int argc, char const *argv[]) {
	
	int *vet, size = 5;	
	vet = (int*) malloc(size * sizeof(int));

	for(int i = 0; i < size; i++) vet[i] = size - i + 1;

	quickSort(vet, 0, size - 1);

	for(int i = 0; i < size; i++) printf("%i\n", vet[i]);

	free(vet);

	return 0;
}