#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void troca(int *v1,int *v2) {
	int aux = *v1;
	*v1 = *v2;
	*v2 = aux;
}

void bubbleSortRecP(int *v, int p, int r, int j, int *m) {	
	if(j == r) {
		return;
	}
	if (v[j] > v[*m]) *m = j;
	j = j + 1;
	bubbleSortRecP(v, p, r, j, m);
}

int * bubbleSortRecS(int * v, int p, int r) {	
	int m = p;
	if (p == (r - 1)) {
		return v;
	}

	bubbleSortRecP(v, p, r, p + 1, &m);
	troca(&v[m], &v[r - 1]); 
	r = r - 1; 
	bubbleSortRecS(v, p, r);
}

int main(int argc, char const *argv[]) {
	int *vetor, length = 5;

	vetor = (int*) malloc (length * sizeof(int));

	srand((unsigned)time(NULL));
	for (int i = 0; i < length; ++i) vetor[i] = rand() % 101;

	bubbleSortRecS(vetor, 0, length);

	for (int i = 0; i < length; ++i) printf("[%i]", vetor[i]);

	printf("\n");

	free(vetor);

	return 0;
}