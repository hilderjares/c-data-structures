#include <stdio.h>
#include <stdlib.h>

struct Fila {
  int *vetor;
  int tamanho;    // tamanho: tamanho máximo da Fila
  int cardinalidade;
  int inicio;    // índice do primeiro elemento
  int ultimo;   // índice do último elemento 
};

typedef struct Fila Fila;

Fila criarFila(int tam) {
  Fila F;
  F.vetor = (int *) malloc(tam * sizeof(int));
  F.cardinalidade = 0;
  F.tamanho = tam;
  F.inicio = 0;
  F.ultimo = -1;
  return F;
}

Fila inserir(Fila F, int valor) {
  if (F.cardinalidade == F.tamanho) printf("Fila cheia\n");
  else {
    F.ultimo = (F.ultimo + 1) % F.tamanho;
    F.vetor[F.ultimo] = valor;
    F.cardinalidade = F.cardinalidade + 1;
  }
  return F;
}

int buscar(Fila F, int valor) {
  if (F.cardinalidade == 0) printf("Fila vazia\n");
  else {
	  for (int j = F.inicio; j != F.ultimo; j = (j + 1) % F.tamanho) {
		  if (F.vetor[j] == valor) return j;
	  }
    if (F.vetor[F.ultimo] == valor) return F.ultimo;
  }
  return -1;
}

Fila remover(Fila F, int *valor) {
    if(F.cardinalidade == 0) printf("Fila vazia!\n");
    else {
         *valor = F.vetor[F.inicio];
         F.inicio = (F.inicio + 1) % F.tamanho;
         F.cardinalidade = F.cardinalidade - 1;
         return F;
    }
    return F;
}

int main() {

  int tamanho = 0, valor = 0;
  Fila F;   

  printf("Digite o tamanho da lista: ");
  scanf("%d", &tamanho);

  F = criarFila(tamanho);
  F = inserir(F, 1);
  F = inserir(F, 2);
  F = inserir(F, 3);

  for(int i = 0; i < F.cardinalidade; i++) printf("%d\n",F.vetor[i]);

  //for(int i=0;i<tam;i++) L = incluir(L,i+1);
   
  printf("Digite o elemento a ser removido na lista: ");
  scanf("%d", &valor);
  F = remover(F, &valor);

  for(int i = 0; i < F.cardinalidade; i++) printf("%d\n",F.vetor[i]);

  return 0;
}

