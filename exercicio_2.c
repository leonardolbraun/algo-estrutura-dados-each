#include <stdio.h>

int somar(int n[], int tamanho_array){
    // int soma = 0;
    // for (int i = 0; i < tamanho_array; i++)
    // {
    //     printf("%d,",n[i]);
    //     soma = soma + n[i]; 
    // }
    if(tamanho_array == 0)
    {
        return 0;
    } else if (n[tamanho_array - 1] > 0)
    {
        return n[tamanho_array - 1] + somar(n,tamanho_array - 1);
    } else 
    {
        return somar(n,tamanho_array - 1); 
    }
}

int main(){

    int numeros[8] = {4,0,7,32,23,56,-3,10};
    int soma = somar(numeros,sizeof(numeros)/sizeof(int));
    printf("soma: %d", soma);
    return 0;
}