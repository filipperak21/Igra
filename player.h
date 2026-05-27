#pragma once


#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"

extern int playerCount;

void savePlayer(Player player);

void showPlayers(void);

void updatePlayer(void);

void deletePlayer(void);

void fileInformation(void);

#endif

