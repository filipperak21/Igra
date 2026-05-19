#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"

extern int playerCount;

Player* loadPlayers(void);
void savePlayer(Player newPlayer);
void showPlayers(void);
void searchPlayer(void);
void updatePlayer(void);
void deletePlayer(void);

#endif