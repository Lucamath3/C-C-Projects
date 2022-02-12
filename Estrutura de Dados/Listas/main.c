#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"

int main(){
    printf("Hello world!\n");
    listaDupla* l;
    l = insere(l,23);
    l = insere(l,4.23);
    l = insere(l,45.67);
    l = insere(l,9.9345);
    l = insere(l,11.24244);
    l = insere(l,25);
    l = insere(l,1.99);
    imprime(l);
    printf("\nRemovendo elemento 45.67");
    l = retira(l,45.67);
    printf("\nRemovendo elemento 1.99");
    l = retira(l,1.99);
    imprime(l);
    libera(l);
    return 0;}
