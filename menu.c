#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "menu.h"
#include "tabuleiro.h"
#include "pecas.h"
#include "funcao.h"
#include "ranking.h"

void menu()
{
    char seta=0, cursor =0;

    hidecursor();
    system("mode con:cols=80 lines=30");

    //Looping para printar o MENU na tela!!!
    do
    {
        printf("   _______  ______    _______  _______  ___   _  _______  __   __  _______\n");
        printf("  |  _    ||    _ |  |       ||   _   ||   | | ||       ||  | |  ||       |\n");
        printf("  | |_|   ||   | ||  |    ___||  |_|  ||   |_| ||   _   ||  | |  ||_     _|\n");
        printf("  |       ||   |_||_ |   |___ |       ||      _||  | |  ||  |_|  |  |   |  \n");
        printf("  |  _   | |    __  ||    ___||       ||     |_ |  |_|  ||       |  |   |  \n");
        printf("  | |_|   ||   |  | ||   |___ |   _   ||    _  ||       ||       |  |   |  \n");
        printf("  |_______||___|  |_||_______||__| |__||___| |_||_______||_______|  |___|  \n\n\n");

        if(cursor==0)
        {
            printf("\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
            printf("\t\t\t\t\xBA-->>PLAY         \xBA \n");
            printf("\t\t\t\t\xBA    RANKING      \xBA \n");
            printf("\t\t\t\t\xBA    INSTRUCTIONS \xBA \n");
            printf("\t\t\t\t\xBA    EXIT         \xBA \n");
            printf("\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            system("color B");//Verde-Água Claro!!!
        }
        else if(cursor==1)
        {
            printf("\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
            printf("\t\t\t\t\xBA    PLAY         \xBA \n");
            printf("\t\t\t\t\xBA-->>RANKING      \xBA \n");
            printf("\t\t\t\t\xBA    INSTRUCTIONS \xBA \n");
            printf("\t\t\t\t\xBA    EXIT         \xBA \n");
            printf("\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            system("color A");//Verde Claro!!!
        }
        else if(cursor==2)
        {
            printf("\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
            printf("\t\t\t\t\xBA    PLAY         \xBA \n");
            printf("\t\t\t\t\xBA    RANKING      \xBA \n");
            printf("\t\t\t\t\xBA-->>INSTRUCTIONS \xBA \n");
            printf("\t\t\t\t\xBA    EXIT         \xBA \n");
            printf("\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            system("color E");//Amarelo Claro!!!
        }
        else if(cursor==3)
        {
            printf("\t\t\t\t\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
            printf("\t\t\t\t\xBA    PLAY         \xBA \n");
            printf("\t\t\t\t\xBA    RANKING      \xBA \n");
            printf("\t\t\t\t\xBA    INSTRUCTIONS \xBA \n");
            printf("\t\t\t\t\xBA-->>EXIT         \xBA \n");
            printf("\t\t\t\t\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
            system("color D");//Lilás!!!

        }

        seta = getch();
        system("cls");

        //Condicional para dar um break!!!
        if (seta == 13)
        {
            break;
        }

        //Condicionais para fazer o cursor subir(CASE 72) ou descer(CASE 80)!!!
        switch(seta)
        {
        case 72:
        {
            cursor=cursor-1;
            break;
        }
        case 80:
        {
            cursor=cursor+1;
            break;
        }

        }

        if(cursor<0)
        {
            cursor=3;
        }
        else if(cursor>3)
        {
            cursor=0;
        }

    }
    while(1);

     //Condicionais para determinar para qual função o cursor vai levar!
    //Iniciar o jogo!!!
    if (cursor == 0)
    {
        tabuleiro();
        pecas();
    }
    else if (cursor == 1)
    {
        ranking();
    }
    //Tutorial!!!
    else if(cursor == 2)
    {
        instructions();
    }
    //Sair do jogo!!!
    else if (cursor == 3)
    {
        system("color F");
        printf("\n\n\n\t\t\t\tVOCE SAIU DO JOGO \n");
        Sleep(1000);
        exit(0);
    }
}
