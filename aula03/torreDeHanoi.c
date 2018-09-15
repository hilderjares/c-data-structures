#include <stdlib.h>
#include <stdio.h>

int *origem, *trabalho, *destino;

int hanoi(int *o, int *topo_origem, int *t, int *topo_trabalho, int *d, int *topo_destino, int numero_disco) {	
	
	char o_nome[20], d_nome[20];
	
	if (numero_disco == 1) {	
		
		(*topo_destino) += 1;
		d[*topo_destino] = o[*topo_origem]; 
		(*topo_origem) -= 1;

		if (o == origem) sprintf(o_nome, "ORIGEM");
		if (o == trabalho) sprintf(o_nome, "TRABALHO");
		if (o == destino) sprintf(o_nome, "DESTINO");

		if (d == origem) sprintf(d_nome, "ORIGEM");
		if (d == trabalho) sprintf(d_nome, "TRABALHO");
		if (d == destino) sprintf(d_nome, "DESTINO");

		printf("MOVEU DISCO (%i) DA TORRE (%s) PARA A TORRE %s \n", d[*topo_destino], o_nome, d_nome);
		return 1;

	} else {
		
		return 
		hanoi(o, topo_origem, d, topo_destino, t, topo_trabalho, numero_disco - 1) +
		hanoi(o, topo_origem, t, topo_trabalho, d, topo_destino, 1) +
		hanoi(t, topo_trabalho, o, topo_origem, d, topo_destino, numero_disco - 1);
	}
}

int main(int argc, char const *argv[]) {
	int n = 4, topo_origem = -1, topo_trabalho = -1, topo_destino = -1;

	origem = (int *) malloc(n * sizeof(int));
	trabalho = (int *) malloc(n * sizeof(int));
	destino = (int *) malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i) origem[i] = n - i;
	topo_origem = n - 1;
	
	hanoi(origem , &topo_origem, trabalho, &topo_trabalho, destino, &topo_destino, n);

	free(origem);
	free(trabalho);
	free(destino);

	return 0;
}
