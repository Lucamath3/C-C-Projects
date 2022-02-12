#include <stdio.h>
#include <stdlib.h>
#include "filaDupla.h"


int main(){
    filaDupla* f = cria();
    insere_ini(f,2.0);
    insere_ini(f,0.0);
    insere_ini(f,10.0);
    insere_ini(f,34.4556);
    insere_ini(f,99.5);
    insere_ini(f,365.0);
    insere_ini(f,2);
    insere_ini(f,2548.98);
    insere_ini(f,20.0);
    imprime_ini(f);
    printf("Primeiro elemento inicio: %.2f\n", retira_ini(f));
    printf("Segundo elemento: %.2f\n", retira_ini(f));
    printf("Primeiro elemento do fim: %.2f\n", retira_fim(f));
    printf("Segundo elemento do fim: %.2f\n", retira_fim(f));
    printf("Configuração da fila do fim para inicio: \n");
    imprime_fim(f);
    printf("Configuração da fila do inicio para fim: \n");
    imprime_ini(f);
    libera(f);
    return 0;
}