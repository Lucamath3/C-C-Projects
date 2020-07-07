#include <stdio.h>
#include <stdlib.h>

/* ############################################################################
                          Bloco para números INTEIROS
   ############################################################################
*/
/* validaDimensaoInt() - Função para evitar a inserção de dimensoes negativas nas
funções*/
int validaDimensao(short int dimensao){
    if (dimensao < 0){
        return dimensao*(-1);}
    else{
        return dimensao;}
}

/* iniciaMatrizInt() - função de inicialização das matrizes (alocação dinâmica);
Importante haver diferenciação entre matrizes quadráticas e não quadráticas devido
a forma como ocorre a alocação da memória (vetor de ponteiros para ponteiros).
*/
int** iniciaMatrizInt(short int linha, short int coluna){
    if (linha < 0 || coluna < 0){ //Verificação das dimensoes da matriz
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna);}

    if (linha != 0 && coluna !=0){ // Condição para evitar matriz vazia
        int **novaMatriz;
        novaMatriz = (int**)malloc(linha*sizeof(int*)); // Alocação de memória para as linhas da matriz
        if (novaMatriz == NULL){ // Verifica se não houve erro na alocação.
            printf("\nErro! Não foi possível alocar memória (linhas)");}
        else {
            for (short int i = 0; i < linha; i++){
                novaMatriz[i] = (int*)malloc(coluna*sizeof(int));   // Alocação de memória para as colunas da matriz
                if (novaMatriz == NULL) {
                    printf("\nErro! Não foi possível alocar memória (colunas)");  }
                }
            return novaMatriz;  }
    }
    else{
        printf("\nNão é possível criar uma matriz com dimensões nulas.\n");
        return NULL;}
}

/*insereElementoInt() - Insere os elementos MANUALMENTE na matriz. Recebe como
parâmetros o número de linhas e colunas válidos (valores >0), e o endereço da
matriz.*/
void insereElementoInt(short int linha, short int coluna, int** matriz){
    short int contadorLinha = 0, contadorColuna = 0;
    if (linha < 0 || coluna < 0){ //Verificação das dimensoes da matriz
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna);}
    for (short int i = 0; i < linha*coluna; i++){
        if (contadorColuna < coluna){
            printf("[i = %d] Digite o elemento da linha [%d] e coluna [%d]: ", i, contadorLinha, contadorColuna);
            scanf("%d", &matriz[contadorLinha][contadorColuna]);
            contadorColuna++;
            if (contadorColuna >= coluna){
                contadorColuna = 0;
                contadorLinha++; }
          }
      }
}


/*imprimeMatrizInt() - Imprime na tela a matriz.*/
void imprimeMatrizInt(short int linha, short int coluna, int** matriz){
    short int contadorLinha = 0, contadorColuna = 0;
    if (linha < 0 || coluna < 0){   //Verificação das dimensoes da matriz
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna);}
    for (short int i = 0; i < linha*coluna ; i++){
          if (contadorColuna >= coluna){
              contadorLinha++;
              contadorColuna = 0;
              printf("\n[%d]\t", matriz[contadorLinha][contadorColuna]); }
          else
              printf("[%d]\t", matriz[contadorLinha][contadorColuna]);
              contadorColuna++;
    }
    printf("\n");
}

// Libera a memória alocada na matriz. Deve sempre ser utilizado ao final do programa.
void liberaMatrizInt(short int linha, short int coluna, int** matriz){
    if (linha < 0 || coluna < 0){ //Verificação das dimensoes da matriz
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna);  }
    for (short int i = 0; i < linha; i++){
        free (matriz[i]); } // Libera as linhas da matriz  }
    free(matriz); // Libera o vetor de ponteiros
}

                  // Operações Matemáticas com INTEIROS
