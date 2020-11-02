#include <stdio.h>
#include <stdlib.h>

/* ############################################################################
                          Bloco para números INTEIROS
   ############################################################################
*/

int** iniciaMatrizInt(unsigned short int linha, unsigned short int coluna){
    if (linha !=0 && coluna !=0){
        int **novaMatriz;
        // Alocação de memória para as linhas da matriz
        novaMatriz = (int**)malloc(linha*sizeof(int*));
        if (novaMatriz == NULL){
            printf("\nErro! Não foi possível alocar memória (linhas)");}
        else {
            for (int i = 0; i < coluna; i++){
               // Alocação de memória para as colunas da matriz
                novaMatriz[i] = (int*)malloc(coluna*sizeof(int));
                if (novaMatriz == NULL) {
                  printf("\nErro! Não foi possível alocar memória (colunas)");  }
            }
            return novaMatriz;
        }
    }
    else
        printf("\nNão é possível criar uma matriz com dimensões nulas.\n");
        return NULL;

}

/*insereElemento() - Insere os elementos MANUALMENTE na matriz. Recebe como
parâmetros o número de linhas e colunas válidos (valores >0), e o endereço da
matriz.*/
void insereElementoInt(unsigned short int linha, unsigned short int coluna, int** matriz){
    for (int i = 0; i < linha; i++)
        for (int j = 0; j < coluna; j++){
            printf("Digite o elemento da linha [%d] e coluna [%d]: ", i,j);
            scanf("%d", &matriz[i][j]);}
}

/*imprimeMatrizInt() - Imprime na tela a matriz.*/
void imprimeMatrizInt(unsigned short int linha, unsigned short int coluna, int** matriz){
  for (int i = 0; i < linha; i++){
      for (int j = 0; j < coluna; j++){
          // Verificação apenas para fins estéticos na apresentação da Matriz
          if (j + 1 >= coluna){
            printf("[%d]\n", matriz[i][j]);  }
      else
        printf("[%d]\t", matriz[i][j]);
      }
  }
}

// Libera a memória alocada na matriz. Deve sempre ser utilizado ao final do programa.
int** liberaMatrizInt(unsigned short int linha, unsigned short int coluna, int** matriz){
  if (matriz == NULL) return NULL;
  for (int i = 0; i < linha; i++){
    // Libera as linhas da matriz
    free (matriz[linha]);  }
  // Libera o vetor de ponteiros
  free(matriz);
  return NULL;
}

                  // Operações Matemáticas com INTEIROS
/*
somaMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
int** somaMatrizInt(unsigned short int linhaA, unsigned short colunaA, int** matrizA,
  unsigned short int linhaB, unsigned short colunaB, int** matrizB){
      // Verificação da condição de Soma de matrizes
      if (linhaA == linhaB && colunaA == colunaB){
          int** matrizSoma;
          /* alocação dinâmica da matrizSoma. Poderia ter sido utilizdo o valor das
          dimensões da matriz B, haja vista que devem ser iguais.*/
          matrizSoma = iniciaMatrizInt(linhaA,colunaA);
          for (int i = 0; i < linhaA; i++){
              for(int j = 0; j < colunaA; j++){
                  matrizSoma[i][j] = matrizA[i][j] + matrizB[i][j];}
          }
      return matrizSoma;  }
    else {
        printf("\nErro! Não é possível somar matrizes de dimensões diferentes.");
        return NULL;  }
}

/*
subMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
int** subMatrizInt(unsigned short int linhaA, unsigned short int colunaA, int** matrizA,
  unsigned short int linhaB, unsigned short int colunaB, int** matrizB){
    // Verificação da condição de Subtração de matrizes
    if (linhaA == linhaB && colunaA == colunaB){
        int** matrizSub;
        /* alocação dinâmica da matrizSub. Poderia ter sido utilizdo o valor das
        dimensões da matriz B, haja vista que devem ser iguais.*/
        matrizSub = iniciaMatrizInt(linhaA,colunaA);
        for (int i = 0; i < linhaA; i++){
            for(int j = 0; j < colunaA; j++){
                matrizSub[i][j] = matrizA[i][j] - matrizB[i][j];}
        }
        return matrizSub;   }
    else {
        printf("\nErro! Não é possível somar matrizes de dimensões diferentes.");
        return NULL;    }
}

