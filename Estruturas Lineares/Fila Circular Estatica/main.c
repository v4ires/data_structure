/**
*Autor: Vinicius Aires Barros
*Estrutura de Dados
*Fila Estatica Circular
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct{
    int conteudo[MAX];
    int qtd;
    int inicio;
    int fim;
} fila;


void iniciaFila(fila *f){
    f->inicio = f->fim = f->qtd = 0;
}

bool filaVazia(fila f){
    return (f.qtd == 0) ? true : false;
}

bool filaCheia(fila f){
    return ((f.fim+1)%MAX == f.inicio) ? true : false;
}

void enfileirar(fila *f,int x){
    if(!filaCheia(*f)){
        f->qtd++;
        f->conteudo[f->fim] = x;
        f->fim = (f->fim + 1) % MAX;
    }
    else
        printf("Lista Cheia!");
}

int desenfileirar(fila *f){
    int aux;

    if(!filaVazia(*f)){
        aux = f->conteudo[f->inicio];
        f->qtd--;
        f->inicio = (f->inicio + 1) % MAX;
        return aux;
    }
    else
        printf("Fila Vazia!");
}

void buscaFila(fila *f,int x){
    int i;

    if(filaVazia(*f))
        printf("Fila Vazia!");
    else{
        while(i != f->fim){
            if(f->conteudo[i] == x){
                printf("Valor encontrado na posicao [%d]\n",i);
            }
            i++;
        }
    }

}

void imprimirFila(fila *f){
    int i = f->inicio;
    if(!filaVazia(*f)){
        while(i != f->fim){
            printf("[%d]",f->conteudo[i]);
            i = (i+1)%MAX;
        }
    }
    else
        printf("Fila Vazia!");
}

int main(){
    int op,num,x;
    fila novo;

    iniciaFila(&novo);

    do{
        system("cls");
        printf("->Fila Circular Estatica\n1-Enfileira\n2-Desenfileirar\n3-Busca\n4-Imprimir Fila\n0-SAIR\nDigite uma opcao: ");
        scanf("%d",&op);

        switch(op){
        case 0:
            op = 0;
        break;

        case 1:
            printf("Digite um numero: ");
            scanf("%d",&num);
            enfileirar(&novo,num);
            system("pause>NULL");
        break;

        case 2:
            num = desenfileirar(&novo);
            printf("%d",num);
            system("pause>NULL");
        break;

        case 3:
            printf("Digite um numero: ");
            scanf("%d",&num);
            buscaFila(&novo,num);
            system("pause>NULL");
        break;

        case 4:
            imprimirFila(&novo);
            system("pause>NULL");
            break;

        default:
            printf("Digite um opcao valida!");
            system("pause>NULL");
        }
    }while(op != 0);
}
