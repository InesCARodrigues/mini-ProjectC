#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void apagar_listas(List_r header_r,List_s header_s,List_u header_u,List_r header_pre)
{
    List_r temp_r,temp_pre;
    List_s temp_s;
    List_u temp_u;

    while(header_r!=NULL)
    {
        temp_r = header_r;
        header_r=header_r->next;
        free(temp_r);
    }
    free(header_r);

    while(header_s!=NULL)
    {
        temp_s = header_s;
        header_s=header_s->next;
        free(temp_s);
    }
    free(header_s);

    while(header_u!=NULL)
    {
        temp_u = header_u;
        header_u=header_u->next;
        free(temp_u);
    }
    free(header_u);

    while(header_pre!=NULL)
    {
        temp_pre = header_pre;
        header_pre=header_pre->next;
        free(temp_pre);
    }
    free(header_pre);


}
