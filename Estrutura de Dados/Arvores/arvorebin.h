



typedef struct  arvore Arv;
Arv* inicializa (void);
Arv* cria (float c, Arv* e, Arv* d);
int vazia(Arv* a);
void imprime (Arv* a);
Arv* libera (Arv* a);
int busca (Arv* a, float c);