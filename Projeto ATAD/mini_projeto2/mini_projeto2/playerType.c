#include "playerType.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>



PlayerType createPlayerType(char *initialText) {
	
	
	PlayerType newPlayerType;

	strcpy_s(newPlayerType.text, sizeof(newPlayerType.text), initialText);

	return newPlayerType;
}

int stringKeyEquals(PlayerType pt1, PlayerType pt2) {
	if (strcmp(pt1.text, pt1.text) == 0) {
		return 1;
	}
	else
	{
		return 0;
	}
}