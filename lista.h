typedef struct Lista lista;

lista* busca_lista(lista* l,int b); //Funcao que busca um elemento 'b' na lista

lista* remove_lista(lista* l,int r); //Funcao que remove um elemento 'r' da lista

lista* adiciona_lista(lista* l, int a); //Funcao que adiciona o elemento 'a' a lista

lista* inicia_lista(void); // Funcao que inicializa a lista apontando para NULL

void imprime_lista(lista* l); //Funcao que exibe os elementos da lista

int vazia_lista(lista* l); //Funcao que verifica se a liSta esta vazia

void libera_lista(lista* l); //Funcao que limpa a lista
