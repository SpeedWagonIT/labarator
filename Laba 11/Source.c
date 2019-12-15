#define _CRT_SECURE_NO_WARNINGS
#define YES 1
#define NO 0
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define MAXLEN 1000
void main(void)
{
	HANDLE hStdout;
	char word[MAXLEN];
	int i = 0;
	int flag1 = 0;//Флаг наличия типа данных в начале строки
	int flag2 = 0;//Флаг наличия круглой скобки в строке
	int flag3 = 0;//Флаг отсутствия оператора приравнивания
	int flag4 = 0;// флаг на структуру
	int flag5 = 0;// флаг на goto
	char line[MAXLEN]; //Строка
	char types[5][MAXLEN] = { "int","float","double","char","void" };//Константные типы данных
	char str[2][MAXLEN] = { "struct", "typedef" };
	char gto[1][MAXLEN] = { "goto" };
	FILE *fp;
	char *ptr;
	char *buf;
	fp = fopen("text.txt", "rt");
	/*Настройка параметров консоли*/
	WORD foregroundColor4;//жёлтый
	WORD foregroundColor3;//зеленый
	WORD foregroundColor2;//бирюзовый цвет
	WORD foregroundColor1;//красный
	WORD foregroundColor0;//фиолетовый цвет
	WORD textAttribute;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor4 = FOREGROUND_INTENSITY | 6;
	SetConsoleTextAttribute(hStdout, foregroundColor4);
	foregroundColor3 = FOREGROUND_INTENSITY | 2;
	SetConsoleTextAttribute(hStdout, foregroundColor3);
	foregroundColor0 = FOREGROUND_INTENSITY | FOREGROUND_BLUE;
	SetConsoleTextAttribute(hStdout, foregroundColor0);
	foregroundColor1 = FOREGROUND_INTENSITY | FOREGROUND_RED;
	SetConsoleTextAttribute(hStdout, foregroundColor1);
	foregroundColor2 = FOREGROUND_INTENSITY | FOREGROUND_GREEN;
	SetConsoleTextAttribute(hStdout, foregroundColor0);
	while (!feof(fp))
	{
		ptr = fgets(line, MAXLEN, fp);
		buf = line;
		while (*buf != '\0')//Проверяем на наличие знаков приравнивания
		{
			if (*buf == '=')
				flag3 = YES;
			buf++;
		}
		while (*ptr != ' ')//Берем первое слово
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
		if (strcmp(word, str[0]) == 0 || strcmp(word, str[1]) == 0)
			flag4 = YES;
		if (strcmp(word, gto[0]) == 0)
			flag5 = YES;
		while (*ptr != '\0')//До конца строки ищем круглую скобку
		{
			if (*ptr == '(')

			{
				flag2 = YES;
				ptr++;
				break;
			}
			else {

				ptr++;
				continue;
			}
		}
		if (flag1 == YES || flag4 == YES || flag5 == YES)//Если надо что-то выделить
		{
			if(flag5 == YES)//найден goto
			{
				textAttribute = foregroundColor4;
				SetConsoleTextAttribute(hStdout, textAttribute);
				printf("%s", line);
			}
			if (flag1 == YES && flag2 == YES && flag3 == NO)//найдена функция
			{
				textAttribute = foregroundColor3;
				SetConsoleTextAttribute(hStdout, textAttribute);
				printf("%s", line);
			}
			if (flag1 == YES && flag2 == NO)//найден тип данных
			{
				textAttribute = foregroundColor0;
				SetConsoleTextAttribute(hStdout, textAttribute);
				printf("%s", line);
			}
			if(flag4 == YES)//найдена структура
			{
				textAttribute = foregroundColor1;
				SetConsoleTextAttribute(hStdout, textAttribute);
				printf("%s", line);
			}
		}
		else//иначе - выводим стандартно
		{
			SetConsoleTextAttribute(hStdout, 7);
			printf("%s", line);
		}
		/*Обнуляем флаги и счетчики*/
		i = 0;
		flag1 = flag2 = flag4 = flag3 = flag5 = NO;
	}
	/*Восстанавливаем стандартные параметры консоли*/
	SetConsoleTextAttribute(hStdout, 7);
	fclose(fp);//Закрываем файл
	getchar();
}