#include <stdio.h>
#include <malloc.h>
#define true 1
#define false 0

typedef enum{esquerdo, direito} LADO;

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux
{
    TIPOCHAVE chave;
    struct aux *esq, *dir;
} NO;

typedef NO* PONT;

PONT buscarChave(TIPOCHAVE ch, PONT raiz){
    if (raiz == NULL) return NULL;
    if (raiz->chave == ch) return raiz;
    PONT aux = buscarChave(ch,raiz->esq);
    if (aux) return aux;
    return buscarChave(ch,raiz->dir);
}

PONT criarNovoNo(TIPOCHAVE ch){
    PONT novoNo = (PONT) malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return novoNo;
}

void criarRaiz(PONT* raiz, TIPOCHAVE chave){
    *raiz = criarNovoNo(chave);
    // printf("Endereco: %d \n",*raiz);
    // printf("Chave: %d \n", (*raiz)->chave);
}

bool inserirFilho(PONT* raiz, TIPOCHAVE novaChave, TIPOCHAVE chavePai, LADO lado){
    PONT pai = buscarChave(chavePai, *raiz);
    if (!pai) return false;
    PONT novo = criarNovoNo(novaChave);
    if(lado == esquerdo){
        novo->esq = pai->esq;
        pai->esq = novo;
    } else{
        novo->dir = pai->dir;
        pai->dir = novo;
    }
    return true;
}

int alturaArvore(PONT raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        int alturaEsq = alturaArvore(raiz->esq);
        int alturaDir = alturaArvore(raiz->dir);
        if (alturaEsq > alturaDir) {
            return alturaEsq + 1;
        } else {
            return alturaDir + 1;
        }
    }
}

void imprimirProfundidade(PONT raiz, int profundidade) {
    if (raiz != NULL) {
        printf("Chave: %d, Profundidade: %d\n", raiz->chave, profundidade);
        imprimirProfundidade(raiz->esq, profundidade + 1);
        imprimirProfundidade(raiz->dir, profundidade + 1);
    }
}

void imprimirNivel(PONT raiz, int nivelAtual, int nivelDesejado) {
    if (raiz != NULL) {
        if (nivelAtual == nivelDesejado) {
            printf("%d ", raiz->chave);
        } else {
            imprimirNivel(raiz->esq, nivelAtual + 1, nivelDesejado);
            imprimirNivel(raiz->dir, nivelAtual + 1, nivelDesejado);
        }
    }
}

void imprimirArvore(PONT raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esq);
        printf("%d ", raiz->chave);
        imprimirArvore(raiz->dir);
    }
}

void imprimirArvoreVisual(PONT raiz, int espaco) {
    // Aumentando a distância entre níveis
    int cont;
    if (raiz == NULL)
        return;
    
    // Aumenta a distância entre níveis
    espaco += 10;
    
    // Processa o nó direito primeiro (isto faz a árvore ser exibida "deitada", com a raiz à esquerda)
    imprimirArvoreVisual(raiz->dir, espaco);
    
    // Imprime o nó atual. O espaço depende do nível do nó.
    printf("\n");
    for (cont = 10; cont < espaco; cont++)
        printf(" ");
    printf("%d\n", raiz->chave);
    
    // Processa o nó esquerdo
    imprimirArvoreVisual(raiz->esq, espaco);
}

int main(){

    PONT raiz = NULL; 
    
    criarRaiz(&raiz,43);
    inserirFilho(&raiz, 25, 43, esquerdo);
    inserirFilho(&raiz, 50, 43, direito);
    inserirFilho(&raiz, 20, 43, esquerdo);
    inserirFilho(&raiz, 27, 43, esquerdo);
    inserirFilho(&raiz, 42, 43, direito);

    imprimirArvore(raiz);
    printf("\n");

    printf("Altura da arvore: %d\n", alturaArvore(raiz));

    int nivelDesejado = 2;
    printf("Nodos no nivel %d: ", nivelDesejado);
    imprimirNivel(raiz, 1, nivelDesejado);
    printf("\n");

    imprimirProfundidade(raiz, 0);
    printf("\n");

    imprimirArvoreVisual(raiz, 0);

    return 0;
};