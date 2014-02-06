/**
*Autor: Vinicius Aires Barros
*Estrutura de Dados
*Fila Encadeada
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int conteudo;
    struct no *proximo;
} no;

typedef struct tfila{
    no *inicio;
    no *fim;
    int cont;
} tfila;

void criaFila(tfila *f){
    f->inicio = f->fim = NULL;
    f->cont = 0;
}

bool filaVazia(tfila f){
    return (f.inicio == NULL && f.fim == NULL) ? true : false;
}

void enfileirar(tfila *f,int x){
    no *novo_no = (no*)malloc(sizeof(no));
    if(novo_no != NULL){
        novo_no->proximo = NULL;
        novo_no->conteudo = x;

        if(filaVazia(*f)){
            f->inicio = f->fim = novo_no;
        }else{
            (f->fim)->proximo = novo_no;
            f->fim = novo_no;
        }
        f->cont++;
    }
}

no *desenfileirar(tfila *f){
    no *aux = NULL;
    if(!filaVazia(*f)){
        aux = f->inicio;
        if(f->inicio->proximo == NULL)
            criaFila(f);
        else{
            f->inicio = (f->inicio)->proximo;
            f->cont--;
        }
    }
    return aux;
}

void imprimeFila(tfila *f){
    no *aux = f->inicio;
    if(!filaVazia(*f)){
        while(aux!=NULL){
            printf("[%d]",aux->conteudo);
            aux = aux->proximo;
        }
    }
}

void buscaFila(tfila *f,int x){
    no *aux = f->inicio;
    if(!filaVazia(*f)){
        while(aux!=NULL){
            if(x == aux->conteudo){
                printf("[%d]",aux->conteudo);
            }
            aux = aux->proximo;
        }
    }
}

int main()
{
    tfila novo;
    int opcao,num;
    no *aux;

    criaFila(&novo);

    do
    {
        system("cls");
        printf("->Fila Encadeada\n");
        printf("1 - Enfileirar\n2 - Desenfileirar\n3 - Imprimir Fila\n4 - Busca Fila\n0 - SAIR\nDigite uma opcao: ");
        scanf("%d",&opcao);

        switch(opcao)
        {
            case 0:
                while(novo.cont > 0)
                    free(desenfileirar(&novo));
                opcao = 0;
            break;

            case 1:
                printf("Digite um numero: ");
                scanf("%d",&num);
                enfileirar(&novo,num);
            break;

            case 2:
                aux = desenfileirar(&novo);
                if(aux != NULL){
                    printf("[%d] Removido\n",aux->conteudo);
                    free(aux);
                }
                system("pause>NULL");
            break;

            case 3:
                imprimeFila(&novo);
                system("pause>NULL");
            break;

            case 4:
                printf("Digite um numero: ");
                scanf("%d",&num);
                buscaFila(&novo,num);
                system("pause>NULL");
            break;

            default:
                printf("Digite uma opcao valida!");
                system("pause>NULL");
        }
    }while(opcao != 0);
}
