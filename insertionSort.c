#include <stdio.h>
#define MAX 50

// typedef struct 
//     {
//         int A[MAX];
//         int nroElem;
//     } LISTA; 

void insertionSort(int *n, int tamanho_array){
    
    for (int j = 1; j <= tamanho_array - 1; j++)
    {
        int chave = n[j];
        int i = j-1;
        while (n[i] > chave && i >= 0)
        {
            n[i + 1] = n[i];
            i = i - 1;
        }
        n[i + 1] = chave;
        
    }
}

int main(){

    int numeros[8] = {4,0,7,32,23,56,3,10};
    insertionSort(numeros,sizeof(numeros)/sizeof(int));
    for (int i = 0; i < sizeof(numeros)/sizeof(int);i++)
    {
        printf("%d,",numeros[i]);
    }

    return 0;
}