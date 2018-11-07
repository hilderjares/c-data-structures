#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int chave;
	struct NO* proximo;
};

typedef NODE NO;

struct FILA {
	NO cabeca;
	NO* ultimo;
	int cardinalidade;
};

typedef FILA FILA;

FILA criaFila() {
	FILA fila;
	fila.cardinalidade = 0;
	fila.ltimo = NULL;
	fila.cabeca.proximo = NULL;
	return fila;
}

int main(int argc, char const *argv[]) {
	
	FILA fila;

	fila = criaFila();

	return 0;
}