/*
somaMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões. Recebe duas matriz e retorna a Soma.
*/
int** somaMatrizInt(short int linhaA, short colunaA, int** matrizA,
  short int linhaB, short colunaB, int** matrizB){
    //Verificação das dimensoes da matriz
    if (linhaA < 0 || colunaA < 0 || linhaB < 0 || colunaB < 0){
        linhaA = validaDimensao(linhaA);
        colunaA = validaDimensao(colunaA);
        linhaB = validaDimensao(linhaB);
        colunaB = validaDimensao(colunaB); }

    if (linhaA == linhaB && colunaA == colunaB){ // Verificação da condição de Soma de matrizes
        int** matrizSoma;
        short int contadorLinha = 0, contadorColuna = 0;
        /* alocação dinâmica da matrizSoma. Poderia ter sido utilizdo o valor das
        dimensões da matriz B, haja vista que devem ser iguais.*/
        matrizSoma = iniciaMatrizInt(linhaA,colunaA);
        for (short int i = 0; i < linhaA*colunaA; i++){
            matrizSoma[contadorLinha][contadorColuna] =
              matrizA[contadorLinha][contadorColuna] + matrizB[contadorLinha][contadorColuna];
            contadorColuna++;
            if (contadorColuna >= colunaA){
                contadorColuna = 0;
                contadorLinha++; }
        }
        return matrizSoma;
    }
    else {
        printf("\nErro! Não é possível somar matrizes de dimensões diferentes.");
        return NULL;  }
}

/*
subMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões. Recebe duas matriz e retorna a Soma.
*/
int** subMatrizInt(short int linhaA, short int colunaA, int** matrizA,
  short int linhaB, short int colunaB, int** matrizB){
    //Verificação das dimensoes da matriz
    if (linhaA < 0 || colunaA < 0 || linhaB < 0 || colunaB < 0){
        linhaA = validaDimensao(linhaA);
        colunaA = validaDimensao(colunaA);
        linhaB = validaDimensao(linhaB);
        colunaB = validaDimensao(colunaB); }

    if (linhaA == linhaB && colunaA == colunaB){ // Verificação da condição de Soma de matrizes
        int** matrizSub;
        short int contadorLinha = 0, contadorColuna = 0;
        /* alocação dinâmica da matrizSoma. Poderia ter sido utilizdo o valor das
        dimensões da matriz B, haja vista que devem ser iguais.*/
        matrizSub = iniciaMatrizInt(linhaA,colunaA);
        for (short int i = 0; i < linhaA*colunaA; i++){
            matrizSub[contadorLinha][contadorColuna] =
              matrizA[contadorLinha][contadorColuna] - matrizB[contadorLinha][contadorColuna];
            contadorColuna++;
            if (contadorColuna >= colunaA){
                contadorColuna = 0;
                contadorLinha++; }
        }
        return matrizSub;
    }
    else {
        printf("\nErro! Não é possível somar matrizes de dimensões diferentes.");
        return NULL;  }
}

