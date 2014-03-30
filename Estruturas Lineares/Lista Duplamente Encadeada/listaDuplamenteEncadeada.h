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

#ifndef LISTADUPLAMENTEENCADEADA_H_INCLUDED
#define LISTADUPLAMENTEENCADEADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int info;
    struct no *prox, *ant;
}no;

typedef struct lista{
    no *inicio, *fim;
    int qtd;
}lista;

bool listaVazia(lista l);
void iniciarLista(lista *l);
no *getNo(int x);
void inserirInicio(lista *l, no *n);
void inserirMeio(no *atual, no *n);
void inserirFim(lista *l, no *n);
void inserir(lista *l, int x);
void inserirOrdenado(lista *l, int x);
no *removerInicio(lista *l);
no *removerMeio(no *atual);
no *removerFim(lista *l);
bool remover(lista *l, int x);
void imprimir(lista *l);
void imprimirInverso(lista *l);
void destruirLista(lista *l);

#endif // LISTADUPLAMENTEENCADEADA_H_INCLUDED
