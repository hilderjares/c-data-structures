#include <stdio.h>
#include <stdlib.h>

#define TAM 2

int matrizProduto(int m1[TAM][TAM], int m2[TAM][TAM], int n) {	
	int produto_matriz = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			produto_matriz += m1[i][j] * m2[i][j];
		}
	}
	return produto_matriz;
}

int main(int argc, char const *argv[]) {
	
	int mat1[TAM][TAM] = {{1, 2}, {1, 2}};
	int mat2[TAM][TAM] = {{1, 2}, {1, 2}};
	printf("%i\n", matrizProduto(mat1, mat2, TAM));
	return 0;
}