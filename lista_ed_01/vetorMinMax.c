#include <stdlib.h>
#include <stdio.h>

#define TAM 5

int * vetorMinMax(int vet[], int n) {	
	int *vetMinMax;
	vetMinMax = malloc (2 * sizeof(int));
	vetMinMax[0] = vet[0], vetMinMax[1] = vet[0]; 

	for (int i = 0; i < n; ++i) {
		if (vet[i] < vetMinMax[0]) {
			vetMinMax[0] = vet[i];
		}
		if (vet[i] > vetMinMax[1]) {
			vetMinMax[1] = vet[i];
		}
	}
	return vetMinMax;
}

int main(int argc, char const *argv[]) {	
	int vet[TAM] = {8, 4, 6, 3, 7};
	int menor = vetorMinMax(vet, TAM)[0];
	int maior = vetorMinMax(vet, TAM)[1];
	printf("MENOR VALOR DO VETOR: %i\nMAIOR VALOR DO VETOR: %i\n", menor, maior);
	return 0;
}