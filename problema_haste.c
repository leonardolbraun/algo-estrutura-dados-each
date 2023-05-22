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
    for (int cut = 1; cut <= haste; cut++) { // Cut é o tamnho do corta da haste
        q = max(q, preco[cut-1] + cut_rod(preco, haste - cut));
    }
    return q;
}

void imprimir_arvore_recursiva(double *preco, int haste, int nivel) {
    if (haste == 0) {
        for (int i = 0; i < nivel; i++) {
            printf("  ");  // Espaços para indentação
        }
        printf("-> [Folha]\n");
        return;
    }

    for (int i = 1; i <= haste; i++) {
        for (int j = 0; j < nivel; j++) {
            printf("  ");  // Espaços para indentação
        }
        printf("-> Corte de tamanho %d (Valor: %.2f)\n", i, preco[i - 1]);
        imprimir_arvore_recursiva(preco, haste - i, nivel + 1);
    }
}

int main() {
    double preco[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int haste = 4;
    printf("Receita (r): %.2f\n", cut_rod(preco, haste));
    
    printf("Árvore Recursiva:\n");
    imprimir_arvore_recursiva(preco, haste, 0);
    
    return 0;
}