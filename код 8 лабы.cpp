#pragma warning(disable : 4996) //необходимо дл€ использовани€ устаревших функций (scanf) 
#include <stdio.h> 
// определение символических констант 
#define YES 1 
#define NO 0 
#define MAXLINE 1000 
void process_line(char buffer[]); // объ€вл€ем функцию 

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
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '?' || c == '!' || c == ';' || c == ':' || c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') // разделитель найден
		{
			if (word == YES) // если подходит по условию выполнить... 
			{	
				if(symb == NO)
				{ 
					while (word_ptr < in_ptr)
						*out_ptr = *word_ptr++;// слово не подлежит удалению оно копируетс€ в результирующую строку вместе со своим разделителем 
				
					
				}
			}
			else//если это разделитель, то...
			{
				*out_ptr++ = c;//возвращаем разделитель на место
			}
			if (symb == NO)
			{
				*pred_word_ptr = *word_ptr;
			}
			symb = NO;
			word = NO;
		}
		else if (c == '\0') // если то конец строки, то последнее сорвр пишем вместо предпоследнего
		{
			while(word_ptr < in_ptr) // слово не подлежит удалению, оно копируетс€ в результирующую строку вместе со своим разделителем
			{
				*pred_word_ptr = *word_ptr++;// копирование слова на место предпоследнего
			}
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
	out_ptr = '\0';//устанавливаем конец строки
}




			
					

