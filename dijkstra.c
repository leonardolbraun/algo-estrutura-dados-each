#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int pertence(int * vec, int n, int x) { // recebe o conjunto de vértices, o número de vértices e um determinado vértice
 int j; //variável auxiliar

 for(j = 0; j < n; ++j) //percorre o número de vértices 
   if(vec[j] == x) // esse if irá verificar se o determinado vértice pertence ao conjunto de vértices
     {
       return 1;
     }
 return 0;
}

int remove_vertice(int * vec, int n, int x) { // recebe o conjunto de vértices, os vértices e o vértice com menor distância
 int i,j; //variáveis auxiliares
 i = 0;
 for(j = 0; j < n; ++j)
   if(vec[j] != x) // se o vértice do conjunto de vetores é diferente do vértice com a menor distância
     {
       vec[i] = vec[j]; // constrói um novo conjunto de vértices retirando o vértice com menor distância (x)
       ++i; //incrementa i
     }
 return i; //retorna o novo tamanho do conjunto de vértices sem o vértice com a menor distância (x)
}

int min_vertice_dist(int * d, int * q, int n){ // recebe as distancias de dist(v), conjunto de vértices q, e o número de vértices
  int i; // variável auxiliar
  int min = INT_MAX; // variável recenbe infinito
  int vmin = 0; // 

  for (i = 0; i < n; ++i)
    if(d[q[i]] < min) //se a distancia (d) do conjunto de vértices (q) vértice (i) for menor que infinito (min)
        {
          min = d[q[i]]; // min recebe a menor distancia entre os vértices disponíveis
          vmin = q[i]; // vmin recebe o vértice com menor distância
                      // importante destacar aqui que esse loop precisa atualizar a cada iteração
                      // o min vmin, para que assim encontre o vertice seguindo a estratégia gulosa.
        }

  return vmin; //retorna o vértice com menor distância
}

int dijkstra(int ** grf, int n, int s, int v_f) { 
  //grf = matriz 
  //n = Número de vértices
  //s = inicio -> home
  //v_f = final -> school
int * dist = (int *) malloc(sizeof(int)*n);
int * q = (int *) malloc(sizeof(int)*n);
int alt,v,u, qsize = n;

if(q == NULL || dist == NULL)
  return 0;

if(n <= 0)
  return 0;

//se o inicio for menor que 0, ou se inicio for maior que n-1 ou fim for menor que 0 ou maior que n-1
if((s < 0 || s > n-1) || (v_f < 0 || v_f > n-1))
  return 0;

//aqui a distancia do inicio é 0, pois é o primeiro vértice
dist[s] = 0;

//é necessário atribuir a distancia para cada vertice v
for(v=0; v < n; ++v)
  {
    if(s != v) //se o s (inicio) é diferente do vertice v
      dist[v] = INT_MAX; // distancia do vertice v receberá infinito (momento incial)
    q[v] = v;//conjunto q de vertices receberá o vertice atual do laço
  }



while(qsize > 0) { // qsize é o n ou o número de vértices, enquanto ainda houver vértices a serem visitados
  for(v=0; v < n; ++v) // Esse for irá percorrer vértice por vértice
    {
      if(pertence(q,qsize,v)) // Esse if faz uma chamada para função pertence passando o conjunto 
                              //de vértices, o número de vértices e o vértice que esá sendo analisado.
                              //
        printf("dist[%d] = %d ", v, dist[v]); // se pertencer irá imprimir a distância do vértice
                                              // na primeira vez apenas o home terá distância 0, os outros
                                              // terão distância infinita
    }

  printf("\nqsize = %d\n", qsize); // o número de vértices
  printf("Digite um caracter para continuar...");
  getchar();
  v = min_vertice_dist(dist, q, qsize); // atribui a v o vértice com menor distância
  qsize = remove_vertice(q,qsize,v); // subtrai o vértice com a menor distância do tamanho de vértices
  printf("v = %d; qsize = %d\n", v,qsize); // imprime o vértice com menor distância e o tamnho de vértices
  
  //Imprime os vértices restantes após cada while
  for(int i = 0; i < qsize; ++i)
    printf("q[%d] = %d ", i, q[i]);
  printf("\n");


  for(u = 0; u < n; ++u) {
    if(grf[v][u] != INT_MAX) { //se a distancia entre os vértices v e u forem diferentes de infinito
    alt = dist[v]+grf[v][u]; // alt recebe a distnacia do vértice + a distância entre os vértices v e u
    printf("dist[%d] = %d; grf[%d][%d] = %d; alt = %d\n",v,dist[v], v,u, grf[v][u], alt); 
    if (alt < dist[u]) // se alt form menor que distancia do vértice u
        dist[u] = alt; // distância de u recebe alt
    printf("dist[%d] = %d;\n",u,dist[u]);
    }
 }
}
printf("valor de u: %d\n",u);
return dist[v_f];
}

int main() {
int ** grf_dist; //cria um ponteiro para um array de ponteiros
int i, j, ini, fim, n = 8; //variáveis para os laços, inicio e fim e o tamanho de vértices (0(home) a 7(school))

grf_dist = (int **) malloc(n*sizeof(int *)); // aloca espaço em memória para grf_dist
for(i = 0; i < n; ++i) {
  grf_dist[i] = (int *) malloc(n*sizeof(int)); // aloca espaço para os 8 vértices do vetor
}

for(i = 0; i < n; ++i)
  for(j = 0; j < n; ++j)
    grf_dist[i][j] = INT_MAX; // Esses for aninhados preenchem todos vértices com infinito.
                              // Abaixo são atribuídos os custos para cada caminho entre os vértices.

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
ini = 0; fim = 7; //Aqui começa em Home (0) e termina em Fim (7)
printf("Distância menor de %d a %d: %d\n", ini, fim, dijkstra(grf_dist,n,ini,fim));
// ini = 0; fim = 5;
// printf("Distância menor de %d a %d: %d\n", ini, fim, dijkstra(grf_dist,n,ini,fim));
// ini = 0; fim = 4;
// printf("Distância menor de %d a %d: %d\n", ini, fim, dijkstra(grf_dist,n,ini,fim));

}