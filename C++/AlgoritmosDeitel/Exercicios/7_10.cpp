/*
    Utilize um array unidimensional para resolver o seguinte problema. Uma empresa paga seu pessoal de vendas por comissão. Os vendedores
recebem $ 200 por semana mais 9% de suas vendas brutas por semana. Por exemplo, um vendedor que vende $ 5.000 brutos em uma
semana recebe $ 200 mais 9% de $ 5.000 ou um total de $ 650. Escreva um programa (utilizando um array de contadores) que determina
quanto o pessoal de vendas ganhou em cada um dos seguintes intervalos (suponha que o salário de cada vendedor foi truncado para uma
quantidade do tipo inteiro) :
a) $ 200–$ 299  b) $ 300–$ 399  c) $ 400–$ 499  d) $ 500–$ 599  e) $ 600–$ 699  f) $ 700–$ 799  g) $ 800–$ 899  h) $ 900–$ 999
i) $ 1.000 e acima
*/

#include <iostream>

using namespace std;

int pagamentoComissao(float vendas){
    int pagamento = 0; //inicialização da variavel
    cout << "Valor de vendas: " << vendas << endl;
    pagamento = 200 + int(vendas*0.09); // formula de pagamento da empresa. *vendasFuncionariosPtr representa o valor do índice no vetor principal.
    return pagamento;
}

void estatisticaDasVendas(float vendasFuncionarios[], int n){
    int estatistica[] = {0,0,0,0,0,0,0,0,0};   // vetor que armazena a quantidade de ocorrências de salarios no intervalo do problema. Inicializado com valores nulos.
    int auxiliar; // variavel que recebe temporarimente o salario

    //Inicio do laço de estatísticas
    for (int i = 0; i < n; i++){
        auxiliar = pagamentoComissao(vendasFuncionarios[i]); // aritmetica de ponteiros: vendasFuncionariosPtr armazena o enderço inicial do
                                                                // vetor com os valores do salario. Desse modo, o incremento de i + 0 percorre o vetor.
        // Sequência de verificações para cada opção do problema 
        if (auxiliar > 200 && auxiliar < 300){
            estatistica[0] = estatistica[0] + 1;  
        }
        else if (auxiliar > 300 && auxiliar < 400){
            estatistica[1] = estatistica[1] + 1;  
        }
            else if (auxiliar > 400 && auxiliar < 500){
                estatistica[2] = estatistica[2] + 1;  
            }
                else if (auxiliar > 500 && auxiliar < 600){
                    estatistica[3] = estatistica[3] + 1;  
                }
                    else if (auxiliar > 600 && auxiliar < 700){
                        estatistica[4] = estatistica[4] + 1;  
                    }
                        else if (auxiliar > 700 && auxiliar < 800){
                            estatistica[5] = estatistica[5] + 1;  
                        }
                            else if (auxiliar > 800 && auxiliar < 900){
                                estatistica[6] = estatistica[6] + 1;  
                            }
                                else if (auxiliar > 900 && auxiliar < 1000){
                                    estatistica[7] = estatistica[7] + 1;  
                                }
        else
            estatistica[8] = estatistica[8] + 1;  
    }

    // Impreção dos resultados
        cout << "\n\n ESTATISTICAS DOS SALÁRIOS\n\n";
        cout << "Funcionários que ganham entre $ 200–$ 299: " << estatistica[0] << endl;
        cout << "Funcionários que ganham entre $ 300–$ 399: " << estatistica[1] << endl;
        cout << "Funcionários que ganham entre $ 400–$ 499: " << estatistica[2] << endl;
        cout << "Funcionários que ganham entre $ 500–$ 599: " << estatistica[3] << endl;
        cout << "Funcionários que ganham entre $ 600–$ 699: " << estatistica[4] << endl;
        cout << "Funcionários que ganham entre $ 700–$ 799: " << estatistica[5] << endl;
        cout << "Funcionários que ganham entre $ 800–$ 899: " << estatistica[6] << endl;
        cout << "Funcionários que ganham entre $ 900–$ 999: " << estatistica[7] << endl;
        cout << "Funcionários que ganham $ 1.000 e acima " << estatistica[8] << endl;
}

int main(){
    const int pessoal = 10; // variavel que representa a quantidade de funcionarios
    float vendasFuncionarios[pessoal]; // vetor que representa as vendas de cada funcionario (funcionario 0, 1, 2 ...)

    // Laço para preencher o vetor "vendasFuncionarios" com a venda semanal de cada funcionario
    for (int i = 0; i < pessoal; i++){
        cout << "Digite o total de vendas do funcionário " << i << ": ";
        cin >> vendasFuncionarios[i];
    } // fim do laço
    cout << endl;

    estatisticaDasVendas(vendasFuncionarios,pessoal);

    return 0;
}