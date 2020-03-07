#pragma once
#define STRINGKEY_MAX_LENGTH 15

typedef struct playerType {
	char text[STRINGKEY_MAX_LENGTH];
} PlayerType;

PlayerType createPlayerType(char *initialText);
int stringKeyEquals(PlayerType pt1, PlayerType pt2);


