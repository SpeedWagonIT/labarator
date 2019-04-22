#include <stdio.h>
#define YES 1
#define NO 0
int main (void)
{
	int c;
	int flag;
	int cnt;
	int found;
	cnt=0;
	flag=NO;
	found=NO;
	while((c=getchar()) !=EOF)
	{
		if( c==' '|| c=='.'|| c=='\n'||c==',')
		{
			if(flag == YES)
			{
				if (found == YES)
				{
					cnt=cnt + 1;
				}
			}
					flag=NO;
				}
				else
				{
					if(c == 'b' || c == 'c' || c == 'd' || c == 'f' || c == 'g' || c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n'|| c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'v' || c == 'w' || c == 'x' || c == 'z' )
						found = YES;
					else 
						found = NO;
					flag=YES;
				}
			}
			printf("number of words = %d\n", cnt);
			getchar ();
			return 0;
		}
	
