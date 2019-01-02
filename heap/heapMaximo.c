
#include <stdio.h>
#include <stdlib.h>

struct HeapMax {
  int *V;
  int tam;    // tamanho: tamanho máximo do HeapMax
  int f;   // índice do último elemento
};

typedef struct HeapMax HeapMax;

HeapMax criarHeapMax(int tam) {
   HeapMax H;
   H.V = (int *) malloc(tam*sizeof(int));
   H.tam = tam;
   H.f = -1;
   return H;
}

int filhoEsq(HeapMax H, int i) {
        if((2*i + 1) <= H.f) return 2*i + 1;
  else return -1;
}

int filhoDir(HeapMax H, int i) {
        if((2*i + 2) <= H.f) return 2*i + 2;
  else return -1;
}

int pai(HeapMax H, int i) {
        if(i == 0) return -1;
  else return (i-1)/2;
}

void subir(HeapMax *H, int i) {
        while(i!=0 && H->V[i] > H->V[(i-1)/2] ) {
            int aux= H->V[i];
            H->V[i] = H->V[(i-1)/2];
            H->V[(i-1)/2] = aux;
            i = (i-1)/2;
        }
}

void descer(HeapMax *H, int i) {
     int maior = i;
     int e = filhoEsq(*H,i);
     int d = filhoDir(*H,i);
     if(e > -1 && H->V[e] > H->V[i]) maior = e;
     if(d > -1 && H->V[d] > H->V[maior]) maior = d;

     if(maior != i) {
        int aux = H->V[i];
        H->V[i] = H->V[maior];
        H->V[maior] = aux;
        descer(H,maior);
     }     
}

void inserir(HeapMax *H, int x) {
    if(H->f == H->tam-1) {
      printf("HEAP CHEIO!\n");
    }
    else {
      (H->f)++;
      H->V[H->f] = x;
      subir(H,H->f);
    }
}

void construirHeapMax(HeapMax *H) {
  for(int i=(H->f+1/2)-1;i>=0;i--)
    descer(H,i);
}

int buscar(HeapMax *H, int valor) {
  if (H->f == 0) printf("Heap vazia\n");
  else {
    for (int j = 0; j <= H->f; j++) {
      if (H->V[j] == valor) return j;
    }
  }
  return -1;
}

void deletar(HeapMax *H, int valor) {
  int indice = buscar(H, valor);
  int aux = H->V[indice];
  H->V[indice] = H->V[H->f];
  H->V[H->f] = aux;
  (H->f)--;
  if (H->V[H->f] > pai(*H, H->f)) {
    descer(H, pai(*H, H->f));
  }
}

int main() {
   int tam=0, x=0;
   HeapMax H;   

   printf("Digite o tamanho da lista: ");
   scanf("%d", &tam);
   H=criarHeapMax(tam);
   inserir(&H,1);
   inserir(&H,3);
   inserir(&H,5);
   inserir(&H,4);
   inserir(&H,2);

  for(int i=0;i<=H.f;i++) printf("%d,",H.V[i]);
  deletar(&H, 3);
  puts("");
  for(int i=0;i<=H.f;i++) printf("%d,",H.V[i]);
   
   printf("\n");
   //printf("Digite o elemento a ser removido na lista: ");
   //scanf("%d", &x);

   return 0;
}