#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char tempo()
    {

        char *mes[12] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
        struct tm *relogio = NULL;

        time_t calendario = 0;
        calendario= time(NULL);
        relogio = localtime(&calendario);

        printf("\n%c%57c %d de %s de %d \n",32,32,relogio->tm_mday,mes[relogio->tm_mon],1900 + relogio->tm_year);
    }
