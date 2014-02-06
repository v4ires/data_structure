/**
*Autor: Vinicius Aires Barros
*Estrutura de Dados
*Lista Circular Encadeada
*/

#include "listaCircularEncadeada.h"

bool listaVazia(listaCircular l){
    return (l.inicio == NULL) ? true : false;
}

void iniciarLista(listaCircular *l){
    l->inicio = l->fim = NULL;
    l->qtd = 0;
}

no *getNo(int x){
    no *n = (no*)malloc(sizeof(no));
    if(n != NULL){
        n->prox = NULL;
        n->info = x;
    }
    return n;
}

void inserirInicio(listaCircular *l, no *n){
    n->prox = l->inicio;
    l->fim->prox = n;
    l->inicio = n;
}

void inserirMeio(no *atual, no *n){
    no *buffer = atual->prox;
    atual->prox = n;
    n->prox = buffer;
}

void inserirFim(listaCircular *l, no *n){
    l->fim->prox = n;
    n->prox = l->inicio;
    l->fim = n;
}

void inserir(listaCircular *l, int x){
    no *novo = getNo(x);
    if(novo != NULL){
        if(listaVazia(*l)){
            l->inicio = l->fim = novo;
            novo->prox = l->inicio;
        }else
            inserirFim(l, novo);
        l->qtd++;
    }
}

void inserirOrdenado(listaCircular *l, int x){
    no *novo = getNo(x);
    if(novo != NULL){
        if(listaVazia(*l)){
            l->inicio = l->fim = novo;
            novo->prox = l->inicio;
        }else{
            if(l->inicio->info > x){
                inserirInicio(l, novo);
            }else{
                no *aux = l->inicio;
                while(aux->prox != l->inicio && aux->prox->info < x)
                    aux = aux->prox;
                if(aux->prox == l->inicio)
                    inserirFim(l,novo);
                else
                    inserirMeio(aux,novo);
            }
        }
        l->qtd++;
    }
}

no *removerInicio(listaCircular *l){
    no *aux = l->inicio;
    if(aux->prox == l->inicio)
        iniciarLista(l);
    else
        l->inicio = l->fim->prox = aux->prox;
    return aux;
}

no *removerMeio(no *ant){
    no *aux = ant->prox;
    ant->prox = aux->prox;
    return aux;
}

no *removerFim(listaCircular *l, no *ant){
    no *aux = l->fim;
    ant->prox = l->inicio;
    l->fim = ant;
    return aux;
}

bool remover(listaCircular *l, int x){
    if(!listaVazia(*l)){
        no *aux = l->inicio;
        if(aux->info == x)
            free(removerInicio(l));
        else{
            while(aux->prox != l->inicio && aux->prox->info != x)
                aux = aux->prox;
            if(aux->prox != l->inicio && aux->prox->info == x){
                if(aux->prox->prox == l->inicio)
                    free(removerFim(l, aux));
                else
                    free(removerMeio(aux));
            }
            else
                return false;
        }
    }
}

void imprimir(listaCircular *l){
    no *aux = l->inicio;
    if(!listaVazia(*l)){
        while(aux->prox != l->inicio){
            printf("[%d]",aux->info);
            aux = aux->prox;
        }
        printf("[%d]",aux->info);
    }
}

void destruirLista(listaCircular *l){
    if(!listaVazia(*l)){
        no *atual = l->inicio, *ant;
        while(atual->prox != l->inicio){
            ant = atual;
            atual = atual->prox;
            free(ant);
        }
        free(atual);
        iniciarLista(l);
    }
}