/*
multMatrizInt() - Multipla duas matrizes A e B, retornando o produto de ambas.
*/
int** multMatrizInt(short int linhaA, short int colunaA, int** matrizA,
                    short int linhaB, short int colunaB, int** matrizB){
    //Verificação das dimensoes da matriz
    if (linhaA < 0 || colunaA < 0 || linhaB < 0 || colunaB < 0){
      linhaA = validaDimensao(linhaA);
      colunaA = validaDimensao(colunaA);
      linhaB = validaDimensao(linhaB);
      colunaB = validaDimensao(colunaB); }

    // Verificação da condição de Multiplicação de matrizes
    if (colunaA == linhaB){
        int** matrizMult;
        // auxiliar é a variável que recebe o valor da soma de cada iteração linha-coluna
        short int auxiliar;
        // alocação dinâmica da matrizMult.
        // Importante observar que as dimensões de matrizMult são:
        // matrizMult[linhaA][colunaB], pela definição de multiplação de matrizes
        matrizMult = iniciaMatrizInt(linhaA,colunaB);
        // Laços de "linha da MatrizA pela coluna da matriz B"
        for (short int i = 0; i < linhaA; i++){
            for(short int j = 0; j < colunaB; j++){
                // a cada iteração o valor é zerado para a nova soma linha-coluna
                auxiliar = 0;
                //Loop interno para percorrer as linhas da coluna A
                for (short int k = 0; k < colunaA; k++) {
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
void multNumMatrizInt(short int linha, short int coluna,
                      int numero,int** matriz){
    short int contadorLinha = 0, contadorColuna = 0;
    //Verificação das dimensoes da matriz
    if (linha < 0 || coluna < 0) {
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna); }

    for (short int i = 0; i < linha*coluna; i++){
        matriz[contadorLinha][contadorColuna] = numero*matriz[contadorLinha][contadorColuna];
        contadorColuna++;
        if (contadorColuna >= coluna){
            contadorColuna = 0;
            contadorLinha++; }
      }
}

// Versao 2.0

/*dpMatrizInt() - Retorna a Diagonal Principal da Matriz de inteiros. É retornando
um vetor 1xn com os valores da diagonal principal.Obs: só é definida a diagonal
principal para matrizes quadradas.*/
int* dpMatrizInt(short int linha, short int coluna,int** matriz){
  //Verificação das dimensoes da matriz
  if (linha < 0 || coluna < 0) {
      linha = validaDimensao(linha);
      coluna = validaDimensao(coluna); }
    // Condição de matriz quadrada
    if (linha == coluna){
        int* diagonalPrincipal = (int*)malloc(linha*sizeof(int));
        if (diagonalPrincipal == NULL){
            printf("\nErro! Não foi possível alocar memória para a diagonal principal.");
            return NULL;  }
        else{
            for (short int i = 0; i < linha; i++){
                for (short int j = 0; j < coluna; j++){
                    // Condição do elemento na DP (indice de linha = indice de coluna)
                    if(i == j){
                       diagonalPrincipal[i] = matriz[i][j];}
                }
            }
        return diagonalPrincipal;  }
    }
    else{
        printf("\nErro! As dimensões da matriz não são iguais.");
        return NULL;}
}

/*dsMatrizInt() - Retorna a Diagnonal Secundária da Matriz de ineiros. É retornado
um vetor 1xn com os valores da diagonal secundária. Obs: só é definida a diagonal
secundária para matrizes quadradas.*/
int* dsMatrizInt(short int linha, short int coluna, int** matriz){
  //Verificação das dimensoes da matriz
  if (linha < 0 || coluna < 0) {
      linha = validaDimensao(linha);
      coluna = validaDimensao(coluna); }

  if (linha == coluna){ // Condição de matriz quadrada
        int* diagonalSecundaria = (int*)malloc(linha*sizeof(int));
        if (diagonalSecundaria == NULL){
            printf("\nErro! Não foi possível alocar memória para a diagonal principal.");
            return NULL;  }
        else{
            for (short int i = 0; i < linha; i++){
                for (short int j = coluna; j >= 0; j--){
                    diagonalSecundaria[i] = matriz[i][j];  }
            }
        return diagonalSecundaria;  }
    }
    else{
        printf("\nErro! As dimensões da matriz não são iguais.");
        return NULL;}
}

/*matrizIdentidadeInt() - Retorna uma matriz identidade com as dimensões passadas.
A matriz identidade é uma matriz cuja Diagonal Principal possui apenas 1, sendo
nulos os outros valores.*/
int** matrizIdentidadeInt(short int linha, short int coluna){
  //Verificação das dimensoes da matriz
  if (linha < 0 || coluna < 0) {
      linha = validaDimensao(linha);
      coluna = validaDimensao(coluna); }
    // Condição de matriz quadrada
  if (linha == coluna){
      int** matrizIdentidade = iniciaMatrizInt(linha,coluna);
      if (matrizIdentidade == NULL){
          printf("\nErro! Não foi possível alocar memória para a Matriz Identidade");
          return NULL;
      }
      else{
          for (short int i = 0; i < linha; i++){
              for (short int j = 0; j < coluna; j++){
                  // Condição do elemento na DP (indice de linha = indice de coluna)
                  if(i == j){
                    matrizIdentidade [i][j]= 1;}
              }
          }
          return matrizIdentidade;}
    }
    else{
        printf("\nErro! As dimensões da matriz não são iguais.");
        return NULL;  }
}

/*matrizZerosInt() - retorna uma matriz completamente nula com as dimensões passadas.
Uma matriz de zeros não necessita, obrigatoriamente, ser quadrada.*/
int** matrizZerosInt(short int linha, short int coluna){
  //Verificação das dimensoes da matriz
  if (linha < 0 || coluna < 0) {
      linha = validaDimensao(linha);
      coluna = validaDimensao(coluna); }
  int** matrizZeros = iniciaMatrizInt(linha,coluna);
  if (matrizZeros == NULL){
        printf("\nErro! Não foi possível alocar memória para a matriz de Zeros.");
        return NULL;  }
  else{
        for (short int i = 0; i < linha; i++){
            for (short int j = 0; j < coluna; j++){
                matrizZeros[i][j] = 0;  }
        }
    return matrizZeros;  }
}

/*matrizOnesInt() - retorna uma matriz com todos os valores iguais a 1,
de acordo com as dimensões passadas. Não necessita, obrigatoriamente, ser quadrada.*/
int** matrizOnesInt(short int linha, short int coluna){
  //Verificação das dimensoes da matriz
  if (linha < 0 || coluna < 0) {
      linha = validaDimensao(linha);
      coluna = validaDimensao(coluna); }
  int** matrizOnes = iniciaMatrizInt(linha,coluna);
      if (matrizOnes == NULL){
          printf("\nErro! Não foi possível alocar memória para a matriz de 1s.");
          return NULL;  }
    else{
        for (short int i = 0; i < linha; i++){
            for (short int j = 0; j < coluna; j++){
                matrizOnes[i][j] = 1;  }
        }
    return matrizOnes;  }
}

/*matrizTranspostaInt() - Retorna a matriz transposta da matriz passada. A
transposta de uma matriz é a inversão das dimensões de linha pela coluna.
Não necessita, obrigatoriamente, ser quadrada.*/
int** matrizTranspostaInt(short int linha, short int coluna, int** matriz) {
    //Verificação das dimensoes da matriz
    if (linha < 0 || coluna < 0) {
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna); }
    int** matrizTransposta = iniciaMatrizInt(coluna,linha);
    /* A matriz transposta de uma matriz não quadrática pode ser representada
    por 2 matrizes de dimensoes linha-coluna; em relação a original,
    logo, é necessário um vetor para armazenar esses valore e, em seguida,
    atribuilos a transposta.*/
   if (matrizTransposta == NULL){
        printf("\nErro! Não foi possível alocar memória para a Matriz Transposta.");
        return NULL;  }
   else {
     // a representação da transposta ocorre pela simples inversao do laço
     // for original (linha/coluna) por (coluna/linha) e atribuição com indices
     // trocados
        for (short int j = 0; j < coluna; j++){
            for (short int i = 0; i < linha; i++){
                matrizTransposta[j][i] = matriz[i][j]; }
        }
    }
    return matrizTransposta;
}


/* Calcula o determinante de uma matriz quadrada*/
int determinanteInt(short int linha,short int coluna, int** matriz){
  //Verificação das dimensoes da matriz
  if (linha < 0 || coluna < 0) {
      linha = validaDimensao(linha);
      coluna = validaDimensao(coluna); }
  int i = 0, j = 0, k = 0, contador = 0, contador_2 = 0, det = 0;
  int valor = 0, soma_direita = 0, soma_esquerda = 0, ordem = linha;
  // Condição de matriz quadrada
  if (linha == coluna){
        //Caso particular 2x2
        if (linha == 2){
          return (matriz[0][0]*matriz[1][1]-matriz[1][0]*matriz[0][1]);
        }
        else{
          // LEITURA DA DIREITA PARA A ESQUERDA
          j = 0;
          k = 0;
          valor = 1;
          contador = 0;
          contador_2 = 0;
          soma_direita = 0;
          // Quantidade total de leituras na matriz
          for ( i = 0; i <= ( ordem * ordem ); i++ ) {
              // Retorna i para inicio da matriz
              if ( j == ordem ) {
                  j = 0;
                  contador_2++;
                  k = contador_2; }
              if ( k == ordem ){
                  k = 0; }
              valor = valor * matriz[j][k];
              j++;
              k++;
              contador++;
              if ( contador == ordem ) {
                  soma_direita = soma_direita + valor;
                  valor = 1;
                  contador = 0; }
          }

          // LEITURA DA ESQUERDA PARA A DIREITA
          j = 0;
          k = ordem - 1;
          valor = 1;
          contador = 0;
          contador_2 = ordem - 1;
          soma_esquerda = 0;
          // Quantidade total de leituras na matriz
          for ( i = 0; i <= ( ordem * ordem ); i++ ) {
              // Retorna i para inicio da matriz
              if ( j == ordem ) {
                  j = 0;
                  contador_2--;
                  k = contador_2; }
              if ( k < 0 ){
                  k = ordem -1 ;}
              valor = valor * matriz[j][k];
              j++;
              k--;
              contador++;
              if ( contador == ordem ) {
                  soma_esquerda = soma_esquerda + valor;
                  valor = 1;
                  contador = 0; }
          }
        }
        return (soma_direita + ( soma_esquerda * (-1) ));
    }
    else {
        printf("\nErro! As matrizes devem ter as mesmas dimensões");
        return -999;}
}

/*matrizInversaInt() - Retona a matriz inversa da matriz, quando possível. A
matriz inversa é uma matriz cuja multiplicação com a matriz original, resulta numa
matriz identidade de mesma ordem. Isto é, A.B = B.A = I (quando a inversa de A
é B e vice-versa.).: SÓ EXISTEM MATRIZ INVERSA PARA MATRIZES QUADRADAS E QUE
OBEDEÇAM A SEGUINTE REGRA:
"caso o determinante dê igual a zero, não existe matriz inversa para ela."*/
//int** matrizInversaInt(short int linha, short int coluna, int** matriz);

/* ############################################################################
                          Bloco para números REAIS
   ############################################################################
*/

/* iniciaMatrizInt() - função de inicialização das matrizes (alocação dinâmica);
Importante haver diferenciação entre matrizes quadráticas e não quadráticas devido
a forma como ocorre a alocação da memória (vetor de ponteiros para ponteiros).
*/
float** iniciaMatrizReal(short int linha, short int coluna){
    if (linha < 0 || coluna < 0){ //Verificação das dimensoes da matriz
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna);}

    if (linha != 0 && coluna !=0){ // Condição para evitar matriz vazia
        float **novaMatriz;
        novaMatriz = (float**)malloc(linha*sizeof(float*)); // Alocação de memória para as linhas da matriz
        if (novaMatriz == NULL){ // Verifica se não houve erro na alocação.
            printf("\nErro! Não foi possível alocar memória (linhas)");}
        else {
            for (short int i = 0; i < linha; i++){
                novaMatriz[i] = (float*)malloc(coluna*sizeof(float));   // Alocação de memória para as colunas da matriz
                if (novaMatriz == NULL) {
                    printf("\nErro! Não foi possível alocar memória (colunas)");  }
                }
            return novaMatriz;  }
    }
    else{
        printf("\nNão é possível criar uma matriz com dimensões nulas.\n");
        return NULL;}
}

/*insereElementoReal() - Insere os elementos MANUALMENTE na matriz. Recebe como
parâmetros o número de linhas e colunas válidos (valores >0), e o endereço da
matriz.*/
void insereElementoReal(short int linha, short int coluna, float** matriz){
    short int contadorLinha = 0, contadorColuna = 0;
    if (linha < 0 || coluna < 0){ //Verificação das dimensoes da matriz
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna);}
    for (short int i = 0; i < linha*coluna; i++){
        if (contadorColuna < coluna){
            printf("[i = %d] Digite o elemento da linha [%d] e coluna [%d]: ", i, contadorLinha, contadorColuna);
            scanf("%f", &matriz[contadorLinha][contadorColuna]);
            contadorColuna++;
            if (contadorColuna >= coluna){
                contadorColuna = 0;
                contadorLinha++; }
          }
      }
}

/*imprimeMatrizReal() - Imprime na tela a matriz.*/
void imprimeMatrizReal(short int linha, short int coluna, float** matriz){
    short int contadorLinha = 0, contadorColuna = 0;
    if (linha < 0 || coluna < 0){   //Verificação das dimensoes da matriz
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna);}
    for (short int i = 0; i < linha*coluna ; i++){
          if (contadorColuna >= coluna){
              contadorLinha++;
              contadorColuna = 0;
              printf("\n[%f]\t", matriz[contadorLinha][contadorColuna]); }
          else
              printf("[%f]\t", matriz[contadorLinha][contadorColuna]);
              contadorColuna++;
    }
    printf("\n");
}

