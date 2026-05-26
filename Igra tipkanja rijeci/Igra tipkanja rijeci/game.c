#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "game.h"
#include "player.h"

static const char* words[WORD_COUNT] = {
    "programiranje",
    "racunalo",
    "tipkovnica",
    "monitor",
    "FERIT",
    "mobitel",
    "funkcije",
    "varijable",
    "koncepti",
    "igra"
};

static inline int randomWord(void)
{
    return rand() % WORD_COUNT;
}

void startGame(void)
{
    Player player;

    printf("Unesi ime igraca: ");
    scanf("%s", player.name);

    int index = randomWord();

    printf("\nUpisi rijec u 8 sekundi:\n");
    printf("%s\n", words[index]);

    char input[MAX_WORD_LENGTH];

    time_t startTime = time(NULL);

    scanf("%s", input);

    time_t endTime = time(NULL);

    double seconds = difftime(endTime, startTime);

    if (seconds <= 8 &&
        strcmp(input, words[index]) == 0)
    {
        player.score = 10;
        printf("TOCNO!\n");
    }
    else
    {
        player.score = 0;
        printf("NETOCNO!\n");
    }

    savePlayer(player);
}

void showMenu(void)
{
    printf("\n===== IGRA TIPKANJA =====\n");

    printf("1. Play Game\n");
    printf("2. Show Players\n");
    printf("3. Search Player\n");
    printf("4. Update Player\n");
    printf("5. Delete Player\n");
    printf("6. Exit\n");
}