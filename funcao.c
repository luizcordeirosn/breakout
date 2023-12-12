#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "menu.h"
#include "funcao.h"
#include "ranking.h"

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}
void hidecursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
//Função para fazer um LOADING!!!
void loading()
{
    hidecursor();
    //Comando Sleep para fazer um LOADING!!!
    printf("\t\t\t\t\n\n\n\n\t\t\t\tLOADING...13%%");
    system("color F");//Branco Brilhante!!!
    Sleep(1000);
    system("cls");

    printf("\n\n\n\n\t\t\t\tLOADING...27%%");
    system("color F");//Branco Brilhante!!!
    Sleep(1000);
    system("cls");

    printf("\n\n\n\n\t\t\t\tLOADING...54%%");
    system("color F");//Branco Brilhante!!!
    Sleep(1000);
    system("cls");

    printf("\n\n\n\n\t\t\t\tLOADING...81%%");
    system("color F");//Branco Brilhante!!!
    Sleep(1000);
    system("cls");

    printf("\n\n\n\n\t\t\t\tLOADING...100%%");
    system("color F");//Branco Brilhante!!!
    Sleep(1000);
    system("cls");

    menu();
}
//Função das INSTRUÇÕES!!!
void instructions()
{
    system("color F");//Branco Brilhante!!!
    char seta;

    while(1)
    {
        printf("\n\n\nUtilize dos direcionais para mover a BARRA para ESQUERDA ou DIREITA");
        printf("\n\n\nObjetivo do jogo eh destruir a maior quantidade de BLOCOS em determinado \n tempo (1 MIN)");
        printf("\n\n\nCaso a VIDA chegue a zero eh GAME OVER");
        printf("\n\n\nTecla ESC retorna ao MENU");

        seta=getch();
        system("cls");

    if(seta==27)
    {
        menu();
    }

    }
}
//Função para quem perde o GAME!!!
void game_over()
{
    system("mode con:cols=80 lines=30");
    system("cls");
    system("color B");//Verde-Água Claro!!!

    //unsigned char nome[4];

    while(1)
    {

        printf(" _______  _______  __   __  _______    _______  __   __  _______  ______   \n");
        printf("|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  \n");
        printf("|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  \n");
        printf("|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ \n");
        printf("|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |\n");
        printf("|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |\n");
        printf("|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|\n\n\n");
        Sleep(1000);

        nome_jogador();

    }
}
//Função para quem termina o GAME!!!
void congratulations()
{
    system("mode con:cols=80 lines=30");
    system("cls");
    system("color B");//Verde-Água Claro!!!

    while(1)
    {
        printf("\t __   __  _______  __   __    _     _  ___   __    _ \n");
        printf("\t|  | |  ||       ||  | |  |  | | _ | ||   | |  |  | |\n");
        printf("\t|  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| |\n");
        printf("\t|       ||  | |  ||  |_|  |  |       ||   | |       |\n");
        printf("\t|_     _||  |_|  ||       |  |       ||   | |  _    |\n");
        printf("\t  |   |  |       ||       |  |   _   ||   | | | |   |\n");
        printf("\t  |___|  |_______||_______|  |__| |__||___| |_|  |__|\n\n\n");
        Sleep(1000);

        nome_jogador();

    }
}
