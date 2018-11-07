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
	if (lista->cardinalidade < lista->tamanho) {
		(lista->ultimo_elemento) += 1;
		lista->vetor[lista->ultimo_elemento] = elemento;
		(lista->cardinalidade) += 1;
		return true;
	}
	return false;
}

int buscar(LISTA_SEQ *lista, int valor) {
	for (int i = 0; i < lista->tamanho; ++i) {
		if (lista->vetor[i] == valor) {
			return i;
			break;
		}
	}
	return -1;
}

bool deletar(LISTA_SEQ *lista, int valor) {
	int indice = buscar(lista, valor);
	if (indice != -1) {
		if ((lista->cardinalidade) >= 0) {
			for (int i = indice; i < (lista->cardinalidade) - 1; ++i) {
				lista->vetor[i] = lista->vetor[i + 1];
			}
			(lista->cardinalidade) -= 1;
			return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[]) {

	LISTA_SEQ lista;
	int size = 5;
	bool result = true;
	int elemento, valor;

	lista = criarLista(size);

	printf("Digite os valores para inserir na lista:\n");
	for (int i = 0; i < size; ++i) {
		scanf("%i", &elemento);
		if(!inserir(&lista, elemento)) break;
	}

	printf("\n");

	for (int i = 0; i < size; ++i) {
		printf("%i\n", lista.vetor[i]);
	}

	printf("\n");
	printf("Digite o valor a ser procurado na lista: ");
	scanf("%i", &valor);
	if(buscar(&lista,valor) != -1) printf("%i\n", buscar(&lista, valor)); 

	if(deletar(&lista, valor)) printf("Elemento deletado\n");
	else printf("Elemento não foi deletado\n");

	if(deletar(&lista, valor + 1)) printf("Elemento deletado\n");
	else printf("Elemento não foi deletado\n");

	for (int i = 0; i < lista.cardinalidade; ++i) {
		printf("%i\n", lista.vetor[i]);
	}

	return 0;
}