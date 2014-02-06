#include "hash.c"

int main(void)
{
    int op;
    chave k;
    hash h;
    iniciarHashEncadeado(&h);
    do{
        system("cls");
        printf("->Tabela Hash Encadeado\n1-Inserir\n2-Buscar\n3-Remover\n4-Mostrar\n0-Sair\nDigite uma opcao: ");
        scanf("%d",&op);
        switch (op) {
        case 0:
            op = 0;
            break;
        case 1:
            printf("Digite uma chave: ");
            scanf("%d",&k.valor);
            insereHashEncadeado(&h,metodoDivisao(k),k);
            break;
        case 2:
            printf("Digite uma chave: ");
            scanf("%d",&k.valor);
            buscaEncadeado(&h,metodoDivisao(k),k);
            system("pause>NULL");
            break;
        case 3:
            printf("Digite uma chave: ");
            scanf("%d",&k.valor);
            removerHashEncadeado(&h,metodoDivisao(k),k);
            break;

        case 4:
            imprimirHashEncadeado(&h);
            system("pause>NULL");
            break;;
        default:
            printf("Digite uma opcao valida!\n");
            break;
            setbuf(stdin,NULL);
        }
    }while(op != 0);
    return 1;
}
