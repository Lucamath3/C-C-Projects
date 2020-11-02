/*
###############################################################################
# Arquivo Cabeçalho de manipulação de matrizes                                #
# Autor: Lucas Gomes                                                          #
# Data: 28/06/20                                                              #
# Versão 1.0                                                                  #
###############################################################################
*/

/* ############################################################################
                          Bloco para números INTEIROS
   ############################################################################
*/

/*
iniciaMatrizInt() - Inicia a Matriz e realiz a Alocação Dinâmica de memória.
Recebe como argumentos o número de linhas e colunas válidos (valores > 0)
*/
int** iniciaMatrizInt(unsigned int linha, unsigned int coluna);

/*insereElemento() - Insere os elementos MANUALMENTE na matriz. Recebe como
parâmetros o número de linhas e colunas válidos (valores >0), e o endereço da
matriz.*/
void insereElementoInt(unsigned int linha, unsigned int coluna, int** matriz);

/*imprimeMatrizInt() - Imprime na tela a matriz.*/
void imprimeMatrizInt(unsigned int linha, unsigned int coluna, int** matriz);

// Libera a memória alocada na matriz. Deve sempre ser utilizado ao final do programa.
void liberaMatrizInt(unsigned int linha, unsigned int coluna, int** matriz);

                    // Operações Matemáticas com INTEIROS
/*
somaMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
int** somaMatrizInt(unsigned int linhaA, unsigned colunaA, int** matrizA,
  unsigned int linhaB, unsigned colunaB, int** matrizB);

/*
subMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
int** subMatrizInt(unsigned int linhaA, unsigned colunaA, int** matrizA,
  unsigned int linhaB, unsigned colunaB, int** matrizB);

/*
multMatrizInt() - Multipla duas matrizes A e B, retornando o produto de ambas.
*/
int** multMatrizInt(unsigned int linhaA, unsigned colunaA, int** matrizA,
  unsigned int linhaB, unsigned colunaB, int** matrizB);

/*
multNumMatrizReal() - Multiplica um número inteiro por uma matriz inteira;
*/

void multNumMatrizInt(unsigned int linha, unsigned coluna, int numero,
  int** matriz);

/* ############################################################################
                          Bloco para números REAIS
   ############################################################################
*/

/*
iniciaMatrizReal() - Inicia a Matriz e realiz a Alocação Dinâmica de memória.
Recebe como argumentos o número de linhas e colunas válidos (valores > 0)
*/
float** iniciaMatrizReal(unsigned int linha, unsigned int coluna);

/*insereElementoReal() - Insere os elementos MANUALMENTE na matriz. Recebe como
parâmetros o número de linhas e colunas válidos (valores >0), e o endereço da
matriz.*/
void insereElementoReal(unsigned int linha, unsigned int coluna, float** matriz);

/*imprimeMatrizReal() - Imprime na tela a matriz.*/
void imprimeMatrizReal(unsigned int linha, unsigned int coluna, float** matriz);

// Libera a memória alocada na matriz. Deve sempre ser utilizado ao final do programa.
void liberaMatrizReal(unsigned int linha, unsigned int coluna, float** matriz);


                      // Operações Matemáticas com REAIS

/*
somaMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
float** somaMatrizReal(unsigned int linhaA, unsigned colunaA, float** matrizA,
                  unsigned int linhaB, unsigned colunaB, float** matrizB);

/*
subMatrizInt() - A Operação de Somar matrizes só é definida para matrizes de
mesmas dimensões (linha == coluna). Recebe duas matriz e retorna a Soma.
*/
float** subMatrizReal(unsigned int linhaA, unsigned colunaA, float** matrizA,
                  unsigned int linhaB, unsigned colunaB, float** matrizB);

/*
multMatrizReal() - Multipla duas matrizes reais A e B, retornando o produto de ambas.
*/
float** multMatrizReal(unsigned int linhaA, unsigned colunaA, float** matrizA,
                  unsigned int linhaB, unsigned colunaB, float** matrizB);
/*
multNumMatrizReal() - Multiplica um número real por uma matriz real;
*/
void multNumMatrizReal(unsigned int linha, unsigned coluna, float numero,
                        float** matriz);
