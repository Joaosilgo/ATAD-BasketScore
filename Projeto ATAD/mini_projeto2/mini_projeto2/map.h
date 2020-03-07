#pragma once

#define MAP_OK            0
#define MAP_NULL          1
#define MAP_NO_MEMORY     2
#define MAP_EMPTY         3
#define MAP_FULL          4
#define MAP_UNKNOWN_KEY	  5

#include "mapElem.h"

struct mapImpl;
typedef struct mapImpl *PtMap;

PtMap mapCreate(unsigned int initialCapacity);
int mapDestroy(PtMap *ptMap);
int mapPut(PtMap map, MapKey key, MapValue value);
int mapRemove(PtMap map, MapKey key, MapValue *ptValue);
int mapGet(PtMap map, MapKey key, MapValue *ptValue);
int mapContains(PtMap map, MapKey key);
int mapSize(PtMap map, int *ptSize);
int mapIsEmpty(PtMap map);
int mapClear(PtMap map);
void mapPrint(PtMap map);