// Libera a memória alocada na matriz. Deve sempre ser utilizado ao final do programa.
void liberaMatrizReal(short int linha, short int coluna, float** matriz){
    if (linha < 0 || coluna < 0){ //Verificação das dimensoes da matriz
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna);  }
    for (short int i = 0; i < linha; i++){
        free (matriz[i]); } // Libera as linhas da matriz  }
    free(matriz); // Libera o vetor de ponteiros
}


                        // Operações Matemáticas com REAIS

/* somaMatrizReal() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões. Recebe duas matriz e retorna a Soma. */
float** somaMatrizReal(short int linhaA, short colunaA, float** matrizA,
                       short int linhaB, short colunaB, float** matrizB){
      //Verificação das dimensoes da matriz
      if (linhaA < 0 || colunaA < 0 || linhaB < 0 || colunaB < 0){
          linhaA = validaDimensao(linhaA);
          colunaA = validaDimensao(colunaA);
          linhaB = validaDimensao(linhaB);
          colunaB = validaDimensao(colunaB); }

      if (linhaA == linhaB && colunaA == colunaB){ // Verificação da condição de Soma de matrizes
          float** matrizSoma;
          short int contadorLinha = 0, contadorColuna = 0;
          /* alocação dinâmica da matrizSoma. Poderia ter sido utilizdo o valor das
          dimensões da matriz B, haja vista que devem ser iguais.*/
          matrizSoma = iniciaMatrizReal(linhaA,colunaA);
          for (short int i = 0; i < linhaA*colunaA; i++){
              matrizSoma[contadorLinha][contadorColuna] =
              matrizA[contadorLinha][contadorColuna] + matrizB[contadorLinha][contadorColuna];
              contadorColuna++;
              if (contadorColuna >= colunaA){
                  contadorColuna = 0;
                  contadorLinha++; }
           }
          return matrizSoma;  }
      else {
          printf("\nErro! Não é possível somar matrizes de dimensões diferentes.");
          return NULL;  }
}

