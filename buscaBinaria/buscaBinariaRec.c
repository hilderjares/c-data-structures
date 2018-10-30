#include <stdio.h>
#include <stdlib.h>
 
int buscaBinariaRec(int *vetor, int lim_inferior, int lim_superior, int chave) {
   int meio = (lim_inferior + lim_superior - 1) / 2;
 
   if(vetor[meio] == chave) return meio;
   if(lim_inferior >= lim_superior - 1) return -1; // caso base
   
   if(chave < vetor[meio])
      buscaBinariaRec(vetor, lim_inferior, lim_superior - 1, chave);
   else
      buscaBinariaRec(vetor, lim_inferior + 1, lim_superior, chave); 
}
   
int main(int argc, char const *argv[]) {
   
   int length, chave, *vetor, posicao_elem;
 
   printf("Digite o tamanho do vetor: ");
   scanf("%i", &length);
 
   vetor = (int*) malloc(length * sizeof(int));
   for(int i = 0; i < length; i++) vetor[i] = i;
 
   printf("Digite o elemento a ser pesquisado: ");
   scanf("%i", &chave);

   posicao_elem = buscaBinariaRec(vetor, 0, length, chave);

   if(posicao_elem != -1)
      printf("Valor encontrado na posição %i\n", posicao_elem);
   else 
      printf("Valor não encontrado!\n");
 
   free(vetor);
 
   return 0;
}