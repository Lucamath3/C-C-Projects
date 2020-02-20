#include <stdio.h>
#include <stdlib.h>

// Estrutura simples para um nó da lista
// constituida de um inteiro e um ponteiro para o próximo elmento

struct Lista{
	int info;
	struct Lista* prox;
};
typedef struct Lista lista;

//Funcao que busca um elemento 'b' na lista
lista* busca_lista(lista* l,int b){
	lista* p;
	for (p=l; p!=NULL; p=p->prox){
		if(p->info == b)
			return p;
	}
	return NULL; //caso nao tenha encontrado o elemento
}

//Funcao que remove um elemento 'r' da lista
lista* remove_lista(lista* l,int r){
	lista* ant = NULL; //ponteiro para o elemento anterior
	lista* p = l;     //ponteiro para percorrer a lista

	//Procura o elemento na lista, guardando o anterior
	while (p != NULL && p->info != r){
		ant = p;
		p = p->prox;
	}

	if (p == NULL){
		printf("\nElemento %d nao encontrado na lista!", p->info);
		return l; //Se nao achar o elemento, retorna a lista original
	}

	//IF para retirar elemento no inicio
	if (ant == NULL){
		l = p->prox; //faz o ponteiro apontar para segundo elemento
		printf("\nElemento %d removido com sucesso!", p->info);
	}

	else{
	//retira elemento no meio da lista
		ant->prox = p->prox; //O ponteiro  anterior aponta para o proximo elemento
		printf("\nElemento %d removido com sucesso!", p->info);
	}
	free(p); //libera o ponteiro auxiliar para percorrer a lista
	return l; //retorna a lista
}

//Funcao que adiciona o elemento 'a' a lista
lista* adiciona_lista(lista* l, int a){
	lista* novo = (lista*)malloc(sizeof(lista));
	novo->info = a;
	novo->prox = l;
	printf("\nElemento %d adiconado à lista!", novo->info);
	return novo;
}

// Funcao que inicializa a lista apontando para NULL
lista* inicia_lista(void){
	return NULL;
}

 //Funcao que exibe os elementos da lista
void imprime_lista(lista* l){
	lista* p;
	for (p = l; p != NULL; p = p->prox){
		printf("\ninfo = %d", p->info);
	}
}

//Funcao que verifica se a liSta esta vazia
int vazia_lista(lista* l){
	if (l == NULL){
		return l;
	}
	else{
		return 0;
	}
}

//Funcao que limpa (zera) a lista
void libera_lista(lista* l){
	lista* p = l;
	while (p != NULL){
		lista* t = p->prox; //guarda referencia para o proximo elemento
		free(p);
		p = t; //p recebe o endereco apontado por t apos liberar o primeiro elmento
	}
	printf("\nLista esvaziada com sucesso!\n");
}

// Implementação simples das funções anteriores
int main(){
	lista* l;
	l = inicia_lista();
	l = adiciona_lista(l,4);
	l = adiciona_lista(l,23);
	l = adiciona_lista(l,45);
	l = adiciona_lista(l,2);
	imprime_lista(l);
	l = remove_lista(l,4);
	imprime_lista(l);
	libera_lista(l);
	return 0;
}
