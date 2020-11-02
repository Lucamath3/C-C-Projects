/*
###############################################################################
# Arquivo Cabeçalho de manipulação de matrizes                                #
# Autor: Lucas Gomes                                                          #
# Data: 28/06/20                                                              #
# Versão 1.0 - Criação do Arquivo                                             #
# Versão 2.0 - Adição das funções para diagonal principal, secundária, matriz #
# identidade, zeros e uns, trasnposta e inversa.                              #
# Versão 3.0 - Correção de  bugs na função de matriz transposta.              #
# Versão 4.0 - Correção de bugs na criação de dimensões negativas (criação da #
# função validaDimensão)                                                      #
# Versão 5.0 - Adaptação das funções Int para funções REAIS                   #
###############################################################################
*/

/* ############################################################################
                          Bloco para números INTEIROS
   ############################################################################
*/

/* validaDimensao() - Função para evitar a inserção de dimensoes negativas nas
funções*/
int validaDimensao(int dimensao);

/* iniciaMatrizInt() - função de inicialização das matrizes (alocação dinâmica);
Importante haver diferenciação entre matrizes quadráticas e não quadráticas devido
a forma como ocorre a alocação da memória (vetor de ponteiros para ponteiros).
*/
int** iniciaMatrizInt(unsigned short int linha, unsigned short int coluna);

/*insereElemento() - Insere os elementos MANUALMENTE na matriz. Recebe como
parâmetros o número de linhas e colunas válidos (valores >0), e o endereço da
matriz.*/
void insereElementoInt(unsigned short int linha, unsigned short int coluna, int** matriz);

/*imprimeMatrizInt() - Imprime na tela a matriz.*/
void imprimeMatrizInt(unsigned short int linha, unsigned short int coluna, int** matriz);

// Libera a memória alocada na matriz. Deve sempre ser utilizado ao final do programa.
void liberaMatrizInt(unsigned short int linha, unsigned short int coluna, int** matriz);

                    // Operações Matemáticas com INTEIROS
/*
somaMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
int** somaMatrizInt(unsigned short int linhaA, unsigned short int colunaA,
                    int** matrizA, unsigned int linhaB, unsigned colunaB,
                    int** matrizB);

/*
subMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
int** subMatrizInt(unsigned short int linhaA, unsigned short colunaA,
                  int** matrizA, unsigned short int linhaB, unsigned colunaB,
                  int** matrizB);

/*
multMatrizInt() - Multipla duas matrizes A e B, retornando o produto de ambas.
*/
int** multMatrizInt(unsigned short int linhaA, unsigned short int colunaA,
                    int** matrizA, unsigned int linhaB, unsigned colunaB,
                    int** matrizB);

/*
multNumMatrizReal() - Multiplica um número inteiro por uma matriz inteira;
O tipo de retorno é void pois a operação é realizada sobre a matriz original.
*/
void multNumMatrizInt(unsigned short int linha, unsigned short int coluna, int numero,
                      int** matriz);

  /*dpMatrizInt() - Retorna a Diagonal Principal da Matriz de inteiros. É retornando
  um vetor 1xn com os valores da diagonal principal.Obs: só é definida a diagonal
  principal para matrizes quadradas.*/
int* dpMatrizInt(unsigned short int linha, unsigned short int coluna,int** matriz);

/*dsMatrizInt() - Retorna a Diagnonal Secundária da Matriz de ineiros. É retornado
um vetor 1xn com os valores da diagonal secundária. Obs: só é definida a diagonal
secundária para matrizes quadradas.*/
int* dsMatrizInt(unsigned short int linha, unsigned short int coluna,int** matriz);

/*matrizIdentidadeInt() - Retorna uma matriz identidade com as dimensões passadas.
A matriz identidade é uma matriz cuja Diagonal Principal possui apenas 1, sendo
nulos os outros valores.*/
int** matrizIdentidadeInt(unsigned short int linha, unsigned short int coluna);

/*matrizZerosInt() - retorna uma matriz completamente nula com as dimensões passadas.
Uma matriz de zeros não necessita, obrigatoriamente, ser quadrada.*/
int** matrizZerosInt(unsigned short int linha, unsigned short int coluna);

/*matrizOnesInt() - retorna uma matriz com todos os valores iguais a 1,
de acordo com as dimensões passadas. Não necessita, obrigatoriamente, ser quadrada.*/
int** matrizOnesInt(unsigned short int linha, unsigned short int coluna);

/*matrizTranspostaInt() - Retorna a matriz transposta da matriz passada. A
transposta de uma matriz é a inversão das dimensões de linha pela coluna.
Não necessita, obrigatoriamente, ser quadrada.*/
int** matrizTranspostaInt(unsigned short int linha, unsigned short int coluna,
                          int** matriz);

/* Calcula o determinante de uma matriz quadrada*/
int determinanteInt(unsigned short int linha, unsigned short int coluna,
                          int** matriz);

