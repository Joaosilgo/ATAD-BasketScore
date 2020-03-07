#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "map.h"
#include <Windows.h>
#include<conio.h>

//ordena por ordem crescente
void bubbleSortName(PtList list) {
	int size;
	listSize(list, &size);
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			ListElem elem1;
			ListElem elem2;
			ListElem aux;
			listGet(list, j, &elem1);
			listGet(list, j + 1, &elem2);
			if (strcmp(elem1.name, elem2.name) > 0) {
				listSet(list, j, elem2, &aux);
				listSet(list, j + 1, elem1, &aux);
			}
		}
	}
}

//ordena por ordem alfabeticas caso os gamesPlayed sejam iguais
void bubbleSort(PtList list) {
	int size;
	listSize(list, &size);

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			ListElem elem1;
			ListElem elem2;
			ListElem aux;
			listGet(list, j, &elem1);
			listGet(list, j + 1, &elem2);
			if (elem1.statistic.gamesPlayed == elem2.statistic.gamesPlayed)
			{
				if (strcmp(elem1.name, elem2.name) > 0)
				{
					listSet(list, j, elem2, &aux);
					listSet(list, j + 1, elem1, &aux);
				}
			}
		}

	}
}



void swap(ListElem  *x, ListElem*y) {

}

//
//void selectionSortMVP(PtList list, unsigned int arrSize) {
//
//	for (int i = 0; i < arrSize; i++) {
//		int indexMin = i;
//		ListElem player1;
//		ListElem player2;
//		ListElem aux;
//		listGet(list, i, &player1);
//		
//		for (int j = i; j < arrSize; j++) {
//			listGet(list, j + 1, &player2);
//			float mvp1 = 0.0;
//			float mvp2 = 0.0;
//			mvp1 = (float)(3 * player1.statistic.threePoints) + (float)(2 * player1.statistic.twoPoints) + (float)(player1.statistic.assists) + (float)(2 * player1.statistic.blocks) - (float)(3 * player1.statistic.fouls);
//			mvp2 = (float)(3 * player2.statistic.threePoints) + (float)(2 * player2.statistic.twoPoints) + (float)(player2.statistic.assists) + (float)(2 * player2.statistic.blocks) - (float)(3 * player2.statistic.fouls);
//			if (mvp1>mvp2)
//			{
//				indexMin = j;
//			}
//			ListElem aux = player1;
//
//			listSet(list, j, player2, &aux);
//			listSet(list, j + 1, player1, &aux);
//		}
//		
//	}
//}









void bubbleSortMVP(PtList list) {
	int size;
	listSize(list, &size);

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			ListElem player1;
			ListElem player2;
			ListElem aux;
			listGet(list, j, &player1);
			listGet(list, j + 1, &player2);
			float mvp1 = 0.0;

			float mvp2 = 0.0;
			mvp1 = (float)((float)(3 * player1.statistic.threePoints) + (float)(2 * player1.statistic.twoPoints) + (float)(player1.statistic.assists) + (float)(2 * player1.statistic.blocks) - (float)(3 * player1.statistic.fouls));
			mvp2 = (float)((float)(3 * player2.statistic.threePoints) + (float)(2 * player2.statistic.twoPoints) + (float)(player2.statistic.assists) + (float)(2 * player2.statistic.blocks) - (float)(3 * player2.statistic.fouls));
			//printf("%f     %f \n", mvp1 , mvp2);
			
			if (mvp1 < mvp2)
			{
				listSet(list, j, player2, &aux);
				listSet(list, j + 1, player1, &aux);
			}
			
		

		}

	}

}



void sortByName(PtList originalList) {
	int inicialCapacity;
	listSize(originalList, &inicialCapacity);

	PtList newList = listCreate(inicialCapacity);

	for (int i = 0; i < inicialCapacity; i++) {
		ListElem elem;
		listGet(originalList, i, &elem);
		listAdd(newList, i, elem);
	}
	bubbleSortName(newList);
	listPrint(newList);
}

int compareDates(Date d1, Date d2) {
	if (d1.year < d2.year) {
		return 1;
	}

	if (d1.year == d2.year && d1.month < d2.month) {
		return 1;
	}

	if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day) {
		return 1;
	}

	return 0;
}

void bubbleSortDate(PtList list) {
	int size;
	listSize(list, &size);

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			ListElem elem1;
			ListElem elem2;
			ListElem aux;
			listGet(list, j, &elem1);
			listGet(list, j + 1, &elem2);

			if (compareDates(elem1.birthDate, elem2.birthDate) == 0) {
				listSet(list, j, elem2, &aux);
				listSet(list, j + 1, elem1, &aux);
			}
		}
	}
}

