#include <stdio.h>
#include <stdlib.h>
#include "numcv2.h"

int main(void){
    //CRIAR O TESTE PARA MATRIZES DE DIMENSOES GENÉRICAS PARA:
    // SOMAR, SUBTRAIR
    // OTIMIZAR A MULTIPLICAÇÃO DE O(N³) -> O(N²)
    // ADICIONAR AS FUNÇÕES REAIS
    // INICIAR A BIBLIOTECA DE ROBOTICA
    float** matrizA;
    float** matrizTransposta;
    float** matrizM;
    float** matrizS;
    float** matrizSub;
    float** matrizUm;
    float** matrizZero;
    float det;

    matrizA = iniciaMatrizReal(3,3);
    insereElementoReal(3,3,matrizA);
    printf("\nElementos de A: \n");
    imprimeMatrizReal(3,3,matrizA);

    matrizTransposta = matrizTranspostaReal(3,3,matrizA);
    printf("\nMatriz Transposta: \n");
    imprimeMatrizReal(3,3,matrizTransposta);

    matrizM = multMatrizReal(3,3,matrizA,3,3,matrizTransposta);
    printf("\nMatriz Mult: \n");
    imprimeMatrizReal(3,3,matrizM);

    matrizS = somaMatrizReal(3,3,matrizA,3,3,matrizA);
    printf("\nMatriz Soma: \n");
    imprimeMatrizReal(3,3,matrizS);

    matrizSub = subMatrizReal(3,3,matrizA,3,3,matrizA);
    printf("\nMatriz Sub: \n");
    imprimeMatrizReal(3,3,matrizSub);

    matrizUm = matrizOnesReal(4,4);
    printf("\nMatriz de 1: \n");
    imprimeMatrizReal(4,4,matrizUm);

    matrizZero = matrizZerosReal(4,3);
    printf("\nMatriz de 0: \n");
    imprimeMatrizReal(4,3,matrizZero);

    det = determinanteReal(3,3,matrizA);
    printf("\nDeterminante de A: [%f]", det);

    liberaMatrizReal(3,3,matrizA);
    liberaMatrizReal(3,3,matrizTransposta);
    liberaMatrizReal(3,3,matrizM);
    liberaMatrizReal(3,3,matrizS);
    liberaMatrizReal(3,3,matrizSub);
    liberaMatrizReal(4,4,matrizUm);
    liberaMatrizReal(4,3,matrizZero);

    printf("\n");
}
