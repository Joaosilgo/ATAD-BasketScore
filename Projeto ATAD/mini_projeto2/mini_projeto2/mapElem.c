#include "mapElem.h"
#include "playerType.h"
#include <stdio.h>

void mapKeyPrint(MapKey key) {
	printf("KEY: %d \n", key);
}

void mapValuePrint(MapValue value) {
	printf("VALUE: %s \n", value.text);

}

/* funcao de comparacao de chaves */
int mapKeyEquals(MapKey key1, MapKey key2) {
	return (key1 == key2);
}