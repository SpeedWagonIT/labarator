#include <stdio.h>
int main (void)
{
	float v;
	float l;
	float t;
	printf("v=");
	scanf("%f", &v);
	printf("l=");
	scanf("%f", &l);
	t=2*l/v;
	printf("time = %f\n", t);
	getchar();
	return 0;
}