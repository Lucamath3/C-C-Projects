/*
1. Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros.
Ao final da leitura o programa deverá imprimir o número da linha que contém o
menor dentre todos os números lidos.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int linha = 2;
const int coluna = 2;

void apresentaMatriz(int matriz[][coluna]){
  for (int i = 0; i < linha; i++){
    for (int j = 0; j < coluna; j++){
      // Verificação apenas para fins estéticos na apresentação da Matriz
      if (j + 1 >= coluna){
        cout << matriz[i][j] << "\n";
      }
      else
        cout << matriz[i][j] << "\t";
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
    cout << "\nO menor valor é " << aux[0] << " na linha " << aux[1]<< " e coluna "
         << aux[2] << endl;
}

int main(void){
  int m[linha][coluna];
  srand((unsigned)time(0)); // números aleatórios
  for (int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      m[i][j] = rand()%1000;
    }
  }
  cout << "\nValores gerados: \n";
  apresentaMatriz(m);
  verificaMenor(m);
  return 0;
}
