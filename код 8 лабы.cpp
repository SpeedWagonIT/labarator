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
	char *in_ptr = line; // указатель на позицию текущего символа исходной cтроки 
	char *out_ptr = line; // указатель на позицию текущего символа результирующей строки 
	char *word_ptr = line; // указатель на позицию начала слова 
	char *pred_word_ptr = line; // указатель на позицию начала предыдущего слова 
	

	do
	{
		c = *in_ptr; // вз€ть текущий символ из буфера 
		if (c == ' ' || c == '\n' ) // разделитель найден
		{
			if (symb == NO)
			{
				pred_word_ptr = word_ptr;
			}
			if (word == YES || symb == YES)
			{
				for (; word_ptr < in_ptr; word_ptr++, out_ptr++)
				{
				}
			}
			*out_ptr++ = c;
			symb = NO;
			word = NO;
		}
		else if (c == '\0') // если то конец строки, то последнее сорвр пишем вместо предпоследнего
		{
			for (; word_ptr < in_ptr; out_ptr++)
			{
				*pred_word_ptr++ = *word_ptr++;
			}
			*pred_word_ptr = c;
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
	*out_ptr = '\0';//устанавливаем конец строки
}




			
					

