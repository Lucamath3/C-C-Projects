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

bool verificaAbertura(FILE *fp);
void fechaArquivo(FILE *fp);
void gravaInformacao(FILE *fp, char string[]);
