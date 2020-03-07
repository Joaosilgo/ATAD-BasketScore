#pragma once
#include "List.h"


void bubbleSortName(PtList list);
void bubbleSortDate(PtList list);
void bubbleSortGames(PtList list);
void sortByName(PtList originalList);
void sortByDate(PtList originalList);
int compareDates(Date date1, Date date2);
void sortByGamesPlayed(PtList list);
PtList averageStatistics(PtList players);
PtList normalizeStatistics(PtList players);
void playerType(PtList list);
void checkType(PtList _this);
void bubbleSortMVP(PtList list);




//void swap(ListElem  *x, ListElem*y);
//void selectionSortMVP(PtList list, unsigned int arrSize);
