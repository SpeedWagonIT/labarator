#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXLEN 10000
#define YES 1
#define NO 0

int main(void)
{
	int i = 0;
	char word[MAXLEN];
	int flag1 = 0;//Флаг наличия типа данных в начале строки
	int flag2 = 0;//Флаг наличия круглой скобки в строке
	int flag3 = 0;//Флаг отсутствия оператора приравнивания
	int flag4 = 0;//флаг на использование функции
	char *tmp;
	char types[5][MAXLEN] = { "int","float","double","char","void" };//Константные типы данных

	FILE *fp;
	char *ptr;
	char *buf;
	int end, start;
	fp = fopen("text.txt", "rt");
	
	
	while (!feof(fp))
	{
		tmp = (char*)malloc((MAXLEN) * sizeof(char));
		ptr = fgets(tmp, MAXLEN, fp);
		buf = tmp;
		start = 1, end = 1;
		while (*buf != '\0')//Проверяем на наличие знаков приравнивания
		{
			if (*buf == '=')
				flag3 = YES;
			buf++;
		}
		while (*ptr != ' ' && *ptr != '\0')//Берем первое слово
		{
			if (*ptr == '\t')
				ptr++;
			word[i] = *ptr;
			ptr++;
			i++;
		}
		word[i++] = '\0';
		/*Проверяем совпадение с типами данных*/
		if (strcmp(word, types[0]) == 0 || strcmp(word, types[1]) == 0 || strcmp(word, types[2]) == 0 || strcmp(word, types[3]) == 0 || strcmp(word, types[4]) == 0)
			flag1 = YES;
		while (*ptr != '\0')//До конца строки ищем круглую скобку
		{
			if (*ptr == '(' || *ptr == ';')
			{
				if (*ptr == '(')

				{
					flag2 = YES;
					ptr++;
				}
				if (*ptr == ';')
				{
					flag4 = YES;
					ptr++;
					break;
				}
				end++;
			}
			else {

				ptr++;
				end++;

			}
		}
		if (flag1 == YES && flag2 == YES && flag3 == NO && flag4 == NO)//Если все флаги в правильном положении - копируем строку
		{
			
			printf("%s",tmp);
		}
		/*Обнуляем флаги и счетчики*/
		i = 0;
		flag1 = flag2 = flag3 = flag4 = NO;
	}

	fclose(fp);
	getchar();
	getchar();
	return 0;
}

