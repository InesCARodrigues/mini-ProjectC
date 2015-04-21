#include <stdio.h>
#include <stdlib.h>

#include "header.h"

/** REMOVE /N DO FGETS**/
void retira_n(char text1[])
{
    int len;
    len = strlen(text1);
    if( text1[len-1] == '\n' )
        text1[len-1] = 0;
}



void topo()
{
    int i;

    printf(" %c", 201);
    for (i=0;i<76;i++)
    {
        printf("%c", 205);
    }
    printf("%c\n", 187);

}

void fim()
{
    int i;

    printf(" %c", 200);
    for (i=0;i<76;i++)
    {
        printf("%c", 205);
    }
    printf("%c \n", 188);
}

void lados (int n)
{
    for ( ;n>0;n--)
        printf(" %c%77c\n", 186,186);


}


void texto (char text1[])
{
    int tamanho,i;
    printf(" %c     %s",186,text1);

    tamanho = 71 - strlen(text1);
    for (i=0;i<tamanho;i++)
    {
        printf(" ");
    }
    printf("%c\n",186);

}

/** AVISO E ERROS COLOCADOS **/


void avisos (char text1[])
{
    printf("         %c%c  AVISO  %c%c         \n\n", 174,174,175,175);
    printf("%s", text1);
}

void erros (char text1[])
{
    printf("\n         %c%c  ERRO  %c%c         \n\n", 174,174,175,175);
    printf("%s", text1);
}

/** MOLDURA DAS SALAS **/

void cabecalho_salas()
{
    int tamanho,i;
    printf(" %c N%c     %c  NOME DA SALA ",186,167,179);
    tamanho = 52;
    for (i=0;i<tamanho;i++)
    {
        printf(" ");
    }
    printf("%c\n",186);
}

void conteudo(int num,char text1[])
{
    retira_n(text1);
    int x,i,tam,tam_num;
    printf(" %c", 186);
    for (i=0;i<76;i++)
    {
        printf("%c", 196);
    }
    printf("%c", 186);
    tam_num = (int)log10(num)+1;
    if(tam_num==1)
        printf("  %c %d      %c  %s",186,num,179,text1);
    else if(tam_num==2)
        printf("  %c %d     %c  %s",186,num,179,text1);
    else
        printf("  %c %d    %c  %s",186,num,179,text1);
    x = strlen(text1);
    tam = 65-x;
    for(i=0;i<tam;i++)
        printf(" ");
    printf("%c\n",186);
}

/** MOLDURA DOS UTILIZADORES **/

void cabecalho_uti()
{
    int tamanho,i;
    printf(" %c N%c     %c  N%c BI%cCC      %c  NOME DE UTILIZADOR",186,167,179,167,47,179,179);
    tamanho = 30;
    for (i=0;i<tamanho;i++)
    {
        printf(" ");
    }
    printf("%c\n",186);
}

void conteudo_uti(int num,char text1[], int bi)
{
    retira_n(text1);
    int x,i,tam,tam_num;
    printf(" %c", 186);
    for (i=0;i<76;i++)
    {
        printf("%c", 196);
    }
    printf("%c", 186);
    tam_num = (int)log10(num)+1;
    if (tam_num == 1)
        printf("  %c %d      %c  %d      %c  %s",186,num,179,bi,179,text1);
    else if(tam_num==2)
        printf("  %c %d     %c  %d      %c  %s",186,num,179,bi,179,text1);
    else
         printf("  %c %d    %c  %d      %c  %s",186,num,179,bi,179,text1);


    x = strlen(text1);
    tam = 48-x;
    for(i=0;i<tam;i++)
        printf(" ");
    printf("%c\n",186);
}

