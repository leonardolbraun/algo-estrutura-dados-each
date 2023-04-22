#include <stdio.h>
//Escreva um algoritmo para obter o maior e o segundo maior elemento de um arranjo. 
// Apresente também a análise desse algoritmo (função de complexidade). VocÊ acha o 
//algoritmo do seu método eficiente? Por quÊ? Procure comprovar as suas respostas.

int* maiores(int *n, int tamanho_array){
    static int numeros[2] = {0,0};
    for (int j = 0; j <= tamanho_array - 1; j++)
    {
        if (n[j] > numeros[0])
        {
            numeros[1] = numeros[0];
            numeros[0] = n[j];
        } else if (n[j] > numeros[1])
        {
            numeros[1] = n[j];
        }      
    }
    return numeros;
}

int main(){

    int numeros[20] = {84,0,7,32,23,56,3,10,435,8678,234234,3,5,67,97,443,234,56,9,97};
    int *numeros_maiores = maiores(numeros,sizeof(numeros)/sizeof(int));
    printf("Os maiores números são: \n");
    for (int i = 0; i <= 1;i++)
    {
        printf("[%d]: [%d] \n",i+1,numeros_maiores[i]);
    }
    return 0;
}

// Análise de complexidade:

// O algoritmo percorre o arranjo uma única vez, comparando cada elemento com o maior 
// e o segundo maior elementos encontrados até o momento. Portanto, a complexidade do 
// algoritmo é O(n), onde n é o tamanho do arranjo.

// Considero o algoritmo eficiente, já que ele percorre o arranjo apenas uma vez e 
// não requer o uso de estruturas de dados complexas, como árvores ou pilhas, para 
// armazenar os elementos e realizar a comparação. No entanto, é importante lembrar 
// que, dependendo do tamanho do arranjo, a diferença entre a complexidade O(n) deste 
// algoritmo e a complexidade de algoritmos mais sofisticados pode ser significativa em 
// termos de tempo de execução. Portanto, em alguns casos, pode ser necessário usar 
// algoritmos mais complexos para obter um desempenho melhor.