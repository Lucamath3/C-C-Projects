/* #############################################################################
Autor: Lucas Gomes
Data: 08/06/2020
Objetivo: Implementar uma biblioteca para auxiliar a criação de Menus com
switch/while
Versão 1.0
#############################################################################*/

#include <stdio.h>
#include <stdlib.h>

/*Funcao genérica para apresentar as opções no MENU;*/
void telaPrincipal(void){
  int opcao;
  printf("\t\t\tTITULO AQUI\t\t\n\n");
  printf("[1] - \n");
  printf("[2] - \n");
  printf("[3] - \n");
  printf("[4] - \n");
  printf("[5] - \n");
  printf("[6] - \n");
  printf("[0] - Sair\n");
  printf("Selecione sua opção: ");
  printf("\n\n");
  scanf("%d",&opcao);
  telaOpcao(opcao); // Transmite a escolha para  aproxima funcao
}

/*Lida com a escolha da funcao telaPrincipal. A partir disso, invoca as outras
funções do programa principal.*/

void telaOpcao(int opcao){
  switch(opcao){
    case 0:
      exit(0);
      break;
    case 1:
      //Faz isso
      printf("Opção 1\n");
      break;
    case 2:
      //Faz isso
      break;
    case 3:
      //Faz isso
      break;
    case 4:
      //Faz isso
      break;
    case 5:
      //Faz isso
      break;
    case 6:
      //Faz isso
      break;
    default:
      printf("\nOpção inválida!\n");
      telaPrincipal();
  }
}
