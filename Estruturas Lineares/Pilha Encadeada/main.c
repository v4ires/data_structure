/**
*Autor: Vinicius Aires Barros
*Estrutura de Dados
*Pilha Encadeada
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct no{
    int num;
    struct no *prox;
}no;

typedef struct pilha{
    no *topo;
    int tam;
}pilha;

void criaPilha(pilha *p);
bool pilhaVazia(pilha p);
bool pilhaCheia(pilha p);
void empilha(pilha *p,int x);
void desenpilha(pilha *p);
void imprimePilha(pilha *p);
void buscaPilha(pilha *p,int x);
void destrutor(pilha *p);

int main()
{
    ///TODO code here...
    return 1;
}

void criaPilha(pilha *p){
    p->topo = NULL;
    p->tam = 0;
}

bool pilhaVazia(pilha p){
    return(p.tam == 0) ? true : false;
}

bool pilhaCheia(pilha p){
    return(p.tam == MAX) ? true : false;
}

void empilha(pilha *p,int x){
    no *novo_no = (no*)malloc(sizeof(no));
    if(novo_no != NULL && !pilhaCheia(*p))
    {
        novo_no->prox = NULL;
        novo_no->num = x;
        novo_no->prox = p->topo;
        p->topo = novo_no;
        p->tam++;
    }
}

void desenpilha(pilha *p){
    no *aux;
    if(!pilhaVazia(*p))
    {
        aux = p->topo;
        p->topo = aux->prox;
        p->tam--;
        free(aux);
    }
    else
        printf("Pilha Vazia!");
}

void imprimePilha(pilha *p){
    no *aux;
    if(!pilhaVazia(*p))
    {
        aux = p->topo;
        while(aux != NULL)
        {
            printf("[%d]\n",aux->num);
            aux = aux->prox;
        }
    }
    else
        printf("\nPilha Vazia!");

}

void buscaPilha(pilha *p,int x){
    no *aux = p->topo;
    bool achou = false;
    while(aux != NULL && !achou){
        if(x == aux->num){
            printf("Numero encontrado: [%d]",aux->num);
            achou = true;
        }
        aux = aux->prox;
    }
}

void destrutor(pilha *p){
    while(p->tam != 0)
        desenpilha(p);
}
