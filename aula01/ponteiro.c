#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int capacidade; 
	int n;
	int *v; 
}Vector;

Vector* criar(int capacidade) {
	Vector *x = malloc(sizeof(Vector));
	x->n = 0;
	x->capacidade = capacidade;
	x-> v = malloc (sizeof(int) * capacidade);

	return x;	
}

void adiciona(int elemento, Vector *x) {
	if (x->n == x->capacidade){
		x->v = realloc(x->v, sizeof(int) * x->capacidade);
		x->v[x->n] = elemento;
		x->n += 1;
		return;
	}

	x->v[x->n] = elemento;
	x->n += 1;

}

void mostrar(Vector *x) {
	int i;
	for (int i = 0; i < x->n; ++i) {
		printf("%i ", x->v[i]);
	}
}

void deleta_ultimo(Vector *x) {
	int indice_ultimo = x->n-1;
	x->v[indice_ultimo] = -1;
	x->n -= 1;
}

int main(int argc, char const *argv[]) {
	// int n; 
	// n = 3;

	// int *p;
	// p = &n;

	// printf("%i\n", *p);

	int *p;
	p = malloc (sizeof(int) * 10);	
	p[9] = 5;

	int elemento;
	Vector *x;

	x = criar(2);
	
	printf("\n");

	adiciona(6, x);
	adiciona(3, x);
	adiciona(5, x);
	mostrar(x);
	deleta_ultimo(x);

	printf("\n");

	mostrar(x);

	printf("\n");

	return 0;
}