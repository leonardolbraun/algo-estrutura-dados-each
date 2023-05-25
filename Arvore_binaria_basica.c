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

void imprimirArvore(PONT raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esq);
        printf("%d ", raiz->chave);
        imprimirArvore(raiz->dir);
    }
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

    return 0;
};
