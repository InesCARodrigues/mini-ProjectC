#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"
#define NOME 60
#define DESCRI 200
#define NUM 9

void carrega_menu(List_r header_r,List_s header_s,List_u header_u,List_r header_pre){

    system("CLS");
    system("title Projecto PPP");

    char menu = 1;
    char mini_menu = 1;

    while(menu)
    {
        tempo();
        topo();
        lados(2);
        texto("1-Reservas");
        lados(1);
        texto("2-Utilizadores");
        lados(1);
        texto("3-Historico de reservas");
        lados(1);
        texto("4-Salas");
        lados(1);
        texto("5-Guardar");
        lados(1);
        texto("0-Sair");
        lados(2);
        fim();

        printf("\n       Insira a sua escolha: ");
        scanf("%s",&menu);

        switch (menu)
        {
            default:
            {
                system("CLS");
                avisos("A sua escolha é invalida, por favor tente novamente\n\n");
                break;
            }
            case '1':
            {
                while(mini_menu)
                {
                    system("CLS");
                    tempo();
                    topo();
                    lados(2);
                    texto("1-Criar reserva");
                    lados(1);
                    texto("2-Cancelar reserva");
                    lados(1);
                    texto("3-Cancelar pre-reserva");
                    lados(1);
                    texto("0-Voltar");
                    lados(2);
                    fim();
                    printf("\n       Insira a sua escolha: ");
                    scanf("%s",&mini_menu);

                    switch(mini_menu)
                    {
                        case '1':
                             {
                                pag_reservas(header_r,header_s,header_u,header_pre);
                                break;
                             }
                        case '2':
                            {
                                system("CLS");
                                elimina_reserva(header_r,header_s,header_u,header_pre);
                                fflush(stdin);
                                break;
                            }
                        case '3':
                            {
                                system("CLS");
                                elimina_pre(header_r,header_s,header_u,header_pre);
                                fflush(stdin);
                                break;
                            }
                        case '0':
                            {
                                system("CLS");
                                carrega_menu(header_r,header_s,header_u,header_pre);
                                return;
                            }
                    }
                }
            }

            case '2':
            {
                system("CLS");
                while(mini_menu)
                {
                    system("cls");
                    tempo();
                    topo();
                    lados(2);
                    texto("1-Adicionar utilizador");
                    lados(1);
                    texto("2-Editar utilizador");
                    lados(1);
                    texto("3-Consultar lista de utilizadores");
                    lados(1);
                    texto("0-Voltar");
                    lados(2);
                    fim();
                    printf("\n       Insira a sua escolha: ");
                    scanf("%s",&mini_menu);

                    switch(mini_menu)
                    {
                        default:
                        {
                            system("CLS");
                            avisos("A sua escolha e invalida, por favor tente novamente\n\n");
                            break;
                        }
                        case '1':
                        {
                            system("CLS");
                            registo_utilizador(header_u);
                            break;
                        }
                        case '2':
                        {
                            system("CLS");
                            editar_utilizador(header_u);
                            break;
                        }
                        case '3':
                        {
                            system("CLS");
                            mostra_utilizadores(header_u);
                            break;
                        }
                        case '0':
                        {
                            system("CLS");
                            carrega_menu(header_r,header_s,header_u,header_pre);
                            return;
                        }
                    }
                }
            }
            case '3':
            {
                while(mini_menu)
                {
                    system("CLS");
                    tempo();
                    topo();
                    lados(2);
                    texto("1-Reservas de uma sala");
                    lados(1);
                    texto("2-Reservas de um utilizador");
                    lados(1);
                    texto("0-Voltar");
                    lados(2);
                    fim();
                    printf("\n Insira a sua escolha: ");
                    scanf("%s",&mini_menu);

                    switch(mini_menu)
                    {
                        case '1':
                        {
                            system("CLS");
                            historico_salas(header_r,header_pre);
                            break;
                        }
                        case '2':
                        {
                            system("CLS");
                            historico_util(header_r,header_pre);
                            break;
                        }
                    case '0':
                        {
                            system("CLS");
                            carrega_menu(header_r,header_s,header_u,header_pre);
                            return;
                        }
                    }
                }
                break;
            }
            case '4':
            {
                system("CLS");
                while(mini_menu)
                {
                    tempo();
                    topo();
                    lados(2);
                    texto("1-Adicionar sala");
                    lados(1);
                    texto("2-Editar sala");
                    lados(1);
                    texto("3-Consultar as salas existentes");
                    lados(1);
                    texto("0-Voltar");
                    lados(2);
                    fim();
                    printf("\n       Insira a sua escolha: ");
                    scanf("%s",&mini_menu);

                    switch(mini_menu)
                    {
                        default:
                        {
                            system("CLS");
                            avisos("A sua escolha é invalida, por favor tente novamente\n\n");
                            break;
                        }
                        case '1':
                        {
                            system("CLS");
                            criar_sala(header_s);
                            break;
                        }
                         case '2':
                        {
                            system("CLS");
                            edita_sala(header_s);
                            break;
                        }
                        case '3':
                        {
                            system("CLS");
                            consulta_sala(header_s);
                            break;
                        }
                        case '0':
                        {
                            system("CLS");
                            carrega_menu(header_r,header_s,header_u,header_pre);
                            return;
                        }
                    }
                }

            break;
            }
            case '5':
            {
                system("CLS");
                guardar(header_r,header_s,header_u,header_pre);
                printf("Os dados foram guardados com sucesso!");
                getch();
                system("CLS");
                break;
            }

            case '0':
            {
                system("CLS");
                printf("Obrigado por ter utilizado o nosso programa\n\n");
                return;
            }
        }
    }
}
