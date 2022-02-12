#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    printf("Hello world!\n");
    Pilha* p = cria();
    empilhar(p, 53);
    empilhar(p, 2);
    empilhar(p, 1);
    empilhar(p, 0);
    imprime(p);
    desempilhar(p);
    desempilhar(p);
    imprime(p);
    libera(p);

    
    return 0;
}
