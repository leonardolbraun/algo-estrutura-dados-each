#include <stdio.h>
/*
subMaxArray() é uma função iterativa que retorna o valor da soma dos
elementos da  subsequência máxima de um outro arranjo chamado x.
Além disso, retorna por referência os arranjos com a subsequência
máxima e o sufixo máximo.

Parâmetros:
x : o ponteiro para o arranjo para o qual será determinada a subsequência máxima;
n : tamanho de x;
sfmarray : ponteiro para o arranjo com os elementos que formam o sufixo máximo;
nsfm : ponteiro para a variável que contém o tamanho de sfmarray;
gbmarray : ponteiro para o arranjo com os elementos que formam a subsequência máxima;
ngbm : ponteiro para a variável que contém o tamanho de gbmarray.

Valor de retorno: soma da subsequência máxima.

*/
double subMaxArray(double *x, int n, double * sfmarray, int * nsfm,
  double * gbmarray, int * ngbm) {
  double globalmax = 0, sufixmax = 0;
  *nsfm = 0; *ngbm = 0;

  for(int i = 0; i < n; i++) {
    printf("sufixmax: %.2f, globalmax: %.2f, x[%d]: %.2f\n", sufixmax, globalmax, i, x[i]);
    printf("Digite um caracter para continuar...");
    getchar();
    if(x[i]+sufixmax > globalmax)
    {
      sufixmax = x[i]+sufixmax;
      sfmarray[*nsfm] = x[i];
      (*nsfm)++;
      globalmax = sufixmax;
      for(int j = 0; j < *nsfm; ++j)
      {
        gbmarray[j] = sfmarray[j];
      }
      *ngbm = *nsfm;
      printf("Novo global máximo == sulfixo máximo: [");
            for(int i = 0; i < *nsfm; ++i)
              printf("%.2f ", sfmarray[i]);
            printf("]\n");
    }
    else {
      if (x[i]+sufixmax > 0)
          {
            sufixmax = x[i]+sufixmax;
            sfmarray[*nsfm] = x[i];
            (*nsfm)++;
            printf("Novo Sulfixo máximo: [");
            for(int i = 0; i < *nsfm; ++i)
              printf("%.2f ", sfmarray[i]);
            printf("]\n");
            printf("Global máximo: [");
            for(int i = 0; i < *ngbm; ++i)
              printf("%.2f ", gbmarray[i]);
            printf("]\n");
          }
      else
        {
          sufixmax = 0;
          *nsfm=0;
          printf("Novo globa máximo == sulfixo máximo: []\n");

        }
    }
  }
  return globalmax;
}

double subMax(double *x, int n) {
  double globalmax = 0, sufixmax = 0;

  for(int i =0; i < n; i++) {
    if(x[i] +sufixmax > globalmax)
    {
      sufixmax = x[i] +sufixmax;
      globalmax = sufixmax;
    }
    else {
      if (x[i] +sufixmax > 0)
          sufixmax = x[i] +sufixmax;
      else
        sufixmax = 0;
    }
  }
  return globalmax;
}


int main() {
    int i, noErros = 0, noTestes = 0;
    double a[] ={2,-3, 1.5, -1, 3, -2, -3, -3, 8};
    double b[] ={2,-3, 5, -1, 3, -2, 13, 3};
    double c[] ={-2,-3, 5, -1, -3, 2, -3, -3};

    double globalmax, sufixmax;
    double globalmax_array[9], sufixmax_array[9];
    int n_globalmax_array, n_sufixmax_array;

    printf("Vetor: [");
    for(i = 0; i < 9; ++i)
      printf("%3.2f ", a[i]);
    printf("]\n");

    printf("Globalmax-Sem-Array: %3.2f\n", subMax(a,9));
    // globalmax = rsubMax(a,8,&sufixmax);
    // printf("===> Calculando os valores da subsequência máxima e do sufixo máximo\n");
    // printf("Globalmax: %3.2f\n", globalmax);
    // printf("Sufixmax: %3.2f\n", sufixmax);


    globalmax = subMaxArray(a,9,sufixmax_array,&n_sufixmax_array, globalmax_array,&n_globalmax_array);

    printf("subMaxArray:\n");
    printf("Globalmax: %3.2f\n", globalmax);
    printf("Sufixmax: %3.2f\n", sufixmax);
    printf("Subsequência máxima correta: [ ");
    for(i = 0; i < n_globalmax_array; ++i)
      printf("%3.2f ", globalmax_array[i]);
    printf("]\n");

    
  return 0;
}