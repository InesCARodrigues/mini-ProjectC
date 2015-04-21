#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define NOME 60
#define DESCRI 200
#define NUM 9


void criar_sala(List_s header_s)
{
    fflush(stdin);
    List_s novo = (List_s)malloc(sizeof(SALAS));
    List_s aux = header_s;
    int num;
    char descri[DESCRI];

    while (aux->next!= NULL)
        aux = aux->next;

    if(novo!=NULL)
    {
        printf("Insira o nome da sala: ");fgets(novo->sala,NOME,stdin);
        fflush(stdin);
        printf("O numero da sala: ");scanf("%d",&num);
        fflush(stdin);
        while(num>999)
        {
            erros("O numero da sala deve ser inferior a 999. Por introduza novamente o numero:\n");
            scanf("%d",&num);
        }
        novo->num = num;

        novo->next = aux->next;
        aux->next = novo;

        aux = header_s;

         for( ;aux->next!=NULL;aux = aux->next)
        {
            if(novo->num == aux->num)
            {
                erros("Ja existe uma sala com esse numero!\nInsira o numero da sala novamente\n");
                fflush(stdin);
                scanf("%d",&num);
                fflush(stdin);
                novo->num = num;
                aux = header_s;
            }
        }

    }


        printf("A sala foi adicionada com sucesso.\n\n");
        fflush(stdin);
        getchar();
        system("CLS");

}

void consulta_sala(List_s header_s)
{
    ordena_salas(header_s);
    system("CLS");
    List_s temp = header_s;
    temp = temp->next;

    if (temp == NULL)
    {
        erros("Nao existem salas guardadas\n");
        getchar();
        goto skip;
    }
    else
    {
        topo();
        cabecalho_salas();
    }

    while(temp!=NULL)
    {
       conteudo(temp->num,temp->sala);
       temp = temp->next;
    }
    fim();
    skip:
    printf("\tPrima qualquer tecla para voltar ao menu");
    fflush(stdin);
    getchar();
    system("CLS");
}

void edita_sala(List_s header_s)
{
    int num;
    char x;
    List_s aux;
    printf("Edicao de Sala\n\n");

    if(header_s->next == NULL)
    {
        fflush(stdin);
        erros("Nao existe nenhuma sala na base de dados\nPressione uma tecla para continuar...");
        getchar();
        system("cls");
        return;
    }

    while(x)
    {
        aux = header_s->next;
        system("CLS");
        printf("Edicao de Salas\n\n");
        fflush(stdin);
        printf("Operacao pretendida:\n[1]-Mudar nome\t[2]-Mudar numero\t[0]-Voltar\n");
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
                printf("Qual o numero da sala que deseja alterar?\n");
                scanf("%d",&num);
                for( ;aux!=NULL;aux = aux->next)
                {
                    if(aux->num==num)
                    {
                        fflush(stdin);
                        printf("Nome actual da sala: %s\n",aux->sala);
                        printf("Insira o novo nome:    ");
                        fgets(aux->sala,NOME,stdin);
                        printf("Pretende editar outra sala?\n");
                        printf("[1]-SIM\t[0]-NAO :");
                        scanf("%d",&x);
                        fflush(stdin);
                    }
                    else
                    {
                        system("CLS");
                        fflush(stdin);
                        erros("Nao introduzio uma sala valida");
                        getchar();
                        break;
                    }
                }
                break;
            }

            case '2':
            {
                int sala_num;
                system("CLS");
                printf("Qual o numero da sala que deseja alterar?\n");
                scanf("%d",&num);
                for( ;aux!=NULL;aux = aux->next)
                {
                    if(aux->num==num)
                    {
                        fflush(stdin);
                        printf("Insira o novo numero:    ");
                        scanf("%d",&sala_num);
                        aux->num = sala_num;
                        fflush(stdin);
                        printf("Pretende editar outra sala?\n");
                        printf("[1]-SIM\t[0]-NAO : ");
                        scanf("%d",&x);
                        fflush(stdin);

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

void ordena_salas(List_s header_s)
{
    List_s temp, aux1;
    aux1 = (List_s)malloc(sizeof(SALAS));
    int i;

    do
    {
        i = 0;
        for (temp = header_s; temp->next != NULL; temp = temp->next)
        {
            if(temp->num > temp->next->num)
            {
                aux1->num = temp->num;
                sprintf(aux1->sala,"%s",temp->sala);

                temp->num = temp->next->num;
                sprintf(temp->sala,"%s",temp->next->sala);

                temp->next->num = aux1->num;
                sprintf(temp->next->sala,"%s",aux1->sala);
                i = 1;
            }
        }

    }while(i == 1);
}