/* subMatrizReal() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões. Recebe duas matriz e retorna a Soma. */
float** subMatrizReal(short int linhaA, short int colunaA, float** matrizA,
                     short int linhaB, short int colunaB, float** matrizB){
        //Verificação das dimensoes da matriz
        if (linhaA < 0 || colunaA < 0 || linhaB < 0 || colunaB < 0){
            linhaA = validaDimensao(linhaA);
            colunaA = validaDimensao(colunaA);
            linhaB = validaDimensao(linhaB);
            colunaB = validaDimensao(colunaB); }

        if (linhaA == linhaB && colunaA == colunaB){ // Verificação da condição de Soma de matrizes
            float** matrizSub;
            short int contadorLinha = 0, contadorColuna = 0;
            /* alocação dinâmica da matrizSoma. Poderia ter sido utilizdo o valor das
            dimensões da matriz B, haja vista que devem ser iguais.*/
            matrizSub = iniciaMatrizReal(linhaA,colunaA);
            for (short int i = 0; i < linhaA*colunaA; i++){
                matrizSub[contadorLinha][contadorColuna] =
                matrizA[contadorLinha][contadorColuna] - matrizB[contadorLinha][contadorColuna];
                contadorColuna++;
                if (contadorColuna >= colunaA){
                    contadorColuna = 0;
                    contadorLinha++; }
             }
            return matrizSub;  }
        else {
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

/*dpMatrizReal() - Retorna a Diagonal Principal da Matriz de reais. É retornando
um vetor 1xn com os valores da diagonal principal.Obs: só é definida a diagonal
principal para matrizes quadradas.*/
float* dpMatrizReal(short int linha, short int coluna,int** matriz){
    //Verificação das dimensoes da matriz
    if (linha < 0 || coluna < 0) {
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna); }
    // Condição de matriz quadrada
    if (linha == coluna){
        float* diagonalPrincipal = (float*)malloc(linha*sizeof(float));
        if (diagonalPrincipal == NULL){
            printf("\nErro! Não foi possível alocar memória para a diagonal principal.");
            return NULL;  }
        else{
            for (short int i = 0; i < linha; i++){
                for (short int j = 0; j < coluna; j++){
                    // Condição do elemento na DP (indice de linha = indice de coluna)
                    if(i == j){
                       diagonalPrincipal[i] = matriz[i][j];}
                }
            }
        return diagonalPrincipal;  }
    }
    else{
        printf("\nErro! As dimensões da matriz não são iguais.");
        return NULL;}
}

/*dsMatrizReal() - Retorna a Diagnonal Secundária da Matriz de ineiros. É retornado
um vetor 1xn com os valores da diagonal secundária. Obs: só é definida a diagonal
secundária para matrizes quadradas.*/
float* dsMatrizReal(short int linha, short int coluna, float** matriz){
  //Verificação das dimensoes da matriz
  if (linha < 0 || coluna < 0) {
      linha = validaDimensao(linha);
      coluna = validaDimensao(coluna); }
    // Condição de matriz quadrada
    if (linha == coluna){
        float* diagonalSecundaria = (float*)malloc(linha*sizeof(float));
        if (diagonalSecundaria == NULL){
            printf("\nErro! Não foi possível alocar memória para a diagonal principal.");
            return NULL;  }
        else{
            for (short int i = 0; i < linha; i++){
                for (short int j = coluna; j >= 0; j--){
                    diagonalSecundaria[i] = matriz[i][j];  }
            }
        return diagonalSecundaria;  }
    }
    else{
        printf("\nErro! As dimensões da matriz não são iguais.");
        return NULL;}
}

/*matrizIdentidadeReal() - Retorna uma matriz identidade com as dimensões passadas.
A matriz identidade é uma matriz cuja Diagonal Principal possui apenas 1, sendo
nulos os outros valores.*/
float** matrizIdentidadeReal(short int linha, short int coluna){
  //Verificação das dimensoes da matriz
  if (linha < 0 || coluna < 0) {
      linha = validaDimensao(linha);
      coluna = validaDimensao(coluna); }
    // Condição de matriz quadrada
    if (linha == coluna){
      float** matrizIdentidade = iniciaMatrizReal(linha,coluna);
      if (matrizIdentidade == NULL){
          printf("\nErro! Não foi possível alocar memória para a Matriz Identidade");
          return NULL;
      }
      else{
          for (short int i = 0; i < linha; i++){
              for (short int j = 0; j < coluna; j++){
                  // Condição do elemento na DP (indice de linha = indice de coluna)
                  if(i == j){
                    matrizIdentidade [i][j]= 1;}
              }
          }
          return matrizIdentidade;}
    }
    else{
        printf("\nErro! As dimensões da matriz não são iguais.");
        return NULL;  }
}

/*matrizZerosReal() - retorna uma matriz completamente nula com as dimensões passadas.
Uma matriz de zeros não necessita, obrigatoriamente, ser quadrada.*/
float** matrizZerosReal(short int linha, short int coluna){
  //Verificação das dimensoes da matriz
  if (linha < 0 || coluna < 0) {
      linha = validaDimensao(linha);
      coluna = validaDimensao(coluna); }
    float** matrizZeros = iniciaMatrizReal(linha,coluna);
    if (matrizZeros == NULL){
        printf("\nErro! Não foi possível alocar memória para a matriz de Zeros.");
        return NULL;
    }
    else{
        for (short int i = 0; i < linha; i++){
            for (short int j = 0; j < coluna; j++){
                matrizZeros[i][j] = 0;
            }
        }
    return matrizZeros;}
}

/*matrizOnesReal() - retorna uma matriz com todos os valores iguais a 1,
de acordo com as dimensões passadas. Não necessita, obrigatoriamente, ser quadrada.*/
float** matrizOnesReal(short int linha, short int coluna){
  //Verificação das dimensoes da matriz
  if (linha < 0 || coluna < 0) {
      linha = validaDimensao(linha);
      coluna = validaDimensao(coluna); }
    float** matrizOnes = iniciaMatrizReal(linha,coluna);
    if (matrizOnes == NULL){
        printf("\nErro! Não foi possível alocar memória para a matriz de 1s.");
        return NULL;
    }
    else{
        for (short int i = 0; i < linha; i++){
            for (short int j = 0; j < coluna; j++){
                matrizOnes[i][j] = 1;
            }
        }
    return matrizOnes;}
}

/*matrizTranspostaReal() - Retorna a matriz transposta da matriz passada. A
transposta de uma matriz é a inversão das dimensões de linha pela coluna.
Não necessita, obrigatoriamente, ser quadrada.*/
float** matrizTranspostaReal(short int linha, short int coluna, float** matriz) {
    //Verificação das dimensoes da matriz
    if (linha < 0 || coluna < 0) {
        linha = validaDimensao(linha);
        coluna = validaDimensao(coluna); }
    // Como a matriz é transposta, para os casos em que não é quadrática,
    // há inversão na passagem de parâmetro dos argumentos "linha" e "coluna"
    float** matrizTransposta = iniciaMatrizReal(coluna,linha);
    if (matrizTransposta == NULL){
        printf("\nErro! Não foi possível alocar memória para a Matriz Transposta.");
        return NULL;  }
    else{
        // a representação da transposta ocorre pela simples inversao do laço
        // for original (linha/coluna) por (coluna/linha) e atribuição com indices
        // trocados
        for (short int j = 0; j < coluna; j++){
            for (short int i = 0; i < linha; i++){
                matrizTransposta[j][i] = matriz[i][j]; }
        }
    }
    return matrizTransposta; }

/* Calcula o determinante de uma matriz quadrada*/
float determinanteReal(short int linha,short int coluna, float** matriz){
  //Verificação das dimensoes da matriz
  if (linha < 0 || coluna < 0) {
      linha = validaDimensao(linha);
      coluna = validaDimensao(coluna); }
    int i = 0, j = 0, k = 0, contador = 0, contador_2 = 0, det = 0, valor = 0, ordem = linha;
    float soma_direita = 0, soma_esquerda = 0;
    // Condição de matriz quadrada
    if (linha == coluna){
        //Caso particular 2x2
        if (linha == 2){
          return (matriz[0][0]*matriz[1][1]-matriz[1][0]*matriz[0][1]);
        }
        else{
          // LEITURA DA DIREITA PARA A ESQUERDA
          j = 0;
          k = 0;
          valor = 1;
          contador = 0;
          contador_2 = 0;
          soma_direita = 0;
          // Quantidade total de leituras na matriz
          for ( i = 0; i <= ( ordem * ordem ); i++ ) {
              // Retorna i para inicio da matriz
              if ( j == ordem ) {
                  j = 0;
                  contador_2++;
                  k = contador_2; }
              if ( k == ordem ){
                  k = 0; }
              valor = valor * matriz[j][k];
              j++;
              k++;
              contador++;
              if ( contador == ordem ) {
                  soma_direita = soma_direita + valor;
                  valor = 1;
                  contador = 0; }
          }

          // LEITURA DA ESQUERDA PARA A DIREITA
          j = 0;
          k = ordem - 1;
          valor = 1;
          contador = 0;
          contador_2 = ordem - 1;
          soma_esquerda = 0;
          // Quantidade total de leituras na matriz
          for ( i = 0; i <= ( ordem * ordem ); i++ ) {
              // Retorna i para inicio da matriz
              if ( j == ordem ) {
                  j = 0;
                  contador_2--;
                  k = contador_2; }
              if ( k < 0 ){
                  k = ordem -1 ;}
              valor = valor * matriz[j][k];
              j++;
              k--;
              contador++;
              if ( contador == ordem ) {
                  soma_esquerda = soma_esquerda + valor;
                  valor = 1;
                  contador = 0; }
          }
        }
        return (soma_direita + ( soma_esquerda * (-1) ));
    }
    else {
        printf("\nErro! As matrizes devem ter as mesmas dimensões");
        return -999;}
}

/*matrizInversaInt() - Retona a matriz inversa da matriz, quando possível. A
matriz inversa é uma matriz cuja multiplicação com a matriz original, resulta numa
matriz identidade de mesma ordem. Isto é, A.B = B.A = I (quando a inversa de A
é B e vice-versa.).: SÓ EXISTEM MATRIZ INVERSA PARA MATRIZES QUADRADAS E QUE
OBEDEÇAM A SEGUINTE REGRA:
"caso o determinante dê igual a zero, não existe matriz inversa para ela."*/
//int** matrizInversaInt(short int linha, short int coluna, int** matriz);
