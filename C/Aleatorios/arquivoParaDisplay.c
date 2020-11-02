/*KTOD: Do teclado para o disco*/
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]){
  FILE *fp;
  char ch;
  if(argc != 2){
    printf("Você esqueceu de digitar o nome do arquivo.\n");
    exit(1);
  }

  if((fp=fopen(argv[1],"r")) == NULL){
    printf("O arquivo não pode ser aberto\n");
    exit(1);
  }
  ch = getc(fp);
  while(ch!= EOF){
    putchar(ch); //Imprime os caracteres
    ch = getc(fp);
  }
fclose(fp);
}
