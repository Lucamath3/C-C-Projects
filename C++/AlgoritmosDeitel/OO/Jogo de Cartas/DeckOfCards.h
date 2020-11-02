// Definição da classe DeckOfCartds que representa um baralho.

class DeckOfCards{
    public:
        DeckOfCards(); // construtor inicializa deck
        void embaralha(); // embaralha as cartas do baralho
        void distribui(); // distribui as cartas do baralho
    private:
        int deck[4][13]; // representa o baralho de cartas
}; // fim da classe DeckofCards