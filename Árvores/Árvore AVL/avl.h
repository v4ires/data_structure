#ifndef AVL_C_INCLUDED
#define AVL_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

typedef struct node{
    int info;
    int fb;
    struct node *father;
    struct node *left;
    struct node *right;
}node;

void inserirTree(node **n, int value);
void rotacaoSimplesEsquerda(node **a);
void rotacaoSimplesDireita(node **a);
void rotacaoDuplaDireita(node **n);
void rotacaoDuplaEsquerda(node **n);
void preOrdem(node *n);
void removeTreeR(node **n,int element);
int CalcularAltura(node *n);
void emOrdem(node *n);
void posOrdem(node *n);
node *twoSons(node *n);


#endif // AVL_C_INCLUDED
