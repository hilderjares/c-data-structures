#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isHeapMax(int vet[], int length) {
	bool isHeapMax = true;
	for (int i = 2; i < length; ++i) {
		if (vet[i / 2] < vet[i]) {
			isHeapMax = false;
		}
	}
	return isHeapMax;
}

int main(int argc, char const *argv[]) {
	int vet_max [] = {7, 5, 2, 1};
	int vet_min [] = {1, 2, 4, 5, 6};	

	{
		int length = sizeof(vet_max) / sizeof(int);
		if(isHeapMax(vet_max, length)) printf("É um heap max!\n");
		else printf("Não é um heap max!\n");
	}

	{
		int length = sizeof(vet_min) / sizeof(int);
		if(isHeapMax(vet_min, length)) printf("É um heap max!\n");
		else printf("Não é um heap max!\n");	
	}

	return 0;
}