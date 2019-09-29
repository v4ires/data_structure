#include "listaDuplamenteEncadeada.h"

bool listaVazia(lista l){
    return (l.inicio == NULL) ? true : false;
}

void iniciarLista(lista *l){
    l->inicio = l->fim = NULL;
    l->qtd = 0;
}

no *getNo(int x){
    no *novo = (no*)malloc(sizeof(no));
    if(novo != NULL){
        novo->prox = novo->ant = NULL;
        novo->info = x;
    }
    return novo;
}

void inserirInicio(lista *l, no *n){
    n->prox = l->inicio;
    l->inicio->ant = n;
    l->inicio = n;
}

void inserirMeio(no *atual, no *n){
    n->prox = atual->prox;
    n->ant = atual;
    atual->prox->ant = n;
    atual->prox = n;
}

void inserirFim(lista *l, no *n){
    l->fim->prox = n;
    n->ant = l->fim;
    l->fim = n;
}

void inserir(lista *l, int x){
    no *novo = getNo(x);
    if(novo != NULL){
        if(listaVazia(*l))
            l->inicio = l->fim = novo;
        else
            inserirFim(l, novo);
        l->qtd++;
    }
}

void inserirOrdenado(lista *l, int x){
    no *novo = getNo(x);
    if(novo != NULL){
        if(listaVazia(*l))
            l->inicio = l->fim = novo;
        else{
            if(l->inicio->info > x){
                inserirInicio(l, novo);
            }else{
                no *aux = l->inicio;
                while(aux->prox != NULL && aux->prox->info < x)
                    aux = aux->prox;
                if(aux->prox == NULL)
                    inserirFim(l,novo);
                else
                    inserirMeio(aux,novo);
            }
        }
        l->qtd++;
    }
}

no *removerInicio(lista *l){
    no *aux = l->inicio;
    if(aux->prox == NULL)
        iniciarLista(l);
    else
        l->inicio = aux->prox;
    return aux;
}

no *removerMeio(no *atual){
    no *aux = atual;
    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;
    return aux;
}

no *removerFim(lista *l){
    no *aux = l->fim;
    l->fim = aux->ant;
    l->fim->prox = NULL;
    return aux;
}

bool remover(lista *l, int x){
    if(!listaVazia(*l)){
        no *aux = l->inicio;
        if(aux->info == x)
            free(removerInicio(l));
        else{
            while(aux != NULL && aux->info != x)
                aux = aux->prox;
            if(aux != NULL && aux->info == x){
                if(aux->prox == NULL)
                    free(removerFim(l));
                else
                    free(removerMeio(aux));
            }else
                return false;
        }
    }
}

void imprimir(lista *l){
    no *aux = l->inicio;
    if(!listaVazia(*l)){
        while(aux != NULL){
            printf("[%d]\n",aux->info);
            aux = aux->prox;
        }
    }else
        printf("Lista Vazia!");
}

void imprimirInverso(lista *l){
    no *aux = l->fim;
    while(aux != NULL){
        printf("[%d]\n",aux->info);
        aux = aux->ant;
    }
}

void destruirLista(lista *l){
    no *aux = l->inicio;
    while (aux->prox != NULL) {
        aux = aux->prox;
        free(aux->ant);
    }
    free(l->fim);
    iniciarLista(l);
}