void sortByDate(PtList originalList) {
	int inicialCapacity;
	listSize(originalList, &inicialCapacity);

	PtList newList = listCreate(inicialCapacity);

	for (int i = 0; i < inicialCapacity; i++) {
		ListElem elem;
		listGet(originalList, i, &elem);
		listAdd(newList, i, elem);
	}
	bubbleSortDate(newList);
	listPrint(newList);
}

void bubbleSortGames(PtList list) {
	int size;
	listSize(list, &size);
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			ListElem elem1;
			ListElem elem2;
			ListElem aux;
			listGet(list, j, &elem1);
			listGet(list, j + 1, &elem2);

			if (elem1.statistic.gamesPlayed > elem2.statistic.gamesPlayed) {
				listSet(list, j, elem2, &aux);
				listSet(list, j + 1, elem1, &aux);
			}

		}
	}
}

void sortByGamesPlayed(PtList originalList) {
	int inicialCapacity;
	listSize(originalList, &inicialCapacity);

	PtList newList = listCreate(inicialCapacity);

	for (int i = 0; i < inicialCapacity; i++) {
		ListElem elem;
		listGet(originalList, i, &elem);
		listAdd(newList, i, elem);
	}
	bubbleSortGames(newList);
	bubbleSort(newList);
	listPrint(newList);
}

PtList averageStatistics(PtList players) {
	
	int inicialCapacity;
	listSize(players, &inicialCapacity);

	PtList newList = listCreate(inicialCapacity);
	int posicao = 0;

	for (int i = 0; i < inicialCapacity; i++) {
		ListElem oldElem;
		ListElem elem;
		listGet(players, i, &elem);


		if (elem.statistic.gamesPlayed > 0) {
			listAdd(newList, posicao, elem);

			elem.statistic.twoPoints = elem.statistic.twoPoints / (float)elem.statistic.gamesPlayed;
			elem.statistic.threePoints = elem.statistic.threePoints / (float)elem.statistic.gamesPlayed;
			elem.statistic.assists = elem.statistic.assists / (float)elem.statistic.gamesPlayed;
			elem.statistic.blocks = elem.statistic.blocks / (float)elem.statistic.gamesPlayed;
			elem.statistic.fouls = elem.statistic.fouls / (float)elem.statistic.gamesPlayed;
			
			listSet(newList, posicao, elem, &oldElem);
			
			posicao++;
			
		}
	}



	return newList;

}


PtList normalizeStatistics(PtList players) {
	if (players == NULL) return NULL;
	ListElem player;
	listGet(players, 0, &player);
	//minimo
	float min2 = player.statistic.twoPoints;
	float min3 = player.statistic.threePoints;
	float minAssists = player.statistic.assists;
	float minFouls = player.statistic.fouls;
	float minBlocks = player.statistic.blocks;
	//maximo
	float max2 = 0.0;
	float max3 = 0.0;
	float maxAssists = 0.0;
	float maxFouls = 0.0;
	float maxBlocks = 0.0;
	int size;
	listSize(players, &size);
	//determinar valores maximos e minimos 
	for (int i = 0; i < size; i++)
	{
		ListElem player;
		listGet(players, i, &player);

		if (player.statistic.gamesPlayed != 0)
		{
			//min
			if (player.statistic.twoPoints < min2) {
				min2 = player.statistic.twoPoints;
			}
			if (player.statistic.threePoints < min3) {
				min3 = player.statistic.threePoints;
			}
			if (player.statistic.assists < minAssists) {
				minAssists = player.statistic.assists;
			}
			if (player.statistic.fouls < minFouls) {
				minFouls = player.statistic.fouls;
			}
			if (player.statistic.blocks < minBlocks) {
				minBlocks = player.statistic.blocks;
			}
			//max
			if (player.statistic.twoPoints > max2) {
				max2 = player.statistic.twoPoints;
			}
			if (player.statistic.threePoints > max3) {
				max3 = player.statistic.threePoints;
			}
			if (player.statistic.assists > maxAssists) {
				maxAssists = player.statistic.assists;
			}
			if (player.statistic.fouls > maxFouls) {
				maxFouls = player.statistic.fouls;
			}
			if (player.statistic.blocks > maxBlocks) {
				maxBlocks = player.statistic.blocks;
			}
		}
	}
	PtList normList = listCreate(size);
	int posicao = 0;
	//adicionar - calcular as normas
	for (int a = 0; a < size; a++)
	{
		ListElem newPlayer;
		listGet(players, a, &newPlayer);

		if (newPlayer.statistic.gamesPlayed != 0) {
			float cima = newPlayer.statistic.twoPoints - min2;
			float baixo = max2 - min2;
			newPlayer.statistic.twoPoints = (cima / baixo)* (2*5)-5;

			
			//threepoints
			cima = newPlayer.statistic.threePoints - min3;
			baixo = max3 - min3;
			newPlayer.statistic.threePoints = cima / baixo;
			//assists
			cima = newPlayer.statistic.assists - minAssists;
			baixo = maxAssists - minAssists;
			newPlayer.statistic.assists = cima / baixo;
			//fouls
			cima = newPlayer.statistic.fouls - minFouls;
			baixo = maxFouls - minFouls;
			newPlayer.statistic.fouls = cima / baixo;
			//blocks
			cima = newPlayer.statistic.blocks - minBlocks;
			baixo = maxBlocks - minBlocks;
			newPlayer.statistic.blocks = cima / baixo;

			listAdd(normList, posicao, newPlayer);
			posicao++;
		}
	}
	return normList;
}

