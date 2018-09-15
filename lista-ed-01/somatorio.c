#include <stdlib.h>
#include <stdio.h>

int somatorio(int numero) {	
	if (numero == 1) {
		return 1;
	}
	return (numero + somatorio(numero - 1));
}

int main(int argc, char const *argv[]) {
	printf("%d\n", somatorio(1));
	return 0;
}