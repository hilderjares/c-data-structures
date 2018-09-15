#include "stdio.h"
#include "stdlib.h"

typedef struct {
	int chave;
	struct NO* proximo;
} NO;

int main(int argc, char const *argv[]) {
	NO cabeca;

	cabeca.chave = 10;

	NO *p = (NO*) malloc(sizeof(NO));

	// printf("%d\n", p);

	(*p).chave = 5;

	cabeca.proximo = p;

	return 0;
}


