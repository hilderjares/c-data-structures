#include "stdio.h"
#include "stdlib.h"

#define false 0
#define true 1
#define bool int

int * bubbleSortRec(int * v, int p, int r) {	
	int m = p, aux = 0;
	if (p == (r - 1)) {
		return v;
	}
	for (int j = p + 1; j < r; ++j) {	
		if (v[j] > v[m]) m = j;
	}
	aux = v[m];
	v[m] = v[r - 1];
	v[r - 1] = aux;
	r = r - 1;
	bubbleSortRec(v, p, r);
}

int * bubbleSort(int * v, int length) {	
	int aux;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length - 1; ++j) {	
			if (v[j] > v[j + 1]) {
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}
	return v;
}

int * bubbleSortBest(int * v, int p, int r) {	
	int aux = 0;
	bool trocado = false;
	do {	
		trocado = false;
		for (int j = 0; j < r - 1; ++j) {
			if (v[j] > v[j + 1]) {
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
				trocado = true;
			}
		}
		r = r - 1;
	}while(trocado);
}

int main(int argc, char const *argv[]) {
	
	int *vetor, length = 5;

	vetor = (int*) malloc (length * sizeof(int));

	vetor[0] = 5, vetor[1] = 10, vetor[2] = 1, vetor[3] = 4, vetor[4] = 3;

	// bubbleSort(vetor, length);

	// bubbleSortBest(vetor, 0, length);

	bubbleSortRec(vetor, 0, length);
	
	for (int i = 0; i < length; ++i) printf("%i\n", vetor[i]);

	free(vetor);

	return 0;
}