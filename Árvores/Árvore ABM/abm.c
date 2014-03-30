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

#include "abm.h"

/**
*Retorna um novo nó alocado
*/
node *criarNode(){
    node *n = (node*)malloc(sizeof(node));
    if(n == NULL)
        printf("NULL\n");
    else{
        int i;
        for(i=0; i<N; i++){
            n->chaves[i].ramoMenor = NULL;
            n->chaves[i].info = 0;
        }
        n->maior = NULL;
        n->tamanho = 0;
        return n;
    }
    return NULL;
}

/**
*Método de ordenação Bubble Sort
*/
void bubbleSort(node **n){
    key temp;
    int i,j;
    for(i=0; i<(*n)->tamanho; i++){
        for(j=i+1; j<(*n)->tamanho; j++){
            if((*n)->chaves[i].info > (*n)->chaves[j].info){
                temp = (*n)->chaves[i];
                (*n)->chaves[i] = (*n)->chaves[j];
                (*n)->chaves[j] = temp;
            }
        }
    }
}

bool jaExiste(node *n, int valor){
    int i;
    for(i=0; i<n->tamanho; i++){
        if(n->chaves[i].info == valor)
            return true;
    }
    return false;
}

/**
*Insere uma nova chave na Árvore
*/
void inserirABM(node **n,int valor) {
    int i;
    if((*n) == NULL) {
        (*n) = criarNode();
        if((*n) == NULL) {
            printf("STACK OVERFLOW!\n");
            return;
        }
    }
    if(!jaExiste((*n), valor)) {
        if((*n)->tamanho < N) {
            (*n)->chaves[(*n)->tamanho++].info = valor;
            bubbleSort(&(*n));
        } else {
            for(i=0; i<N; i++) {
                if((*n)->chaves[i].info > valor) {
                    inserirABM(&(*n)->chaves[i].ramoMenor, valor);
                    return;
                }
            }
            inserirABM(&(*n)->maior,valor);
        }
    }else{
        printf("Chave ja existe!\n");
        system("pause>NULL");
    }
}

/**
*Retorna o indice da chave que contem o valor
*informação nescessaria para realizar a busca
*na funcao buscaABM()
*/
int buscaNo(node *n, int valor){
    int i, qtdChaves = (n->tamanho-1);

    for(i=0; i<qtdChaves; i++){
        if(valor <= n->chaves[i].info)
            return i;
    }
    return qtdChaves;
}

/**
*Busca de forma recursiva apartir do
*indice retornado pela buscaNo()
*/
void buscaABM(node *n,int valor) {
    if(n == NULL){
        printf("NOT FOUND!\n");
        return;
    }else{
        int aux = buscaNo(n, valor);
        if(valor == n->chaves[aux].info)
            printf("[%d]",n->chaves[aux].info);
        else if(valor < n->chaves[aux].info)
            buscaABM(n->chaves[aux].ramoMenor, valor);
        else if(valor > n->chaves[aux].info)
            buscaABM(n->maior, valor);
    }
}

/**
*Retorna a menor chave contido na ABM
*/
key menorValor(node **n){
    node *aux = (*n);
    key temp;
    while(aux->chaves[0].ramoMenor != NULL){
        aux =  aux->chaves[0].ramoMenor;
    }
    temp = aux->chaves[0];
    removeKey(&aux, temp.info);
    return temp;
}

/**
*Retorna a maior chave contido na ABM
*/
key maiorValor(node **n){
    node *aux = (*n);
    key temp;
    while(aux->maior != NULL){
        aux =  aux->maior;
    }
    temp = aux->chaves[aux->tamanho-1];
    removeKey(&aux, temp.info);
    return temp;
}

/**
*Recebe o nó que contem o valor e reordena os
*valores apartir da posição
*/
void removeKey(node **n, int valor){
    int i = buscaNo((*n), valor);

    for(i=i+1; i<(*n)->tamanho; i++){
        (*n)->chaves[i-1] = (*n)->chaves[i];
    }
    (*n)->tamanho--;
}


/**
*Remove uma chave dado pelo seu valor
*/
void removerABM(node **n,int valor) {
    if((*n) == NULL) {
        printf("NOT FOUND!\n");
        return;
    } else {
        int aux = buscaNo((*n), valor);
        if(valor == (*n)->chaves[aux].info) {
            ///Se a chave estiver no Nó Folha
            if((*n)->chaves[0].ramoMenor == NULL && (*n)->chaves[1].ramoMenor == NULL && (*n)->chaves[2].ramoMenor == NULL && (*n)->maior == NULL){
                if((*n)->tamanho == 1){
                    node *aux = (*n);
                    free(aux);
                    (*n) = NULL;
                }else
                    removeKey(&(*n), valor);
            }
            else {
                ///Se a chave estiver em qualquer outro Nó Não Follha
                if(aux < ((*n)->tamanho-1))
                    (*n)->chaves[aux].info = maiorValor(&(*n)->chaves[aux].ramoMenor).info;
                else
                    (*n)->chaves[aux].info = menorValor(&(*n)->maior).info;
            }
        } else if(valor < (*n)->chaves[aux].info)
            removerABM(&(*n)->chaves[aux].ramoMenor, valor);
        else if(valor > (*n)->chaves[aux].info)
            removerABM(&(*n)->maior, valor);
    }
}

/**
*Imprime em Ordem Crescente
*/
void printASC(node *n){
    if(n == NULL)
        return;
    else{
		int i;
        for(i=0; i<n->tamanho; i++){
            printASC(n->chaves[i].ramoMenor);
            printf("[%d]",n->chaves[i].info);
            printf("\n");
        }
        printASC(n->maior);
    }
}

/**
*Imprime em Ordem de Inserção
*/
void printABM(node *n){
    if(n == NULL)
        return;
    else{
        int i;
        printf("\n");
        for(i=0; i<n->tamanho; i++){
            printf("[%d]",n->chaves[i].info);
        }
        printABM(n->chaves[0].ramoMenor);
        printABM(n->chaves[1].ramoMenor);
        printABM(n->chaves[2].ramoMenor);
        printABM(n->maior);
    }
}

/**
*TODO Fazer uma função que Destrua
*a arvore ABM
*/
void zerarABM(node **n){
}
