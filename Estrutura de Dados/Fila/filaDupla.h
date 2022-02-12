/*
Autor: Lucas Gomes
Data: 09/02/2022
Projeto: Arquivo Cabeçalho de uma Fila Dupla
Descrição: Consiste numa fila na qual é possível inserir novos elementos em ambas as extremidades (inicio e fim).
           É como se , dentro de uma mesma estrutura de fila, tivéssemos duas filas, com os elementos dispostos 
           em ordem inversa.
*/

typedef struct filaDupla filaDupla;

filaDupla* cria (void);                          // Cria uma estrutura do tipo filaDupla
void insere_ini (filaDupla* f, float v);         // Insere um elemento no início da fila
void insete_fim (filaDupla* f, float v);         // Insete um elemento no fim da fila
float retira_ini (filaDupla* f);                 // Retira o elemento do início
float retira_fim(filaDupla* f);                  // Retira o elemento do fim
int vazia (filaDupla* f);                        // Verifica se a fila está vazia
void libera (filaDupla* f);                      // Libera a memória
void imprime_fim (filaDupla* f);                 // Função que imprime os valores do fim ao inicio
void imprime_ini (filaDupla* f);                 // Função que imprime os valores do inicio ao fim