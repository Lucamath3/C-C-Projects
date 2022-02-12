#include <math.h>
#include <stdlib.h>
#include "ponto.h"

struct ponto {
    float x;
    float y;
};

Ponto* pto_cria(float x, float y){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if (p != NULL){
        p -> x = x;
        p -> y = y;
    }
    return p;
} 

void pto_libera(Ponto* p){
    free(p);
}

// Recupera, por referência, o valor de um ponto
void pto_acessa(Ponto* p, float* x, float* y){
    *x = p -> x;
    *y = p -> y;
}

// Recupera, por referência, o valor de um ponto
void pto_atribui(Ponto* p, float x, float y){
    p -> x = x;
    p -> y = y;
}

float pto_distancia(Ponto* p1, Ponto* p2){
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx*dy + dy*dy);
}
