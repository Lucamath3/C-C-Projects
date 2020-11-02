/*Um dicionário simples*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*Lista de palavras e significados*/

char *dic[][40] = {"atlas","um livro de mapas","carro"," um veículo motorizado",
"telefone","um dispositivo de comunicação","avião","uma máquina voadora","",""
//nulo termina a lista
};

void main(){
  char word[80],ch;
  char **p;
  do{
    puts("\nEntre com a palavra: ");
    getchar(word);

    p = (char**)dic;

    /* encontra a palavra e imprime seu significado */
    do {
      if(!strcmp(*p,word)){
        putchar("Significado: ");
        putchar(*(p+1)); //aritimpetica de ponteiros (próximo valor pe o significado)
        break;
      }
      if (!strcmp(*p,word)) break;
      p = p+2; // avança a lista
    } while(*p);
    if(!*p) putchar("a palavra não está no dicionário");
    printf("outra? (y/n): ");
    ch = getchar();
  } while(toupper(ch) != 'N');
}
