/*Código qualquer para testar o comando git init*/
/*cópia do códgio de AED da EACH*/


#include <stdio.h>
#include <malloc.h>

#define false 0
#define true 1

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef struct {
    ELEMENTO* cabeca;
} LISTA;

void inicializaLista(LISTA* l){
    l->cabeca = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    l->cabeca->prox = l->cabeca;
}

int tamanho(LISTA* l){
    ELEMENTO* atual = l->cabeca->prox;
    int tam = 0;
    while (atual != l->cabeca){
        tam++;
        atual = atual->prox;
    }
    return tam;
}

void exibirLista(LISTA* l){
    ELEMENTO* atual = l->cabeca->prox;
    printf("Lista: \"");
    while (atual != l->cabeca){
        printf("%i ", atual->reg.chave);
        atual = atual->prox;
    }
    printf("\"\n");
}

ELEMENTO* buscarElemComSentinela(LISTA* l, TIPOCHAVE ch){
    ELEMENTO* atual = l->cabeca->prox;
    l->cabeca->reg.chave = ch;
    while(atual->reg.chave != ch) atual = atual->prox;
    if(atual != l->cabeca) return atual;
    return NULL;
}

ELEMENTO* buscaAuxiliarLista(LISTA* l, TIPOCHAVE ch, ELEMENTO** ant){
    *ant = l->cabeca;
    ELEMENTO* atual = l->cabeca->prox;
    l->cabeca->prox = ch;
    while(atual->reg.chave < ch){
        *ant = atual;
        atual = atual->prox;
    }
    if(atual != l->cabeca && atual->reg.chave == ch) return atual;
    return NULL;
}


bool inserirElemListaOrd(LISTA* l, REGISTRO reg){
    ELEMENTO* ant;
    ELEMENTO* atual;
    atual = buscaAuxiliar(l, reg.chave, &ant);
    //achou um elemento igual
    if(atual != NULL) return false;
    //se não achou um elemento igual, então:
    atual = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    atual->reg = reg;
    atual->prox = ant->prox;
    ant->prox = atual;
    return true;
}

bool excluiElem(LISTA* l, TIPOCHAVE ch){
    ELEMENTO* ant;
    ELEMENTO* atual;
    atual = buscaAuxiliar(l, ch, &ant);
    if(atual == NULL) return false;
    ant->prox = atual->prox;
    free(atual);
    return true;
}

void reinicializarLista(LISTA* l){
    ELEMENTO* atual = l->cabeca->prox;
    while(atual != l->cabeca){
        ELEMENTO* apagar = atual;
        atual = atual->prox;
        free(apagar);
    }
    l->cabeca->prox = l->cabeca;
}

void funcaoQualquer(LISTA* l){
    /*função só para ter uma alteração para commitar*/

    /*uma alteração qualquer para usar o rebase*/
}

int main(){
    LISTA l;
    inicializaLista(&l);
}