/*
multMatrizInt() - Multipla duas matrizes A e B, retornando o produto de ambas.
*/
int** multMatrizInt(unsigned short int linhaA, unsigned short int colunaA, int** matrizA,
  unsigned short int linhaB, unsigned short int colunaB, int** matrizB){
    // Verificação da condição de Multiplicação de matrizes
    if (colunaA == linhaB){
        int** matrizMult;
        // auxiliar é a variável que recebe o valor da soma de cada iteração linha-coluna
        int auxiliar;
        // alocação dinâmica da matrizMult.
        // Importante observar que as dimensões de matrizMult são:
        // matrizMult[linhaA][colunaB], pela definição de multiplação de matrizes
        matrizMult = iniciaMatrizInt(linhaA,colunaB);
        // Laços de "linha da MatrizA pela coluna da matriz B"
        for (int i = 0; i < linhaA; i++){
            for(int j = 0; j < colunaB; j++){
                // a cada iteração o valor é zerado para a nova soma linha-coluna
                auxiliar = 0;
                //Loop interno para percorrer as linhas da coluna A
                for (int k = 0; k < colunaA; k++) {
                    auxiliar = auxiliar + matrizA[i][k]*matrizB[k][j];  }
            matrizMult[i][j] = auxiliar;  }
        }
        return matrizMult;  }
    else {
        printf("\nErro! Não é possível somar matrizes de dimensões diferentes.");
        return NULL;  }
}

/*
multNumMatrizReal() - Multiplica um número inteiro por uma matriz inteira;
*/
void multNumMatrizInt(unsigned short int linha, unsigned short int coluna,
                      int numero,int** matriz){
    for (int i = 0; i < linha; i++)
        for (int j = 0; j < coluna; j++){
          matriz[i][j] = numero*matriz[i][j];  }
}

/* ############################################################################
                          Bloco para números REAIS
   ############################################################################
*/

/*
iniciaMatrizReal() - Inicia a Matriz e realiz a Alocação Dinâmica de memória.
Recebe como argumentos o número de linhas e colunas válidos (valores > 0)
*/
float** iniciaMatrizReal(unsigned short int linha, unsigned short int coluna){
    if (linha !=0 && coluna !=0){
        float **novaMatriz;
        // Alocação de memória para as linhas da matriz
        novaMatriz = (float**)malloc(linha*sizeof(float*));
        if (novaMatriz == NULL){
            printf("\nErro! Não foi possível alocar memória (linhas)");}
        else {
            for (int i = 0; i < coluna; i++){
               // Alocação de memória para as colunas da matriz
                novaMatriz[i] = (float*)malloc(coluna*sizeof(float));
                if (novaMatriz == NULL) {
                  printf("\nErro! Não foi possível alocar memória (colunas)");  }
            }
            return novaMatriz;
        }
    }
    else
        printf("\nNão é possível criar uma matriz com dimensões nulas.\n");
        return NULL;
}

/*insereElementoReal() - Insere os elementos MANUALMENTE na matriz. Recebe como
parâmetros o número de linhas e colunas válidos (valores >0), e o endereço da
matriz.*/
void insereElementoReal(unsigned short int linha, unsigned short int coluna, float** matriz){
  for (int i = 0; i < linha; i++)
      for (int j = 0; j < coluna; j++) {
        printf("Digite o elemento da linha [%d] e coluna [%d]: ", i,j);
        scanf("%f", &matriz[i][j]);  }
}

/*imprimeMatrizReal() - Imprime na tela a matriz.*/
void imprimeMatrizReal(unsigned short int linha, unsigned short int coluna, float** matriz){
  for (int i = 0; i < linha; i++){
    for (int j = 0; j < coluna; j++){
      // Verificação apenas para fins estéticos na apresentação da Matriz
      if (j + 1 >= coluna){
          printf("[%f]\n", matriz[i][j]);  }
      else
          printf("[%f]\t", matriz[i][j]);  }
  }
}

