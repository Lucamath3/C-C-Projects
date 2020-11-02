/*
Classificação por borbulhamento (bubble sort)
    No algoritmo de classificação por borbulhamento, valores menores gradualmente sobem para a parte superior do array como bolhas 
de ar subindo na água, enquanto as bolhas maiores afundam. A classificação por borbulhamento faz várias passagens pelo array. Em 
cada passagem, sucessivos pares de elementos são comparados. Se um par estiver na ordem crescente (ou os valores forem idênticos),
deixamos os valores como eles estão. Se um par estiver na ordem decrescente, seus valores são trocados no array. Escreva um 
programa que classifica um array de 10 inteiros utilizando classificação por borbulhamento.

*/
#include <iostream>

using namespace std;

void bubbleSort(int vetor[], int tamanhoVetor){
    int auxiliar; // variavel auxiliar para ordenar o vetor
    for (int i = 0; i < tamanhoVetor; i++){
        for (int j = 0; j < tamanhoVetor; j++){
            
            // Ordenação crescente
            if (vetor[j] > vetor[i]){
                auxiliar = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = auxiliar;
            }
        } // fim do laço interno da ordenação
    } // fim do laço exinterno da ordenação

    // Imprime o vetor ordenado
    cout << "\n\tELEMENTOS NA ORDEM CRESCENTE" << endl;
    for (int i = 0; i < tamanhoVetor; i++)
        cout << vetor[i] << endl;
}


int main(){
    int tamanhoVetor = 10;
    int vetor[tamanhoVetor];
    for (int i = 0; i < tamanhoVetor; i++){
        cout << "Digite o elemento " << i << ": ";
        cin >> vetor[i];
    }
    bubbleSort(vetor,tamanhoVetor);
    return 0;
}