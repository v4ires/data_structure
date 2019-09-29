#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1024
#define A 0.6180339887

typedef struct chave{
    int valor;
}chave;

typedef struct no{
    chave k;
    struct no *prox;
}no;

typedef struct hash{
    no *inicio[MAX];
}hash;

void iniciarHashEncadeado(hash *h);
void buscaEncadeado(hash *h, int pos, chave x);
void insereHashEncadeado(hash *h, int pos, chave x);
void removerHashEncadeado(hash *h, int pos, chave x);
int metodoDivisao(chave k);
int metodoMultiplicacao(chave k);
int metodoUniversal(chave k);
void imprimirHashEncadeado(hash *h);

#endif // HASH_H_INCLUDED
