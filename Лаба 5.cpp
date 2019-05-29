#include <stdio.h>
#define N 10
int main( void )
{
int x[N]; 
int max;
int i;

 for( i = 0; i < N; i++ )
 scanf("%d", &x[i]);

 max = 0;
 for( i = 0; i < N; i++ )
 if(max < x[i])
	max = x[i];

 for( i = 0; i < N; i++ )
  {
	  if (x[i] == max)
	   break;
	  else
		  x[i]=0;
  }
 for( i ; i < N; i++ )
	 x[i] = max;

 for( i = 0; i < N; i++ )
 printf("%d ", x[i]);
 printf("\n");
return 0;
}