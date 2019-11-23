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

void out(FILE *f, almс *mp, int size)
{
	fwrite(&size, sizeof(int), 1, f);
	fwrite(mp, sizeof(almс), size, f);
}

void in(FILE *f, almс *mp, int *size)
{
	fread(size, sizeof(int), 1, f);
	fread(mp, sizeof(almс), *size, f);
}

almс add()
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
//
//int day(const void *f, const void *s)
//{
//	return strcmp(((almс*)f)->day, ((almс*)s)->day) > 0;
//}
//
//int month(const void *f, const void *s)
//{
//	return (((almс*)f)->month - ((almс*)s)->month < 0);
//}


int main(void)
{
	almс mp[100];
	int size = 0, i;
	FILE *f = fopen("f.txt", "rb");
	if (f)
	{
		in(f, mp, &size);
		fclose(f);
	}
	f = fopen("f.txt", "wb");
	while (1)
	{
		printf("\n1 add\n2 edit \n3 delete \n4 sort(not yet) \n5 show all \n6 find(not yet) \n0 exit\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			mp[size] = add();
			size++;
			break;

		case 2:
			printf("\ni: ");
			scanf("%d", &i);
			mp[i] = add();
			break;

		case 3:
			printf("\ni: ");
			scanf("%d", &i);
			--size;
			for (; i < size; i++)
				mp[i] = mp[i + 1];
			break;

		case 5:
			show(mp, size);
			break;

		case 0:
			out(f, mp, size);
			fclose(f);
			return 0;
		}

	}
}


