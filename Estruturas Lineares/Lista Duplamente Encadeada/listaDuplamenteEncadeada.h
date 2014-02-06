#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int info;
    struct no *prox, *ant;
}no;

typedef struct lista{
    no *inicio, *fim;
    int qtd;
}lista;

bool listaVazia(lista l);
void iniciarLista(lista *l);
no *getNo(int x);
void inserirInicio(lista *l, no *n);
void inserirMeio(no *atual, no *n);
void inserirFim(lista *l, no *n);
void inserir(lista *l, int x);
void inserirOrdenado(lista *l, int x);
no *removerInicio(lista *l);
no *removerMeio(no *atual);
no *removerFim(lista *l);
bool remover(lista *l, int x);
void imprimir(lista *l);
void imprimirInverso(lista *l);
void destruirLista(lista *l);

#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED
