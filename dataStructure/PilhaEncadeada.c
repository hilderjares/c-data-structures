#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int chave;
  struct NODE* prox;
};

typedef struct NODE NO;

struct PilhaEncadeada {
  NO cabeca;
  int card;  // Quantidade de elementos na Pilha
};
typedef struct PilhaEncadeada PilhaEnc;

PilhaEnc criarPilha() {
   PilhaEnc P;
   P.card = 0;
   P.cabeca.prox = NULL;
   return P;
}

void imprimir(PilhaEnc P) {
   NO* p = P.cabeca.prox;
   while(p != NULL) {
	printf("%d ", p->chave);
        p = p->prox;
   }
   printf("\n");
}

void incluir(PilhaEnc *P, int x) {
   NO* novo = NULL;
   
   novo = (NO*) malloc(sizeof(NO));
   novo->chave = x;
   novo->prox = P->cabeca.prox;
   P->cabeca.prox = novo;
   (P->card)++;
}

NO* remover(PilhaEnc *P) {
   NO* aux = P->cabeca.prox;
   
   if(aux == NULL) printf("Pilha VAZIA!\n");
   else {
	P->cabeca.prox = aux->prox;
	(P->card)--;
   }
   return aux;
}

int main() {
   PilhaEnc P;

   P = criarPilha();
   incluir(&P,1);
   incluir(&P,2);
   incluir(&P,3);
   imprimir(P);

   return 0;
}

