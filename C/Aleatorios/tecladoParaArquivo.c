/*Programa que realiza a mesma função do vi em gravar informações em um arquivo
 de texto. O nome do arquivo deve ser passado via parâmetro na execução do programa
 */
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
  FILE *fp;
  char ch;
printf("Digite '$' para sair\n");
  if(argc != 2){
    printf("Você esqueceu de digitar o nome do arquivo.\n");
    exit(1);
  }

  if((fp=fopen(argv[1],"w")) == NULL){
    printf("O arquivo não pode ser aberto\n");
    exit(1);
  }

  do{
    ch = getchar();
    putc(ch,fp);
  } while(ch!='$');
fclose(fp);
}
