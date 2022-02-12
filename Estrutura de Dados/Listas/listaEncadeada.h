/*
Autor: Lucas Gomes
Data: 08/02/2022
Projeto: Arquivo cabeçalho de uma Lista Encadeada
Descrição: Para cada novo elemento inserido na estrutura, alocamos um espaço de memória para armazena-lo.
*/

#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED



#endif // LISTAENCADEADA_H_INCLUDED

struct lista{
    float elemento;
    struct lista* prox;
};
// Criação do tipo Lista para representar um nó da lista e a estrutura de lista encadeada será representada
// pelo ponteiro elemento (tipo (Lista*)
typedef struct lista Lista;


Lista* inicializa (void);              // FUNÇÃO DE INICIALIZAÇÃO - Cria uma lista vazia (sem nenhum elemento) representada pelo ponteiro NULL
Lista* insere (Lista* l, float i);     // FUNÇÃO DE INSERÇÃO - Para cada elemento da lista, aloca-se memória dinamicamente e encadeia o elemento à lista existente
void imprime (Lista* l);               // FUNÇÃO QUE PERCORRE OS ELEMENTOS DA LISTA - Percorre os elementos e impreme-os
int vazia (Lista* l);                  // FUNÇÃO QUE VERIFICA SE A LISTA ESTÁ VAZIA
Lista* busca (Lista* l, float v);      // FUNÇÃO DE BUSCA - Consiste em verificar se determidao elemento está na lista
Lista* retira (Lista* l, float v);     // FUNÇÃO QUE RETIRA UM ELEMENTO DA LISTA - Existem dois casos: Se o elemento removido for o primeiro e se o elemento estiver no meio da lista
void libera (Lista* l);                // FUNÇÃO PARA LIBERAR A LISTA
