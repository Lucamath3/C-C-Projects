// Definição da classe SalesPerson
// Funções-membro definidas em SalesPerson.cpp

#ifndef SALES_H
#define SALESP_H

class SalesPerson{
    public:
        SalesPerson(); // construtor
        void getObtemVendas(); // insere as vendas a partir do teclado
        void setVendas(int, double); // configura as vendas de um mês específico
        void imprimeVendasAno(); // resume e imprime as vendas
    private:
        double totalVendasAno(); // protótipo para função utilitária
        double vendas[12]; // 12 estimativas de vendas mensais
}; // fim da classe SalesPerson

#endif