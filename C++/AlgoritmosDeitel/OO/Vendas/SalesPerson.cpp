// Funções-membro para a classe SalesPerson.

#include <iostream>
#include <iomanip>
#include "SalesPerson.h"

using namespace std;

// inicializa elementos do array sales como 0.0
SalesPerson::SalesPerson(){
    for (int i = 0; i < 12; i++)
        vendas[i] = 0.0;
} // fim do construtor SalesPerson

// obtém 12 estimatvas de vendas do usuário no teclado
void SalesPerson::getObtemVendas(){
    double objetoVendas;
    for (int i = 1; i <= 12; i++){
        cout << "Entre com a quantidade de vendas do mês " << i << ": ";
        cin >> objetoVendas;
        setVendas(i,objetoVendas);
    } // fim do for
} // fim da função getObtemVendas

// configura uma das 12 estimativas de vendas mensai; a funçãi subtrai
// um do valor mensal para o subscrito adequado no array sales
void SalesPerson::setVendas ( int mes, double montante){
    // testa a validade do mês e do valor
    if (mes >= 1 && mes <= 12 && montante > 0)
        vendas[mes-1] = montante; // ajusta para subscritos 0-11
    else // mês ou valor inválido
        cout << "Mês ou montante inválido" << endl;
} // fim da função setVendas

// imprime o total das vendas anuais (com ajuda da função utilitária)
void SalesPerson::imprimeVendasAno(){
    cout << setprecision(2) << fixed
         << "\nO total de vendas anual é: R$ "
         << totalVendasAno() << endl; // chama a função utilitária
} // fim da função imprimeVendasAno

// função utilitária private para somar vendas anuais
double SalesPerson::totalVendasAno(){
    double total = 0.0; // inicia o total
    for (int i = 0; i < 12; i++) // resume resultados de vendas
        total += vendas[i]; // adiciona vendas do mês i ao total
    
    return total;
} // fim da função totalVendasAno

