#include <stdio.h>
#include <stdlib.h>
#define NOME 60
#define DESCRI 200
#define NUM 9
#include "header.h"

void pag_reservas(List_r header_r,List_s header_s,List_u header_u,List_r header_pre){
    fflush(stdin);
    int res=0;
    int numero;
    char aux;
    List_u temp = header_u;

    system("CLS");
    printf("RESERVAS\n\n");
    printf("Introduza o numero de usuario: ");scanf("%d",&numero);
    fflush(stdin);


    while(temp!=NULL)
    {
        if(numero == temp->n_utilizador)
        {
            reserva(header_r,header_s,temp,header_pre);
            return;
        }
        temp = temp->next;

    }

    printf("O numero %d nao se encontra na nossa base de dados.\nDeseja efectuar o registo do utilizador?(s/n) \n",numero);
    scanf("%c",&aux);
    if (aux == 's')
    {
        system("CLS");
        registo_utilizador(header_u);
    }

    else printf("O programa vai voltar ao menu inicial \n\n");
    fflush(stdin);
    getchar();
    system("CLS");
}

void reserva(List_r header_r,List_s header_s, List_u temp,List_r header_pre)
{

    List_s s;
    List_r novo = (List_r)malloc(sizeof(RESERVAS));
    List_r aux = header_r;
    int num = 0, i,cont, res, res2,res3, flag=0,auxi=0;
    char car;

    while(aux->next!=NULL) /*Puxa a lista das reservas para o fim */
        aux = aux->next;


    while(flag==0) /*While para o utilizador repetir a reserva caso tenha introduzido algo errado */
    {

        system("CLS");
        printf("Bem-vindo(a) %s\n",temp->nome);
        s = header_s;
        printf("Salas existentes:\n\n");

        if(s->next==NULL)
        {
            printf("ERRO: Nao existem salas na nossa base de dados.\n");
            getchar();
            system("CLS");
            return;
        }

        s = s->next;
        for(i = 1; s!=NULL;i++)
        {
            printf("%d. Sala %s",i,s->sala);
            s = s->next;
        }

        printf("Numero da sala a reservar: ");
        scanf("%d",&cont);

        s = header_s;

        for(i=0;i<cont;i++)
            s = s->next;

        res = recebe_horas_ini(novo);
          if (res==1) /*if que garante que só são introduzidas horas finais e data se não ocorrer erro nas iniciais*/
            {
                res2 = recebe_horas_fim(novo);
                res3 = data(novo);
            }
        else
            {
                res2 = 0;
                res3 = 0;
            }

        /** Vê se ja existe reserva para essa hora nessa sala**/


        if (res == 1 && res2==1 && res3 == 1)
        {
            novo->n_utilizador = temp->n_utilizador;
            novo->n_sala = s->num;
            auxi = valida_reserva(novo,header_r,header_pre,temp);

            if (auxi == 1)
                goto skip;


            printf("\n\t<DADOS DA RESERVA>\n");
            printf("   Nome: %s",temp->nome);
            printf("   N: %d\n",novo->n_utilizador);
            printf("   Sala: %s   Inicio: %d:%d\n   Fim: %d:%d\n",s->sala,novo->hora_ini1,novo->hora_ini2,novo->hora_fim1,novo->hora_fim2);
            printf("   Data: %d%c%d%c%d", novo->dia,47,novo->mes,47,novo->ano);

            flag=1;

            printf("\nConfirma a reserva? <s/n>\n");
            fflush(stdin);
            scanf("%c",&car);

            if(car == 's')
            {
                novo->next=NULL;
                aux->next=novo;
                printf("Reserva confirmada!");
                fflush(stdin);
                getchar();
                system("cls");
                return;
            }
            else
            {
                flag=0;
                printf("A sua reserva nao foi efectuada");
                fflush(stdin);
                getchar();
                system("CLS");
                return;
            }



        }

        else
        {
            printf("\nVolte a fazer a sua reserva\n\n");
            flag=0;
            fflush(stdin);
            getchar();
            system("cls");
        }

    }
    skip:
    fflush(stdin);
    system("CLS");
}

int valida_reserva(List_r novo,List_r header_r,List_r header_pre,List_u user)
{
   List_r temp = header_r;
   List_r temp_pre = header_pre;
   int aux1;

   for( ;temp!=NULL;temp=temp->next)
   {
       if(novo->n_sala == temp->n_sala && novo->dia == temp->dia && novo->mes == temp->mes && novo->ano == temp->ano)
       {
           if(novo->hora_ini1 >= temp->hora_ini1 && novo->hora_fim1 >= temp->hora_ini1 && novo->hora_ini2 >=temp->hora_ini2 && novo->hora_fim2 >= temp->hora_ini2 ||novo->hora_ini1 <= temp->hora_fim1  && novo->hora_fim1 <= temp->hora_fim1 && novo->hora_ini2 <= temp->hora_fim2 && novo->hora_fim2 <= temp->hora_fim2)
            /* Vai verificar se a hora e data pretendida para reserva está disponivel */
           {
                continue;
           }
           else
           {
               printf("A sala que pretende reservar ja se encontra reservada para esse horario\nDeseja fazer uma pre-reserva?\n");
               printf("[1]-Sim\t[0]-Nao\n");
               scanf("%d",&aux1);

               if(aux1==1)
               {
                   while(temp_pre->next!=NULL)
                       temp_pre = temp_pre->next;

                    novo->next=NULL;
                    temp_pre->next=novo;


                    printf("\n\t<DADOS DA PRE-RESERVA>\n");
                    printf("   Nome: %s",user->nome);
                    printf("   N: %d\n",novo->n_utilizador);
                    printf("   Sala: %d   Inicio: %d:%d\n   Fim: %d:%d\n",novo->n_sala,novo->hora_ini1,novo->hora_ini2,novo->hora_fim1,novo->hora_fim2);
                    printf("   Data: %d%c%d%c%d\n", novo->dia,47,novo->mes,47,novo->ano);

                   printf("Pre-reserva guardada com sucesso!");
                   fflush(stdin);
                   getchar();
                   return 1;
               }


               printf("O programa vai voltar ao menu principal");
               fflush(stdin);
               getchar();
               system("cls");
               return 1;

           }
        }
   }

}

