#include <stdio.h>
#include <stdlib.h>
#define NOME 30
#define DESCRI 200
#define NUM 9
#include "header.h"
#include <time.h>

void carrega(List_r header_r,List_s header_s, List_u header_u,List_r header_pre) /* SO "APANHA" O PRIMEIRO ELEMENTO */
{
    int num_sala,num,bi,h_i,m_i,h_f,m_f,dia,mes,ano;
    char sala[NOME];
    char line[NOME];
    char teste[NOME];
    List_s temp_s,novo_s;
    List_u temp_u,novo_u;
    List_r temp_r,novo_r;
    List_r temp_pre,novo_pre;

    temp_pre = header_pre;
    temp_r = header_r;
    temp_s = header_s;
    temp_u = header_u;

    FILE *abre_s = fopen("salas.txt","r");

    if(abre_s!=NULL)
    {
        while(fscanf(abre_s, "%d", &num_sala)==1)
            {
            novo_s = (List_s)malloc(sizeof(SALAS));
            novo_s->num = num_sala;
            fgets(line,NOME,abre_s);

            sprintf(novo_s->sala,"%s",line);

            novo_s->next = NULL;

            if(temp_s->next == NULL)
                temp_s->next = novo_s;
            else
            {
                for(temp_s = header_s;temp_s->next!= NULL; temp_s = temp_s->next);
                    temp_s->next = novo_s;
            }
        }
    }
    fclose(abre_s);


    /*carrega usuarios*/

    FILE *abre_u = fopen("usuarios.txt","r");

    if(abre_u!=NULL)
    {
        while(fscanf(abre_u, "%d%d", &num, &bi)==2)
        {
            novo_u = (List_s)malloc(sizeof(SALAS));
            novo_u->n_utilizador = num;
            novo_u->bi = bi;

            fgets(line,NOME,abre_u);

            strcpy(novo_u->nome,line);

            novo_u->next = NULL;

            if(temp_u->next == NULL)
                temp_u->next = novo_u;
            else
            {
                for(temp_u = header_u;temp_u->next!= NULL; temp_u = temp_u->next);
                temp_u->next = novo_u;
            }
        }
    }
    fclose(abre_u);

    /**ABRE RESERVAS **/

    FILE *abre_r = fopen("reservas.txt","r");

    if(abre_r!=NULL)
    {

        while(fscanf(abre_u, "%d%d%d%d%d%d%d%d%d",&num,&num_sala,&h_i,&m_i,&h_f,&m_f,&dia,&mes,&ano)==9)
        {
            novo_r = (List_r)malloc(sizeof(SALAS));

            novo_r->n_utilizador = num;
            novo_r->n_sala = num_sala;
            novo_r->hora_ini1 = h_i;
            novo_r->hora_ini2 = m_i;
            novo_r->hora_fim1 = h_f;
            novo_r->hora_fim2 = m_f;
            novo_r->dia = dia;
            novo_r->mes = mes;
            novo_r->ano = ano;



            novo_r->next = NULL;

            if(temp_r->next == NULL)
                temp_r->next = novo_r;
            else
            {
                for(temp_r = header_r;temp_r->next!= NULL; temp_r = temp_r->next);
                temp_r->next = novo_r;
            }
        }
    }
    fclose(abre_r);

    /**Carrega Pre-Reservas**/

    FILE *abre_pre = fopen("pre-reservas.txt","r");

    if(abre_pre!=NULL)
    {

        while(fscanf(abre_u, "%d%d%d%d%d%d%d%d%d",&num,&num_sala,&h_i,&m_i,&h_f,&m_f,&dia,&mes,&ano)==9)
        {
            novo_pre = (List_r)malloc(sizeof(SALAS));

            novo_pre->n_utilizador = num;
            novo_pre->n_sala = num_sala;
            novo_pre->hora_ini1 = h_i;
            novo_pre->hora_ini2 = m_i;
            novo_pre->hora_fim1 = h_f;
            novo_pre->hora_fim2 = m_f;
            novo_pre->dia = dia;
            novo_pre->mes = mes;
            novo_pre->ano = ano;



            novo_pre->next = NULL;

            if(temp_pre->next == NULL)
                temp_pre->next = novo_pre;
            else
            {
                for(temp_pre = header_pre;temp_pre->next!= NULL; temp_pre = temp_r->next);
                temp_pre->next = novo_pre;
            }
        }
    }
    fclose(abre_pre);
}
