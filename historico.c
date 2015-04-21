#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define NOME 60
#define DESCRI 200
#define NUM 9

void historico_salas(List_r header_r,List_r header_pre)
{
    List_r temp_r,temp_n,novo_header,novo,aux;
    List_s temp_s;
    novo_header = (List_r)malloc(sizeof(RESERVAS));
    novo_header->next = NULL;
    temp_r = header_r;
    temp_n = novo_header;


    int num_sala, i;

    printf("Insira o numero da sala: ");
    scanf("%d",&num_sala);

    while(temp_r!=NULL) /*FAZ UMA LISTA APENAS COM A SALA PRETENDIDA*/
    {
        if (temp_r->n_sala == num_sala)
        {
            novo = (List_r)malloc(sizeof(RESERVAS));
            novo = memcpy (novo,temp_r, sizeof (RESERVAS));
            novo->next = NULL;
            temp_n->next = novo;
            temp_n = temp_n->next;
        }
        temp_r= temp_r->next;


    }

    /*ORDENA*/
    aux = (List_r)malloc(sizeof(RESERVAS));

    do
    {
        i = 0;
        for (temp_n = novo_header->next; temp_n->next != NULL; temp_n = temp_n->next)
        {
            if(temp_n->ano > temp_n->next->ano || temp_n->ano == temp_n->next->ano &&temp_n->mes >temp_n->next->mes || temp_n->ano == temp_n->next->ano && temp_n->mes == temp_n->next->mes && temp_n->dia > temp_n->next->dia)
            {
                aux->dia = temp_n->dia;
                aux->mes = temp_n->mes;
                aux->ano = temp_n->ano;

                temp_n->dia = temp_n->next->dia;
                temp_n->mes = temp_n->next->mes;
                temp_n->ano = temp_n->next->ano;

                temp_n->next->dia = aux->dia;
                temp_n->next->mes = aux->mes;
                temp_n->next->ano = aux->ano;
                i = 1;
            }
        }

    }while(i == 1);

    /*IMPRIME O "HISTORICO*/

    printf("\n\tRESERVAS\n\n\n");
    temp_n = novo_header->next;
    for( ;temp_n!=NULL;temp_n=temp_n->next)
    {
        printf("\n\tNumero da sala: %d",temp_n->n_sala);
        printf("\n\tHora Inicio: %d:%d\tHora Fim: %d:%d\n",temp_n->hora_ini1,temp_n->hora_ini2,temp_n->hora_fim1,temp_n->hora_fim2);
        printf("\tData: %d/%d/%d\n\n",temp_n->dia,temp_n->mes,temp_n->ano);
    }

    /*FREE*/
    fflush(stdin);
    getchar();
    system("cls");
}

void historico_util(List_r header_r,List_r header_pre)
{
    List_r temp_r,temp_n,novo_header,novo,aux;
    List_u temp_u;
    novo_header = (List_r)malloc(sizeof(RESERVAS));
    novo_header->next = NULL;
    temp_r = header_r;
    temp_n = novo_header;

    int num_u,i,j=1;

    printf("Insira o numero de utilizador: ");
    scanf("%d",&num_u);

    while(temp_r!=NULL) /*FAZ UMA LISTA APENAS COM O UTILIZADOR PRETENDIDO */
    {
        if (temp_r->n_utilizador == num_u)
        {
            novo = (List_r)malloc(sizeof(RESERVAS));
            novo = memcpy (novo,temp_r, sizeof (RESERVAS));
            novo->next = NULL;
            temp_n->next = novo;
            temp_n = temp_n->next;
        }
        temp_r= temp_r->next;
    }

    /*ORDENA*/
    aux = (List_r)malloc(sizeof(RESERVAS));

    do
    {
        i = 0;
        for (temp_n = novo_header->next; temp_n->next != NULL; temp_n = temp_n->next)
        {
            if(temp_n->ano < temp_n->next->ano || temp_n->ano == temp_n->next->ano &&temp_n->mes >temp_n->next->mes || temp_n->ano == temp_n->next->ano && temp_n->mes == temp_n->next->mes && temp_n->dia < temp_n->next->dia)
            {
                aux->dia = temp_n->dia;
                aux->mes = temp_n->mes;
                aux->ano = temp_n->ano;

                temp_n->dia = temp_n->next->dia;
                temp_n->mes = temp_n->next->mes;
                temp_n->ano = temp_n->next->ano;

                temp_n->next->dia = aux->dia;
                temp_n->next->mes = aux->mes;
                temp_n->next->ano = aux->ano;
                i = 1;
            }
        }

    }while(i == 1);

    /*IMPRIME O "HISTORICO*/

    printf("\n\tRESERVAS\n\n\n");
    temp_n = novo_header->next;
    for( ;temp_n!=NULL;temp_n=temp_n->next,j++)
    {
        /*printf("Nome da sala: %s",);*/
        printf("\tNumero de utilizador: %d\n",temp_n->n_utilizador);
        printf("\tReserva: %d \n", j);
        printf("\tHora Inicio: %d:%d\tHora Fim: %d:%d\n",temp_n->hora_ini1,temp_n->hora_ini2,temp_n->hora_fim1,temp_n->hora_fim2);
        printf("\tData: %d/%d/%d\n\n",temp_n->dia,temp_n->mes,temp_n->ano);
    }

    /*FREE*/

    fflush(stdin);
    getchar();
    system("cls");
}



