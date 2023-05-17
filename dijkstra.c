#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int pertence(int * vec, int n, int x) {
 int j;

 for(j = 0; j < n; ++j)
   if(vec[j] == x)
     {
       return 1;
     }
 return 0;
}

int remove_vertice(int * vec, int n, int x) {
 int i,j;
 i = 0;
 for(j = 0; j < n; ++j)
   if(vec[j] != x)
     {
       vec[i] = vec[j];
       ++i;
     }
 return i;
}

int min_vertice_dist(int * d, int * q, int n){
  int i;
  int min = INT_MAX;
  int vmin = 0;

  for (i = 0; i < n; ++i)
    if(d[q[i]] < min)
        {
          min = d[q[i]];
          vmin = q[i];
        }

  return vmin;
}

int dijkstra(int ** grf, int n, int s, int v_f) {
int * dist = (int *) malloc(sizeof(int)*n);
int * q = (int *) malloc(sizeof(int)*n);
int alt,v,u, qsize = n;

if(q == NULL || dist == NULL)
  return 0;

if(n <= 0)
  return 0;

if((s < 0 || s > n-1) || (v_f < 0 || v_f > n-1))
  return 0;

dist[s] = 0;

for(v=0; v < n; ++v)
  {
    if(s != v)
      dist[v] = INT_MAX;
    q[v] = v;
  }



while(qsize > 0) {
  for(v=0; v < n; ++v)
    {
      if(pertence(q,qsize,v))
        printf("dist[%d] = %d ", v, dist[v]);
    }
  printf("\nqsize = %d\n", qsize);
  printf("Digite um caracter para continuar...");
  getchar();
  v = min_vertice_dist(dist, q, qsize);
  qsize = remove_vertice(q,qsize,v);
  printf("v = %d; qsize = %d\n", v,qsize);
  for(int i = 0; i < qsize; ++i)
    printf("q[%d] = %d ", i, q[i]);
  printf("\n");

  for(u = 0; u < n; ++u) {
    if(grf[v][u] != INT_MAX) {
    alt = dist[v]+grf[v][u];
    printf("dist[%d] = %d; grf[%d][%d] = %d; alt = %d\n",v,dist[v], v,u, grf[v][u], alt);
    if (alt < dist[u])
        dist[u] = alt;
    printf("dist[%d] = %d;\n",u,dist[u]);
    }
 }
}
printf("valor de u: %d\n",u);
return dist[v_f];
}

int main() {
int ** grf_dist;
int i, j, ini, fim, n = 8;

grf_dist = (int **) malloc(n*sizeof(int *));
for(i = 0; i < n; ++i) {
  grf_dist[i] = (int *) malloc(n*sizeof(int));
}

for(i = 0; i < n; ++i)
  for(j = 0; j < n; ++j)
    grf_dist[i][j] = INT_MAX;

// grf_dist[0][1] = 6;
// grf_dist[0][2] = 8;
// grf_dist[0][3] = 7;
// grf_dist[1][3] = 100;
// grf_dist[1][4] = 99;
// grf_dist[2][5] = 1;
// grf_dist[3][2] = 200;
// grf_dist[3][4] = 400;
// grf_dist[3][5] = 500;
// grf_dist[4][6] = 200;
// grf_dist[5][4] = 600;
// grf_dist[5][6] = 1;

// Home (0), A(1), B(2), C(3), D(4), E(5), F(6), School (7)
grf_dist[0][1] = 3; // Home -> A
grf_dist[0][2] = 2; // Home -> B
grf_dist[0][3] = 5; // Home -> C
grf_dist[1][4] = 3; // A -> D
grf_dist[4][2] = 1; // D -> B
grf_dist[4][6] = 4; // D -> F
grf_dist[2][5] = 6; // B -> E
grf_dist[2][4] = 1; // B -> D
grf_dist[3][5] = 2; // C -> E
grf_dist[5][6] = 1; // E -> F
grf_dist[6][7] = 2; // F -> School
grf_dist[5][7] = 4; // E -> School



// for(i = 0; i < n; ++i)
//   {
//     for(j = 0; j < n; ++j)
//       printf("grf_dist[%d][%d] = %d ", i, j, grf_dist[i][j]);
//     printf("\n");
//    }
ini = 0; fim = 7;
printf("Distância menor de %d a %d: %d\n", ini, fim, dijkstra(grf_dist,n,ini,fim));
// ini = 0; fim = 5;
// printf("Distância menor de %d a %d: %d\n", ini, fim, dijkstra(grf_dist,n,ini,fim));
// ini = 0; fim = 4;
// printf("Distância menor de %d a %d: %d\n", ini, fim, dijkstra(grf_dist,n,ini,fim));

}