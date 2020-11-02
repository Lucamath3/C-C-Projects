#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

void main(void){
    // p é o ponteiro que guarda o endereço da pilha
    pilha* p = iniciaPilha();
    empilharValor(p,1);
    empilharValor(p,2);
    empilharValor(p,3);
    empilharValor(p,4);
    empilharValor(p,5);
    empilharValor(p,6);
    printf("\n\n\t\t\tValores iniciais\n");
    imprimePilha(p);
    printf("\n\n\t\t\tValor depois de removido:\n");
    removeTopo(p);
    removeTopo(p);
    removeTopo(p);
    imprimePilha(p);
    printf("\n\n\t\t\tValor depois de inserir:\n");
    empilharValor(p,10);
    empilharValor(p,11);
    imprimePilha(p);
    printf("\n\n\t\t\tValor depois de removido:\n");
    removeTopo(p);
    imprimePilha(p);
    limpaPilha(p);
}
