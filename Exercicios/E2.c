/*
2. Escreva um programa que leia 3 notas de um aluno e a média das notas dos
exercícios realizados por ele. Calcular a média de aproveitamento, usando a
fórmula: MA = (N1 + N2*2 + N3*3 + ME)/7. A partir da média, informar o conceito
de acordo com a tabela:
maior ou igual a 9 	A
maior ou igual a 7.5 e menor que 9 	B
maior ou igual a 6 e menor que 7.5 	C
maior ou igual a 4 e menor que 6 	D
menor que 4 	E
*/
#include <stdio.h>
#include <stdlib.h>

void obtemNotas(float *notas){
  int i = 0;
  // laço apenas para as 3 notas
  while (i < 3){
    printf("Digite a nota %d: ", i+1);
    scanf("%f",&notas[i]);
    i++;
  }
  printf("Digite a média das atividades: ");
  scanf("%f",&notas[3]);
}

float calculaAproveitamento(float *notas){
  return (notas[0]+notas[1]*2+notas[2]*3+notas[3])/7;
}

void verificaConceito(float mediaFinal){
  if (mediaFinal > 9.0){
      printf("Média %2.f. Conceito A\n", mediaFinal);
      exit(0);
  }
  else
      if (mediaFinal > 7.5 && mediaFinal < 9.0){
          printf("Média %.2f. Conceito B\n", mediaFinal);
          exit(0);
      }

      else
          if (mediaFinal > 6 && mediaFinal < 7.5){
            printf("Média %.2f. Conceito C\n", mediaFinal);
            exit(0);
          }

          else
              if (mediaFinal > 4 && mediaFinal < 6.0){
                printf("Média %.2f. Conceito D\n", mediaFinal);
                exit(0);
              }
              else
                printf("Média %.2f. Conceito E\n", mediaFinal);
                exit(0);
}

void main (void){
  //3 notas do aluno ([1][2][3]), média das atvs([4]) e média final ([5])
  float notas[5];
  obtemNotas(notas);
  notas[4] = calculaAproveitamento(notas);
  verificaConceito(notas[4]);
}
