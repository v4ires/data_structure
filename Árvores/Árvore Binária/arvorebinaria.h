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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node{
    int info;
    struct node *esq;
    struct node *dir;
}node;

node *getnode(int x);
void inserirArvoreR(node **n,int x);
node *noSucessor(node *n);
void removerNoR(node **n,int x);
void emOrdem(node *n);
void posOrdem(node *n);
void preOrdem(node *n);
bool buscarNoR(node *n,int value);
node *buscaNoI(node *n, int x);
int maiorValorR(node *n);
int menorValorR(node *n);
node *maiorValorXR(node *n);
node *menorValorXR(node *n);
node *maiorValorXI(node *n);
node *menorValorXI(node *n);
int alturaArvore(node* node);


