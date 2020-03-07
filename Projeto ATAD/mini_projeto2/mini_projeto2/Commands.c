#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "Commands.h"


int equalsStringIgnoreCase(char str1[], char str2[]) {
	/* Apenas faz uma comparacao utilizando o strcmp.
	* Necessita de modificacao para obter uma comparacao
	* 'case insensitive' */
	return (_stricmp(str1, str2) == 0);
	//return (strcmp(str1, str2) == 0);
}
char** split(char *str, int nFields, const char *delim) {

	char **tokens = malloc(sizeof(char*) * nFields);

	int index = 0;
	char *next_token = NULL; //para controlo interno da funcao strtok_s

	char *token = strtok_s(str, delim, &next_token);
	while (token)
	{
		//puts(token);
		tokens[index++] = token;
		token = strtok_s(NULL, delim, &next_token);
	}

	return tokens;
}

//COMMAND LOAD
void importPlayers(PtList list) {
	FILE *fd;
	int err = fopen_s(&fd, "players.csv", "r");
	if (err != 0) {
		printf("\nNao foi possivel abrir o ficheiro %s ... \n", "players.csv");
	}
	char nextLinee[1024];
	//contagem de jogadores lidos
	int countPlayers = 0;
	while (fgets(nextLinee, sizeof(nextLinee), fd))
	{
		if (strlen(nextLinee) < 1) {
			continue;
		}
		char **tokens = split(nextLinee, 5, ";");
		//o array neste momento contém as seguintes "strings":
		//tokens[0] - id
		//tokens[1] - nome
		//tokens[2] - clube
		//tokens[3] - data de nascimento
		//tokens[4] - genero

		int playerID = atoi(tokens[0]);
		int day, month, year;
		sscanf_s(tokens[3], "%d/%d/%d", &day, &month, &year);
		char playerGender = tokens[4][0]; //primeiro carater de tokens[4]
		Date date = createDate(day, month, year);
		Player player = createPlayer(playerID, tokens[1], tokens[2], date, playerGender);
		listAdd(list, countPlayers, player);
		free(tokens);
		countPlayers++;
	}
	FILE *games;
	int file = fopen_s(&games, "games.csv", "r");
	if (file != 0) {
		printf("\nNao foi possivel abrir o ficheiro %s ... \n", "games.csv");
	}
	char nextLine[1024];
	//contagem de jogadores lidos
	int countGames = 0;
	while (fgets(nextLine, sizeof(nextLine), games))
	{
		if (strlen(nextLine) < 1) {
			continue;
		}
		char **tokens = split(nextLine, 8, ";");
		int playerID = atoi(tokens[0]);
		float twoPoints = atof(tokens[2]);
		float threePoints = atof(tokens[3]);
		float assists = atoi(tokens[4]);
		float fouls = atoi(tokens[5]);
		float blocks = atoi(tokens[6]);
		int size;
		listSize(list, &size);		
		for (int i = 0 ; i < size ; i++)
		{
			ListElem player, aux;
			listGet(list, i, &player);
			if (player.id == playerID) {
				player.statistic.twoPoints += twoPoints;
				player.statistic.threePoints += threePoints;
				player.statistic.assists += assists;
				player.statistic.fouls += fouls;
				player.statistic.blocks += blocks;
				player.statistic.gamesPlayed++;
				listSet(list, i, player, &aux);
			}	
		}
		free(tokens);
		countGames++;
	}
	printf("\nForam lidos %d jogadores e informacao sobre %d jogos\n", countPlayers, countGames);
}

//COMMAND CLEAR
void CLEAR(PtList list){
	int size;
	listSize(list, &size);
	listClear(list);
	printf("Foram apagados %d registos", size);
}

//COMMAND SHOW
void SHOW(PtList list) {
	listPrint(list);
}

//COMMAND SORT
void SORT(PtList list) {
	int option;
	printf("Sort by:\n");
	printf("\t1-Name\n\t2-BirthDay\n\t3-Games Played\n");
	printf("Option> ");
	scanf_s("%d", &option);

	if (option == 1)
	{
		sortByName(list);
	}
	else if (option == 2)
	{
		sortByDate(list);
	}
	else if (option == 3)
	{
		sortByGamesPlayed(list);
	}
	else {
		printf("Insira uma opcao valida!");
	}
}

//COMMAND AVG
void AVG(PtList list) {
	//
	PtList average = averageStatistics(list);
	//int s;
	//listSize(average, &s);
	bubbleSortMVP(average);
	listPrint(average);
	listClear(average);
	listDestroy(&average);
}

//COMMAND NORM
void NORM(PtList list) {
	PtList average = averageStatistics(list);
	PtList normalizeList = normalizeStatistics(average);
	listPrint(normalizeList);
	listClear(average);
	listClear(normalizeList);
	listDestroy(&average);
	listDestroy(&normalizeList);
}

//COMMAND TYPE
void TYPE(PtList list) {
	playerType(list);
}

//COMMAND CHECKTYPE
void CHECKTYPE(PtList list) {
	checkType(list);
}