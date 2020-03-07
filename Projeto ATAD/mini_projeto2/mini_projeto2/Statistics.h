#pragma once

typedef struct statistics {
	float twoPoints; /* total ou media de cestos de dois pontos */
	float threePoints; /* total ou media de cestos de três pontos */
	float assists; /* total ou media de assitencias */
	float fouls; /* total ou media de faltas */
	float blocks; /* total ou media de blocos */
	int gamesPlayed; /* total de jogos disputados */
					 /* pode acrescentar algum atributo/campo se achar relevante */
} Statistics;

typedef Statistics* PtStatistics;

Statistics createStatistics();
void printStatistic(PtStatistics _this);	