#include "stdio.h"
#include "stdlib.h"

unsigned int *fibonacci_vetor;

unsigned int fatorial(int n) {
	if (n == 0) {
		return 1;
	}
	return  n * fatorial(n - 1);
}

unsigned int fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned int fibonacci_recursivo_melhorado(int n) {
	if (n == 0) {
		fibonacci_vetor[0] = 0;
		return fibonacci_vetor[0];
	}
	if (n == 1) {
		fibonacci_vetor[1] = 1;
		return fibonacci_vetor[1];
	}

	if (fibonacci_vetor[n - 1] == -1) fibonacci_vetor[n - 1] = fibonacci_recursivo_melhorado(n - 1); 
	if (fibonacci_vetor[n - 2] == -1) fibonacci_vetor[n - 2] = fibonacci_recursivo_melhorado(n - 2); 

	return fibonacci(n - 1) + fibonacci(n - 2);
}

unsigned int fibonacci_iterativo(int n) {	
	unsigned int resultado;
	unsigned int *fibonacci_iterativo = (int *) malloc(n *sizeof(int));

	fibonacci_iterativo[0] = 0;
	fibonacci_iterativo[1] = 1;

	for (int i = 2; i <= n; ++i) {
		fibonacci_iterativo[i] = fibonacci_iterativo[i - 1] + fibonacci_iterativo[i - 2];
	}

	resultado = fibonacci_iterativo[n];
	free(fibonacci_iterativo);
	return resultado;
}

int main(int argc, char const *argv[]) {	
	int n = 10;

	fibonacci_vetor = (int *) malloc((n + 1) * sizeof(int));

	for (int i = 0; i < n; ++i) fibonacci_vetor[i] = -1;

	printf("%d\n", fatorial(5));
	printf("%d\n", fibonacci(4));
	printf("%d\n", fibonacci_iterativo(4));
	printf("%d\n", fibonacci_recursivo_melhorado(4));

	return 0;
}
