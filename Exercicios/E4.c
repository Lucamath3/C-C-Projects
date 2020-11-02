/*
4. Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem
alfabética. Faça isto com string de C e de C++
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void main(void){
  char nome1[80];
  char nome2[80];
  printf("\nDigite o primeiro nome: ");
  gets(nome1);
  printf("Digite o segundo nome: ");
  gets(nome2);
  if (tolower(nome1[0]) > tolower(nome2[0])){
      printf("\nEm ordem alfabética:\n");
      puts(nome2);
      printf(" vem antes de ");
      puts(nome1);
      printf("\n");
  }
  else{
      printf("\nEm ordem alfabética:\n");
      printf("%s",nome1);
      printf(" vem antes de ");
      printf("%s",nome2);
      printf("\n");
  }
}
