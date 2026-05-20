#pragma once
#ifndef GAME_H
#define GAME_H

#include <stdio.h>

#define MAX_NAME 50
#define MAX_WORD 50
#define WORD_COUNT 5

typedef enum MenuOption
{
    MENU_PLAY = 1,
    MENU_SHOW,
    MENU_UPDATE,
    MENU_DELETE,
    MENU_EXIT

} MenuOption;

typedef struct Player
{
    char name[MAX_NAME];
    int score;

} Player;

void showMenu(void);

void startGame(void);

#endif