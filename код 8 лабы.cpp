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

void process_line(char buffer[])
{
	char c; // ������� ������ 
	int word = NO; // ������� ����� 
	int symb = NO; // ��������� ������� ������ �������� 
	char *ish_ptr = 0; // ������� �������� ������� �������� c����� 
	char *res_ptr = 0; // ������� �������� ������� �������������� ������ 
	char *start_ptr = 0; // ������� ������ ����� 
	char *pred_start_ptr = 0; // ������� ������ ����������� ����� 
	start_ptr = buffer;
	ish_ptr = buffer;
	start_ptr = buffer;
	pred_start_ptr = buffer;
	res_ptr = buffer;

	do
	{
		c = *ish_ptr; // ����� ������� ������ �� ������ 
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '?' || c == '!' || c == ';' || c == ':' || c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') // ����������� ������
		{
			if (word == YES) // ���� �������� �� ������� ���������... 
			{
				if(symb == NO)
				{ 
					while (start_ptr < ish_ptr)
						*res_ptr = *start_ptr++;// ����� �� �������� �������� ��� ���������� � �������������� ������ ������ �� ����� ������������ 
				
					
				}
			}
			else//���� ��� �����������, ��...
			{
				*res_ptr = *ish_ptr++;//���������� ����������� �� �����
			}
			if (symb == NO)
			{
				*pred_start_ptr = *start_ptr;
			}
			symb = NO;
			word = NO;
		}
		else if (c == '\0') // ���� �� ����� ������, �� ��������� ����� ����� ������ ��������������
		{
			while(start_ptr < ish_ptr) // ����� �� �������� ��������, ��� ���������� � �������������� ������ ������ �� ����� ������������
			{
				*pred_start_ptr = *start_ptr++;// ����������� ����� �� ����� ��������������
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
				start_ptr = ish_ptr; // ��������� ������� ������ ����� 
			}
			word = YES;
		}
		ish_ptr++;
	} while (c != '\0');// ���������� �� ����� ������
	res_ptr = '\0';//������������� ����� ������
}




			
					

