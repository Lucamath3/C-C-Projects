/*
5. Crie um programa  capaz de multiplicar uma linha de uma matriz de inteiros
por um dado número. Faça o mesmo para uma coluna. A matriz deve ser lida de
teclado.
*/

#include <stdio.h>
#include <stdlib.h>

// Cria a matriz da função principal
int** criaMatriz (unsigned int linha,unsigned int coluna){
  int **novaMatriz;
  novaMatriz = (int**)malloc(linha*sizeof(int*));
  if (novaMatriz == NULL){
    printf("\nErro! Não foi possível alocar memória (linhas)");
  }
  else {
    for (int i = 0; i < coluna; i++){
        novaMatriz[i] = (int*)malloc(coluna*sizeof(int));
        if (novaMatriz == NULL){
            printf("\nErro! Não foi possível alocar memória (colunas)");
        }
    }
  }
  return novaMatriz;
}

// Recebe a matriz da função principal e preenche-a
void insereValor(unsigned int linha, unsigned int coluna, int **matriz){
  for (int i = 0; i < linha; i++)
      for (int j = 0; j < coluna; j++){
        printf("Digite o elemento da linha [%d] e coluna [%d]: ", i,j);
        scanf("%d", &matriz[i][j]);
      }
}

// Recebe a matriz da função principal e imprime na tela
void apresentaMatriz(unsigned int linha, unsigned int coluna, int **matriz){
  for (int i = 0; i < linha; i++){
    for (int j = 0; j < coluna; j++){
      // Verificação apenas para fins estéticos na apresentação da Matriz
      if (j + 1 >= coluna){
      printf("[%d]\n", matriz[i][j]);
      }
      else
        printf("[%d]\t", matriz[i][j]);
    }
  }
}

// Multiplica a matriz pelo número dado
void multiplicaMatriz(int linha, int coluna, int n, int **matriz){
  for (int i = 0; i < linha; i++)
      for (int j = 0; j < coluna; j++){
        matriz[i][j] = n*matriz[i][j];
      }
  printf("\nNova matriz após a multiplação: \n");
  apresentaMatriz(linha,coluna,matriz);
}

void main(void){
  //vetorCaracteristica possui as informações da matriz ([0] linha [1] coluna
  // e [2] o numero n)
  unsigned int linha, coluna;
  int n;
  int **matriz;
  printf("\nDigite o número de linhas da matriz: ");
  scanf("%d",&linha);
  printf("\nDigite o número de colunas da matriz: ");
  scanf("%d",&coluna);
  matriz = criaMatriz(linha,coluna);
  insereValor(linha,coluna,matriz);
  printf("\nA matriz criada foi: \n");
  apresentaMatriz(linha,coluna,matriz);
  printf("\nDigite o número que deseja realiar a multiplicação: ");
  scanf("%d",&n);
  multiplicaMatriz(linha,coluna,n,matriz);
}
