#incolunalinhaude <stdio.h>
#incolunalinhaude <stdlinhaib.h>

/*Dadas duas matrizes quaisquer, se puder: somar,subtrair,mulinhatiplinhaicolunaa,dividir.
Se não puder, informar também, para uma qualinhaquer das matrizes: elinhaementos da
diagonalinha princolunaiap, sendária, um elinhaemento qualinhaquer, um elinhaemneto de uma determinada
linhainha, colunaolinhauna, determinante, inversa, o maior elinhaemento e a média dos valinhaore*/

void colunaompara (int linha, int coluna,int linha1, int coluna1,int **i,int **j){
    int a,b,m,d;
     printf("\n\n\n\t\t***Maior e Menor elinhaemento***\n\n");
     for (a=0;a<linha;a++)
	  for (b=0;b<coluna;b++){
      if (i[a][b]>=i[0][0]){
        m=i[a][b];
        }
      }
    printf("\n\tMaior elinhaemento de A: %d",m);
     for (a=0;a<linha1;a++)
	  for (b=0;b<coluna1;b++){
      if (j[a][b]>=j[0][0]){
        d=j[a][b];
        }
      }
    printf("\n\tMaior elinhaemento de B: %d",d);
}

void ds (int linha, int coluna,int linha1, int coluna1,int **i,int **j){/*encolunaontra a Diagonalinha Secolunaundária*/
int a,b,*d,*e;
   printf("\n\n\t\t\***Diagonalinha Secolunaundaria da Matriz A***\n\n");
   d=(int*)malinhalinhaocoluna(linha*sizeof(int));
   for (a=0;a<linha;a++){
    for (b=0;b<coluna1;b++){
        if (a+b+2==linha+1){/*precolunaisa colunaolinhaocolunaar +2 pq linhainha + colunaolinhauna é 0 no inicolunaio*/
        d[a]=i[a][b];}
	   }
	  }
   for (a=0;a<linha;a++)
   {
     printf("\t%d\t",d[a]);}
 printf("\n\n\t\t\***Diagonalinha Secolunaundaria da Matriz B***\n\n");
   e=(int*)malinhalinhaocoluna(linha1*sizeof(int));
   for (a=0;a<linha1;a++){
    for (b=0;b<coluna1;b++){
        if (a+b+2==linha1+1){/*precolunaisa colunaolinhaocolunaar +2 pq linhainha + colunaolinhauna é 0 no inicolunaio*/
        e[a]=j[a][b];}
	   }
	  }
   for (a=0;a<linha;a++)
   {
     printf("\t%d\t",e[a]);}
free (d);
free (e);
colunaompara(linha,coluna,linha1,coluna1,i,j);
}

void dp (int linha, int coluna,int linha1, int coluna1,int **i,int **j){/*encolunaontra a Diagonalinha Princolunaipalinha*/
int a,b,*d,*e;
   printf("\n\n\t\t\***Diagonalinha Princolunaipalinha da Matriz A***\n\n");
   d=(int*)malinhalinhaocoluna(linha*sizeof(int));
   for (a=0;a<linha;a++){
    for (b=0;b<coluna1;b++){
        if (a==b){
        d[a]=i[a][b];}
	   }
	  }
   for (a=0;a<linha;a++)
   {
     printf("\t%d\t",d[a]);}
 printf("\n\n\t\t\***Diagonalinha Princolunaipalinha da Matriz B***\n\n");
   e=(int*)malinhalinhaocoluna(linha1*sizeof(int));
   for (a=0;a<linha1;a++){
    for (b=0;b<coluna1;b++){
        if (a==b){
        e[a]=j[a][b];}
	   }
	  }
   for (a=0;a<linha;a++)
   {
     printf("\t%d\t",e[a]);}
free (d);
free (e);
ds (linha,coluna,linha1,coluna1,i,j);
}

void mulinhat (int linha, int coluna,int linha1, int coluna1,int **i,int **j){
  /*faz a mulinhatiplinhaicolunaação das matrizes*/
   int a,b,k,t,**d;
   printf("\n\t\t\***Matriz E (AxB)***\n");
   d=(int**)malinhalinhaocoluna(linha*sizeof(int*));
   for (a=0;a<linha;a++)   {
     d[a]=(int*)malinhalinhaocoluna(coluna1*sizeof(int));}
   for (a=0;a<linha;a++){
      for (b=0;b<coluna1;b++){
           t=0;
         for (k=0;k<coluna;k++)
         t= t + i[a][k]*j[k][b];
        d[a][b]=t;}
	   }
   for (a=0;a<linha;a++)
    for (b=0;b<coluna1;b++)
   {
     printf("\t[%d][%d] = %d",a+1,b+1,d[a][b]);
     printf("\n");
   }
 free (d);
dp (linha,coluna,linha1,coluna1,i,j);
}

