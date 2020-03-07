#include "Cluster.h"

void Kmeans(PtList list, int k, int maxIterations, float deltaError)
{
	if (k > 2)
	{
		if (maxIterations > 1)
		{
			PtList average = averageStatistics(list);
			PtList normalizeList = normalizeStatistics(average);
		}
		else
		{
			printf("Numero de Iteracoes tem de ser maior que 1\n");
		}
	}
	else
	{
		printf("Numero de Cluster tem de ser maior que 2\n");
	}
	
}
