#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOME 60
#define DESCRI 200
#define NUM 9
#include "header.h"

int recebe_horas_ini(List_r novo)
{
    char horas[3], mins[3], horas_inicio[6];
    int i, t=0, horas_int,mins_int, verif;


    printf("Introduza as horas de inicio da reserva: (hh:mm)\n");
    scanf("%s", horas_inicio);

    for (i=0;horas_inicio[i]!='\0';i++)
    {
        if (horas_inicio[i]==':')
            break;
        horas[i] = horas_inicio[i];
    }

    for (i=3;horas_inicio[i]!='\0';i++)
    {
        mins[t]=horas_inicio[i];
        t++;
    }

    horas_int = atoi(horas);
    mins_int = atoi(mins);

    if (horas_int < 10 || horas_int > 24)
    {
        erros("As horas introduzidas nao sao validas 1");
        verif=0;
    }
    else if (mins_int != 0 && mins_int != 30)
    {
        erros("As horas introduzidas nao sao validas 1");
        verif=0;
    }
    else
    {
        novo->hora_ini1 = horas_int;
        novo->hora_ini2 = mins_int;
        verif=1;
    }

    return verif;
}

int recebe_horas_fim(List_r novo)
{
    char horas[3], mins[3], horas_fim[6];
    int i, t=0, horas_int,mins_int, verif;

    printf("Introduza as horas de final da reserva: (hh:mm)\n");
    scanf("%s", horas_fim);

    for (i=0;horas_fim[i]!='\0';i++)
    {
        if (horas_fim[i]==':')
            break;
        horas[i] = horas_fim[i];
    }

    for (i=3;horas_fim[i]!='\0';i++)
    {
        mins[t]=horas_fim[i];
        t++;
    }

    horas_int = atoi(horas);
    mins_int = atoi(mins);


    if (horas_int < 10 || horas_int > 24)
    {
        erros("As horas introduzidas nao sao validas");
        verif=0;
    }
    else if (mins_int != 0 && mins_int != 30)
    {
        erros("As horas introduzidas nao sao validas");
        verif=0;
    }
    else
    {
        novo->hora_fim1 = horas_int;
        novo->hora_fim2 = mins_int;
        verif=1;
    }

    return verif;
}
