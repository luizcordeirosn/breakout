#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "tabuleiro.h"

unsigned char tab[33][57];

void tabuleiro()
{
    int i,j;

    system("color F");//Branco Brilhante!!!

    //Comando para redefinir o tamanho do CONSOLE!!!
    system("mode con:cols=80 lines=34");

    //Laço para a matriz!!!
    for(i=0; i<33; i++)
    {
        for(j=0; j<57; j++)
        {
            if(i==0 || i==32 || j==0 || j==56 || j==37)
            {
                tab[i][j] = 219;
            }
            //Condicional para os blocos!!!
            else if(i>=2 && i<=6 && j>=2 && j<=35)
            {
                tab[i][j] = 178;
            }
            else
            {
                tab[i][j] = 0;
            }

        }

    }

    //Printar o que foi declarado à cima!!!
    for(i=0; i<33; i++)
    {
        for(j=0; j<57; j++)
        {
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
}
