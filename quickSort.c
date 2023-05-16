#include <stdio.h>
#include <math.h>



void imprime_a(int *, int, int);
int particao (int * A, int p, int r) {
 int x, i, j, temp, iguais;
 x = A[r]; // pivo
 i = p - 1;
 iguais = 1;

 printf("Inicalização (linhas 1-5):------------------------\n");
 
 j=p;
 printf("x (pivô) (%d), p (%d), r (%d), j (%d), i (%d) \n", A[r],p,r,j,i);
 
 printf("Arranjo não particionado:\n");
 imprime_a(A,p,r);
 
 printf("Fim inicalização (linhas 1-5):--------------------\n\n");
  
 printf("Teste laço (linha 6): j (%d) <= r-1 (%d)?\n",j,r-1);
 while(j <= r-1)
   {
   printf("Verdadeiro: i = %d, j=%d, x=%d\n", i,j,x);
   imprime_a(A,p,r);
   printf("Teste if (linha 7):  A[j] (%d) <= x (%d)?\n",A[j],x);
    if (A[j] != x )
    {
       iguais = 0;
    } 
   if(A[j] >= x)
    {
     i++; 
     // trocar
     printf("Verdadeiro:Incrementa i (linha 9): i = %d\n",i);
     printf("(linhas 11-13) A[j] <=> A[i]: A[%d]=%d<=>A[%d]=%d\n",j,A[j],i,A[i]);
     temp = A[i];
     A[i] = A[j];
     A[j] = temp;
    }
    else
     printf("Falso: ==> já é maior que o pivô; não precisa trocar.\n");
   imprime_a(A,p,r);
    ++j;
    printf("Teste laço (linha 6): j (%d) <= r-1 (%d)?\n",j,r-1);
    }
    printf("Falso: Fim do laço\n");
    
 imprime_a(A,p,r);
 printf("Reposicionar o pivo (linhas 18-20): A[i+1] <=> A[r]:  A[%d+1] (%d) <=> A[%d] (%d) (pivô)\n", i,A[i+1],r,A[r]);
 // reposicionar o pivo
 
     temp = A[i+1];
     A[i+1] = A[r];
     A[r] = temp;
 printf("Arranjo particionado:\n");
 imprime_a(A,p,r);
 
if (iguais)
{
    printf("Valor retornado (linha 21): p+r=%d+%d/2 (%d)\n",p,r,(p+r)/2);
    return (p+r)/2;
}

printf("Valor retornado (linha 21): i+1=%d+1 (%d)\n",i,i+1);
return (i+1);

}

 void quickSort (int * A, int p, int r) { 

    int q;
    if (p < r)
    {
       q = particao(A, p, r);
       quickSort(A, p, q-1);
       quickSort(A, q+1, r);
    }

    for (int i = 0; i <= r; i++)
    {
        printf("%d,", A[i]);
    }
    printf("\n,");
 }

void imprime_a(int * a, int p, int r) {
  int i;
  int n = r-p+1;
  for(i = 0; i < n; ++i)
    printf(" %2d",i);
  printf("\n-");
  for(i = 0; i < n; ++i)
    printf("---");
    
  printf("\n|");
  for(i = p; i < r+1; ++i)
    printf("%2d|",a[i]);
    
  printf("\n");
  for(i = 0; i < n; ++i)
    printf("---");
  printf("-\n");
}

int main() {
  //int a[] ={2,8,7,1,3,5,6,4};
  int a[] ={13,19,9,5,12,8,7,4,11,2,6,21};
  //int a[] ={1,2,3,4,5,6,7,8,9,10,11,12};
  //int a[] ={12,11,10,9,8,7,6,5,4,3,2,1};
  //int a[] ={5,5,5,5,5,5,5,5,5,5,5,5};
  
  quickSort(a,0,11);
  //particao(a,0,11);
  /* particao(a,0,2);
  particao(a,4,7);
  particao(a,4,6);
  particao(a,0,1); */
  
  //imprime_a(a, 0, 7);
  return 0;
}