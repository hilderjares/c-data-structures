#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Heap {
	int *vet;
	int tamanho;
	int ultimoElemento;	
};

typedef struct Heap HeapMin;

HeapMin criarHeapMin(int tamanho) {
	HeapMin H;
	H.vet = (int*) malloc (tamanho * sizeof(int));
	H.tamanho = tamanho;
	H.ultimoElemento = -1;
	return H;
}

int filhoEsquerdo(HeapMin H, int i) {
    if ((2 * i + 1) <= H.ultimoElemento) return 2 * i + 1;  
    else return -1;
}
 
int filhoDireito(HeapMin H, int i) {
    if ((2 * i + 2) <= H.ultimoElemento) return 2 * i + 2;
    else return -1;
}

void subir(HeapMin *H) {
    int i = H->ultimoElemento;

    while(true){  
        int pai = (i - 1) / 2;
        if (pai >= 0 && H->vet[pai] > H->vet[i]){
            int aux = H->vet[pai];
            H->vet[pai] = H->vet[i];
            H->vet[i] = aux;
            i = pai;
        } else {
            break;
        }
    }
}

void descer(HeapMin *H, int i) {
     
    int maior = i;
    int e = filhoEsquerdo(*H,i);
    int d = filhoDireito(*H,i);
    if(e > -1 && H->vet[e] > H->vet[i]) maior = e;
    if(d > -1 && H->vet[d] > H->vet[maior]) maior = d;

    if(maior != i) {
        int aux = H->vet[i];
        H->vet[i] = H->vet[maior];
        H->vet[maior] = aux;
        descer(H,maior);
    }     
}

void construirHeapMax(HeapMin *H) {
    for(int i = (H->ultimoElemento+1/2)-1; i >= 0; i--) descer(H,i);
}

void inserir(HeapMin *H, int valor){
    H->ultimoElemento = H->ultimoElemento + 1;
    H->vet[H->ultimoElemento] = valor;
    subir(H);
}

int main(int argc, char const *argv[]) {

	int tamanho = 0, k = 0;
	HeapMin H;
	
	printf("Digite o tamanho do Heap :\n");
	scanf("%i", &tamanho);

    H = criarHeapMin(tamanho);
    int elementos[tamanho];
    
    printf("Digite os valores do Heap :\n");
    for (int i = 0; i < tamanho; ++i) {
        scanf("%i", &elementos[i]);
    }

    printf("Digite o valor de k :\n");
    scanf("%i", &k);

    for (int i = 0; i < k; ++i) {
        inserir(&H, elementos[i]);
    }

    puts("-------------------");
    for (int i = 0; i <= H.ultimoElemento; ++i) {
        printf("%i ", H.vet[i]);
    }  
    puts("\n-------------------");

    for (int i = k; i < tamanho; ++i) {
        printf("raiz: [%i]\n", H.vet[0]);
        if (elementos[i] > H.vet[0]) {
            int aux = H.vet[0];
            H.vet[0] = elementos[i];
            elementos[i] = aux;
            construirHeapMax(&H);
        } 
        {
            for (int i = 0; i <= H.ultimoElemento; ++i) {
                printf("%i ", H.vet[i]);
            }  
            puts("");
        }
    }

    puts("-------------------");
    for (int i = 0; i <= H.ultimoElemento; ++i) {
        printf("%i ", H.vet[i]);
    }
    puts("\n-------------------");

	return 0;
}