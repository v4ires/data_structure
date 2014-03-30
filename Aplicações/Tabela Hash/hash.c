/**
*Autor: Vinicius Aires Barros
*Estrutura de Dados
*Tabela Hash com Listas Ligadas
*/
#include "hash.h"

void iniciarHashEncadeado(hash *h){
    int i;
    for(i=0; i<MAX; i++)
        h->inicio[i] = NULL;
}

void buscaEncadeado(hash *h, int pos, chave x){
    if(h->inicio[pos]->k.valor == x.valor)
        printf("[%d]",h->inicio[pos]->k.valor);
    else{
        no *aux = h->inicio[pos];
        while(aux != NULL && aux->k.valor != x.valor)
            aux = aux->prox;
        if(aux != NULL)
            printf("[%d]",aux->k.valor);
    }
}

void insereHashEncadeado(hash *h, int pos, chave x){
    no *n = (no*)malloc(sizeof(no));
    if(n != NULL){
        n->prox = NULL;
        n->k = x;
        if(h->inicio[pos] == NULL)
            h->inicio[pos] = n;
        else{
            no *aux = h->inicio[pos];
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = n;
        }
    }
}

void removerHashEncadeado(hash *h, int pos, chave x){
    no *aux = h->inicio[pos];
    if(h->inicio[pos] != NULL){
         if(h->inicio[pos]->k.valor == x.valor){
            h->inicio[pos] = h->inicio[pos]->prox;
            free(aux);
        }else{
            no *buffer = NULL;
            while(aux->prox != NULL && aux->prox->k.valor != x.valor)
                aux = aux->prox;
            if(aux->prox != NULL){
                buffer = aux->prox;
                if(aux->prox->prox == NULL)
                    aux->prox = NULL;
                else
                    aux->prox = aux->prox->prox;
                free(buffer);
            }else
                printf("Nao Achei!\n");
        }   
    }else{
        printf("Elemento nao encontrado!\n");
    }
}

int metodoDivisao(chave k){
    return (k.valor%MAX);
}

int metodoMultiplicacao(chave k){
    return (int)(floor(MAX*(fmod(k.valor*A,1))));
}

void imprimirHashEncadeado(hash *h){
    int i;
    no *aux;
    for(i=0; i<MAX; i++){
        aux = h->inicio[i];
        while(aux != NULL){
            printf("[%d]",aux->k.valor);
            aux = aux->prox;
        }
    }
}
