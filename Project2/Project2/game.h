#pragma once
#ifndef GAME_H
#define GAME_H

#define MAX_WORD_LENGTH 50
#define MAX_NAME_LENGTH 50
#define WORD_COUNT 10

typedef enum MenuOption {
    MENU_PLAY = 1,
    MENU_SHOW,
    MENU_SEARCH,
    MENU_UPDATE,
    MENU_DELETE,
    MENU_EXIT
} MenuOption;

typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void startGame(void);
void showMenu(void);

#endif