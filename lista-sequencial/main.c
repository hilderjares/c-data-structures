#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

typedef struct {
	int *vetor;
	int ultimo_elemento;
	int cardinalidade;
	int tamanho;
} LISTA_SEQ;

LISTA_SEQ criarLista(int tamanho) {
	LISTA_SEQ lista;
	lista.vetor = (int*) malloc(tamanho * sizeof(int));
	lista.ultimo_elemento = -1;
	lista.cardinalidade = 0;
	lista.tamanho = tamanho;
	return lista;
}

bool inserir(LISTA_SEQ *lista, int elemento) {
	if(lista->cardinalidade < lista->tamanho) {
		(lista->ultimo_elemento) += 1;
		lista->vetor[lista->ultimo_elemento] = elemento;
		(lista->cardinalidade) += 1;
		return true;
	}
	return false;
}

int main(int argc, char const *argv[]) {

	LISTA_SEQ lista;
	int size = 5;
	bool result = true;
	int valor;

	lista = criarLista(size);

	printf("Digite os valores para inserir na lista:\n");
	for (int i = 0; i < size; ++i) {
		scanf("%i", &valor);
		if(!inserir(&lista, valor)) break;
	}

	printf("\n");

	for (int i = 0; i < size; ++i) {
		printf("%i\n", lista.vetor[i]);
	}


	return 0;
}