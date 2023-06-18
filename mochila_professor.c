/*********************************************************************/
/**   ACH2002 - Introducao à Análise de Algoritmos                  **/
/**   EACH-USP - Segundo Semestre de 2022                           **/
/**   Turma extra - Prof. Marcos Lordello Chaim                     **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                   **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <numero USP>          **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define true 1
#define false 0

typedef int boolean;


typedef struct {
  boolean exists;
  boolean belongs;
} celula_mochila;

/*
mochila() retorna uma matriz P[n+1,K+1] com as possíveis soluções para o problema da
mochila para um arranjo S de tamanho n e uma mochila de tamanho K.
P é uma matriz tal que P[i,j].exists = true, se existe uma solução para o
problema da mochila com os primeiros i
(0 <= i <= n) elementos e uma mochila de tamanho k (0 <= k <= K);
e P[i,j].belongs = true, se o i-ésimo elemento pertence à solução.

Parâmetros:
S: um arranjo de tamanho n que armazena os tamanhos dos itens.
n: tamanho do arranjo S
K: tamanho da mochila

Valor de retorno: ponteiro para a matriz P.

Observação: Os valores válidos para S, n e K são, respectivamente,
S != NULL, n > 0, K > 0. A função deve retornar NULL se os valores
de algum dos parâmetros não for válido.

Dica: não se esqueça de fazer uma cópia de S, chamada,  por exemplo,
S2, que inclui um item de tamanho 0 (zero). Por exemplo, se
S[] = {2,3,5,6}, S2 será S2 [] = {0,2,3,5,6}.
*/

celula_mochila ** mochila(int * S, int n, int K)
{
  int i, k;

  if(S == NULL || n <= 0 || K <= 0)
    return NULL;

  int * s = (int *) malloc((n+1)*sizeof(int));
  if(s == NULL)
    return NULL;

  s[0] = 0;
  for(i=1; i <= n; ++i)
    s[i] = S[i-1];

  // for(i=0; i <= n; ++i)
  //     printf("s[%d] = %d ",i, s[i]);
  // printf("\n");

  celula_mochila ** P = (celula_mochila **) malloc((n+1)*sizeof(celula_mochila *));
  if(P == NULL)
    return NULL;
  for(i = 0; i < n+1; ++i)
    {
      P[i] = (celula_mochila *) malloc((K+1)*sizeof(celula_mochila));
      if(P[i] == NULL) return NULL;
    }

  P[0][0].exists = true;

  for(k = 1; k <= K; k++)
    P[0][k].exists = false;

  for(i=1; i <= n; ++i)
    for(k = 0; k <= K; ++k)
    {
    P[i][k].exists = false;
    if(P[i-1][k].exists){
      P[i][k].exists = true;
      P[i][k].belongs = false;
      // printf("1:s[%d]=%d,%d:%d/",i,s[i],k,(P[i][k].exists)?1:0);
      // printf("%d  ",(P[i][k].belongs)?1:0);
      // printf("Digite um <enter> para continuar...");
      // getchar();
    }
    else
    {
    // printf("s[%d]=%d,%d\n",i,s[i],k);
    if(k-s[i] >= 0){
        //printf("1:s[%d]=%d,%d:%d/",i-1,s[i],k,(P[i-1][k].exists)?1:0);
        if(P[i-1][k-s[i]].exists){
         P[i][k].exists = true;
         P[i][k].belongs = true;
        }
      }
      // printf("2:s[%d]=%d,%d:%d/",i,s[i],k,(P[i][k].exists)?1:0);
      // printf("%d  ",(P[i][k].belongs)?1:0);
      // printf("Digite um <enter> para continuar...");
      // getchar();
    }
  }
return P;
}

/* selecionaItensMochila() percorre uma matriz P[n+1,K+1] com as
possíveis soluções para o problema da
mochila para um arranjo S de tamanho n e uma mochila de tamanho K e
adiciona a um arranjo recebido como parâmetro os itens que preenchem
completamente a mochila.

Parâmetros:
P: P[n+1,K+1] com as possíveis soluções para o problema da
mochila para um arranjo S de tamanho n e uma mochila de tamanho K.
itens: ponteiro para o arranjo que conterá os itens que preenchem
a mochila.
S: um arranjo de tamanho n que armazena os tamanhos dos itens.
n: tamanho do arranjo S
K: tamanho da mochila

Valor de retorno: nenhum, pois os valores desejados deverão ser incluídos
no arranjo itens passado como parâmetro.

*/

void selecionaItensMochila(int * itens, celula_mochila ** P, int *S, int n, int K) {
  int i, k;

  if(K <= 0)
    return;

  for(i = n; i >=0; i--) {
     if(P[i][K].exists && P[i][K].belongs)
        {
          *itens = S[i-1]; //o conjunto de S vai de 0 a 3, e n vai de 4 a 0. Por isso tem S[i-1] aqui 
          itens++;
          selecionaItensMochila(itens,P,S,n,K-S[i-1]);
          break;
        }
  }

}

/* imprimeMatrizP() foi criada para imprimir de forma "bonita"
a matriz P retornada pela função mochila().
*/

