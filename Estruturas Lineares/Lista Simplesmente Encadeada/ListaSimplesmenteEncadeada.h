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

#ifndef LISTASIMPLESMENTEENCADEADA_H_INCLUDED
#define LISTASIMPLESMENTEENCADEADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int valor;
    struct no *prox;
}no;

typedef struct lista{
    no *inicio, *fim;
}lista;

bool listaVazia(lista l);
void iniciarLista(lista *l);
no *getNo(int x);
void inserirInicio(lista *l , no *n);
void inserirFim(lista *l, no *n);
void inserirMeio(no *ant, no *n);
void inserirLista(lista *l, int x);
void inserirListaOrdenada(lista *l, int x);
void removerInicio(lista *l);
void removerMeio(no *ant);
void removerFim(lista *l, no *ant);
void removerLista(lista *l, int x);
void imprimirLista(lista *l);
void destruirLista(lista *l);


#endif // LISTASIMPLESMENTEENCADEADA_H_INCLUDED
