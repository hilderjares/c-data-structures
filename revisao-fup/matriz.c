#include "stdio.h"

int main(int argc, char const *argv[]) {
	int m[3][3] = {{0, 1, 4}, 
				   {6, 7, 8}, 
				   {9, 0, 9}};

	for (int i = 0; i < 3; ++i)
		printf("%i\n", m[i][i]);

	return 0;
}