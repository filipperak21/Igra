#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "player.h"

int playerCount = 0;

static const char* fileName = "data.txt";

void savePlayer(Player player)
{
    FILE* fp = fopen(fileName, "a");

    if (fp == NULL)
    {
        printf("Greska datoteke!\n");
        return;
    }

    fprintf(fp,
        "%s %d\n",
        player.name,
        player.score);

    fclose(fp);

    playerCount++;
}

void showPlayers(void)
{
    FILE* fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        printf("Nema igraca!\n");
        return;
    }

    Player player;

    printf("\n===== IGRACI =====\n");

    while (fscanf(fp,
        "%s %d",
        player.name,
        &player.score) == 2)
    {
        printf("%s - %d\n",
            player.name,
            player.score);
    }

    fclose(fp);
}

void updatePlayer(void)
{
    FILE* fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        return;
    }

    FILE* temp = fopen("temp.txt", "w");

    Player player;

    char searchName[MAX_NAME];

    int newScore;

    printf("Ime igraca: ");
    scanf("%s", searchName);

    printf("Novi score: ");
    scanf("%d", &newScore);

    while (fscanf(fp,
        "%s %d",
        player.name,
        &player.score) == 2)
    {
        if (strcmp(player.name, searchName) == 0)
        {
            player.score = newScore;
        }

        fprintf(temp,
            "%s %d\n",
            player.name,
            player.score);
    }

    fclose(fp);
    fclose(temp);

    remove(fileName);

    rename("temp.txt", fileName);
}

void deletePlayer(void)
{
    FILE* fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        return;
    }

    FILE* temp = fopen("temp.txt", "w");

    Player player;

    char deleteName[MAX_NAME];

    printf("Ime igraca za brisanje: ");
    scanf("%s", deleteName);

    while (fscanf(fp,
        "%s %d",
        player.name,
        &player.score) == 2)
    {
        if (strcmp(player.name, deleteName) != 0)
        {
            fprintf(temp,
                "%s %d\n",
                player.name,
                player.score);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(fileName);

    rename("temp.txt", fileName);
}