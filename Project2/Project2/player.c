#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "player.h"
#include "fileManager.h"

int playerCount = 0;

static const char* fileName = "data.bin";

Player* loadPlayers(void)
{
    FILE* fp = fopen(fileName, "rb");

    if (fp == NULL)
    {
        return NULL;
    }

    long size = getFileSize(fp);

    playerCount = size / sizeof(Player);

    if (playerCount == 0)
    {
        fclose(fp);
        return NULL;
    }

    Player* players = (Player*)calloc(playerCount, sizeof(Player));

    if (players == NULL)
    {
        fclose(fp);
        return NULL;
    }

    fread(players, sizeof(Player), playerCount, fp);

    fclose(fp);

    return players;
}

void savePlayer(Player newPlayer)
{
    FILE* fp = fopen(fileName, "ab");

    if (fp == NULL)
    {
        perror("Greska kod otvaranja datoteke");
        return;
    }

    fwrite(&newPlayer, sizeof(Player), 1, fp);

    fclose(fp);
}

void showPlayers(void)
{
    Player* players = loadPlayers();

    if (players == NULL)
    {
        printf("Nema igraca!\n");
        return;
    }

    for (int i = 0; i < playerCount; i++)
    {
        printf("%d. %s - %d\n",
            i + 1,
            players[i].name,
            players[i].score);
    }

    free(players);
    players = NULL;
}

int comparePlayers(const void* a, const void* b)
{
    Player* p1 = (Player*)a;
    Player* p2 = (Player*)b;

    return strcmp(p1->name, p2->name);
}

void searchPlayer(void)
{
    Player* players = loadPlayers();

    if (players == NULL)
        return;

    qsort(players,
        playerCount,
        sizeof(Player),
        comparePlayers);

    char name[MAX_NAME_LENGTH];

    printf("Ime igraca: ");
    scanf("%s", name);

    Player key;
    strcpy(key.name, name);

    Player* found = (Player*)bsearch(
        &key,
        players,
        playerCount,
        sizeof(Player),
        comparePlayers);

    if (found != NULL)
    {
        printf("Pronaden: %s (%d)\n",
            found->name,
            found->score);
    }
    else
    {
        printf("Igrac nije pronaden!\n");
    }

    free(players);
    players = NULL;
}

void updatePlayer(void)
{
    Player* players = loadPlayers();

    if (players == NULL)
        return;

    char name[MAX_NAME_LENGTH];

    printf("Unesi ime igraca za azururanje: ");
    scanf("%s", name);

    for (int i = 0; i < playerCount; i++)
    {
        if (strcmp(players[i].name, name) == 0)
        {
            printf("Novi score: ");
            scanf("%d", &players[i].score);
        }
    }

    FILE* fp = fopen(fileName, "wb");

    if (fp == NULL)
    {
        free(players);
        return;
    }

    fwrite(players, sizeof(Player), playerCount, fp);

    fclose(fp);

    free(players);
    players = NULL;
}

void deletePlayer(void)
{
    Player* players = loadPlayers();

    if (players == NULL)
        return;

    char name[MAX_NAME_LENGTH];

    printf("Unesi ime igraca za brisanje: ");
    scanf("%s", name);

    FILE* temp = fopen("temp.bin", "wb");

    if (temp == NULL)
    {
        free(players);
        return;
    }

    for (int i = 0; i < playerCount; i++)
    {
        if (strcmp(players[i].name, name) != 0)
        {
            fwrite(&players[i], sizeof(Player), 1, temp);
        }
    }

    fclose(temp);

    remove(fileName);

    rename("temp.bin", fileName);

    free(players);
    players = NULL;
}