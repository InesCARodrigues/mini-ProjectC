#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NOME 60
#define DESCRI 200
#define NUM 9

#include "header.h"

int data(List_r novo)
{
    char dia[3], mes[3], ano[5], data[11];
    int i, t=0,j=0, dia_int,mes_int,ano_int, verif, res;

    printf("Introduza a data da sua reserva: (dd/mm/aaaa)");
    scanf("%s",data);

    for (i=0;data[i]!='\0';i++)
    {
        if(data[i]=='/')
            break;
        dia[i]=data[i];
    }

    for (i=3;data[i]!='\0';i++)
    {
        if(data[i]=='/')
            break;
        mes[t]=data[i];
        t++;
    }

    for(i=6;data[i]!='\0';i++)
    {
        ano[j]=data[i];
        j++;
    }

    dia_int = atoi(dia);
    mes_int = atoi(mes);
    ano_int = atoi(ano);

    res = compara_datas(dia_int,mes_int,ano_int);

    if (dia_int < 1 || dia_int >31)
        {
        erros("Data invalida\n");
        verif = 0;
        }
    else if (mes_int < 1 || mes_int > 12)
        {
        erros("Data invalida\n");
        verif = 2;
        }
    else if (ano_int < 2012 || ano_int > 2100)
        {
        erros("Data invalida\n");
        verif = 3;
        }
    else if(res == 0)
        {
        erros("Data invalida\n");
        verif = 4;
        }
    else
    {
        verif=1;
        novo->dia = dia_int;
        novo->mes = mes_int;
        novo->ano = ano_int;
    }

return verif;

}

int compara_datas(int dia, int mes, int ano)
{
    int dia_sys, mes_sys, ano_sys;
    struct tm *relogio = NULL;

    time_t calendario = 0;
    calendario= time(NULL);
    relogio = localtime(&calendario);

    dia_sys = relogio->tm_mday;
    mes_sys = relogio->tm_mon+1;
    ano_sys = 1900 + relogio->tm_year;

    if ((ano<ano_sys) || (ano==ano_sys && mes<mes_sys) || (ano==ano_sys && mes==mes_sys && dia<dia_sys))
        {
        /*Se a data do utilizador for inferior à data de sistema devolve 0
        que vai ser depois usado para verificar na funcao data */
        return 0;
        }
    else
        return 1;

}



