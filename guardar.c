#include <stdio.h>
#include <stdlib.h>
#define NOME 60
#define DESCRI 200
#define NUM 9
#include "header.h"
#include <time.h>


void guardar(List_r header_r,List_s header_s, List_u header_u, List_r header_pre)
{
    /*Cria copias dos headers */
    List_r temp_r = header_r;
    List_s temp_s = header_s;
    List_u temp_u = header_u;
    List_r temp_pre = header_pre;



    FILE *guarda_u = fopen("usuarios.txt","w");
    FILE *guarda_s = fopen("salas.txt","w");
    FILE *guarda_r = fopen("reservas.txt","w");
    FILE *guarda_pre = fopen("pre-reservas.txt","w");

    temp_u=temp_u->next;
    while(temp_u!=NULL)
    {
        fprintf(guarda_u,"%d ",temp_u->n_utilizador);
        fprintf(guarda_u,"%d",temp_u->bi);
        fprintf(guarda_u,"%s\n",temp_u->nome);
        temp_u = temp_u -> next;
    }
    fclose(guarda_u);

    temp_s=temp_s->next;
    while(temp_s!=NULL)
    {
        fprintf(guarda_s,"%d",temp_s->num);
        fprintf(guarda_s,"%s\n",temp_s->sala);
        temp_s=temp_s->next;
    }
    fclose(guarda_s);

    temp_r=temp_r->next;
    while(temp_r!=NULL)
    {
        fprintf(guarda_r,"%d %d %d %d %d %d %d %d %d\n",temp_r->n_utilizador,temp_r->n_sala,temp_r->hora_ini1,temp_r->hora_ini2,temp_r->hora_fim1,temp_r->hora_fim2, temp_r->dia, temp_r->mes, temp_r->ano);
        temp_r=temp_r->next;
    }
    fclose(guarda_r);

    temp_pre=temp_pre->next;
     while(temp_pre!=NULL)
    {
        fprintf(guarda_pre,"%d %d %d %d %d %d %d %d %d\n",temp_pre->n_utilizador,temp_pre->n_sala,temp_pre->hora_ini1,temp_pre->hora_ini2,temp_pre->hora_fim1,temp_pre->hora_fim2,temp_pre->dia, temp_pre->mes, temp_pre->ano);
        temp_pre=temp_pre->next;
    }
    fclose(guarda_pre);
}
