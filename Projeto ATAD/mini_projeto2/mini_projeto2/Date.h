#pragma once

typedef struct date {
	unsigned int day;
	unsigned int month;
	unsigned int year;
} Date;

typedef Date* PtDate;

Date createDate(unsigned int day, unsigned int month, unsigned int year);
void datePrint(PtDate _this);

