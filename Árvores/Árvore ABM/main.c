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

#include "abm.c"

int main(){
    node *n = NULL;
    FILE *f;
    int opcao,num;
    char str[4];

    do{
        system("cls");
        printf("->Arvore de Busca Multidirecional <ABM>\n");
        printf("\n1 - Inserir\n2 - Excluir\n3 - Imprimir\n4 - Imprimir ASC\n5 - Buscar\n6 - Ler Arquivo\n0 - SAIR\n");
        printf("Digite uma opcao: ");
        scanf("%d",&opcao);

        switch (opcao){
        case 0:
            opcao = 0;
            break;

        case 1:
            printf("Digite o valor da chave: ");
            scanf("%d",&num);
            inserirABM(&n,num);
            break;

        case 2:
            printf("Digite o valor da chave: ");
            scanf("%d",&num);
            removerABM(&n,num);
            break;

        case 3:
            printABM(n);
            system("pause>NULL");
            break;

        case 4:
            printf("\n");
            printASC(n);
            system("pause>NULL");
            break;

        case 5:
            printf("Digite o valor da chave: ");
            scanf("%d",&num);
            buscaABM(n,num);
            system("pause>NULL");
            break;

        case 6:
            f = fopen("input.txt","r");
            if(f == NULL)
                printf("Erro ao abrir o arquivo!\n");
            else{
                printf("Inserindo...");
                while(!feof(f)){
                    fgets(str, 4, f);
                    if(atoi(str)!=0)
                        inserirABM(&n,atoi(str));
                }
                fclose(f);
                system("pause>NULL");
            }
            break;

        default:
            printf("Digite uma opcao valida!\n");
            system("pause>NULL");
        }
        setbuf(stdin,NULL);
    }while(opcao!=0);

    return 0;
}

