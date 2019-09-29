#include "avl.h"

int CalcularAltura(node *n){
    int esquerda;
    int direita;

    if (n == NULL)
        return 0;
    else{
        esquerda = CalcularAltura(n->left);
        direita = CalcularAltura(n->right);

        if (esquerda > direita)
            return esquerda + 1;
        else
           return direita + 1;
    }
}

void rotacaoSimplesEsquerda(node **a) {
    node *b = (*a)->right;
    (*a)->right = b->left;
    b->left = (*a);
    (*a) = b;
}

void rotacaoSimplesDireita(node **a) {
    node *b = (*a)->left;
    (*a)->left = b->right;
    b->right = (*a);
    (*a) = b;
}

void rotacaoDuplaDireita(node **n) {
    rotacaoSimplesEsquerda(&(*n)->left);
    rotacaoSimplesDireita(&(*n));
}

void rotacaoDuplaEsquerda(node **n) {
    rotacaoSimplesDireita(&(*n)->right);
    rotacaoSimplesEsquerda(&(*n));
}

void inserirTree(node **n, int value) {
    if((*n) == NULL) {
        (*n) = (node*)malloc(sizeof(node));
        (*n)->right = (*n)->left = NULL;
        (*n)->info = value;
        (*n)->fb = 0;
    } else {
        if(value < (*n)->info) {
            inserirTree(&(*n)->left, value);
            (*n)->fb = CalcularAltura((*n)->right)-CalcularAltura((*n)->left);

            ///No desbalanceado com FB = -2
            if((*n)->fb == -2){
                if((*n)->left->fb > 0){
                    printf("Rotacao Dupla para Direita!\n");
                    system("pause>NULL");
                    rotacaoDuplaDireita(&(*n));
                }
                else{
                    printf("Rotacao Simples para Direita!\n");
                    system("pause>NULL");
                    rotacaoSimplesDireita(&(*n));
                }
            }
        } else if(value > (*n)->info) {
            inserirTree(&(*n)->right, value);
            (*n)->fb = CalcularAltura((*n)->right)-CalcularAltura((*n)->left);

            ///No desbalanceado com FB = +2
            if((*n)->fb == 2) {
                if((*n)->right->fb < 0){
                    printf("Rotacao Dupla para Esquerda!\n");
                    system("pause>NULL");
                    rotacaoDuplaEsquerda(n);
                }
                else{
                    printf("Rotacao Simples para Esquerda!\n");
                    system("pause>NULL");
                    rotacaoSimplesEsquerda(n);
                }
            }
        }
    }
}

void preOrdem(node *n) {
    if(n == NULL)
        return;
    else{
        printf("[%d] fb %d",n->info,n->fb);
        preOrdem(n->left);
        preOrdem(n->right);
    }
}

void emOrdem(node *n){
    if(n == NULL){
        return;
    }
    emOrdem(n->left);
    printf("[%d]",n->info);
    emOrdem(n->right);
}

void posOrdem(node *n){
    if(n == NULL)
        return;
    else{
        posOrdem(n->left);
        posOrdem(n->right);
        printf("[%d]",n->info);
    }
}


node *twoSons(node *n){
    if(n == NULL)
        return;
    else if(n->left == NULL)
        return n;
    else
        return twoSons(n->left);
}

void removeTreeR(node **n,int element){
    node *aux = NULL;
    if((*n) == NULL)
        return;
    else
    {
        if(element < (*n)->info){
            removeTreeR(&(*n)->left,element);

            (*n)->fb = CalcularAltura((*n)->right)-CalcularAltura((*n)->left);

            ///No desbalanceado com FB = +2
            if((*n)->fb == 2) {
                if((*n)->right->fb < 0){
                    printf("Rotacao Dupla para Esquerda!\n");
                    system("pause>NULL");
                    rotacaoDuplaEsquerda(n);
                }
                else{
                    printf("Rotacao Simples para Esquerda!\n");
                    system("pause>NULL");
                    rotacaoSimplesEsquerda(n);
                }
            }
        }
        else if(element > (*n)->info){
            removeTreeR(&(*n)->right,element);

            (*n)->fb = CalcularAltura((*n)->right)-CalcularAltura((*n)->left);

            ///No desbalanceado com FB = -2
            if((*n)->fb == -2){
                if((*n)->left->fb > 0){
                    printf("Rotacao Dupla para Direita!\n");
                    system("pause>NULL");
                    rotacaoDuplaDireita(&(*n));
                }
                else{
                    printf("Rotacao Simples para Direita!\n");
                    system("pause>NULL");
                    rotacaoSimplesDireita(&(*n));
                }
            }
        }
        else{
            if((*n)->left == NULL && (*n)->right == NULL){
                ///Remove quando o no for folha
                aux = (*n);
                free(aux);
                (*n) = NULL;
            }
            else if((*n)->left == NULL){
                ///Remove quando so houver um no a direita
                aux = (*n);
                (*n) = aux->right;
                free(aux);
            }
            else if((*n)->right == NULL){
                ///Remove quando so houver um no a esquerda
                aux = (*n);
                (*n) = aux->left;
                free(aux);
            }
            else{
                ///Remove quando o n� tiver 2 filhos
                aux = twoSons((*n)->right);
                (*n)->info = aux->info;
                removeTreeR(&(*n)->right,(*n)->info);
            }
        }
    }
}

bool ehAVL(node *n,bool status){
    if(n != NULL){
        status = ehAVL(n->left, status);
        status = ehAVL(n->right, status);
        if(n->fb == 2 || n->fb == -2)
            status = false;
        return status;
    }
}

int busca(node *n, int valor){
    if(n != NULL){
        if(n->info == valor)
            return n->info;
        else if(valor < n->info)
            busca(n->left, valor);
        else
            busca(n->right, valor);
    }
}
