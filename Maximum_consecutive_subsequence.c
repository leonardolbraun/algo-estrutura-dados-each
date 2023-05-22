#include <stdio.h>
/*
Maber pág. 106 - 5.8 - Finding the Maximum Consecutive Subsequence

encontrarSubsequenciaMaxima (subMaxArray()) é uma função iterativa que retorna o valor da soma dos
elementos da  subsequência máxima de um outro arranjo chamado arr (x).
Além disso, retorna por referência os arranjos com a subsequência
máxima e o sufixo máximo.

Parâmetros:
arr (x) : o ponteiro para o arranjo para o qual será determinada a subsequência máxima;
size (n) : tamanho de x;
sufixoMaxArray (sfmarray) : ponteiro para o arranjo com os elementos que formam o sufixo máximo;
tamanhoSufixoMax (nsfm) : ponteiro para a variável que contém o tamanho de sufixoMaxArray (sfmarray);
subsequenciaMaximaArray (gbmarray) : ponteiro para o arranjo com os elementos que formam a subsequência máxima;
tamanhoSubsequenciaMaxima (ngbm) : ponteiro para a variável que contém o tamanho de subsequenciaMaximaArray (gbmarray).

Valor de retorno: soma da subsequência máxima.

*/
double encontrarSubsequenciaMaxima(double *arr, int size, double *sufixoMaxArray, int *tamanhoSufixoMax,
                                  double *subsequenciaMaximaArray, int *tamanhoSubsequenciaMaxima) {
    double globalMaximo = 0, sufixoMaximo = 0;
    *tamanhoSufixoMax = 0;
    *tamanhoSubsequenciaMaxima = 0;

    for (int i = 0; i < size; i++) {
        printf("Sufixo máximo: %.2f, Global máximo: %.2f, arr[%d]: %.2f\n", sufixoMaximo, globalMaximo, i, arr[i]);
        printf("Digite um caractere para continuar...");
        getchar();

        if (arr[i] + sufixoMaximo > globalMaximo) {
            sufixoMaximo = arr[i] + sufixoMaximo;
            sufixoMaxArray[*tamanhoSufixoMax] = arr[i];
            (*tamanhoSufixoMax)++;
            globalMaximo = sufixoMaximo;

            for (int j = 0; j < *tamanhoSufixoMax; ++j) {
                subsequenciaMaximaArray[j] = sufixoMaxArray[j];
            }
            *tamanhoSubsequenciaMaxima = *tamanhoSufixoMax;

            printf("Novo global máximo == sufixo máximo: [");
            for (int i = 0; i < *tamanhoSufixoMax; ++i) {
                printf("%.2f ", sufixoMaxArray[i]);
            }
            printf("]\n");
        } else {
            if (arr[i] + sufixoMaximo > 0) {
                sufixoMaximo = arr[i] + sufixoMaximo;
                sufixoMaxArray[*tamanhoSufixoMax] = arr[i];
                (*tamanhoSufixoMax)++;

                printf("Novo sufixo máximo: [");
                for (int i = 0; i < *tamanhoSufixoMax; ++i) {
                    printf("%.2f ", sufixoMaxArray[i]);
                }
                printf("]\n");

                printf("Global máximo: [");
                for (int i = 0; i < *tamanhoSubsequenciaMaxima; ++i) {
                    printf("%.2f ", subsequenciaMaximaArray[i]);
                }
                printf("]\n");
            } else {
                sufixoMaximo = 0;
                *tamanhoSufixoMax = 0;
                printf("Novo global máximo == sufixo máximo: []\n");
            }
        }
    }
    return globalMaximo;
}

double encontrarSubsequenciaMaximaSemArray(double *arr, int size) {
    double globalMaximo = 0, sufixoMaximo = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] + sufixoMaximo > globalMaximo) {
            sufixoMaximo = arr[i] + sufixoMaximo;
            globalMaximo = sufixoMaximo;
        } else {
            if (arr[i] + sufixoMaximo > 0) {
                sufixoMaximo = arr[i] + sufixoMaximo;
            } else {
                sufixoMaximo = 0;
            }
        }
    }
    return globalMaximo;
}

int main() {
    double arrayA[] = {2, -3, 1.5, -1, 3, -2, -3, -3, 8};
    double arrayB[] = {2, -3, 5, -1, 3, -2, 13, 3};
    double arrayC[] = {-2, -3, 5, -1, -3, 2, -3, -3};

    double globalMaximo, sufixoMaximo;
    double subsequenciaMaximaArray[9], sufixoMaxArray[9];
    int tamanhoSubsequenciaMaxima, tamanhoSufixoMax;

    printf("Vetor: [");
    for (int i = 0; i < 9; ++i) {
        printf("%3.2f ", arrayA[i]);
    }
    printf("]\n");

    printf("Global máximo (Sem Array): %3.2f\n", encontrarSubsequenciaMaximaSemArray(arrayA, 9));

    globalMaximo = encontrarSubsequenciaMaxima(arrayA, 9, sufixoMaxArray, &tamanhoSufixoMax,
                                               subsequenciaMaximaArray, &tamanhoSubsequenciaMaxima);

    printf("Subsequência Máxima:\n");
    printf("Global máximo: %3.2f\n", globalMaximo);
    printf("Sufixo máximo: %3.2f\n", sufixoMaximo);
    printf("Subsequência máxima correta: [ ");
    for (int i = 0; i < tamanhoSubsequenciaMaxima; ++i) {
        printf("%3.2f ", subsequenciaMaximaArray[i]);
    }
    printf("]\n");

    return 0;
}