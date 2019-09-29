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
	int i = 0; // позици€ текущего символа исходной cтроки 
	int pos = 0; // позици€ текущего символа результирующей строки 
	int start = 0; // позици€ начала слова 
	int pred_start = 0; // позици€ начала предыдущего слова 

	do
	{
		c = line[i];
		if (c == ' ' || c == '.' || c == ',' || c == '\n' )
		{
			if (word == YES)
			{
				for (; start < i; start++, pos++)
				{
					line[pos] = line[start];
				}
			}
			if (symb == NO)
			{
				pred_start = start;
			}
			line[pos++] = c;
			symb = NO;
			word = NO;
		}
		else if (c == '\0')
		{
			for (; start < i; start++, pos++)
			{
				line[pos] = line[pred_start];
			}
		}
		else
		{
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
			{
				symb = YES;
			}
			if (word == NO && symb == NO)
			{
				start = i;
			}
			word = YES;
		}
		i++;
	} 
	while (c != '\0');
	line[pos] = '\0';
}