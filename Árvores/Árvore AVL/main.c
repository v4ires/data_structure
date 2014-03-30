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

#include "avl.c"

int main(){

    node *n = NULL;

    ///Rotação Dupla à Direita OK
    ///ENTRADA {25,10,5,20,30,27,28}
    ///SAIDA {25,10,5,20,28,27,30}

    ///Rotação Dupla á Esquerda OK
    ///ENTRADA {10,5,20,30,25}
    ///Saida {10,5,25,20,30}

    ///Rotação Simples para a Direita OK
    ///ENTRADA {25,10,5,20,30,28,27}
    ///Saida {25,10,5,20,28,27,30}

    ///Rotação Simples para a Esquerda OK
    ///ENTRADA {10,20,30,40,50}
    ///Saida {20,10,40,30,50}

    int op, num;
    do{
        system("cls");
        printf("->Arvore AVL\n");
        printf("1 - Inserir\n2 - Excluir \n3 - Em Ordem\n4 - Pre Ordem\n5 - Pos Ordem\n6 - Eh AVL\n0 - SAIR\nDigite uma opcao: ");
        scanf("%d",&op);
        switch (op) {
        case 0:
            op = 0;
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d",&num);
            inserirTree(&n, num);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d",&num);
            removeTreeR(&n,num);
            break;

        case 3:
            emOrdem(n);
            system("pause>NULL");
            break;

        case 4:
            preOrdem(n);
            system("pause>NULL");
            break;

        case 5:
            posOrdem(n);
            system("pause>NULL");
            break;

        case 6:
            if(ehAVL(n,true))
                printf("Eh AVL\n");
            else
                printf("Nao eh AVL\n");
            system("pause>NULL");
            break;

        case 7:
            scanf("%d",&num);
            printf("%d",busca(n,num));
            system("pause>NULL");
            break;
        break;
        }
        setbuf(stdin, NULL);
    } while(op!=0);

    return 0;
}
