/**
*Autor: Vinicius Aires Barros
*Estrutura de Dados
*Lista Simplesmente Encadeada
*/
#include "ListaSimplesmenteEncadeada.h"

bool listaVazia(lista l){
    return (l.inicio == NULL) ? true : false;
}

void iniciarLista(lista *l){
    l->inicio = l->fim = NULL;
}

no *getNo(int x){
    no *novo = (no*)malloc(sizeof(no));
    if(novo != NULL){
        novo->prox = NULL;
        novo->valor = x;
    }
    return novo;
}

void inserirInicio(lista *l , no *n){
    n->prox = l->inicio;
    l->inicio = n;
}

void inserirFim(lista *l, no *n){
    l->fim->prox = n;
    l->fim = n;
}

void inserirMeio(no *ant, no *n){
    no *buffer = ant->prox;
    ant->prox = n;
    n->prox = buffer;
}

void inserir(lista *l, int x){
    no *novo = getNo(x);
    if(novo != NULL){
        if(listaVazia(*l))
            l->inicio = l->fim = novo;
        else
            inserirFim(l, novo);
    }
}

void inserirListaOrdenada(lista *l, int x){
    no *novo = getNo(x);
    if(novo != NULL){
        if(listaVazia(*l))
            l->inicio = l->fim = novo;
        else{
            if(l->inicio->valor > x){
                inserirInicio(l, novo);
            }else{
                no *aux = l->inicio;
                while(aux->prox != NULL && aux->prox->valor < x)
                    aux = aux->prox;
                if(aux->prox == NULL)
                    inserirFim(l, novo);
                else
                    inserirMeio(aux, novo);
            }
        }
    }
}

void removerInicio(lista *l){
    no *aux = l->inicio;
    if(aux->prox == NULL)
        iniciarLista(l);
    else
        l->inicio = aux->prox;
    free(aux);
}

void removerMeio(no *ant){
    no *aux = ant->prox;
    ant->prox = aux->prox;
    free(aux);
}

void removerFim(lista *l, no *ant){
    no *aux = ant->prox;
    ant->prox = NULL;
    free(aux);
}

void removerLista(lista *l, int x){
    if(!listaVazia(*l)){
        if(l->inicio->valor == x)
            removerInicio(l);
        else{
            no *aux = l->inicio;
            while(aux->prox != NULL && aux->prox->valor != x)
                aux = aux->prox;
            if(aux->prox != NULL && aux != l->fim){
                if(aux->prox == l->fim)
                    removerFim(l,aux);
                else
                    removerMeio(aux);
            }
        }
    }else
        printf("Lista Vazia!\n");
}

void imprimirLista(lista *l){
    no *aux = l->inicio;
    while(aux != NULL){
        printf("[%d]\n",aux->valor);
        aux = aux->prox;
    }
}

void destruirLista(lista *l){
    no *aux = l->inicio;
    no *buffer;
    while(aux != NULL){
        buffer = aux;
        aux = aux->prox;
        free(buffer);
    }
    iniciarLista(l);
}
