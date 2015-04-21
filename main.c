#include <stdio.h>
#include <stdlib.h>
#define NOME 60
#define DESCRI 200
#define NUM 9
#include "header.h"
#include <time.h>

int main()
{
    /*definir headers*/
    List_r header_r=(List_r) malloc (sizeof (RESERVAS));
    List_s header_s=(List_s) malloc (sizeof (SALAS));
    List_u header_u=(List_u) malloc (sizeof (UTILIZADORES));
    List_r header_pre = (List_r)malloc(sizeof(RESERVAS));

    if (header_r && header_s && header_u != NULL)
        {
        header_r->next = NULL;
        header_u->next = NULL;
        header_s->next = NULL;
        header_pre->next = NULL;
        }
        else{
            erros("Impossivel executar o programa");
            return 0;
            }

    carrega(header_r,header_s,header_u,header_pre);

    carrega_menu(header_r,header_s,header_u,header_pre);

    guardar(header_r,header_s,header_u,header_pre);

    apagar_listas(header_r,header_s,header_u,header_pre);

    return 0;
}
