#include <stdio.h>

// Retorna o máximo de dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Retorna o valor máximo que pode ser colocado na mochila
int mochila(int capacidade_mochila_W, int qtde_itens_n,int * peso_itens, int * valor_itens ){
   
    // Caso base
    if (qtde_itens_n == 0 || capacidade_mochila_W == 0)
    return 0;
    

    // Se o peso do n-ésimo item for mais do que a capacidade W, então
    // esse item não pode ser incluído na solução ótima
    if (peso_itens[qtde_itens_n - 1] > capacidade_mochila_W)
        return mochila(capacidade_mochila_W, qtde_itens_n - 1, peso_itens, valor_itens);
    
    // Retorne o máximo de duas situações:
    // (1) n-ésimo item incluído
    // (2) não incluído
    else
        return max(valor_itens[qtde_itens_n - 1] + 
        mochila(capacidade_mochila_W - peso_itens[qtde_itens_n - 1], qtde_itens_n - 1,peso_itens, valor_itens), 
        mochila(capacidade_mochila_W, qtde_itens_n - 1, peso_itens, valor_itens));
}

int main(){

    int val[] = {60, 100, 120, 5, 200};
    int wt[] = {10, 20, 30, 35, 15};
    int  W = 45;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d \n", mochila(W, n, wt, val));
    return 0;
}