/*matrizInversaInt() - Retona a matriz inversa da matriz, quando possível. A
matriz inversa é uma matriz cuja multiplicação com a matriz original, resulta numa
matriz identidade de mesma ordem. Isto é, A.B = B.A = I (quando a inversa de A
é B e vice-versa.).: SÓ EXISTEM MATRIZ INVERSA PARA MATRIZES QUADRADAS.
int** matrizInversaInt(unsigned short int linha, unsigned short int coluna,
                       int** matriz);  */


/* ############################################################################
                          Bloco para números REAIS
   ############################################################################
*/

/*
iniciaMatrizReal() - Inicia a Matriz e realiz a Alocação Dinâmica de memória.
Recebe como argumentos o número de linhas e colunas válidos (valores > 0)
*/
float** iniciaMatrizReal(unsigned short int linha, unsigned short int coluna);

/*insereElementoReal() - Insere os elementos MANUALMENTE na matriz. Recebe como
parâmetros o número de linhas e colunas válidos (valores >0), e o endereço da
matriz.*/
void insereElementoReal(unsigned short int linha, unsigned short int coluna, float** matriz);

/*imprimeMatrizReal() - Imprime na tela a matriz.*/
void imprimeMatrizReal(unsigned short int linha, unsigned short int coluna, float** matriz);

// Libera a memória alocada na matriz. Deve sempre ser utilizado ao final do programa.
void liberaMatrizReal(unsigned short int linha, unsigned short int coluna, float** matriz);


                      // Operações Matemáticas com REAIS

/*
somaMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
float** somaMatrizReal(unsigned short int linhaA, unsigned short int colunaA,
                       float** matrizA, unsigned short int linhaB,
                       unsigned short colunaB, float** matrizB);

/*
subMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
float** subMatrizReal(unsigned short int linhaA, unsigned short int colunaA,
                      float** matrizA, unsigned short int linhaB,
                      unsigned short int colunaB, float** matrizB);

/*
multMatrizReal() - Multipla duas matrizes reais A e B, retornando o produto de ambas.
*/
float** multMatrizReal(unsigned short int linhaA, unsigned short int colunaA,
                       float** matrizA, unsigned short int linhaB,
                       unsigned short int colunaB, float** matrizB);
/*
multNumMatrizReal() - Multiplica um número real por uma matriz real;
*/
void multNumMatrizReal(unsigned short int linha, unsigned short int coluna,
                       float numero, float** matriz);

/*dpMatrizReal() - Retorna a Diagonal Principal da Matriz real. É retornando
um vetor 1xn com os valores da diagonal principal.Obs: só é definida a diagonal
principal para matrizes quadradas.*/
float* dpMatrizReal(unsigned short int linha, unsigned short int coluna, float** matriz);

/*dsMatrizReal() - Retorna a Diagnonal Secundária da Matriz de ineiros. É retornado
um vetor 1xn com os valores da diagonal secundária. Obs: só é definida a diagonal
secundária para matrizes quadradas.*/
float* dsMatrizReal(unsigned short int linha, unsigned short int coluna, float** matriz);

/*matrizIdentidadeReal() - Retorna uma matriz identidade com as dimensões passadas.
A matriz identidade é uma matriz cuja Diagonal Principal possui apenas 1, sendo
nulos os outros valores.*/
float** matrizIdentidadeReal(unsigned short int linha, unsigned short int coluna);

/*matrizZerosReal() - retorna uma matriz completamente nula com as dimensões passadas.
Uma matriz de zeros não necessita, obrigatoriamente, ser quadrada.*/
float** matrizZerosReal(unsigned short int linha, unsigned short int coluna);

/*matrizOnesReal() - retorna uma matriz com todos os valores iguais a 1,
de acordo com as dimensões passadas. Não necessita, obrigatoriamente, ser quadrada.*/
float** matrizOnesReal(unsigned short int linha, unsigned short int coluna);

/*matrizTranspostaReal() - Retorna a matriz transposta da matriz passada. A
transposta de uma matriz é a inversão das dimensões de linha pela coluna.
Não necessita, obrigatoriamente, ser quadrada.*/
float** matrizTranspostaReal(unsigned short int linha, unsigned short int coluna,
                             float** matriz);

/* Calcula o determinante de uma matriz quadrada*/
float determinanteReal(unsigned short int linha, unsigned short int coluna,
                     float** matriz);

/*matrizInversaReal() - Retona a matriz inversa da matriz, quando possível. A
matriz inversa é uma matriz cuja multiplicação com a matriz original, resulta numa
matriz identidade de mesma ordem. Isto é, A.B = B.A = I (quando a inversa de A
é B e vice-versa.).: SÓ EXISTEM MATRIZ INVERSA PARA MATRIZES QUADRADAS.
float** matrizInversaReal(unsigned short int linha, unsigned short int coluna,
                          float** matriz);  */
