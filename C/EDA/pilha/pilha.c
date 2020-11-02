// #############################################################################

/* Pilha é uma estrutura de dados cujo funcionamento ocorre da seguinte forma:
O primeiro valor que entra é o último a sair; o ultimo valor que entra é
o primeiro a sair. (First in, Last out - FILO). Sendo assim, uma pilha deve
possuir as funções de inserir um valor no topo e remover um valor do topo.
*/

// Autor: Lucas Gomes
// Data: 04/06/2020
// Objetivo: Implementar o algoritmo de uma pilha com menu e gravação em arquivo
// Versão 2.0
// #############################################################################
#include <stdio.h>
#include <stdlib.h>

struct lista{
    int valor;
    struct lista* prox;
};
typedef struct lista lista;

/* Struct para cabeçalho da pilha; lista* prim guarda a referência do primeiro
valor da pilha; É um ponteiro para struct lista devido ao tamanho da estrutura na
memória.*/
struct pilha{
    lista* prim;
};
typedef struct pilha pilha;

/*Obs: Uma pilha nada mais é que uma lista onde há uma referência ao primeiro
valor e a inserção/remoção ocorre no topo*/

// Inicializa o ponteiro para a primeira célula da pilha
pilha* iniciaPilha (void){
    // variavel alocada dinamicamente (tamano da struct pilha)
    pilha* cabeca = (pilha*)malloc(sizeof(pilha));
    // inicaliza a variavel apontando para NULL (segurança)
    cabeca->prim = NULL;
    return cabeca;
}

/* Recebe como parâmetro o ponteiro para uma struct e a variável a ser inserida;
Cria uma nova célula (p) e utiliza os campos da struct pilha (ponteiro para prox
e valor); Desse modo, o ponteiro inicial é passado para a variável p->prox e
a lista é linkada para cada novo elemento. */

lista* insereTopo(lista* fim, int novoValor){
    lista* p = (lista*)malloc(sizeof(lista));
    p->valor = novoValor;
    p->prox = fim;
    return p;
}

/* Funcao que recebe como parametro uma struct pilha e realiza um casting para
a struct lista; Em seguida, aloca memória para uma nova célula, recebe o endereço
do ponteiro de inicialização (próximo endereço d'e memória) e limpaPilha o anterior.
*/
lista* desempilhaValor(lista* topo){
    lista* novoTopo = (lista*)malloc(sizeof(lista));
    novoTopo = topo->prox;
    free(topo);
    return novoTopo;
}

/* Funcao para guardar o valor da variavel na pilha; Recebe como parâmetro o
ponteiro da pilha e o valor a ser empilhado; É do tipo void pois utiliza apenas
o atributo da struct da lista do próximo valor (lista *prox) e invoca a
funcao de inserção (insereValor) no campo valor da struct. */
void empilharValor(pilha* p, int novoValor){
    p->prim =insereTopo(p->prim, novoValor);
}
/* Recebe como parâmetro o ponteiro para o primeiro elemento da pilha (struct pilha)
. Após isso, invoca a função para verificar se a pilha está verificaVazia (p->prim == NULL);
Caso contrário, invoca a função de remoção no inicio (removeTopo).
*/
void removeTopo (pilha* topo){
    if (verificaVazia(topo)){
        printf("Fila VAZIA");
        // exit retorna 1 ao SO sem finalizar o programa, porém sai da funcao.
        exit(1);
    }
    //Envia o cabeçalho da pilha para a funcao de remocao (desempilhaValor)
    topo->prim = desempilhaValor(topo->prim);
}

// Verifica se a pilha está Vazia (primeiro elemento == NULL)
int verificaVazia (pilha* f){
    return (f->prim==NULL);
}

/* Função para libera a memória utilizada pela pilha; Recebe como parâmetro o
cabeçalho da pilha; Cria uma variavel do tipo lista (struct lista) para auxiliar;
Enquanto q->prox não for NULL, free em cada elemento.*/
void limpaPilha(pilha* f){
    lista* q = f->prim;
    while(q!=NULL){
        lista* p = q->prox;
        free(q);
        q = p;}
    free(f);
}

/*Funcao para impressão dos elementos da pilha; Recebe como parâmetro o ponteiro
para o primeiro elemento da pilha.*/
void imprimePilha(pilha* f){
  /* q é uma variável auxiliar para receber os valores de f e verificar se já
  chegou ao final da pilha.*/
    lista* q;
    // q recebe f e enquanto não for nulo (final da pilha) recebe referência
    // aos proximos valores e imprime na tela os valores.
    for (q = f->prim; q != NULL; q = q->prox){
        printf("\nValor: %d", q->valor);
    }
    printf("\n");
}
