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

void listar_rec(NO *p) {
   	if (p != NULL) {
      	printf("%i\n", p->chave);
      	listar_rec(p->prox);
   	}
}

void listar_invertido(NO *node){
    if(node != NULL){
         listar_invertido(node->prox);
         printf("%d\n", node->chave);
    }
}

int numerosDeNodes(NO* cabeca) { 
    int count = 0;  
    NO* p = cabeca;
    while (p != NULL) { 
        count++; 
        p = p->prox; 
    } 
    return count; 
} 

int main() {
	
	ListaEnc lista = criarLista();
	lista = incluir(lista, 12);
	lista = incluir(lista, 13);
	lista = incluir(lista, 11);
	lista = incluir(lista, 10);
	lista = incluir(lista, 9);

	listar(&lista);
	printf("\n");
	listar_rec(&lista.cabeca);
	printf("\n");
	listar_invertido(&lista.cabeca);
	printf("\n%i\n", numerosDeNodes(&lista.cabeca));

	return 0;
}
