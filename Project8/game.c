#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "game.h"
#include "player.h"

static const char* words[WORD_COUNT] =
{
    "computer",
    "keyboard",
    "monitor",
    "pointer",
    "function"
};

void showMenu(void)
{
    printf("\n===== TYPING GAME =====\n");

    printf("1. Play Game\n");
    printf("2. Show Players\n");
    printf("3. Update Player\n");
    printf("4. Delete Player\n");
    printf("5. Exit\n");
}

static inline int randomWord(void)
{
    return rand() % WORD_COUNT;
}

void startGame(void)
{
    Player player;

    printf("Ime igraca: ");
    scanf("%s", player.name);

    int index = randomWord();

    printf("\nUpisi rijec:\n");
    printf("%s\n", words[index]);

    char input[MAX_WORD];

    scanf("%s", input);

    if (strcmp(input, words[index]) == 0)
    {
        printf("TOCNO!\n");

        player.score = 10;
    }
    else
    {
        printf("NETOCNO!\n");

        player.score = 0;
    }

    savePlayer(player);
}