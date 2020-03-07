#include "player.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <Windows.h>
#include <conio.h>


Player createPlayer(unsigned int id, char name[], char team[], Date birthDate, char gender) {

	Player player;

	player.id = id;

	strcpy_s(player.name, strlen(name) + 1, name);

	strcpy_s(player.team, strlen(team) + 1, team);

	player.birthDate = birthDate;

	player.gender = gender;

	player.statistic = createStatistics();

	return player;
}

void printPlayer(PtPlayer _this) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 3);
	printf("Jogador %3d : %-15s | %-15s | %02d/%02d/%04d | %c \n",
		_this->id, _this->name, _this->team, _this->birthDate.day, _this->birthDate.month, _this->birthDate.year, _this->gender);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 7);
	printStatistic(&_this->statistic);
}