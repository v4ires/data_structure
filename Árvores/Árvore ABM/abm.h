#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 3

typedef struct key{
    struct node *ramoMenor;
    int info;
}key;

typedef struct node{
    int tamanho;
    key chaves[N];
    struct node *maior;
}node;

node *criarNode();
void bubbleSort(node **n);
void inserirABM(node **n,int valor);
void printABM(node *n);
int buscaNo(node *n, int valor);
void buscaABM(node *n,int valor);
void removeKey(node **n, int valor);
key menorValor(node **n);
key maiorValor(node **n);
void printASC(node *n);
bool jaExiste(node *n, int valor);
void zerarABM(node **n);

#endif // ABM_H_INCLUDED
