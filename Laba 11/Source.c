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
	int flag1 = 0;//���� ������� ���� ������ � ������ ������
	int flag2 = 0;//���� ������� ������� ������ � ������
	int flag3 = 0;//���� ���������� ��������� �������������
	int flag4 = 0;// ���� �� ���������
	int flag5 = 0;// ���� �� goto
	char line[MAXLEN]; //������
	char types[5][MAXLEN] = { "int","float","double","char","void" };//����������� ���� ������
	char str[2][MAXLEN] = { "struct", "typedef" };
	char gto[1][MAXLEN] = { "goto" };
	FILE *fp;
	char *ptr;
	char *buf;
	fp = fopen("text.txt", "rt");
	/*��������� ���������� �������*/
	WORD foregroundColor4;//�����
	WORD foregroundColor3;//�������
	WORD foregroundColor2;//��������� ����
	WORD foregroundColor1;//�������
	WORD foregroundColor0;//���������� ����
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
		while (*buf != '\0')//��������� �� ������� ������ �������������
		{
			if (*buf == '=')
				flag3 = YES;
			buf++;
		}
		while (*ptr != ' ')//����� ������ �����
		{
			if (*ptr == '\t')
				ptr++;
			word[i] = *ptr;
			ptr++;
			i++;
		}
		word[i++] = '\0';
		/*��������� ���������� � ������ ������*/
		if (strcmp(word, types[0]) == 0 || strcmp(word, types[1]) == 0 || strcmp(word, types[2]) == 0 || strcmp(word, types[3]) == 0 || strcmp(word, types[4]) == 0)
			flag1 = YES;
		if (strcmp(word, str[0]) == 0 || strcmp(word, str[1]) == 0)
			flag4 = YES;
		if (strcmp(word, gto[0]) == 0)
			flag5 = YES;
		while (*ptr != '\0')//�� ����� ������ ���� ������� ������
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
		if (flag1 == YES || flag4 == YES || flag5 == YES)//���� ���� ���-�� ��������
		{
			if(flag5 == YES)//������ goto
			{
				textAttribute = foregroundColor4;
				SetConsoleTextAttribute(hStdout, textAttribute);
				printf("%s", line);
			}
			if (flag1 == YES && flag2 == YES && flag3 == NO)//������� �������
			{
				textAttribute = foregroundColor3;
				SetConsoleTextAttribute(hStdout, textAttribute);
				printf("%s", line);
			}
			if (flag1 == YES && flag2 == NO)//������ ��� ������
			{
				textAttribute = foregroundColor0;
				SetConsoleTextAttribute(hStdout, textAttribute);
				printf("%s", line);
			}
			if(flag4 == YES)//������� ���������
			{
				textAttribute = foregroundColor1;
				SetConsoleTextAttribute(hStdout, textAttribute);
				printf("%s", line);
			}
		}
		else//����� - ������� ����������
		{
			SetConsoleTextAttribute(hStdout, 7);
			printf("%s", line);
		}
		/*�������� ����� � ��������*/
		i = 0;
		flag1 = flag2 = flag4 = flag3 = flag5 = NO;
	}
	/*��������������� ����������� ��������� �������*/
	SetConsoleTextAttribute(hStdout, 7);
	fclose(fp);//��������� ����
	getchar();
}