// Libera a memória alocada na matriz. Deve sempre ser utilizado ao final do programa.
float **liberaMatrizReal(unsigned short int linha, unsigned short int coluna, float** matriz){
  if (matriz == NULL) return NULL;
  for (int i = 0; i < linha; i++){
    // Libera as linhas da matriz
    free (matriz[linha]);  }
  // Libera o vetor de ponteiros
  free(matriz);
  return NULL;
}

                        // Operações Matemáticas com REAIS
/*
somaMatrizFloat() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
float** somaMatrizReal(unsigned short int linhaA, unsigned short int colunaA, float** matrizA,
                      unsigned short int linhaB, unsigned short int colunaB, float** matrizB){
        // Verificação da condição de Soma de matrizes
        if (linhaA == linhaB && colunaA == colunaB){
            float** matrizSoma;
            /* alocação dinâmica da matrizSoma. Poderia ter sido utilizdo o valor das
            dimensões da matriz B, haja vista que devem ser iguais.*/
            matrizSoma = iniciaMatrizReal(linhaA,colunaA);
            for (int i = 0; i < linhaA; i++) {
                for(int j = 0; j < colunaA; j++) {
                    matrizSoma[i][j] = matrizA[i][j] + matrizB[i][j];  }
            }
            return matrizSoma; }
            else{
                printf("\nErro! Não é possível somar matrizes de dimensões diferentes.");
                return NULL;  }
}

/*
subMatrizFloat() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
float** subMatrizReal(unsigned short int linhaA, unsigned short int colunaA, float** matrizA,
                    unsigned short int linhaB, unsigned short int colunaB, float** matrizB){
        // Verificação da condição de Subtração de matrizes
        if (linhaA == linhaB && colunaA == colunaB){
            float** matrizSub;
            /* alocação dinâmica da matrizSub. Poderia ter sido utilizdo o valor das
            dimensões da matriz B, haja vista que devem ser iguais.*/
            matrizSub = iniciaMatrizReal(linhaA,colunaA);
            for (int i = 0; i < linhaA; i++){
                for(int j = 0; j < colunaA; j++){
                    matrizSub[i][j] = matrizA[i][j] - matrizB[i][j]; }
             }
            return matrizSub;  }
        else{
            printf("\nErro! Não é possível somar matrizes de dimensões diferentes.");
            return NULL;  }
}

//multMatrizFloat() - Multipla duas matrizes A e B, retornando o produto de ambas.
float** multMatrizReal(unsigned short int linhaA, unsigned short int colunaA, float** matrizA,
                      unsigned short int linhaB, unsigned short int colunaB, float** matrizB){
        // Verificação da condição de Multiplicação de matrizes
        if (colunaA == linhaB){
            float** matrizMult;
            // auxiliar é a variável que recebe o valor da soma de cada iteração linha-coluna
            float auxiliar;
            /* alocação dinâmica da matrizMult. Importante observar que as
            dimensões de matrizMult são: matrizMult[linhaA][colunaB], pela
            definição de multiplação de matrizes*/
            matrizMult = iniciaMatrizReal(linhaA,colunaB);
            // Laços de "linha da MatrizA pela coluna da matriz B"
            for (int i = 0; i < linhaA; i++){
                for(int j = 0; j < colunaB; j++){
                    // a cada iteração o valor é zerado para a nova soma linha-coluna
                    auxiliar = 0;
                    //Loop interno para percorrer as linhas da coluna A
                    for (int k = 0; k < colunaA; k++){
                        auxiliar = auxiliar + matrizA[i][k]*matrizB[k][j];  }
                matrizMult[i][j] = auxiliar;  }
           }
           return matrizMult;  }
        else {
            printf("\nErro! Não é possível multiplcar matrizes de dimensões diferentes.");
            return NULL;  }
}

//multNumMatrizReal() - Multiplica um número inteiro por uma matriz inteira;
void multNumMatrizReal(unsigned short int linha, unsigned short int coluna,
                      int numero, float** matriz){
    for (int i = 0; i < linha; i++)
        for (int j = 0; j < coluna; j++){
            matriz[i][j] = numero*matriz[i][j];  }
}
