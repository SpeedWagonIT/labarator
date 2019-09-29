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

void process_line(char buffer[])
{
	char c; // текущий символ 
	int word = NO; // признак слова 
	int symb = NO; // индикатор наличи€ лишних символов 
	char *ish_ptr = 0; // позици€ текущего символа исходной cтроки 
	char *res_ptr = 0; // позици€ текущего символа результирующей строки 
	char *start_ptr = 0; // позици€ начала слова 
	char *pred_start_ptr = 0; // позици€ начала предыдущего слова 
	start_ptr = buffer;
	ish_ptr = buffer;
	start_ptr = buffer;
	pred_start_ptr = buffer;
	res_ptr = buffer;

	do
	{
		c = *ish_ptr; // вз€ть текущий символ из буфера 
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '?' || c == '!' || c == ';' || c == ':' || c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') // разделитель найден
		{
			if (word == YES) // если подходит по условию выполнить... 
			{
				if(symb == NO)
				{ 
					while (start_ptr < ish_ptr)
						*res_ptr = *start_ptr++;// слово не подлежит удалению оно копируетс€ в результирующую строку вместе со своим разделителем 
				
					
				}
			}
			else//если это разделитель, то...
			{
				*res_ptr = *ish_ptr++;//возвращаем разделитель на место
			}
			if (symb == NO)
			{
				*pred_start_ptr = *start_ptr;
			}
			symb = NO;
			word = NO;
		}
		else if (c == '\0') // если то конец строки, то последнее сорвр пишем вместо предпоследнего
		{
			while(start_ptr < ish_ptr) // слово не подлежит удалению, оно копируетс€ в результирующую строку вместе со своим разделителем
			{
				*pred_start_ptr = *start_ptr++;// копирование слова на место предпоследнего
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
				start_ptr = ish_ptr; // запомнить позицию начала слова 
			}
			word = YES;
		}
		ish_ptr++;
	} while (c != '\0');// продолжать до конца строки
	res_ptr = '\0';//устанавливаем конец строки
}




			
					

