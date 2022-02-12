#include <stdio.h>
#include <stdlib.h>
#include "arvorebin.h"

int main(){
    Arv* a1 = cria(1,inicializa(),inicializa());
    Arv* a2 = cria(2,inicializa(),a1);
    Arv* a3 = cria(3,inicializa(),inicializa());
    Arv* a4 = cria(4,inicializa(),inicializa());
    Arv* a5 = cria(5,a3,a4);
    Arv* a = cria(6,a2,a5);
    imprime(a);
    printf("\n");
    return 0;
}

/*
                        6
                    /      \
                    2       1
                     \      /  \
                      5    3    4


 
*/