#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reversa(char *s);

void main(int argc, char *argv[]){
  for (int i = argc-1; i >0; i--)
    reversa(argv[i]);
  printf("\n");
}

void reversa (char *s){
  register int t;
    for (t=strlen(s)-1;t>=0;t--)
      putchar(s[t]);
}
