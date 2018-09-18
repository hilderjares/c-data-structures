#include <stdio.h>
#include <stdlib.h>
 
void printVetor(int *vetor, int lim_inferior, int lim_superior) {
  for(int i = lim_inferior; i < lim_superior; i++) 
    printf("%d ", vetor[i]);
  printf("\n");
}
 
void merge(int *vetor, int lim_inferior, int meio, int lim_superior) {

  int *vetor_direita = (int*) malloc((meio - lim_inferior + 2) * sizeof(int));
  int *vetor_esquerda = (int*) malloc((lim_superior - meio + 1) * sizeof(int));
 
  int j = 0;
  for(int i = lim_inferior; i <= meio; i++) {
    vetor_direita[j] = vetor[i];
    j++;
  }
  
  vetor_direita[j] = 1000000;  // Infinito
   
  int k = 0;
  for(int i = meio + 1; i <= lim_superior; i++) {
    vetor_esquerda[k] = vetor[i];
    k++;
  }
  
  vetor_esquerda[k] = 1000000;  // Infinito

  j = 0; k = 0;
  for(int i = lim_inferior; i <= lim_superior; i++) {
    if(vetor_direita[j] < vetor_esquerda[k]) {
        vetor[i] = vetor_direita[j];
        j++;
    } else {
        vetor[i] = vetor_esquerda[k];
        k++;
    }
  }
}
 
void mergeSort(int *vetor, int lim_inferior, int lim_superior) {
   
  if(lim_inferior >= lim_superior) return;
 
  int meio = (lim_superior + lim_inferior) / 2;   
  
  mergeSort(vetor, lim_inferior, meio);
  mergeSort(vetor, meio + 1, lim_superior);
  merge(vetor, lim_inferior, meio, lim_superior); 
}
 
int main(int argc, char const *argv[]) {

  int size = 0;
  int *vetor = NULL;
 
  printf("Digite o tamanho do vetor: ");
  scanf("%d",&size);
 
  vetor = (int*) malloc(size * sizeof(int));
  
  for(int i = 0; i < size; i++) 
    vetor[i] = size - i + 1;
  
  mergeSort(vetor, 0, size - 1);

  printVetor(vetor, 0, size); 
  
  free(vetor);  
 
  return 0;
}