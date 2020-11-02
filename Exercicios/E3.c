/*
3. Faça o programa que apresenta a seguinte saída, perguntando ao usuário o
número máximo (no exemplo, 9). Este número deve ser sempre ímpar.

1 2 3 4 5 6 7 8 9
  2 3 4 5 6 7 8
    3 4 5 6 7
      4 5 6
        5
*/

#include <stdio.h>
#include <stdlib.h>

void imprimeTela(int *vetor, int n){ //poderia ser utilizado o parmetro vetor[]
    int auxiliar = 0; //Variavel para indicar a contagem dos valores exibidos
    while(auxiliar < (n/2) + 0.5){
        // Laço para percorrer o vetor conforme alterações das linhas
        for (int i = auxiliar; i < n-auxiliar; i++){
              // - Laço para imprimir conforme o vetor diminui
              // - Laço dentro de um laço para controlar a diminuição do vetor
              // conforme ocorre a iteração do tamanho (?)
              for (int j = i; j < n - i; j++){
                  printf("[%d]\t", vetor[j]);
              }
              auxiliar++;
              printf("\n");
              // Altera as caixas e recuo
              for (int j = 0; j < auxiliar; j++){
                  printf("\t");
              }
        }
    }
    printf("\n");
}

void main (void){
    int n;
    while (1){
      printf("\nDigite um número ímpar: ");
      scanf("%d",&n);
      if (n %2 != 0){
        break;
      }
      else
        printf("\nErro! Digite um número ÍMPAR.");
    }
    // Alocação de memória para o vetor
    int *vetor = malloc(n * sizeof(int));

    // Laço para preencher o vetor inicial
    for (int i = 0; i < n; i ++){
        vetor[i] = i + 1;
    }
    imprimeTela(vetor,n);
    free(vetor);
}
