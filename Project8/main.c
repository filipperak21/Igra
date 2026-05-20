#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "player.h"

int main(void)
{
    srand((unsigned)time(NULL));

    int choice = 0;

    do
    {
        showMenu();

        printf("Odabir: ");
        scanf("%d", &choice);

        switch ((MenuOption)choice)
        {
        case MENU_PLAY:
            startGame();
            break;

        case MENU_SHOW:
            showPlayers();
            break;

        case MENU_UPDATE:
            updatePlayer();
            break;

        case MENU_DELETE:
            deletePlayer();
            break;

        case MENU_EXIT:
            printf("Izlaz iz programa...\n");
            break;

        default:
            printf("Pogresan unos!\n");
        }

    } while (choice != MENU_EXIT);

    return 0;
}