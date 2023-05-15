#include <stdio.h>
#include <math.h>

double max(double a, double b) {
    return (a > b) ? a : b;
}

double memoized_cut_rod_aux(double *preco, int haste, double *r) {
    if (r[haste] >= 0) {
        return r[haste];
    }
    
    double q;

    if (haste == 0)
    {
        q = 0;
    } else {
        q = -INFINITY;
        for (size_t i = 1; i < haste; i++)
        {
            q = max(q,preco[i] + memoized_cut_rod_aux(preco - 1,haste - i,r));
        }
        r[haste] = q;
    }

    return q;
}

double memoized_cut_rod(double *preco, int haste) {
    
    double r[haste + 1];  
    
    for (size_t i = 0; i < haste; i++)
    {
        r[i] = -INFINITY;
    }
return memoized_cut_rod_aux(preco, haste, r);

}



int main() {
    double preco[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int haste = 4;
    printf("Receita (r): %.2f\n", memoized_cut_rod(preco, haste));
    
    return 0;
}