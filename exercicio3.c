#include <stdio.h>
#include <malloc.h>

typedef struct aux
{
    int id;
    struct aux* mae;
    struct aux* pai;
} PESSOA;

PESSOA* inicializar (int id){
    
    PESSOA* pessoa = (PESSOA*)malloc(sizeof(PESSOA*));
    printf("Memoria necessaria: %i\n",sizeof(PESSOA*));
    pessoa->id = id;
    pessoa->mae = NULL;
    pessoa->pai = NULL;
    return pessoa;
    
/* 
    O código abaixo não funciona pois a alocação de memória é local e e destruída após a execução da função.
    VER: https://www.educative.io/answers/resolving-the-function-returns-address-of-local-variable-error
    VER: https://stackoverflow.com/questions/4911288/allocate-struct-from-function-in-c
    É necessário utilizar o malloc para alocar memória para a estrutura.

    PESSOA pessoa;
    pessoa.id = id;
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    return &pessoa;
*/
}

void registrar (PESSOA* filho, PESSOA* mae, PESSOA* pai){

    filho->mae = mae;
    filho->pai = pai;

}

int main(){

    PESSOA* m = inicializar(1);
    PESSOA* p = inicializar(2);
    PESSOA* f = inicializar(3);

    registrar(f,m,p);

    printf("Filho: %p  Mae: %p  Pai: %p\n", f, f->mae, f->pai);

    return 0;

}