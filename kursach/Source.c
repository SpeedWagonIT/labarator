#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAXLINE 1000 

typedef struct {
	int day;
	char month[20];
	int event;
	//int year;
	char birthday[100];
	char holiday[100];
}almс;

void out(FILE *almanac, almс *mp, int size)
{
	fwrite(&size, sizeof(int), 1, almanac);
	fwrite(mp, sizeof(almс), size, almanac);
}

void in(FILE *almanac, almс *mp, int *size)
{
	fread(size, sizeof(int), 1, almanac);
	fread(mp, sizeof(almс), *size, almanac);
}

almс red()
{
	almс mp;
	printf("\n select month: ");
	scanf("%s", &mp.month);
	printf("\n select day: ");
	scanf("%d", &mp.day);
	printf("\n holiday[1]/bithday[0]?");
	scanf("%d", &mp.event);
	switch (mp.event) {
	case 1:
		printf("\nthe name of the holiday");
		scanf("\n %s", &mp.holiday);
		break;
	case 2:
		printf("\nWho's birthday");
		scanf("\n %s", &mp.birthday);
		break;
	}
	return mp;
}

void show(almс *mp, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("\nmonth: %s \nday: %d \nholiday: %s \nbirthday: %s ", mp[i].month, mp[i].day, mp[i].holiday, mp[i].birthday);
	}
	
}



int main(void)
{
	almс mp[100];





}