#include "Date.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

Date createDate(unsigned int day, unsigned int month, unsigned int year) {
	Date newDate;

	newDate.day = day;

	newDate.month = month;

	newDate.year = year;

	return newDate;
}

void datePrint(PtDate _this) {
	printf("%02d/%02d/%02d \n", _this->day, _this->month, _this->year);
}