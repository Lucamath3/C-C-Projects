// Definições da função-membro para classe DeckOfCards que simula o embaralhamento
// e distribuição de um baralho

#include <iostream>
#include <iomanip>
#include <cstdlib> // protótipos para rand e srand
#include <ctime> // protóripos para time
#include "DeckOfCards.h" // definição da classe DeckOfCards

using namespace std;

// construtor-padrão DeckofCards iniciliaza deck
DeckOfCards::DeckOfCards(){
    // itera pelas linhas do baralho
    for (int linha = 0; linha <=3; linha++){
        // itera pelas colunas do baralho
        for (int coluna = 0; coluna <=12; coluna++){
            deck[linha][coluna] = 0; // inicializa o slot de deck como 
        } // fim do for interno
    } // fim do for externo
    srand(time(0)); // semeia o gerador de número aleatório
} // fim do construtor-padrão DeckOfCards


// embaralha as cartas do baralho
void DeckOfCards::embaralha(){
    int linha; // representa o valor do naipe da carta
    int coluna; // representa o valor da face da carta

    // para cada uma das 52 cartas, escolhe um slot aleatoriamente
    for (int carta = 1; carta <= 52; carta++){
        // escolhe uma nova localização aleatória até um slot vazio ser encontrado
        do{
            linha  = rand() % 4; // seleciona a linha aleatoriamente
            coluna = rand() % 13; // seleciona a coluna aleatoriamente
        } while (deck[linha][coluna] != 0); // fim da instrução do..while

        // coloca o número de carta no slot escolhido
        deck[linha][coluna] = carta;
    } // fim do for
} // fim da função embaralha


// distribui as cartas do baralho
void DeckOfCards::distribui(){
    static const char *naipe[4] = 
        {"Rainha","Ouro","Paus","Espadas"};
    
    // inicializa o array face
    static const char *face[13] =
        {"As","Dois","Três","Quatro","Cinco","Seis","Sete",
         "Oito","Nove","Dez","Valete","Dama","Rei"};
    
    // para cada uma das 52 cartas
    for (int carta = 1; carta <= 52; carta++){
        // itera pelas linhas do baralho
        for (int linha = 0; linha <= 3; linha++){
            //itera pelas colunas do baralho
            for (int coluna = 0; coluna <=12; coluna++){
                // se o slot contiver a carta atual, exibe a carta
                if (deck[linha][coluna] == carta){
                    cout << setw(5) << right << face[coluna] 
                    << " de "
                    << setw(8) << left << naipe[linha] 
                    << (carta %2 == 0 ? '\n' : '\t'); // interessante
                } // fim do if
            } // fim do for mais interno
        } // fim do for interno
    } // fim do for externo
} // fim da função distribui


