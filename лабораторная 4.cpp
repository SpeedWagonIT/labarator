#pragma warning(disable : 4996) //���������� ��� ������������� ���������� ������� (scanf) 
#include <stdio.h> 
// ����������� ������������� �������� 
#define YES 1 
#define NO 0 
#define MAXLINE 1000 
void process_line(char line[]); // ��������� ������� 

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
	char c; // ������� ������ 
	int word = NO; // ������� ����� 
	int symb = NO; // ��������� ������� ������ �������� 
	int i = 0; // ������� �������� ������� �������� c����� 
	int pos = 0; // ������� �������� ������� �������������� ������ 
	int start = 0; // ������� ������ ����� 
	int pred_start = 0; // ������� ������ ����������� ����� 

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