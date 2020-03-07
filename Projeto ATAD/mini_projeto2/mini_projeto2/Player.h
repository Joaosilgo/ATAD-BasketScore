#pragma once

#include "Date.h"
#include "Statistics.h"

typedef struct player {
	int id;
	char name[50];
	char team[50];
	Date birthDate;
	char gender;
	Statistics statistic;
}Player;

typedef Player* PtPlayer;

Player createPlayer(unsigned int id, char name[], char team[], Date birthDate, char gender);
void printPlayer(PtPlayer _this);




