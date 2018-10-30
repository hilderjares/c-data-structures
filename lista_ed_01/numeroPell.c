#include "stdio.h"
#include "stdlib.h"

int pell(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return pell(n - 1) + pell(n - 2);
}

int main(int argc, char const *argv[]) {	
	printf("%i\n", pell(13));
	return 0;
}
