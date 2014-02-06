/**
*Autor: Vinicius Aires Barros
*Estrutura de Dados
*Pilha Estatica
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int conteudo[MAX];
    int topo;
}pilha;

///Protótipo Funções
void criaPilha(pilha *p);
bool pilhaVazia(pilha p);
bool pilhaCheia(pilha p);
void empilha(pilha *p,int x);
void desenpilha(pilha *p);
void imprimePilha(pilha *p);
void removerValor(pilha *p, int x);

int main(){
    ///Todo code here...
    return 1;
}

void criaPilha(pilha *p){
    p->topo = 0;
}

bool pilhaVazia(pilha p){
    return(p.topo == 0) ? true : false;
}

bool pilhaCheia(pilha p){
    return(p.topo == MAX) ? true : false;
}

void empilha(pilha *p,int x){
    if(pilhaCheia(*p))
        printf("Pilha Cheia!");
    else{
        p->conteudo[p->topo] = x;
        p->topo++;
    }
}

void desenpilha(pilha *p){
    if(pilhaVazia(*p))
        printf("Pilha Vazia!");
    else
        p->topo--;
}

void removerValor(pilha *p, int x){
    if(!pilhaVazia(*p)){
        pilha aux;
        if(p->conteudo[p->topo] == x){
            p->topo--;
        }else{
            int i = p->topo;
            criaPilha(&aux);
            while(p->conteudo[i] != x){
                empilha(&aux,p->conteudo[i]);
                desenpilha(p);
                i--;
            }
            i = aux.topo-1;
            while(i > 0){
                empilha(p,aux.conteudo[i]);
                i--;
            }
        }
    }
}

void imprimePilha(pilha *p){
    int i;
    for(i=(p->topo-1); i>=0; i--){
        printf("[%d]\n",p->conteudo[i]);
    }
}
