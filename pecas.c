#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "menu.h"
#include "pecas.h"
#include "funcao.h"

extern unsigned char tab[33][57];
unsigned int pontos=0;

void pecas()
{
    unsigned char seta=0, barra=205, bola=169;
    int x_barra=18, y_barra=31;
    int x_bola=21, y_bola=30;
    int velocidadeVertical = -1, velocidadeHorizontal = -1;
    unsigned int vida=3;
    unsigned int milissegundos=0,segundos=0;

    while(1)
    {
        //Printar a BARRA!!!
        gotoxy(x_barra,y_barra);
        printf("%c%c%c%c%c%c%c%c%c",barra,barra,barra,barra,barra,barra,barra,barra,barra);

        //Printar a BOLA ao longo do console!!!
        gotoxy(x_bola - velocidadeHorizontal, y_bola - velocidadeVertical);
        printf(" ");
        gotoxy(x_bola,y_bola);
        printf("%c",bola);

        //Printar a quantidade de pontos do PLAYER!!!
        gotoxy(41,15);
        printf("POINTS: %d",pontos);

        //Printar a quantidade de vidas restantes do PLAYER!!!
        gotoxy(41,16);
        printf("LIFE: %d",vida);

        //Printar o tempo percorrido!!!
        gotoxy(41,17);
        printf("TIME: %d : %d s",segundos,milissegundos);

        //Condicionais para os ricochetes da BOLA!!!
        if(x_bola == 2 || x_bola == 36)
        {
            velocidadeHorizontal*=-1;
        }
        else if(y_bola==2)
        {
            velocidadeVertical*=-1;
        }
        else if (y_bola == y_barra && (x_bola == x_barra || x_bola == x_barra+1 || x_bola == x_barra+2 || x_bola == x_barra+3
                                       || x_bola == x_barra+4))
        {
            if(velocidadeHorizontal==1 && velocidadeVertical==1)
            {
                velocidadeHorizontal*=-1;
                velocidadeVertical*=-1;
            }
            else if(velocidadeHorizontal==-1 && velocidadeVertical==1)
            {
                velocidadeVertical*=-1;
            }
        }
        else if(y_bola == y_barra && (x_bola == x_barra+5|| x_bola == x_barra+6|| x_bola == x_barra+7|| x_bola == x_barra+8))
        {
            if(velocidadeHorizontal==1 && velocidadeVertical==1)
            {
                velocidadeVertical*=-1;
            }
            else if(velocidadeHorizontal==-1 && velocidadeVertical==1)
            {
                velocidadeHorizontal*=-1;
                velocidadeVertical*=-1;
            }
        }
        //Condicional para quando deixar a BOLA cair!!!
        if(y_bola==33 && vida>0)
        {
            gotoxy(x_bola,y_bola);
            printf("%c",219);
            x_bola=21;
            y_bola=30;
            velocidadeHorizontal=-1;
            velocidadeVertical=-1;
            vida--;
        }
        else if(y_bola==33 && vida==0)
        {
            game_over();
        }

        x_bola += velocidadeHorizontal;
        y_bola += velocidadeVertical;

        Sleep (50);

        //Condicional para inicial o movimento da BOLA!!!
        if(kbhit())
        {
            seta = getch();
            if(seta==32)
                seta= getch();
            if(seta==32)
                continue;
        }

        else
            seta = 0;

        //Condicional para sair do jogo após clicar no ESC(27)!!!
        if(seta==27)
        {
            menu();
        }

        //Condicionais para fazer o cursor ir para a direita(CASE 77) ou ir para a esquerda(CASE 75)!!!
        switch(seta)
        {
        case 77:
        {
            x_barra+=2;
            gotoxy(x_barra-2,y_barra);
            printf("  ");
            gotoxy(x_barra,y_barra);
            break;
        }
        case 75:
        {
            x_barra-=2;
            gotoxy(x_barra+9,y_barra);
            printf("  ");
            gotoxy(x_barra,y_barra);
            break;
        }

        }
        //Condicional para a BARRA não passar a margem do tabuleiro!!!
        if(x_barra<2)
        {
            x_barra=2;
        }
        else if(x_barra>29)
        {
            x_barra=29;
        }

        //BOLA batendo nos BLOCOS!!!
        //Se a cima e do lado da BOLA for um BLOCO e ela estiver indo no sentido nordeste!!!
        if(tab[y_bola-1][x_bola] == 178 && tab[y_bola][x_bola+1] && velocidadeVertical==-1 && velocidadeHorizontal==1)
        {
            tab[y_bola-1][x_bola]=0;
            gotoxy(x_bola-1,y_bola+1);
            printf("%c",0);
            velocidadeVertical*=-1;
            velocidadeHorizontal*=-1;
            pontos+=10;
        }
        //Se a cima e do lado da BOLA for um BLOCO e ela estiver indo no sentido noroeste!!!
        else if(tab[y_bola-1][x_bola] == 178 && tab[y_bola][x_bola-1] && velocidadeVertical==-1 && velocidadeHorizontal==-1)
        {
            tab[y_bola-1][x_bola]=0;
            gotoxy(x_bola+1,y_bola+1);
            printf("%c",0);
            velocidadeVertical*=-1;
            velocidadeHorizontal*=-1;
            pontos+=10;
        }
        //Se a baixo e do lado da BOLA for um BLOCO e ela estiver indo no sentido sudeste!!!
        else if(tab[y_bola+1][x_bola] == 178 && tab[y_bola][x_bola+1] && velocidadeVertical==1 && velocidadeHorizontal==1)
        {
            tab[y_bola+1][x_bola]=0;
            gotoxy(x_bola-1,y_bola-1);
            printf("%c",0);
            velocidadeVertical*=-1;
            velocidadeHorizontal*=-1;
            pontos+=10;
        }
        //Se a baixo e do lado da BOLA for um BLOCO e ela estiver indo no sentido sudoeste!!!
        else if(tab[y_bola+1][x_bola] == 178 && tab[y_bola][x_bola-1] && velocidadeVertical==1 && velocidadeHorizontal==-1)
        {
            tab[y_bola+1][x_bola]=0;
            gotoxy(x_bola+1,y_bola-1);
            printf("%c",0);
            velocidadeVertical*=-1;
            velocidadeHorizontal*=-1;
            pontos+=10;
        }
        //Se a cima da BOLA for um BLOCO!!!
        else if(tab[y_bola-1][x_bola] == 178)
        {
            //BOLA sentido nordeste batendo em baixo do BLOCO!!!
            if(velocidadeVertical==-1 && velocidadeHorizontal==1)
            {
                tab[y_bola-1][x_bola]=0;
                gotoxy(x_bola-1,y_bola+1);
                printf("%c",0);
                velocidadeVertical*=-1;
                pontos+=10;
            }
            //BOLA sentido noroeste batendo em baixo do BLOCO!!!
            else if(velocidadeVertical==-1 && velocidadeHorizontal==-1)
            {
                tab[y_bola-1][x_bola]=0;
                gotoxy(x_bola+1,y_bola+1);
                printf("%c",0);
                velocidadeVertical*=-1;
                pontos+=10;
            }
        }
        //Se a baixo da BOLA for um BLOCO!!!
        if(tab[y_bola+1][x_bola] == 178)
        {
            //BOLA sentido sudeste batendo em cima do BLOCO!!!
            if(velocidadeVertical==1 && velocidadeHorizontal==1)
            {
                tab[y_bola+1][x_bola]=0;
                gotoxy(x_bola-1,y_bola-1);
                printf("%c",0);
                velocidadeVertical*=-1;
                pontos+=10;
            }
            //BOLA sentido sudoeste batendo em cima do BLOCO!!!
            else if(velocidadeVertical==1 && velocidadeHorizontal==-1)
            {
                tab[y_bola+1][x_bola]=0;
                gotoxy(x_bola+1,y_bola-1);
                printf("%c",0);
                velocidadeVertical*=-1;
                pontos+=10;
            }
        }
        //BOLA batendo em um BLOCO a sua direita!!!
        else if(tab[y_bola][x_bola+1] == 178)
        {
            //BOLA sentido nordeste!!!
            if(velocidadeVertical==-1 && velocidadeHorizontal==1)
            {
                tab[y_bola][x_bola-1]=0;
                gotoxy(x_bola-1,y_bola+1);
                printf("%c",0);
                velocidadeHorizontal*=-1;
                pontos+=10;
            }
            //BOLA sentido sudeste!!!
            else if(velocidadeVertical==1 && velocidadeHorizontal==1)
            {
                tab[y_bola][x_bola-1]=0;
                gotoxy(x_bola-1,y_bola-1);
                printf("%c",0);
                velocidadeHorizontal*=-1;
                pontos+=10;
            }
        }
        //BOLA batendo em um BLOCO a sua esquerda!!!
        else if(tab[y_bola][x_bola-1] == 178)
        {
            //BOLA sentido noroeste!!!
            if(velocidadeVertical==-1 && velocidadeHorizontal==-1)
            {
                tab[y_bola][x_bola-1]=0;
                gotoxy(x_bola+1,y_bola+1);
                printf("%c",0);
                velocidadeHorizontal*=-1;
                pontos+=10;
            }
            //BOLA sentido sudoeste!!!
            else if(velocidadeVertical==1 && velocidadeHorizontal==-1)
            {
                tab[y_bola][x_bola-1]=0;
                gotoxy(x_bola+1,y_bola-1);
                printf("%c",0);
                velocidadeHorizontal*=-1;
                pontos+=10;
            }
        }

        milissegundos++;

        //Condicional para o cronômetro!!!
        if(milissegundos>60)
        {
            milissegundos=0;
            segundos++;
        }
        else if(segundos==60)
        {
            congratulations();
        }
    }
}
