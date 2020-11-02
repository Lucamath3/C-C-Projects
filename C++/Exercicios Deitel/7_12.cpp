/*
A classificação por borbulhamento descrita no Exercício 7.11 é ineficiente para arrays grandes. Faça as seguintes modificações simples
para aprimorar o desempenho da classificação por borbulhamento:
a) Depois da primeira passagem, garante-se que o maior número está no elemento de número mais alto do array; após a segunda passagem,
os dois números mais altos estão ‘no lugar’; e assim por diante. Em vez de fazer nove comparações em cada passagem, modifique a
classificação por borbulhamento para fazer oito comparações na segunda passagem, sete na terceira passagem e assim por diante.

b) Os dados no array já podem estar na ordem adequada ou ordem quase adequada, então por que fazer nove passagens se menos seriam
suficientes? Modifique a classificação para verificar no fim de cada passagem se alguma troca foi feita. Se nenhuma troca tiver sido
feita, então os dados já devem estar na ordem apropriada; portanto, o programa deve terminar. Se trocas foram feitas, então pelo menos
mais uma passagem é necessária
*/

#include <iostream>

using namespace std;

void bubbleSort(int vetor[], int tamanhoVetor){
    int auxiliar; // variavel auxiliar para ordenar o vetor
    int contador = 0; // variavel auxiliar que evita a rechecagem de valores já verificados

    for (int i = 0; i < tamanhoVetor; i++){
        // Subtraindo i do tamanhoVetor, o laço interno é executado mais rapidamente.
        // Após a primeira iteração, o ultimo elemento é o maior. Após a segunda, o penultimo o segundo maior e etc.
        // Desse modo, não há necessidade de comparar novamente os valores já verificados

        for (int j = 0; j < tamanhoVetor - contador; j++){
            
            // Ordenação crescente
            if (vetor[j] > vetor[i]){
                auxiliar = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = auxiliar;
            }
        } // fim do laço interno da ordenação
        contador++;
        
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