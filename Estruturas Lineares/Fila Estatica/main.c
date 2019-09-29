#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct{
    int vetor[MAX];
    int fim;
} fila;

void criarFila(fila *f);
bool filaVazia(fila f);
bool filaCheia(fila f);
int enfileirar(fila *f,int dado);
void desenfileirar(fila *f);
void imprimirFila(fila *f);

int main(){
    int opcao,num;
    fila novo;

    criarFila(&novo);

    do{
        system("cls");
        printf("->Fila Sequencial\n");
        printf("1 - Enfileirar\n2 - Desenfilerar\n3 - Imprimir\n0 - SAIR\nDigite uma opcao: ");
        scanf("%d",&opcao);

        switch(opcao){
        case 0:
            opcao = 0;
            break;

        case 1:
            printf("Digite um numero: ");
            scanf("%d",&num);
            enfileirar(&novo,num);
            break;

        case 2:
            desenfileirar(&novo);
            break;

        case 3:
            imprimirFila(&novo);
            system("pause>NULL");
            break;
        }
    }while(opcao != 0);
}

void criarFila(fila *f){
    f->fim = 0;
}

bool filaVazia(fila f){
    return(f.fim == 0) ? true : false;
}

bool filaCheia(fila f){
    return(f.fim == MAX) ? true : false;
}

int enfileirar(fila *f,int dado){
    if(filaCheia(*f))
        printf("Fila Cheia!\n");
    else{
        f->vetor[f->fim] = dado;
        (f->fim)++;
    }
}

void desenfileirar(fila *f){
    int i = 0;
    for(i=i+1; i < f->fim; i++)
        f->vetor[i-1] = f->vetor[i];
    f->fim--;
}

void imprimirFila(fila *f){
    int i;

    if(filaVazia(*f))
        printf("Fila Vazia!\n");
    else{
        for(i=0; i<f->fim; i++){
            printf("[%d]",f->vetor[i]);
        }
    }
}
