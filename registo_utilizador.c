#include <stdio.h>
#include <stdlib.h>
#define NOME 60
#define DESCRI 200
#define NUM 9
#include "header.h"

void registo_utilizador(List_u header_u){

    List_u novo=(List_u)malloc(sizeof(UTILIZADORES));
    List_u temp = header_u;

    int res, bi, cenas = 0,tamanho = 0, num_utilizador = 1;;

    fflush(stdin);

    while(temp->next!=NULL)/*correr a lista ate ao ultimo elemento*/
    {
        temp = temp->next;
        num_utilizador +=1;
    }


    if (novo!=NULL)
    {
        printf("Insira o seu nome: ");
        fgets(novo->nome,NOME,stdin);
        printf("\nInsira o seu numero do BI/CC: ");
        scanf("%d",&bi);
        fflush(stdin);
        bi = verificar_tam(bi);
        novo->bi = bi;
        novo->next = temp->next;
        temp->next = novo;

        temp = header_u;

        for( ;temp->next!=NULL;temp = temp->next)
        {
            if(novo->bi == temp->bi)
            {
                system("cls");
                erros("Ja existe um utilizador com esse numero de BI/CC!\nInsira um novo numero:\n");
                fflush(stdin);
                scanf("%d",&bi);
                bi = verificar_tam(bi);
                fflush(stdin);
                novo->bi = bi;
                temp = header_u;
            }
        }
        novo->n_utilizador = num_utilizador;


    }



    printf("Registo efectuado com sucesso! Numero de utilizador atribuido: %d\n\n",num_utilizador);
    fflush(stdin);
    getchar();


}


void editar_utilizador(List_u header_u)
{
    int num;
    char x = 1;
    List_u temp = header_u;
    List_u aux;
    temp = temp->next;

    printf("Edição de Utilizador\n\n");

    if(header_u->next == NULL)
    {
        fflush(stdin);
        erros("Nao existe nenhum utilizador na base de dados\nPressione uma tecla para continuar...");
        getchar();
        system("cls");
        return;
    }

    while(x)
    {
        aux = header_u->next;
        system("CLS");
        printf("Edicao de Utilizador\n\n");
        fflush(stdin);
        printf("Operacao pretendida:\n[1]-Mudar nome de utilizador\t[2]-Mudar num BI/CC\t[0]-Voltar\n");
        printf("\n       Insira a sua escolha: ");
        scanf("%c",&x);
        fflush(stdin);


        switch(x)
        {
             default:
            {
                system("CLS");
                avisos("A sua escolha e invalida, por favor tente novamente\n\n");
                fflush(stdin);
                getchar();
                break;
            }

            case '1':
            {
                system("CLS");
                printf("Qual o numero do utilizador que deseja alterar?\n");
                scanf("%d",&num);
                for( ;aux!=NULL;aux = aux->next)
                {
                    if(aux->n_utilizador==num)
                    {
                        fflush(stdin);
                        printf("Nome actual do Utilizador: %s\n",aux->nome);
                        printf("Insira o novo nome:    ");
                        fgets(aux->nome,NOME,stdin);
                        printf("Pretende editar outro Utilizador?\n");
                        printf("[1]-SIM\t[0]-NAO :");
                        scanf("%d",&x);
                        fflush(stdin);

                    }
                    else
                    {
                        system("CLS");
                        fflush(stdin);
                        erros("Nao introduzio um numero de utilizador valido");
                        getchar();
                        break;
                    }
                }
                break;
            }

            case '2':
            {
                int num_bi;
                system("CLS");
                printf("Qual o numero do Utilizador que deseja alterar?\n");
                scanf("%d",&num);
                for( ;aux!=NULL;aux = aux->next)
                {
                    if(aux->n_utilizador==num)
                    {
                        fflush(stdin);
                        printf("Insira o novo numero de BI/CC:    ");
                        scanf("%d",&num_bi);
                        aux->bi = num_bi;
                        fflush(stdin);
                        printf("Pretende editar outro Utilizador?\n");
                        printf("[1]-SIM\t[0]-NAO : ");
                        scanf("%d",&x);
                        fflush(stdin);

                    }
                    else
                    {
                        system("CLS");
                        fflush(stdin);
                        erros("Nao introduzio um numero de utilizador valido");
                        getchar();
                        break;
                    }
                }

                break;
            }

             case '0':
            {
                system("cls");
                return;
            }
        }
    }
    fflush(stdin);
    system("CLS");


}

void mostra_utilizadores(List_u header_u)
{
    List_u temp = header_u;
    temp = temp->next;

    if (temp == NULL)
    {
        erros("Nao ha utilizadores registados");
        getchar();
        goto skip;
    }
    else
    {
        topo();
        cabecalho_uti();
    }

    while(temp!=NULL)
    {
        conteudo_uti(temp->n_utilizador,temp->nome,temp->bi);

        temp = temp->next;
    }
    fim();
    skip:
    printf("\tPrima qualquer tecla para voltar ao menu");
    fflush(stdin);
    getchar();
    system("CLS");
}

