#include <stdio.h>
#include <stdlib.h>

struct listaDupla{
    float info;                 // Campo com a informação da struct
    struct listaDupla* ant;     // Ponteiro "listaDupla" para a estrutura listaDupla anterior
    struct listaDupla* prox;    // Ponteiro "listaDupla" para a próxima estrutura listaDupla
};
typedef struct listaDupla listaDupla;

// Função de inserção de elemento no início
    // O novo elemento é encadeado no início da lista.
    // Desse modo, o próximo elemento é o antigo primeiro elemento da lista e como valor anterior NULL
listaDupla* insere(listaDupla* l, float v); 

// Função de busca
listaDupla* busca (listaDupla* l, float v);

// Função de remoção de elemento
    // Utilizando a função de busca acima, basta redirecionar os ponteiros para 'prox' e 'ant'
listaDupla* retira (listaDupla* l, float v);

//  FUNÇÃO QUE PERCORRE OS ELEMENTOS DA LISTA
void imprime (listaDupla* l);

// FUNÇÃO PARA LIBERAR A LISTA
void libera (listaDupla* l);