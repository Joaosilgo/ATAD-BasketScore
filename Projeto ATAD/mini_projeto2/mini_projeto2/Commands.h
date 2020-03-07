#pragma once
#include "List.h"

int equalsStringIgnoreCase(char str1[], char str2[]);
char** split(char *str, int nFields, const char *delim);

//COMMAND LOAD
void importPlayers(PtList list);

//COMMAND CLEAR
void CLEAR(PtList list);

//COMMAND SHOW
void SHOW(PtList list);

//COMMAND SORT
void SORT(PtList list);

//COMMAND AVG
void AVG(PtList list);

//COMMAND NORM
void NORM(PtList list);

//COMMAND TYPE
void TYPE(PtList list);

//COMMAND CHECKTYPE
void CHECKTYPE(PtList list);