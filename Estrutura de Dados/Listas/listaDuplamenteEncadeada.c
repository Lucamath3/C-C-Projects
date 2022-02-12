/*
Autor: Lucas Gomes
Data: 09/02/2022
Projeto: Arquivo de uma Lista Duplamene Encadeada
Descrição: Para cada novo elemento inserido na estrutura, alocamos um espaço de memória para armazena-lo, salvando o endereço
           do elemento seguinte e do anterior.
*/
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
listaDupla* insere(listaDupla* l, float v){
    listaDupla* novo = (listaDupla*)malloc(sizeof(listaDupla));     // Alocação dinâmica para criação do novo elemento da lista do tipo ponteiro para struct
    novo->info = v;                                                 // Atribui o valor inserido
    novo->prox = l;                                                 // Aponta para a estrutura passada na referência
    novo->ant = NULL;                                               // Aponta para o elemento anterior (nulo)
        if (l != NULL){                                                 // Verifica se a lista não está vazia
            l->ant = novo;}

    return novo;   
}

// Função de busca
listaDupla* busca (listaDupla* l, float v){
    listaDupla* p;
    for ( p = l; p != NULL; p = p->prox){                           // A cada nova iteração, p recebe a estrutura seguinte da lista passada e verifica o valor
        if (p->info == v){                                          
            return p;                                               // Se encotnrar o valor, retorna a estrutura p (endereço)
        }
    }
    return NULL;                                                    // Se não encontrar o valor, retorna NULL
}



// Função de remoção de elemento
    // Utilizando a função de busca acima, basta redirecionar os ponteiros para 'prox' e 'ant'

listaDupla* retira (listaDupla* l, float v){
    listaDupla* p = busca(l,v);
    
    if (p == NULL){                                                   // Condição de elemento não encontrado
        return l;}

    if (l == p){                                                      // Condição de elemento ser o primeiro da lista
        l = p->prox;}
    else{
        p->ant->prox = p->prox;}                                      // Condição de o elemento estar no meio da lisa
                                                                      // (p->ant) -> prox  faz com que o elemento anterior receba o proximo elemento 
    if (p->prox != NULL){
        p->prox->ant = p->ant;}                                       // (p->prox) -> ant faz com que o proximo elemento receba o elemento anterior (se não for NULL)
    free(p);                                                          // Libera a memória 

    return l;
}

//  FUNÇÃO QUE PERCORRE OS ELEMENTOS DA LISTA
    // Percorre os elementos e impreme-os

void imprime (listaDupla* l){
    listaDupla* p;                                       // Variavel auxiliar para percorrer a lista
    for (p = l; p!= NULL; p = p->prox){             // p recebe a lista; enquanto não for NULL (final da lista); p recebe o proximo elemento que p aponta
        printf("Elemento = %.3f\n",p->info);
    }
}

// FUNÇÃO PARA LIBERAR A LISTA
void libera (listaDupla* l){
    listaDupla* p = l;
    while(p != NULL){
        listaDupla* t = p->prox;                         // Armazena a referência ao próximo elemento
        free(p);
        p = t;                                           // Faz p apontar par o próximo elemento
    }
}