/*
Autor: Lucas Gomes
Data: 09/02/2022
Projeto: Arquivo Cabeçalho de uma Fila
Descrição: Na Fila, o primeiro elemento que entra é o primeiro que sai (FIFO - First In, First Out)
           Ou seja, só podem ser adicionados valores ao final e retirados no começo.
*/

typedef struct fila Fila;
Fila* cria (void);                  // Cria dinamicamente a estrutura da fila, inicializa seus campos e retorna seu ponteiro
void insere(Fila* f, float v);      // Adiciona um novo elemento ao final da fila
float retira (Fila* f);             // Remove o elemento do inicio
int vazia (Fila* f);                // Informa se a fila está ou não vazia
void libera(Fila* f);               // Destói a estrutura, liberando toda a memória alocada
void imprime(Fila* f);              // Função que imprime os valores