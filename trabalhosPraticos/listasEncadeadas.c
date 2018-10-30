#include <stdio.h>
#include <stdlib.h>

/* <LISTA SEQUENCIAL> */

struct ListaSequencial{
  int *vetor;
  int ultimo_elemento;   
  int tamanho;
};

typedef struct ListaSequencial ListaSeq;

/* </LISTA SEQUENCIAL> */
 
/* <LISTA ENCADEADA> */

struct NODE {
  char chave;
  struct NODE* prox;
};

typedef struct NODE NO;

struct ListaEncadeada {
  NO cabeca;
  int cardinalidade;
};

typedef struct ListaEncadeada ListaEnc;

/* </LISTA ENCADEADA> */

ListaSeq ciraListaSequencial(int tamanho) {
	ListaSeq LE;
	LE.vetor = (int*) malloc(tamanho * sizeof(int));
	LE.ultimo_elemento = -1;
	LE.tamanho = tamanho;
	return LE;
}

ListaEnc criaListaEncadeada() {
	ListaEnc LS;
	LS.cardinalidade = 0;
	LS.cabeca.prox = NULL;
	return LS;
}

ListaSeq incluirSequencial(ListaSeq ls, int valor) {
   	if ((ls.ultimo_elemento)+1 < ls.tamanho) {
      	(ls.ultimo_elemento) += 1;
	    ls.vetor[ls.ultimo_elemento] = valor;
   	} else printf("Lista cheia! Elemento NÃO incluído!\n");
   	return ls;
}

ListaEnc incluirEcadeada(ListaEnc le, char valor) {
   NO* novo = NULL;
   novo = (NO*) malloc(sizeof(NO));
   novo->chave = valor;
   novo->prox = le.cabeca.prox;
   le.cabeca.prox = novo;
   return le;
}

void imprimirListaSequencial(ListaSeq ls) {
	printf("ListaSequencial = {");
	for (int i = 0; i <= (ls.ultimo_elemento); ++i) {
    	printf("[%i]", ls.vetor[i]);
    }
    printf("}\n");
}

void imprimirListaEncadeada(ListaEnc *le) {
	NO* p = le->cabeca.prox;
	printf("ListaEncadeada = {");
	while(p != NULL) {
		printf("[%c]", p->chave);
		p = p->prox;
	}
	printf("}\n");
}

NO* deletarPeloIndice(NO *cabeca, int i) {
    NO *proximo;

    if (cabeca == NULL)
        return cabeca;
    proximo = cabeca->prox;

    if (i == 0) {
    	free(cabeca);
    	return proximo;
    }

    return (cabeca->prox = deletarPeloIndice(proximo, i - 1), cabeca);
}

void deletaListaEncadeada(ListaEnc *le, ListaSeq ls) {
	NO* p;
	for (int i = 0; i <= ls.ultimo_elemento; ++i) {
		p = deletarPeloIndice(&le->cabeca, ls.vetor[i]);	
	}
}

void listaEncadeadaInvertida(NO *cabeca){
    if(cabeca != NULL){
        listaEncadeadaInvertida(cabeca->prox);
        printf("[%c]", cabeca->chave);
    }
}

int main(int argc, char const *argv[]) {
	
	ListaEnc le;
	ListaSeq ls;

	le = criaListaEncadeada(15);
	ls = ciraListaSequencial(10);

   	le = incluirEcadeada(le, 'A');
	le = incluirEcadeada(le, 'B');
	le = incluirEcadeada(le, 'C');
	le = incluirEcadeada(le, 'D');
	le = incluirEcadeada(le, 'E');

	ls = incluirSequencial(ls, 2);
    ls = incluirSequencial(ls, 4);
    ls = incluirSequencial(ls, 8);

	imprimirListaSequencial(ls);
	imprimirListaEncadeada(&le);
	deletaListaEncadeada(&le, ls);
	imprimirListaEncadeada(&le);
	listaEncadeadaInvertida(&le.cabeca);

	printf("\n");

	return 0;
}