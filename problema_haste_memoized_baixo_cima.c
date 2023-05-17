#include <stdio.h>
#include <math.h>

double max(double a, double b) {
    return (a > b) ? a : b;
}

double memoized_cut_rod(double *preco, int haste) {
    
    double r[haste + 1], q;

    r[0] = 0;  
    
    for (size_t j = 0; j <= haste; j++)
    {
        q = -INFINITY;
        for (size_t i = 0; i <= j; i++)
        {
            q = max(q,preco[i-1] + r[j-i]);
        }
    }
}

int main() {
    double preco[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int haste = 4;
    printf("Receita (r): %.2f\n", memoized_cut_rod(preco, haste));
    
    return 0;
}