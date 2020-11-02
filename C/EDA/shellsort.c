/*
  O ShellSort é um do métodos de ordenação mais eficientes. É derivado da ordenação
por inserção e é baseado na diminuição dos incrementos. Basicamente, ocorre como
conchas do mar empilhadas uma sobre as outras, comparando o menor (ou maior)
de cada camada e, por fim, as camadas subsequentes. Sua eficiência se dá devido
ao fato de que ocorre com poucos elementos em cada comparação.
*/

void shellSort(char *item, int contador){
  register int i, j, gap, k;
  char x, a[5];
  a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

  for ( k = 0; k < 5; k++){
    gap = a[k];
    for (i = gap; i < contador; ++i){
      x = item[i];
      for (j = i - gap; x < item[j] && j >= 0; j = j - gap)
        item[j + gap] = item[j];
      item[+gap] = x;
    }
  }
}
