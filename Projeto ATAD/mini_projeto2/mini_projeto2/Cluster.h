#include "List.h"


typedef struct cluster
{
	float meanTwoPoints;
	float meanThreePoints;
	float meanAssists;
	float meanFouls;
	float meanBlocks;
	PtList members;
}Cluster;

void Kmeans(PtList list,int k,int maxIterations,float deltaError);