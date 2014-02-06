#ifndef LISTASIMPLESMENTEENCADEADA_H_INCLUDED
#define LISTASIMPLESMENTEENCADEADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int valor;
    struct no *prox;
}no;

typedef struct lista{
    no *inicio, *fim;
}lista;

bool listaVazia(lista l);
void iniciarLista(lista *l);
no *getNo(int x);
void inserirInicio(lista *l , no *n);
void inserirFim(lista *l, no *n);
void inserirMeio(no *ant, no *n);
void inserirLista(lista *l, int x);
void inserirListaOrdenada(lista *l, int x);
void removerInicio(lista *l);
void removerMeio(no *ant);
void removerFim(lista *l, no *ant);
void removerLista(lista *l, int x);
void imprimirLista(lista *l);
void destruirLista(lista *l);


#endif // LISTASIMPLESMENTEENCADEADA_H_INCLUDED
