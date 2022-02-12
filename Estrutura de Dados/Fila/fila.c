/*
Autor: Lucas Gomes
Data: 09/02/2022
Projeto: Arquivo de uma Fila
Descrição: Na Fila, o primeiro elemento que entra é o primeiro que sai (FIFO - First In, First Out)
           Ou seja, só podem ser adicionados valores ao final e retirados no começo.
           Há duas estruturas para controle: uma para criação da lista e outra para armazenar o começo e o final da lista.
*/

#include <stdlib.h>
#include <stdio.h>

// Estrutura da lista
struct no {
    float info;
    struct no* prox;
};
typedef struct no No;

// Estrutura da fila
struct fila{
    No* ini;
    No* fim;
};
typedef struct fila Fila;


// Função "cria". Inicializa a fila como sendo vazia
Fila* cria (void){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

// Função para verificar se a fila está vazia
    // A fila está vaiza se a lista estiver vazia, logo:
int vazia (Fila* f){
    return (f->ini==NULL);
}

// Cada novo elemento é inserido no fim da lista e, sempre que solicitado, retiramos o elemento do início da lista. 
// Portanto, as duas funções a seguir auxiliam no processo:
// Função Auxiliar insere no fim
No* ins_fim (No* fim, float v){
    No* p = (No*)malloc(sizeof(No));
    p->info = v;
    p->prox = NULL;
    if (fim != NULL){                                               // Verifica se a lista não estava vazia
        fim->prox = p;
    }
    return p;                                                       // Retorna o novo fim da lista
}

// Função Auxiliar insere no início
No* ret_ini (No* ini){
    No* p = ini->prox;                                              // p aponta para onde o inicio apontava
    free(ini);                                                      // inicio é deletado da memória
    return p;                                                       // retorna o novo ponto
}

// As funções que manipulam a fila fazem uso dessas funções de lista
void insere (Fila* f, float v){
    f->fim = ins_fim(f->fim,v);
    if (f->ini == NULL){                                            // Verifica se a fila estava vazia
        f->ini = f->fim;
    }
}

float retira (Fila* f){
    float v;
    if (vazia(f)){
        printf("Fila vazia.\n");
        exit(1);                                                    // Aborta o programa
    }
    v = f->ini->info;                                               // Armazena em v o valor removido
    f->ini = ret_ini(f->ini);
    
    if (f->ini == NULL){                                            // Verifica se a fila ficou vazia
        f->fim == NULL;
    }
    return v;                                                       // Retorna o valor removido
}

// Função que libera a fila
void libera (Fila* f){
    No* q = f->ini;                                                 // 'q' aponta para o inicio da fila
    while (q != NULL){                                              // Enquanto não for nulo
        No* t = q->prox;                                            // 't' aponta para o próximo elemento de q
        free(q);                                                    // 'q' é deletado
        q = t;                                                      // 'q' aponta para onde 't' estava apontando
    }
    free(f);                                                        // Finalmente a fila 'f' é deletada
}

// Função que imprime os valores
void imprime(Fila* f){
    No* q;
    for (q = f->ini; q != NULL; q = q->prox){
        printf("Valor: %.2f\n", q->info);
    }
}