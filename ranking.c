#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "menu.h"
#include "ranking.h"

extern unsigned int pontos;

//Fun��o para ARQUIVAR o NOME e o SCORE de um PLAYER!!!
void nome_jogador ()
{
    FILE*ranking;
    unsigned char nome[4];

    ranking = fopen("ranking.txt", "a+");

    printf("\t\t\tEscreva seu nome:");
    gets(nome);
    Sleep(1000);

    fprintf(ranking, "%s\t%d\n", nome, pontos);

    fclose(ranking);

    system("cls");
    menu();

}
//Fun��o para PRINTAR o RANKING na tela!!!
void ranking ()
{
    system("color F");//Branco Brilhante!!!

    char seta;
    FILE*ranking;
    int score;
    char nome [4];

    ranking = fopen("ranking.txt", "r");

    printf("NAME:\tSCORE:\n");

    if (ranking == NULL)
        printf("ERRO!");

    while (fscanf(ranking, "%s\t%d\n", &nome, &score) != EOF)
        printf("%s\t%d\n", nome, score);

    fclose(ranking);

    //La�o para retornar ao MENU!!!
    while(1)
    {
        seta = getch();

        if(seta == 27)
        menu();

    }

}
