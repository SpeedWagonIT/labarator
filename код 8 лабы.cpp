#pragma warning(disable : 4996) //необходимо дл€ использовани€ устаревших функций (scanf) 
#include <stdio.h> 
// определение символических констант 
#define YES 1 
#define NO 0 
#define MAXLINE 1000 
void process_line(char line[]); // объ€вл€ем функцию 

int main(void)
{
	char line[MAXLINE];
	printf("Please, enter some words\n");
	gets(line);
	process_line(line);
	printf("Result:\n");
	puts(line);
	getchar();
	getchar();
	return 0;
}

void process_line(char line[])
{
	char c; // текущий символ 
	int word = NO; // признак слова 
	int symb = NO; // индикатор наличи€ лишних символов 
	char* in_ptr = line; // указатель на позицию текущего символа исходной cтроки 
	char* out_ptr = line; // указатель на позицию текущего символа результирующей строки 
	char* word_ptr = line; // указатель на позицию начала слова 
	char* pred_word_ptr = line; // указатель на позицию начала предыдущего слова 


	do
	{
		c = *in_ptr; // вз€ть текущий символ из буфера 
		if (c == '\0')
		{
			if (pred_word_ptr != word_ptr)
				for (; *(pred_word_ptr - 1) != '\0'; word_ptr++, pred_word_ptr++)
				{
					*pred_word_ptr = *word_ptr;
				}
			break;
		}
		else if (c == ' ') // разделитель найден
		{
			if (word == YES && symb == NO)
			{
				pred_word_ptr = word_ptr;
			}
			symb = NO;
			word = NO;
		}
		else
		{
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) // проверить не €вл€етс€ ли этот символ лишним
			{
				symb = YES; // в слове есть лишний символ
			}
			if (word == NO && symb == NO) // найдена перва€ буква слова 
			{
				word_ptr = in_ptr; // запомнить позицию начала слова 
			}
			word = YES;
		}
		in_ptr++;
	} while (c != '\0');// продолжать до конца строки
}

