/*
Autor: Lucas Gomes
Data: 08/02/2022
Projeto: Arquivo de uma Lista Encadeada
Descrição: Para cada novo elemento inserido na estrutura, alocamos um espaço de memória para armazena-lo.
*/

#include <stdio.h>
#include <stdlib.h>

struct lista{
    float elemento;
    struct lista* prox;
};
// Criação do tipo Lista para representar um nó da lista e a estrutura de lista encadeada será representada
// pelo ponteiro elemento (tipo (Lista*)
typedef struct lista Lista;


// FUNÇÃO DE INICIALIZAÇÃO
    // Cria uma lista vazia (sem nenhum elemento) representada pelo ponteiro NULL

Lista* inicializa (void){
    return NULL;
}

// FUNÇÃO DE INSERÇÃO
    // Para cada elemento da lista, aloca-se memória dinamicamente e encadeia o elemento à lista existente

Lista* insere (Lista* l, float i){
    Lista* novo = (Lista*)malloc(sizeof(Lista));    // Alocação dinâmica de memória
    novo->elemento = i;                             // Atribui o novo elemento ao ponteiro da estrutura criada
    novo->prox = l;                                 // Encadeia o novo ponteiro a lista anterior
    return novo;                                    // retorna a nova lista, representada pelo ponteiro para o novo elemento
}

//  FUNÇÃO QUE PERCORRE OS ELEMENTOS DA LISTA
    // Percorre os elementos e impreme-os

void imprime (Lista* l){
    Lista* p;                                       // Variavel auxiliar para percorrer a lista
    for (p = l; p!= NULL; p = p->prox){             // p recebe a lista; enquanto não for NULL (final da lista); p recebe o proximo elemento que p aponta
        printf("Elemento = %.3f\n",p->elemento);
    }
}


// FUNÇÃO QUE VERIFICA SE A LISTA ESTÁ VAZIA

int vazia (Lista* l){
    return (l == NULL); // retorna 1 se l for nulo
}

// FUNÇÃO DE BUSCA
    // Consiste em verificar se determidao elemento está na lista

Lista* busca (Lista* l, float v){
    Lista* p;
    for (p = l; p!=NULL; p = p->prox)
        if (p->elemento == v)
            return p;                                // Caso encontre o elemento
    return NULL;                                     // Caso não encontre o elemento
}

// FUNÇÃO QUE RETIRA UM ELEMENTO DA LISTA
    // Existem dois casos: Se o elemento removido for o primeiro e se o elemento estiver no meio da lista

Lista* retira (Lista* l, float v){
    Lista* ant = NULL;                              // Ponteiro para o elemento anterior
    Lista* p = l;                                   // Ponteiro para percorrer a lista

    while (p !=NULL && p->elemento !=v){            // loop para procurar o elemento na lista, guardando o anterior
        ant = p;
        p = p->prox;
    }

    if (p == NULL){                                 // Verifica se achou o elemento
        return l;                                   // Condição em que o elemento não é encontrado
    }

    if (ant == NULL){
        l = p->prox;                                // Condição em que o elemento é o primeiro
    }

    else{
        ant->prox = p->prox;                        // Condição em que o elemento está no meio
    }
    free(p);                                        // Libera o espaço de p
    return l;                                       // Retorna a nova lista apos a remoção (ou não) do elemento
}

// FUNÇÃO PARA LIBERAR A LISTA

void libera (Lista* l){
    Lista* p = l;
    while(p != NULL){
        Lista* t = p->prox;                         // Armazena a referência ao próximo elemento
        free(p);
        p = t;                                      // Faz p apontar par o próximo elemento
    }
}
