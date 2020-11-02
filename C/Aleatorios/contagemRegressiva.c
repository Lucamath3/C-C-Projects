/* Programa de contagem regressiva utilizando argc e argv */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void main(int argc, char *argv[]){
  int disp, contador;
  if(argc<2){
    printf("Você deve digitar o valor a ser contado\n");
    printf("na linha de comando. Tente novamente.\n");
    exit(1);
  }

  if (argc == 3 && !strcmp(argv[2], "display")){
    disp = 1;
  }
  else disp = 0;

  for (contador = atoi(argv[1]); contador; --contador){
    if(disp) printf("%d\n",contador);
  }

  putchar('\a'); /* isso irá tocar a campainha da maioria dos computadores */
  printf("O tempo acabou!");
}
