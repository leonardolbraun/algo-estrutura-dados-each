#include <stdio.h>

double max(double a, double b) {
    return (a > b) ? a : b;
}

double encontrarSubsequenciaMaximaRecursiva(double *arr, int inicio, int fim) {
    if (inicio == fim) {
        if (arr[inicio] > 0) {
            return arr[inicio];
        } else {
            return 0;
        }
    }

    int meio = (inicio + fim) / 2;

    double maxEsquerda = encontrarSubsequenciaMaximaRecursiva(arr, inicio, meio);
    double maxDireita = encontrarSubsequenciaMaximaRecursiva(arr, meio + 1, fim);

    double maxDosDoisLados = 0;
    double sum = 0;
    double sumMaxEsquerda = 0;
    double sumMaxDireita = 0;

    for (int i = meio; i >= inicio; i--) {
        sum += arr[i];
        if (sum > sumMaxEsquerda) {
            sumMaxEsquerda = sum;
        }
    }

    sum = 0;

    for (int i = meio + 1; i <= fim; i++) {
        sum += arr[i];
        if (sum > sumMaxDireita) {
            sumMaxDireita = sum;
        }
    }

    maxDosDoisLados = sumMaxEsquerda + sumMaxDireita;

    return max(max(maxEsquerda, maxDireita), maxDosDoisLados);

    // double maxSubsequencia = maxEsquerda;

    // if (maxDireita > maxSubsequencia) {
    //     maxSubsequencia = maxDireita;
    // }

    // if (maxDosDoisLados > maxSubsequencia) {
    //     maxSubsequencia = maxDosDoisLados;
    // }

    // return maxSubsequencia;
}

int main() {
    double arrayA[] = {2, -3, 1.5, -1, 3, -2, -3, -3};
    double arrayB[] = {2, -3, 5, -1, 3, -2, 13, 3};
    double arrayC[] = {-2, -3, 5, -1, -3, 2, -3, -3};

    int tamanhoArrayA = sizeof(arrayA) / sizeof(arrayA[0]);
    // int tamanhoArrayB = sizeof(arrayB) / sizeof(arrayB[0]);
    // int tamanhoArrayC = sizeof(arrayC) / sizeof(arrayC[0]);

    printf("Vetor A: [");
    for (int i = 0; i < tamanhoArrayA; ++i) {
        printf("%3.2f ", arrayA[i]);
    }
    printf("]\n");

    printf("Subsequência máxima (Recursiva): %3.2f\n", encontrarSubsequenciaMaximaRecursiva(arrayA, 0, tamanhoArrayA - 1));


    return 0;
}