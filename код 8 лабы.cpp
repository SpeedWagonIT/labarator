#pragma warning(disable : 4996) //���������� ��� ������������� ���������� ������� (scanf) 
#include <stdio.h> 
// ����������� ������������� �������� 
#define YES 1 
#define NO 0 
#define MAXLINE 1000 
void process_line(char buffer[]); // ��������� ������� 

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
	char *in_ptr = line; // ��������� �� ������� �������� ������� �������� c����� 
	char *out_ptr = line; // ��������� �� ������� �������� ������� �������������� ������ 
	char *word_ptr = line; // ��������� �� ������� ������ ����� 
	char *pred_word_ptr = line; // ��������� �� ������� ������ ����������� ����� 
	

	do
	{
		c = *in_ptr; // ����� ������� ������ �� ������ 
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '?' || c == '!' || c == ';' || c == ':' || c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') // ����������� ������
		{
			if (word == YES) // ���� �������� �� ������� ���������... 
			{	
				if(symb == NO)
				{ 
					while (word_ptr < in_ptr)
						*out_ptr = *word_ptr++;// ����� �� �������� �������� ��� ���������� � �������������� ������ ������ �� ����� ������������ 
				
					
				}
			}
			else//���� ��� �����������, ��...
			{
				*out_ptr++ = c;//���������� ����������� �� �����
			}
			if (symb == NO)
			{
				*pred_word_ptr = *word_ptr;
			}
			symb = NO;
			word = NO;
		}
		else if (c == '\0') // ���� �� ����� ������, �� ��������� ����� ����� ������ ��������������
		{
			while(word_ptr < in_ptr) // ����� �� �������� ��������, ��� ���������� � �������������� ������ ������ �� ����� ������������
			{
				*pred_word_ptr = *word_ptr++;// ����������� ����� �� ����� ��������������
			}
		}
		else
		{
			if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) // ��������� �� �������� �� ���� ������ ������
			{
				symb = YES; // � ����� ���� ������ ������
			}
			if (word == NO && symb == NO) // ������� ������ ����� ����� 
			{
				word_ptr = in_ptr; // ��������� ������� ������ ����� 
			}
			word = YES;
		}
		in_ptr++;
	} while (c != '\0');// ���������� �� ����� ������
	out_ptr = '\0';//������������� ����� ������
}




			
					

