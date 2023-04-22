#include <stdio.h>
#include <stdlib.h>


void merge(int *A,int p,int q,int r){
    int i, j, k;
    int tamseq1 = q - p + 1;
    int tamseq2 = r - q;
    int* seq1 = (int *)malloc(tamseq1*sizeof(int));

    for (i = 0; i < tamseq1; i++)
    {
        seq1[i] = A[p+i];
    }
    
    int* seq2 = (int *)malloc(tamseq2*sizeof(int));

    for (j = 0; j < tamseq2; j++)
    {
        seq2[j] = A[q+j+1];
    }
    //Faz a junção das duas subsequências
    k = p; i = 0; j = 0;
    while (i < tamseq1 && j < tamseq2)
    {
        if(seq2[j] <= seq1[i])
        {
            A[k] = seq2[j];
            j++;
        } else {
            A[k] = seq1[i];
            i++;
        }
        k++;
    }
    //Completa com a sequência que ainda não acabou
    while (i < tamseq1)
    {
        A[k] = seq1[i];
        k++;
        i++;
    }
    while (j < tamseq2)
    {
        A[k] = seq2[j];
        k++;
        j++;
    }
}


void mergeSort(int *n, int p, int r){

    int q;
    if(p < r){
        //divisão
        q = (p+r)/2;

        //conquista
        mergeSort(n,p,q);
        mergeSort(n,q+1,r);

        //combinação
        merge(n,p,q,r);
    }
}

int main(){

    int numeros[20] = {4,0,7,32,23,56,3,10,89,76,56,98,45,34,23,65,8,1,3,76};
    mergeSort(numeros,0,19);
    for (int i = 0; i < sizeof(numeros)/sizeof(int);i++)
    {
        printf("%d,",numeros[i]);
    }

    return 0;
}