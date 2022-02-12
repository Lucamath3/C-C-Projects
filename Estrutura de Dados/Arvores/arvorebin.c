/*
Autor: Lucas Gomes
Data: 12/02/2022
Projeto: Arquivo de uma arvore
Descrição: Uma árvore é composta por um nó e suas respectivas subarvores.
*/


#include <stdio.h>
#include <stdlib.h>

struct arvore{
    float info;
    struct arvore* esq;
    struct arvore* dir;
};
typedef struct arvore Arv;

// Inicializa a árvore nula
Arv* inicializa(void){
    return NULL;
}

// Cria uma árvore não nula
    // sae = Sub Arvore Esquerda
    // sad = Sub Arvore Direita
Arv* cria (float c, Arv* sae, Arv* sad){
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

// Verifica se a árvore está vazia
int vazia(Arv* a){
    return a == NULL;
}

// Imprime, recursivamente, a informação do nó
void imprime (Arv* a){
    if (!vazia(a)){
        // Dependendo da aplicação, a consulta da árvore pode ser:
            // Pré-Ordem: raiz, sae,sad
            // Simétrica: sae, raiz, sad
            // Pós-Ordem: sae,raiz,sad
        // Para ajustar, basta modificar a ordem de busca/impressão
        printf("%.2f ", a->info);                     // Imprime a raiz
        imprime(a->esq);                            // Imprime a SAE
        imprime(a->dir);                            // Imprime a SAD
    }
}


// Libera memória da árvore
Arv* libera (Arv* a){
    if (!vazia(a)){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

// Busca um elemento
int busca (Arv* a,float c){
    if (vazia(a))
        return 0;
    else
        return a->info == c || busca(a->esq,c) || busca(a->dir,c);          // O operador lógico Ou faz com que a busca seja interrompida assim que o elemento
                                                                            // for encontrado, não chegando a fazer as outras verificações
                                                                    
}