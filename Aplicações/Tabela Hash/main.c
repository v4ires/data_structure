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
