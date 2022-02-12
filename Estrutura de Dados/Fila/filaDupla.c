/*
Autor: Lucas Gomes
Data: 09/02/2022
Projeto: Arquivo de uma Fila Dupla
Descrição: Consiste numa fila na qual é possível inserir novos elementos em ambas as extremidades (inicio e fim).
           É como se , dentro de uma mesma estrutura de fila, tivéssemos duas filas, com os elementos dispostos 
           em ordem inversa.
*/


// Serão necessárias duas estruturas: uma para o nó (armazenar a informação e o ponteiro para o elemento ant e prox)
//                                    uma para a fila (armazenar o inicio e o fim da fila)
#include <stdio.h>
#include <stdlib.h>

struct no{
    float info;
    struct no* ant;
    struct no* prox;
};
typedef struct no No;

struct filaDupla{
    No* ini;
    No* fim;
};
typedef struct filaDupla filaDupla;

// Função "cria". Inicializa a fila como sendo vazia
filaDupla* cria (void){
    filaDupla* f = (filaDupla*)malloc(sizeof(filaDupla));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

// Funções auxiliares para manipulação da lista dupla
    
    // Função de inserção no inicio
No* ins_ini (No* ini,float v){
    No* p = (No*)malloc(sizeof(No));
    p->info = v;
    p->ant = NULL;                          // O "ant" do inicio sempre será o NULL
    p->prox = ini;                          // O "prox" do inicio sempre será o elemento inserido (o novo fim)
    if(ini != NULL){                        // Verifica se a lista não estava vazia
        ini->ant = p;
    }
    return p;                               // Retorna a nova lista
}

    // Função de inserção no fim
No* ins_fim (No* fim, float v){
    No* p = (No*)malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;                         // O "prox" do fim sempre será NULL
    p->ant = fim;                           // O "ant" do fim sempre será o elemento inserido (o novo "ante-fim")
    if (fim != NULL){                       // Verifica se a lista não estava vazia
        fim->prox = p;
    }
    return p;                               // Retorna a nova lista
}

    // Função de remoção no inicio
No* rem_ini (No* ini){
    No* p = ini->prox;
    if(p != NULL){                          // Verifica se a lista não ficou vazia
        p->ant = NULL;
    }
    free(ini);                              // Libera o inicio
    return p;                               // Retorna a nova lista
}

    // Função de remoção no fim
No* rem_fim (No* fim){
    No* p = fim->ant;
    if(p != NULL){                          // Verifica se a lista não ficou vazia
        p->prox = NULL;
    }
    free(fim);                              // Libera o fim
    return p;                               // Retorna a nova lista
}

// Funções que manipulam a fila utilizando as funções anteriores

void insere_ini (filaDupla* f, float v){
    f->ini = ins_ini (f->ini,v);
    if (f->fim == NULL){                    // Verifica se a lista não ficou vazia
        f->fim = f->ini;                     // faz o fim apontar para o inicio/anterior (condição de encadeamento)
    }
}

void insere_fim (filaDupla* f, float v){
    f->fim = ins_fim (f->fim,v);
    if (f->ini == NULL){                    // Verifica se a lista não ficou vazia
        f->ini = f->fim;                     // faz o fim apontar para o fim/proximo (condição de encadeamento)
    }
}

float retira_ini (filaDupla* f){
    float v;
    if (vazia(f)){
        printf("Fila vazia.\n");
        exit(1);
    }
    v = f->ini->info;                       // v armazena o valore removido
    f->ini = rem_ini(f->ini);               // f recebe o novo ponteiro para o inicio
    if (f->ini == NULL){                    // Verifica se a lista ficou vazia
        f->fim == NULL;
    }
    return v;                               // Retorna o valor removido
}


float retira_fim (filaDupla* f){
    float v;
    if (vazia(f)){
        printf("Fila vazia.\n");
        exit(1);
    }
    v = f->fim->info;                       // v armazena o valore removido
    f->fim = rem_fim(f->fim);               // f recebe o novo ponteiro para o inicio
    if (f->fim == NULL){                    // Verifica se a lista ficou vazia
        f->ini == NULL;
    }
    return v;                               // Retorna o valor removido
}


// Função que imprime os valores do inicio ao fim
void imprime_ini (filaDupla* f){
    No* q;
    for (q = f->ini; q != NULL; q = q->prox){
        printf("Valor: %.2f\n", q->info);
    }
}


// Função que imprime os valores do fim ao inicio
void imprime_fim (filaDupla* f){
    No* q;
    for (q = f->fim; q != NULL; q = q->ant){
        printf("Valor: %.2f\n", q->info);
    }
}

// Função para verificar se a fila está vazia
    // A fila está vaiza se a lista estiver vazia, logo:
int vazia (filaDupla* f){
    return (f->ini==NULL);
}

// Função que libera a fila
void libera (filaDupla* f){
    No* q = f->ini;                                                 // 'q' aponta para o inicio da fila
    while (q != NULL){                                              // Enquanto não for nulo
        No* t = q->prox;                                            // 't' aponta para o próximo elemento de q
        free(q);                                                    // 'q' é deletado
        q = t;                                                      // 'q' aponta para onde 't' estava apontando
    }
    free(f);                                                        // Finalmente a fila 'f' é deletada
}