void playerType(PtList list) {

	PtList averageList = averageStatistics(list);
	//tamanho da lista para 
	int size;
	listSize(averageList, &size);
	printf("%d \n", size);

	PtList ShootingGuard = listCreate(size);
	PtList PointGuard = listCreate(size);
	PtList AllStar = listCreate(size);

	float avg2 = 0.0;
	float avgAssists = 0.0;
	float avg3 = 0.0;
	float avgBlocks = 0.0;

	for (int i = 0; i < size; i++)
	{
		ListElem player;
		listGet(averageList, i, &player);

		avg2 = avg2 + player.statistic.twoPoints;
		avgAssists = avgAssists + player.statistic.assists;
		avg3 = avg3 + player.statistic.threePoints;
		avgBlocks = avgBlocks + player.statistic.blocks;
	}
	//piece = (float)((b - a) / d);

	avg2 = (float)(avg2 / (float)size);
	avgAssists = (float)(avgAssists / (float)size);
	avg3 = (float)(avg3 / (float)size);
	avgBlocks = (float)(avgBlocks / (float)size);
	//está correto

	int positionShooting = 0;
	int positionPoint = 0;
	int positionAll = 0;

	for (int i = 0; i < size; i++)
	{

		ListElem player1;

		listGet(averageList, i, &player1);

		float sum2 = player1.statistic.twoPoints;
		float sum3 = player1.statistic.threePoints;
		float sumAssists = player1.statistic.assists;
		float sumBlocks = player1.statistic.blocks;

		//printf("%.2f , %.2f , tam: %d %.2f , %.2f\n", avg23, avgAssistsBlocks, tam, sumAVG23, sumAssistsBlocks);

		if (sum2 > avg2 && sum3 > avg3 && sumAssists < avgAssists && sumBlocks < avgBlocks) {
			listAdd(ShootingGuard, positionShooting, player1);
			positionShooting++;

		}
	}
	for (int i = 0; i < size; i++)
	{
		ListElem player2;
		listGet(averageList, i, &player2);


		float sum2 = player2.statistic.twoPoints;
		float sum3 = player2.statistic.threePoints;
		float sumAssists = player2.statistic.assists;
		float sumBlocks = player2.statistic.blocks;

		//adiciona ao positionShooting
		if (sum2 < avg2 && sum3 < avg3 && sumAssists > avgAssists && sumBlocks > avgBlocks)
		{
			listAdd(PointGuard, positionPoint, player2);
			positionPoint++;

		}
	}

	for (int i = 0; i < size; i++)
	{
		ListElem player3;

		listGet(averageList, i, &player3);

		float sum2 = player3.statistic.twoPoints;
		float sum3 = player3.statistic.threePoints;
		float sumAssists = player3.statistic.assists;
		float sumBlocks = player3.statistic.blocks;

		if (sum2 > avg2 && sum3 > avg3 && sumAssists > avgAssists && sumBlocks > avgBlocks)
		{
			listAdd(AllStar, positionAll, player3);
			positionAll++;

		}
	}




	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 135);
	printf("                                          ShootingGuard                                                              \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	listPrint(ShootingGuard);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 135);
	printf("                                          PointGuard                                                              \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	listPrint(PointGuard);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 135);
	printf("                                          All-Star                                                              \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	listPrint(AllStar);
}


void checkType(PtList list) {
	if (list == NULL) return LIST_NULL;
	PtList playerList = listCreate(500);
	playerList = averageStatistics(list);
	int sizeList;
	listSize(playerList, &sizeList);
	PtMap playerMap = mapCreate(500);

	//iniciação com as medias de todos os jogadores
	float avgAllPlayersTwoPoints = 0.0;
	float avgAllPlayersThreePoints = 0.0;
	float avgAllPlayersBlocks = 0.0;
	float avgAllPlayersFouls = 0.0;
	float avgAllPlayersAssist = 0.0;
	/*Adiciona as medias de todos*/

	for (int i = 0; i < sizeList; i++) {
		Player player;
		listGet(playerList, i, &player);
		avgAllPlayersTwoPoints += player.statistic.twoPoints;
		avgAllPlayersThreePoints += player.statistic.threePoints;
		avgAllPlayersBlocks += player.statistic.blocks;
		avgAllPlayersFouls += player.statistic.fouls;
		avgAllPlayersAssist += player.statistic.assists;
	}

	/*Divide pela quantidade de jogadores*/
	avgAllPlayersTwoPoints /= sizeList;
	avgAllPlayersThreePoints /= sizeList;
	avgAllPlayersBlocks /= sizeList;
	avgAllPlayersFouls /= sizeList;
	avgAllPlayersAssist /= sizeList;


	for (int i = 0; i < sizeList; i++) {
		Player player1;
		listGet(playerList, i, &player1);
		float avgTwoPThreePtTemp = player1.statistic.twoPoints + player1.statistic.threePoints;
		float avgAssBloTemp = player1.statistic.assists + player1.statistic.blocks;
		/*-Tipo Shooting - Guard: Todos os jogadores cujos
		valores médios twoPoints e threePoints sejam superiores à média geral
		valores médios assists e blocks sejam inferiores à respetiva média geral.*/
		if (avgTwoPThreePtTemp > (avgAllPlayersTwoPoints + avgAllPlayersThreePoints)
			&& avgAssBloTemp < (avgAllPlayersAssist + avgAllPlayersBlocks)) {
			PlayerType playerTy = createPlayerType(
				"shooting-guard",
				player1.statistic.twoPoints,
				avgAllPlayersTwoPoints,
				player1.statistic.threePoints,
				avgAllPlayersThreePoints,
				player1.statistic.blocks,
				avgAllPlayersBlocks,
				player1.statistic.fouls,
				avgAllPlayersFouls,
				player1.statistic.assists,
				avgAllPlayersAssist
			);
			mapPut(playerMap, player1.id, playerTy);
		}
		/*-Tipo Point - Guard: Todos os jogadores cujos valores médios twoPoints e threePoints
		sejam inferiores à média geral, e cujos valores médios assists e blocks sejam
		superiores à média geral.*/
		else if (avgTwoPThreePtTemp < (avgAllPlayersTwoPoints + avgAllPlayersThreePoints)
			&& avgAssBloTemp >(avgAllPlayersAssist + avgAllPlayersBlocks)) {
			PlayerType playerTy = createPlayerType(
				"Point-Guard  ",
				player1.statistic.twoPoints,
				avgAllPlayersTwoPoints,
				player1.statistic.threePoints,
				avgAllPlayersThreePoints,
				player1.statistic.blocks,
				avgAllPlayersBlocks,
				player1.statistic.fouls,
				avgAllPlayersFouls,
				player1.statistic.assists,
				avgAllPlayersAssist
			);
			mapPut(playerMap, player1.id, playerTy);
		}
		/*-Tipo All - Star: Todos os jogadores cujos valores médios twoPoints, threePoints,
		assists e blocks sejam superiores à média geral.*/
		else if (avgTwoPThreePtTemp > (avgAllPlayersTwoPoints + avgAllPlayersThreePoints)
			&& avgAssBloTemp > (avgAllPlayersAssist + avgAllPlayersBlocks)) {
			PlayerType playerTy = createPlayerType(
				"All-Star ",
				player1.statistic.twoPoints,
				avgAllPlayersTwoPoints,
				player1.statistic.threePoints,
				avgAllPlayersThreePoints,
				player1.statistic.blocks,
				avgAllPlayersBlocks,
				player1.statistic.fouls,
				avgAllPlayersFouls,
				player1.statistic.assists,
				avgAllPlayersAssist
			);
			mapPut(playerMap, player1.id, playerTy);
		}
	}
	int search = 1;
	int sizeMap;
	mapSize(playerMap, &sizeMap);
	while (search != 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 3);
		printf(".Introduza o ID para a consulta  \n");
		printf(".0 para sair \n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 8);
		printf("->");
		scanf_s("%d", &search);

		if (mapContains(playerMap, search)) {
			PlayerType pT;
			mapGet(playerMap, search, &pT);
			int index = findKeyIndex(playerMap, search);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 135);
			mapKeyPrint(index, search);
			mapValuePrint(pT);
			
			
			printf("");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 8);
		}
		else if (search == 0)
		{
			printf("Goodbye\n");
			mapDestroy(&playerMap);
		}
		else
		{
			printf("Map do not have that key\n");
		}


	}

	//mapDestroy(playerMap);
}