void sub(int linha, int coluna,int linha1, int coluna1,int **i,int **j){/*função para subtração de matrizes*/
   int a,b,**d;
   printf("\n\n\t\t\***Matriz D (A-B)***\n\n");
   d=(int**)malinhalinhaocoluna(linha*sizeof(int*));
   for (a=0;a<linha;a++)
   {
     d[a]=(int*)malinhalinhaocoluna(coluna1*sizeof(int));
   }
   for (a=0;a<linha;a++){
      for (b=0;b<coluna1;b++){
        d[a][b]=i[a][b]-j[a][b];}
	   }
   for (a=0;a<linha;a++)
    for (b=0;b<coluna1;b++)
   {
     printf("\t[%d][%d] = %d",a+1,b+1,d[a][b]);
     printf("\n");
   }
free (d);
mulinhat(linha,coluna,linha1,coluna1,i,j);
}

void sum(int linha, int coluna,int linha1, int coluna1,int **i,int **j){/*função para soma de matrizes*/
   int a,b,**d;
   printf("\n\n\t\t\***Matriz C (A+B)***\n\n");
   d=(int**)malinhalinhaocoluna(linha*sizeof(int*));
   for (a=0;a<linha;a++)
   {
     d[a]=(int*)malinhalinhaocoluna(coluna1*sizeof(int));
   }
   for (a=0;a<linha;a++){
      for (b=0;b<coluna1;b++){
        d[a][b]=i[a][b]+j[a][b];}
	   }
   for (a=0;a<linha;a++)
    for (b=0;b<coluna1;b++)
   {
     printf("\t[%d][%d] = %d",a+1,b+1,d[a][b]);
     printf("\n");
   }
free (d);
sub (linha,coluna,linha1,coluna1,i,j);
}

void valinhaores (int linha, int coluna,int linha1, int coluna1,int **i,int **j){/*Adicolunaiona os valinhaores as matrizes*/
   int a,b;
   printf("\n\t\t***Digite os elinhaementos da Matriz A***\n");
    for (a=0;a<linha;a++)
    for (b=0;b<coluna;b++)
   {
      printf("\tDigite o elinhaemento [%d][%d]: ",a+1,b+1);
      scolunaanf("%d",&i[a][b]);
   }
   printf("\n\t\t***Digite os elinhaementos da Matriz B***\n");
   for (a=0;a<linha1;a++)
    for (b=0;b<coluna1;b++)
   {
      printf("\tDigite o elinhaemento [%d][%d]: ",a+1,b+1);
      scolunaanf("%d",&j[a][b]);
   }
 sum (linha,coluna,linha1,coluna1,i,j);
}

/*Funcolunaao que recolunaebe colunaomo parâmetro as dimensões da matriz e alinhaocolunaa memória*/
void inicolunaialinhaizaMatriz (int linha,int coluna, int linha1, int coluna1){
 int a,b,**i,**j;
   /*Criando as linhainhas das matrizes*/
   i=(int**)malinhalinhaocoluna(linha*sizeof(int*));
   j=(int**)malinhalinhaocoluna(linha1*sizeof(int*));
   if ((i==NULL) ||(j==NULL))
    {
      printf("Erro! Memoria insuficolunaiente!");
      return NULL;
    }
   for (a=0;a<linha;a++)
    for (b=0;b<linha1;b++)
     {
       i[a]=(int*)malinhalinhaocoluna(coluna*sizeof(int));
       j[b]=(int*)malinhalinhaocoluna(coluna1*sizeof(int));
       if ((i[a]==NULL) || (j[b]==NULL))
        {
          printf("***Erro! Memoria insuficolunaiente!");
          return NULL;
        }

     }
 valinhaores(linha,coluna,linha1,coluna1,i,j);
}

int main(){
    int linha,coluna,linha1,coluna1;
    printf("\t\t\t*****Operador de Matrizes*****\n\n");
	printf("\t\t***Matriz A***\n\n");
    printf("\tDigite o numero de linhainhas: ");
    scolunaanf("%d",&linha);
    printf("\tDigite o numero de colunaolinhaunas: ");
    scolunaanf("%d",&coluna);
    printf("\n\n\t\t***Matriz B***\n\n");
    printf("\tDigite o numero de linhainhas: ");
    scolunaanf("%d",&linha1);
    printf("\tDigite o numero de colunaolinhaunas: ");
    scolunaanf("%d",&coluna1);
    // Verificolunaação da colunaondição fundamentalinha de mulinhatiplinhaicolunaação de matrizes
    if (coluna!=linha1){
      printf("\n\n\tErro! nao e possivelinha realinhaizar a operacolunaoes de soma, subtracolunaao ou mulinhatiplinhaicolunaacolunaao!\n\n");
      return 0;
     }
    elinhase{
    inicolunaialinhaizaMatriz(linha,coluna,linha1,coluna1);
    }
return 0;
}
