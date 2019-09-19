#include <stdio.h>
#define YES 1 
#define NO 0
#define MAXLINE 1000
void process_line(char buffer[]);

int main(void)
{
	char line[MAXLINE];
	printf("Please, enter some words\n");
	gets(line);
	process_line(line);
	printf("Result:\n");
	puts(line);
	return 0:
}
void process_line(char buffer[])
{
	char c;
	int word = NO;
	int symb = NO;
	int ish = 0;
	int res = 0;
	int start = 0;
	int pred_start = 0;
	int j;

	do
	{
		c = buffer[ish];
		if (c == '' || c == '.' || c == ',' || c == '\n' || c == '?' || c== '!' || c == ';' || c == ':' || c == '-' || c == '_' || c == '(' || c == ')' || c == '\t' || c == '/' || c == '&' || c == '"') 
		{

