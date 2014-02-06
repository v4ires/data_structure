#ifndef LISTACIRCULARENCADEADA_H_INCLUDED
#define LISTACIRCULARENCADEADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int info;
    struct no *prox;
}no;

typedef struct listaCircular{
    no *inicio, *fim;
    int qtd;
}listaCircular;

bool listaVazia(listaCircular l);
void iniciarLista(listaCircular *l);
no *getNo(int x);
void inserirInicio(listaCircular *l, no *n);
void inserirMeio(no *atual, no *n);
void inserirFim(listaCircular *l, no *n);
void inserir(listaCircular *l, int x);
void inserirOrdenado(listaCircular *l, int x);
no *removerInicio(listaCircular *l);
no *removerMeio(no *atual);
no *removerFim(listaCircular *l, no *ant);
bool remover(listaCircular *l, int x);
void imprimir(listaCircular *l);
void destruirLista(listaCircular *l);


#endif // LISTACIRCULARENCADEADA_H_INCLUDED
