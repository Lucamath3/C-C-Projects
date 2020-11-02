/* Um arquivo em C é manipulado por uma variável ponteiro para arquivo. Para
tanto, utiliza-se a biblioteca stdio.h;
Para gravar um caracter no arquivo, a função uilizada é "putc", cujos parâmetros
são: int putc(int ch, FILE *fp) (caractere, ponteiro para arquivo);
*/

/* #############################################################################
Autor: Lucas Gomes
Data: 08/06/2020
Objetivo: Implementar uma biblioteca para auxiliar a manipulação de arquivos
Versão 1.0
#############################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Estrutura para verificação se o arquivo foi aberto/criado
bool verificaAbertura(FILE *fp){
if (!fp){
  printf("Erro na abertura do arquivo.");
  return false;
  }
else
  return true;
}

void fechaArquivo(FILE *fp){
  fclose(fp);
}

void gravaInformacao(FILE *fp, char string[]){
  for (int i = 0; i < strlen(string); i++){
    putc(string[i], fp);
  }
}

void main(void){
  FILE *fp;
  char string[100];
  fp = fopen("arquivo.txt","a");
  if(verificaAbertura(fp)){
    printf("Entre com uma string: ");
    gets(string);
    gravaInformacao(fp,string);
    fechaArquivo(fp);
  }

}
