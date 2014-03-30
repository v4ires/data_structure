/**********************************************************************************************
** Os códigos aqui implementados são implementações das Estrutura de Dados implementados
** durante as disciplinas de Estrutura de Dados I, Estrutura de Dados II e na Monitoria onde
** implementei alguns desses códigos em conjunto com os alunos durante o ano de 2013 e inicio
** de 2014. 
**
** Desenvolvido por:
**                   Vinicius Aires Barros
**
** Contato: Vinícius Aires Barros (viniciusaires7@gmail.com)
***********************************************************************************************/

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
