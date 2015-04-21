#include <stdio.h>
#include <stdlib.h>
#define NOME 60
#define DESCRI 200
#define NUM 9
#include "header.h"


int verificar_tam(int bi)
{
    int cenas, tamanho;
    while(cenas)
    {
        tamanho = (int)log10(bi)+1;

        if (tamanho !=8)
            {
            system("cls");
            fflush(stdin);
            erros("O numero do CC/BI deve ter 8 digitos\n");
            fflush(stdin);
            printf("\nInsira o seu numero do BI/CC: "); scanf("%d",&bi);
            cenas=1;
            fflush(stdin);
            }
        else
            cenas = 0;
    }
    return bi;

}