void imprimeMatrizP(celula_mochila ** p, int * s, int n, int K){
 int i,j;

  printf("\n   P   ");
  for(i=0; i < K+1; i++)
    printf("  %d  ",i);
  printf("\n");

  for(i=0; i < n+1; i++){
    if(i == 0)
      printf("k_0 = 0 ");
    else
      printf("k_%d =%2d ", i,s[i-1]);
    for(j=0; j < K+1; j++)
      {
      printf("%c/",(p[i][j].exists)?'T':'F');
      printf("%c  ",(p[i][j].belongs)?'T':'F');
      }
    printf("\n");
  }

}
/*
	função main criada apenas para seus testes.
  Os testes abaixo são apenas ilustrativos.
  A correção será realizada com testes diferentes.
	Voce deve adicionar novos testes que testem
  o mais completamente possível seu código.
	ESTA função SERA IGNORADA NA CORRECAO
*/

int main() {
int ** grf_dist;
int i, j, ini, fim, n = 7;
int noErros = 0, noTestes = 0;

// Prepara dados para testar a função mochila() e selecionaItensMochila()
noTestes++;
int r[] = {2,3,5,6}; // itens a serem possivelmente salvos na celula_mochila
int K = 9;
n = 4;
int itensmochila[] = {-1,-1,-1,-1};
celula_mochila ** p = mochila(r,n,K);

if(p != NULL)
  {
  imprimeMatrizP(p,r,n,K);
  selecionaItensMochila(itensmochila, p, r,n,K);

  printf("Itens mochila de tamanho 9: ");
  for(i=0; i < 4; ++i)
    if(itensmochila[i]!=-1)
      printf("%d ",itensmochila[i]);
  printf("\n");

  if(itensmochila[0] == 6 && itensmochila[1] == 3)
   {
     printf("Teste %d: OK\n", noTestes);
   }
   else {
     printf("Teste %d: NOK:", noTestes);
     printf("Itens mochila de tamanho 9: 6 3\n");
     noErros++;
   }
}
else {
  printf("Teste %d: NOK:", noTestes);
  printf("Itens mochila de tamanho 9: 6 3\n");
  noErros++;
}

noTestes++;
int s[] = {1,2,3,5,6}; // itens a serem possivelmente salvos na celula_mochila
K = 9;
n = 5;
int itensmochila2[] = {-1,-1,-1,-1,-1};
p = mochila(s,n,K);

if(p != NULL)
  {
  imprimeMatrizP(p,s,n,K);
  selecionaItensMochila(itensmochila2, p,s,n,K);
  printf("Itens mochila de tamanho 9: ");
  for(i=0; i < 5; ++i)
    if(itensmochila2[i]!=-1)
      printf("%d ",itensmochila2[i]);
  printf("\n");
  }
else {
  printf("Teste %d: NOK:", noTestes);
  printf("Itens mochila de tamanho 9: 5 3 1\n");
  noErros++;
}

noTestes++;
int itensmochila3[] = {-1,-1,-1,-1,-1};
if(p != NULL)
  {
  selecionaItensMochila(itensmochila3, p,s,n,7);
  printf("Itens mochila de tamanho 7: ");
  for(i=0; i < 5; ++i)
    if(itensmochila3[i]!=-1)
      printf("%d ",itensmochila3[i]);
  printf("\n");
}
else {
  printf("Teste %d: NOK:", noTestes);
  printf("Itens mochila de tamanho 7: 5 2\n");
  noErros++;
}
noTestes++;

int q[] = {1,2,5,6}; // itens a serem possivelmente salvos na celula_mochila
K = 7;
n = 4;
int itensmochila4[] = {-1,-1,-1,-1,-1};
p = mochila(q,n,K);
imprimeMatrizP(p,q,n,K);
if(p != NULL)
  {
  selecionaItensMochila(itensmochila4, p,q,n,K);
  printf("Itens mochila de tamanho 9kk: ");
  for(i=0; i < 5; ++i)
    if(itensmochila4[i]!=-1)
      printf("%d ",itensmochila4[i]);
  printf("\n");
}
else {
  printf("Teste %d: NOK:", noTestes);
  printf("Itens mochila de tamanho 9: 5 3 1\n");
  noErros++;
}


// Testa verificação dos parâmetros
 noTestes++;
 p = mochila(s,0,K);
 if(p==NULL)
   {
   printf("Teste %d: OK\n", noTestes);
   }
 else{
   printf("Teste %d: NOK:", noTestes);
   printf("p == NULL\n");
   noErros++;
   }

   noTestes++;
   p = mochila(NULL,5,K);
   if(p==NULL)
     {
     printf("Teste %d: OK\n", noTestes);
     }
   else{
     printf("Teste %d: NOK:", noTestes);
     printf("p == NULL\n");
     noErros++;
     }

     noTestes++;
     p = mochila(s,5,-1);
     if(p==NULL)
       {
       printf("Teste %d: OK\n", noTestes);
       }
     else{
       printf("Teste %d: NOK:", noTestes);
       printf("p == NULL\n");
       noErros++;
       }
}