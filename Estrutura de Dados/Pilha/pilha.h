/*
Autor: Lucas Gomes
Data: 08/02/2022
Projeto: Arquivo cabeçalho de Estrutura de dados do tipo pilha
Descrição:
    São estruturas de dados do tipo LIFO (last-in first-out), onde o último elemento a ser inserido, será o primeiro a ser retirado. Assim,
    uma pilha permite acesso a apenas um item de dados - o último inserido. Para processar o penúltimo item inserido, deve-se remover o último.
    A implementação de pilhas pode ser realizada através de vetor (alocação do espaço de memória para os elementos é contígua) ou através de listas
    encadeadas.Numa pilha, a manipulação dos elementos é realizada em apenas uma das extremidades, chamada de topo, em oposição a outra extremidade,
    chamada de base.
*/


typedef struct pilha Pilha;
Pilha* cria(void);
void empilhar(Pilha* p, float v);
float desempilhar(Pilha* p);
int vazia(Pilha* p);
void libera(Pilha* p);
void imprime(Pilha* p);