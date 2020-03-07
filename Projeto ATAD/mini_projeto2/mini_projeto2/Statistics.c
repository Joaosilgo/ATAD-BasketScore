#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "Statistics.h"

Statistics createStatistics() {
	Statistics newStatistic;

	newStatistic.twoPoints = 0.0;

	newStatistic.threePoints = 0.0;

	newStatistic.assists = 0.0;

	newStatistic.fouls = 0.0;

	newStatistic.blocks = 0.0;

	newStatistic.gamesPlayed = 0;

	return newStatistic;
}


void printStatistic(PtStatistics _this) {
	printf("\n Two Points: %.2f \n Three Points: %.2f \n Assists: %.2f \n Fouls: %.2f \n Blocks: %.2f \n Games Played: %d \n", _this->twoPoints, _this->threePoints,
		_this->assists, _this->fouls, _this->blocks, _this->gamesPlayed);
}