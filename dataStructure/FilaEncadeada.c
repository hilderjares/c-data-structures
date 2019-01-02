#include <stdio.h>
#include <stdlib.h>

struct NODE {
  int chave;
  struct NODE* prox;
};

typedef struct NODE NO;

struct FilaEncadeada {
  NO cabeca;
  NO* ult;
  int card;  // Quantidade de elementos na Fila
};
typedef struct FilaEncadeada FilaEnc;

FilaEnc criarFila() {
   FilaEnc F;
   F.card = 0;
   F.ult = NULL;
   F.cabeca.prox = NULL;
   return P;
}

void imprimir(FilaEnc F) {
   NO* p = F.cabeca.prox;
   while(p != NULL) {
	printf("%d ", p->chave);
        p = p->prox;
   }
   printf("\n");
}

void incluir(FilaEnc *F, int x) {
   NO* novo = NULL;
   
   novo = (NO*) malloc(sizeof(NO));
   novo->chave = x;
   novo->prox = NULL;
   if(F->cabeca.prox == NULL) F->cabeca.prox = novo;
   else F->ult->prox = novo;
   F->ult = novo;
   (F->card)++;
}

NO* remover(FilaEnc *F) {
   NO* aux = F->cabeca.prox;
   
   if(aux == NULL) printf("Fila VAZIA!\n");
   else {
	F->cabeca.prox = aux->prox;
	(F->card)--;
   }
   return aux;
}

int main() {
   FilaEnc F;

   F = criarFila();
   incluir(&F,1);
   incluir(&F,2);
   incluir(&F,3);
   imprimir(F);

   return 0;
}

