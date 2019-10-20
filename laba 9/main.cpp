#pragma warning(disable : 4996)
#include <stdio.h>
#define MAXLINE 1024
#define YES 1
#define NO 0
char filestr[MAXLINE];
char c;
char *pred_word_ptr;
char *word_ptr;

void delword(void);
void mirrortext(void);
void mirrorres(void);
int main(void)
{
	printf("Current contents of the file text.txt:\n");
	mirrortext();
	delword();
	printf("\nResult of processing (res.txt):\n");
	mirrorres();


	getchar();
	getchar();
	return 0;
}

void delword(void)
{
	FILE *frd, *fwr;
	char *filestr_ptr;
	int cnt = 0, cnt1 = 0;
	int word = NO;
	int symb = NO;
	frd = fopen("text.txt", "rt");
	fwr = fopen("res.txt", "w");
	if (frd == NULL) {
		printf("File hasnot been opened");
		return;
	}
	while (!feof(frd)) {
		filestr_ptr = fgets(filestr, MAXLINE, frd); // ÷èòàåì ñòðîêó
		if (filestr_ptr == NULL)
			break; // file end
		do
		{
			c = *filestr_ptr; // взять текущий символ из буфера 
			if (c == '\0')
			{
				if (pred_word_ptr != word_ptr)
					for (; *(pred_word_ptr - 1) != '\0'; word_ptr++, pred_word_ptr++)
					{
						*pred_word_ptr = *word_ptr;
					}
			}
			else if (c == ' ') // разделитель найден
			{
				if (word == YES)
				{
					pred_word_ptr = word_ptr;
				}
				word = NO;
			}
			else
			{
				if (word == NO) // найдена первая буква слова 
				{
					word_ptr = filestr_ptr; // запомнить позицию начала слова 
				}
				word = YES;
			}
			filestr_ptr++;
		} while (c != '\0');// продолжать до конца строки
			fputs(filestr, fwr);
			}
	fclose(frd);
	fclose(fwr);
}
	


	void mirrortext(void)
	{
		FILE *fp;
		fp = fopen("text.txt", "rt");
		if (fp == NULL) 
		{
			printf("FILE HAS NOT BEEN OPENED");
			exit(1);
		}
		while (!feof(fp))
		{
			c = fgetc(fp);
			printf("%c", c);
		}
		fclose(fp);
	}

	void mirrorres(void)
	{
		FILE *fp;
		fp = fopen("res.txt", "rt");
		if (fp == NULL)
		{
			printf("FILE HAS NOT BEEN OPENED");
			exit(1);
		}
		while (!feof(fp))
		{
			c = fgetc(fp);
			printf("%c", c);
		}
		fclose(fp);
	}
