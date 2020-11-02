/*
Escreva instruções simples que realizam as seguintes operações de um array unidimensional:
    a) Inicialize os 10 elementos do array de inteiros counts como zeros.
    b) Adicione 1 a cada um dos 15 elementos do array de inteiros bonus.
    c) Leia 12 valores para o array double monthlyTemperatures a partir do teclado.
    d) Imprima os 5 valores do array de inteiros bestScores em formato de coluna.
*/

#include <iostream>

using namespace std;

int main(){
    int count[] = {0,0,0,0,0,0,0,0,0,0}; // item a)
    int bonus[15];
    double monthlyTemperatures[12];
    int bestScores[] = {5,8,9,887,14};
    
    // item b)
    for (int i = 0; i <15; i++){
        bonus[i] = 1;
    }

    // item c)
    for (int i = 0; i < 12; i++){
        cout << "Digite a temperatura do mês " << i + 1 << " : ";
        cin >> monthlyTemperatures[i];
    }

    // item d)
    for (int i = 0; i < 5; i++){
        cout << "Saida do vetor bestScores: " << bestScores[i] << endl;
    }

    return 0;
}