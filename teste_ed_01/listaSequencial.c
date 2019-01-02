#include<stdio.h>
#include<stdlib.h>

typedef struct {

  int *V;

  int f;   // índice do último elemento

  int tam; // tamanho: tamanho máximo da lista 

} ListaSeq;


ListaSeq criarLista(int tam) {

   ListaSeq L;

   L.V = (int *) malloc(tam*sizeof(int));

   L.f = -1;

   L.tam = tam;

   return L;

}


ListaSeq incluir(ListaSeq L, int x) {

   if((L.f)+1 < L.tam) {

      (L.f)++;

      L.V[L.f] = x;

   } else printf("Lista cheia! Elemento NÃO incluído!\n");

   return L;

}

ListaSeq removeTodos(ListaSeq L, int x){
	for (int i = 0; i <= (L.f); ++i) {
		if (L.V[i] == x) {
		 	L.V[i] = 0;
		 	int aux = L.V[L.f];
		 	L.V[L.f] = L.V[i];
		 	L.V[i] = aux;
		    (L.f) -= 1;
		}
	}
	return L;
}

int main() {
    
    ListaSeq lista;
    lista = criarLista(8);
    lista = incluir(lista, 12);
    lista = incluir(lista, 14);
    lista = incluir(lista, 12);
    lista = incluir(lista, 13);
    lista = incluir(lista, 17);

    lista = removeTodos(lista, 12);

    for (int i = 0; i <= (lista.f); ++i) {
    	printf("%i\n", lista.V[i]);
    }

    return 0;
}














