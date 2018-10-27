#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int chave;
  struct NODE* prox;
};

typedef struct NODE NO;

struct ListaEncadeada {
  NO cabeca;
  int card;  // Quantidade de elementos na Lista
};
typedef struct ListaEncadeada ListaEnc;


ListaEnc criarLista() {

   ListaEnc L;
   L.card = 0;
   L.cabeca.prox = NULL;
   return L;
}

ListaEnc incluir(ListaEnc L, int x) {
   NO* novo = NULL;

   novo = (NO*) malloc(sizeof(NO));
   novo->chave = x;
   novo->prox = L.cabeca.prox;
   L.cabeca.prox = novo;
   return L;
}

void listar(ListaEnc *L) {
	NO* p = L->cabeca.prox;
	while(p != NULL) {
		printf("%i\n", p->chave);
		p = p->prox;
	}
}

int main() {
	
	ListaEnc lista = criarLista();
	lista = incluir(lista, 12);
	lista = incluir(lista, 13);
	lista = incluir(lista, 11);
	lista = incluir(lista, 10);
	lista = incluir(lista, 9);

	listar(&lista);

	return 0;
}