void elimina_reserva(List_r header_r,List_s header_s,List_u header_u,List_r header_pre)
{

    int num,i,aux;
    List_r temp_pre = header_pre;
    List_r temp_r = header_r;
    List_u temp_u = header_u;
    List_s temp_s = header_s;
    List_r ante;

    temp_r = temp_r->next;

    system("CLS");

        if (header_r->next==NULL)
        {
            fflush(stdin);
            erros("Nao existem reservas\nPressione uma tecla para continuar...");
            getchar();
            system("cls");
            return;
        }


    for( ;temp_r!=NULL;temp_r=temp_r->next)
    {
        i++;
        printf("\n\tReserva numero %d\n",i);
        printf("   Sala N%c: %d   Inicio: %d:%d\tFim: %d:%d\n",167,temp_r->n_sala,temp_r->hora_ini1,temp_r->hora_ini2,temp_r->hora_fim1,temp_r->hora_fim2);
        printf("   Data: %d%c%d%c%d\n\n", temp_r->dia,47,temp_r->mes,47,temp_r->ano);
    }
    printf("Seleccione 0 para sair\n\n");
    printf("Qual o numero da reserva que pretende eliminar: ");
    scanf("%d",&aux);

    temp_r = header_r;

    if (aux != 0)
    {
        for(i=0;i<aux;i++)
        {
            ante=temp_r;
            temp_r=temp_r->next;
        }


        ante->next=temp_r->next;
        free(temp_r);

        printf("A reserva %d foi eliminada",aux);



        fflush(stdin);
        getchar();
    }
    else
        return;

}

void elimina_pre(List_r header_r,List_s header_s,List_u header_u,List_r header_pre)
{

    int num,i,aux;
    List_r temp_pre = header_pre;
    List_r temp_r = header_r;
    List_u temp_u = header_u;
    List_s temp_s = header_s;
    List_r ante;

    temp_pre = temp_pre->next;

    system("CLS");

    if (header_pre->next==NULL)
    {
        fflush(stdin);
        erros("Nao existem pre-reservas\nPressione uma tecla para continuar...");
        getchar();
        system("cls");
        return;
    }


    for( ;temp_pre!=NULL;temp_pre=temp_pre->next)
    {
        i++;
        printf("\n\tReserva numero %d\n",i);
        printf("   Sala N%c: %d   Inicio: %d:%d\tFim: %d:%d\n",167,temp_pre->n_sala,temp_pre->hora_ini1,temp_pre->hora_ini2,temp_pre->hora_fim1,temp_pre->hora_fim2);
        printf("   Data: %d%c%d%c%d\n\n", temp_pre->dia,47,temp_pre->mes,47,temp_pre->ano);
    }

    printf("Seleccione 0 para sair\n\n");
    printf("Qual o numero da reserva que pretende eliminar: ");
    scanf("%d",&aux);

    temp_pre = header_pre;

    if (aux != 0)
    {
        for(i=0;i<aux;i++)
        {
            ante=temp_pre;
            temp_pre=temp_pre->next;
        }

        ante->next=temp_pre->next;
        free(temp_pre);

        printf("A pre-reserva %d foi eliminada",aux);
        fflush(stdin);
        getchar();
    }
    else
        return;
}

/*int verifica_prereserva(List_r header_r,List_r header_pre,int num)
{
    List_r temp_r;
    List_r temp_pre;
    List_r ant;

    temp_r = header_r;
    temp_pre = header_pre;

    int i;

    if(num ==0)
        return 0;

    for(i=0;i<num;i++)
        temp_r=temp_r->next;


    while(temp_pre->next!=NULL)
    {
        ant = temp_pre;
        temp_pre = temp_pre->next;

        if(temp_r->dia == temp_pre->dia && temp_r->mes == temp_pre->mes && temp_r->ano == temp_pre->ano)
        {
            if (temp_pre->hora_ini1 > temp_r->hora_ini1 || temp_pre->hora_ini1 == temp_r->hora_ini1 && temp_pre->hora_ini2 >= temp_r->hora_ini2 || temp_pre->hora_fim1 < temp_r->hora_fim1 || temp_pre->hora_fim1 == temp_r->hora_fim1 && temp_pre->hora_fim2 <= temp_r->hora_fim2)
            {
                temp_r = memcpy(temp_r,temp_pre, sizeof (RESERVAS));
                ant->next=temp_pre->next;
                free(temp_pre);
                return 1;
            }
        }

    }

    return 0;

}*/

