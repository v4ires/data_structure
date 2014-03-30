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

#include "arvorebinaria.h"

node *getnode(int x){
    node *novo = (node*)malloc(sizeof(node));
    novo->esq = novo->dir = NULL;
    novo->info = x;
    return novo;
}

void inserirArvoreR(node **n,int x){
    if((*n) == NULL){
        (*n) = getnode(x);
    }
    else{
        if(x == (*n)->info)
            return;
        if(x < (*n)->info)
            inserirArvoreR(&(*n)->esq,x);
        else
            inserirArvoreR(&(*n)->dir,x);
    }
}

node *noSucessor(node *n){
    if(n == NULL)
        return;
    else if(n->esq == NULL)
        return n;
    else
        return noSucessor(n->esq);
}

node *noPredecessor(node *n){
    if(n == NULL)
        return;
    else if(n->dir == NULL)
        return n;
    else
        return noSucessor(n->dir);
}


void removerNoR(node **n,int x){
    node *aux = NULL;
    if((*n) == NULL)
        return;
    else
    {
        if(x < (*n)->info)
            removerNoR(&(*n)->esq,x);
        else if(x > (*n)->info)
            removerNoR(&(*n)->dir,x);
        else{
            if((*n)->esq == NULL && (*n)->dir == NULL){
                aux = (*n);
                free(aux);
                (*n) = NULL;
            }else if((*n)->esq == NULL){
                aux = (*n);
                (*n) = aux->dir;
                free(aux);
            }else if((*n)->dir == NULL){
                aux = (*n);
                (*n) = aux->esq;
                free(aux);
            }else{
                aux = noSucessor((*n)->dir);
                (*n)->info = aux->info;
                removerNoR(&(*n)->dir,(*n)->info);
            }
        }
    }
}

void emOrdem(node *n){
    if(n == NULL){
        return;
    }
    emOrdem(n->esq);
    printf("[%d]",n->info);
    emOrdem(n->dir);
}

void posOrdem(node *n){
    if(n == NULL){
        return;
    }
    posOrdem(n->esq);
    posOrdem(n->dir);
    printf("[%d]",n->info);
}

void preOrdem(node *n){
    if(n == NULL){
        return;
    }
    printf("[%d]",n->info);
    preOrdem(n->esq);
    preOrdem(n->dir);
}

bool buscarNoR(node *n,int x){
	if (n != NULL)
		return n->info == x || buscarNoR(n->esq, x) || buscarNoR(n->dir, x);
	return false;
}

node *buscaNoI(node *n, int x){
    node *aux = n;
    while(aux != NULL){
       if(aux->info == x)
            return aux;
        else if(aux->info > x)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
}

int maiorValorR(node *n){
    if(n->dir == NULL)
        return n->info;
    else
        maiorValorR(n->dir);
}

int menorValorR(node *n){
    if(n->esq == NULL)
        return n->info;
    else
        maiorValorR(n->esq);
}

node *maiorValorXR(node *n){
    if(n->dir == NULL)
        return n;
    else
        maiorValorR(n->dir);
}

node *menorValorXR(node *n){
    if(n->esq == NULL)
        return n;
    else
        maiorValorR(n->esq);
}


node *maiorValorXI(node *n){
    node *aux = n;
    while(aux->dir != NULL){
        aux = aux->dir;
    }
    return aux;
}

node *menorValorXI(node *n){
    node *aux = n;
    while(aux->esq != NULL){
        aux = aux->esq;
    }
    return aux;
}

int alturaArvore(node* node)
{
   if (node==NULL)
       return 0;
   else
   {
     int esq = alturaArvore(node->esq);
     int dir = alturaArvore(node->dir);

     if (esq > dir)
         return(esq + 1);
     else
        return(dir + 1);
   }
}

node *maiorValor(node *n){
    return (n->dir == NULL) ? n : maiorValor(n->dir);
}

node *menorValor(node *n){
    return (n->esq == NULL) ? n : menorValor(n->esq);
}
