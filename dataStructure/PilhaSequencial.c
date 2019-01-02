#include "stdio.h"
#include "stdlib.h"

struct PilhaSequencial {
	int *vetor;
	int tamanho;
	int topo;
};

typedef struct PilhaSequencial pilha;

pilha criar(int tamanho) {	
	pilha p;
	p.vetor = (int*) malloc(tamanho * sizeof(int));
	p.tamanho = tamanho;
	p.topo = -1;

	return p;
}

pilha inserir(int elemento) {
	pilha p;
	if (p.tamanho > (p.topo) + 1) {
		p.topo += 1;
		p.vetor[p.topo] = elemento;
	}
	return p;
}

int busar(int elemento) {
	pilha p;
	for (int i = 0; i <= p.topo; ++i) {
		if (p.vetor[i] == elemento) 
			return i;
	}
	return - 1;
}

pilha deletar() {
	pilha p;
	if (p.topo > -1)
		p.topo -= 1;
	return p;
}

int main(int argc, char const *argv[]) {
	pilha p;
	p = criar(10);

	p = inserir(7);
	p = inserir(15);
	p = inserir(12);
	p = deletar();
	p = deletar();
	p = deletar();
	p = inserir(7);
	p = inserir(12);

	if (busar(12) != -1) printf("%i\n", busar(12)); 

	for (int i = 0; i <= p.topo; ++i)
		printf("%i\n", p.vetor[i]);
	
	free(p.vetor);

	return 0;
}