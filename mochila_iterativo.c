#include <stdio.h>

// Retorna o máximo de dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Retorna o valor máximo que pode ser colocado na mochila
int mochila(int capacidade_mochila_W, int qtde_itens_n,int * peso_itens, int * valor_itens ){
    int itens_i, peso_corrente_mochila_w;
    int solucoes_possiveis_K[qtde_itens_n+1][capacidade_mochila_W+1]; // matriz que irá armazenar as soluções
    
    // Construir a tabela K[][] de baixo pra cima (bottom up)
    for (itens_i = 0; itens_i <= qtde_itens_n; itens_i++)
    {
        for (peso_corrente_mochila_w = 0; peso_corrente_mochila_w <= capacidade_mochila_W; peso_corrente_mochila_w++)
        {
            if (itens_i == 0 || peso_corrente_mochila_w == 0)
            {
                solucoes_possiveis_K[itens_i][peso_corrente_mochila_w] = 0;
            } else if (peso_itens[itens_i-1] <= peso_corrente_mochila_w)
            {
                solucoes_possiveis_K[itens_i][peso_corrente_mochila_w] = max(valor_itens[itens_i - 1] 
                + solucoes_possiveis_K[itens_i - 1][peso_corrente_mochila_w-peso_itens[itens_i - 1]], 
                solucoes_possiveis_K[itens_i - 1][peso_corrente_mochila_w]);
            } else {
                solucoes_possiveis_K[itens_i][peso_corrente_mochila_w] = solucoes_possiveis_K[itens_i - 1][peso_corrente_mochila_w];
            }
            
            
        }
        
    }


    return solucoes_possiveis_K[qtde_itens_n][capacidade_mochila_W];
}

int main(){

    int val[] = {60, 100, 120, 5, 200};
    int wt[] = {10, 20, 30, 35, 15};
    int  W = 45;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d \n", mochila(W, n, wt, val));
    return 0;
}