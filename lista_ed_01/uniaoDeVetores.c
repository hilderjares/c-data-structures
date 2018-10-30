#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

	int n = 3, *vetor_um, *vetor_dois, *vetor_result, i = 0, j = 0;
	
	vetor_um = (int*) malloc(n * sizeof(int));
	vetor_dois = (int*) malloc(n * sizeof(int));
	vetor_result = (int*) malloc((n * 2) * sizeof(int));

	vetor_um[0] = 2, vetor_um[1] = 3, vetor_um[2] = 5;
	vetor_dois[0] = 1, vetor_dois[1] = 4, vetor_dois[2] = 7;

	for(int k = 0; k < 2 * n; k++) {
		if(i >= n) {
			vetor_result[k] = vetor_dois[j];
			j++;
		} else if(j >= n) {
			vetor_result[k] = vetor_um[i];
			i++;
		} else if(vetor_um[i] < vetor_dois[j]) {
			vetor_result[k] = vetor_um[i];
			i++;
		} else {
			vetor_result[k] = vetor_dois[j];
			j++;
		}
	}

	for(int i = 0; i < 2 * n; i++) {
		printf("%d ", vetor_result[i]);
	}
	printf("\n");

	free(vetor_um);
	free(vetor_dois);
	free(vetor_result);
	
	return 0;
}
		
