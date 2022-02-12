/*
Autor: Lucas Gomes
Data: 08/02/2022
Projeto: Estrutura de dados do tipo pilha
Descrição:
    São estruturas de dados do tipo LIFO (last-in first-out), onde o último elemento a ser inserido, será o primeiro a ser retirado. Assim,
    uma pilha permite acesso a apenas um item de dados - o último inserido. Para processar o penúltimo item inserido, deve-se remover o último.
    A implementação de pilhas pode ser realizada através de vetor (alocação do espaço de memória para os elementos é contígua) ou através de listas
    encadeadas.Numa pilha, a manipulação dos elementos é realizada em apenas uma das extremidades, chamada de topo, em oposição a outra extremidade,
    chamada de base.
*/

#include <stdio.h>
#include <stdlib.h>


struct no{                                // Estrutura que armazena a lista de valores reais
   float info;
   struct no* prox;};
typedef struct no No;

struct pilha{                             // Estrutura de ponteiro que armazena o primeiro elemento da pilha
   No* prim;
};
typedef struct pilha Pilha;

// Função 'cria'. Aloca a estrutura da pilha e inicializa a lista como sendo vazia.
Pilha* cria (void){
   Pilha* p = (Pilha*)malloc(sizeof(Pilha));
   p->prim = NULL;
   return p;
}

                                       ////***** Funções auxiliares (listas) *****/////
// Função auxiliar que insere no inicio
No* ins_ini (No* l, float v){
   No* p = (No*)malloc(sizeof(No));
   p->info = v;
   p->prox = l;
   return p;
}

// Função auxiliar que retira no inicio
No* ret_ini (No* l){
   No* p = l->prox;
   free(l);
   return p;
}
                                       /////******* Funções que mapipulam a pilha ******* //////

void empilhar (Pilha* p, float v){
   p->prim = ins_ini(p->prim, v);
}

float desempilhar (Pilha* p){
   float v;
   if (vazia(p)){                               // Verifica se a pilha está vazia
      printf("Pilha vazia.\n");
      exit(1); 
   }
   v = p->prim->info;                           // v recebe o novo valor do topo da lista
   p->prim = ret_ini(p->prim);
   return v;
}

int vazia (Pilha* p){
   return (p->prim == NULL);
}

void libera (Pilha* p){
   No* q = p->prim;
   while (q != NULL){
      No* t = q->prox;
      free(q);
      q = t;}
   free(p);
}

void imprime(Pilha* p){
   No* q;
   for (q = p->prim; q != NULL; q = q->prox){
      printf("%.3f\n",q->info);}
      
}