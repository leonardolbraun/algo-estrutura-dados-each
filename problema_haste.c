#include <stdio.h>
#include <math.h>

double max(double a, double b) {
    return (a > b) ? a : b;
}

double cut_rod(double *preco, int haste) {
    if (haste == 0) {
        return 0;
    }
    double q = -INFINITY;  // Inicialize q com um valor negativo para comparar corretamente
    for (int i = 1; i <= haste; i++) {
        q = max(q, preco[i] + cut_rod(preco, haste - i));
    }
    return q;
}

int main() {
    double preco[] = {1, 5, 8, 9};
    int haste = 4;
    printf("Receita (r): %.2f\n", cut_rod(preco, haste));
    return 0;
}