/*Mostra um relógio por software.*/

#include <stdio.h>

#define DELAY 128000

struct myTime{
  int hora;
  int minutos;
  int segundos;
};
typedef struct myTime myTime;

void display (myTime *t);
void update(myTime *t);
void delay(void);

void main(){
  myTime systime;
  systime.hora = 0;
  systime.minutos = 0;
  systime.segundos = 0;
// loop infinito
  for (;;){
    update(&systime);
    display(&systime);
  }
}

void update(myTime *t){
  t->segundos++;

  if(t->segundos == 60){
    t->segundos = 0;
    t->minutos++;
  }

  if(t->minutos == 60){
    t->minutos = 0;
    t->hora++;
  }

  if (t->hora==24) t->hora = 0;
  delay();
}

void display(myTime *t){
  printf("%02d:",t->hora);
  printf("%02d:",t->minutos);
  printf("%02d\n",t->segundos);
}
delay(void){
  long int t;
  /* configura o delay confome o necessário*/
  for (t = 1; t< DELAY; ++t);
}
