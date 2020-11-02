/*
1. Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros.
Ao final da leitura o programa deverá imprimir o número da linha que contém o
menor dentre todos os números lidos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //incluida apenas para gerar valores realmente aleatorios

//definindo staticamente o número de linhas e colunas
#define linha 5
#define coluna 5

void apresentaMatriz(int matriz[][coluna]){
  for (int i = 0; i < linha; i++){
    for (int j = 0; j < coluna; j++){
      // Verificação apenas para fins estéticos na apresentação da Matriz
      if (j + 1 >= coluna){
      printf("[%d]\n", matriz[i][j]);
      }
      else
        printf("[%d]\t", matriz[i][j]);
    }
  }
}

void verificaMenor(int matriz[][coluna]){
// Vetor para armazenar o primeiro valor da matriz [0], o enderaço da linha[1]
// e o enderaço da coluna [2]
  int aux[3];
  aux[0] = matriz[0][0];
  aux[1] = aux[2] = 0; // inicialização dos campos do vetor
  for (int i = 0; i < linha; i++){
    for (int j = 0; j < coluna; j++){
      // Verificação do menor elemento
      if (aux[0] > matriz[i][j]){
        aux[0] = matriz [i][j];
        aux[1] = i;
        aux[2] = j;
      }
    }
  }
  printf("\nO menor valor e '%d' na linha [%d] e coluna [%d].\n",aux[0],aux[1],aux[2]);
}

void main(){
  int m[linha][coluna];
  srand((unsigned)time(0));
  for (int i = 0; i < linha; i++){
    for (int j = 0; j < coluna; j++){

      m[i][j] = rand()%1000;
    }
  }
  printf("\nValores gerados: \n");
  apresentaMatriz(m); // Apenas para visulização da matriz criada
  verificaMenor(m); //Passagem por referência da matriz
}
