#include <stdio.h>
#define N 4

int main(void)
{
	int x[N][N];
	int summa1=0;//����� ��� ������� ����������
    int summa2=0;//����� ��� ������� ����������
	int i,j;
	//���� �������
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			scanf("%d", &x[i][j]);
	
	//������� summa1
	for(i=1, j=1; j<N; j++)
		summa1 = summa1 + x[i][j];
	for (i=2, j=2; j<N; j++)
		summa1 = summa1 + x[i][j];
	for (i=3, j=3; j<N; j++)
		summa1 = summa1 + x[i][j];
	
	//������� summa2
	for(i=1,j=0; i<N; i++)
		summa2 = summa2 + x[i][j];
	for(i=2,j=1; i<N; i++)
		summa2 = summa2 + x[i][j];
	for(i=3,j=2; i<N; i++)
		summa2 = summa2 + x[i][j];
	//�������� �� �������
	if (summa1 < summa2){
		for(i=0, j=1; j<N; j++)
		 x[i][j] = 0;
	    for (i=1, j=2; j<N; j++)
		 x[i][j] = 0;
	    for (i=2, j=3; j<N; j++)
			x[i][j] = 0;}
	else
		{for(i=1,j=0; i<N; i++)
		 x[i][j] = 0;
	    for(i=2,j=1; i<N; i++)
		 x[i][j] = 0;
	    for(i=3,j=2; i<N; i++)
			x[i][j] = 0;}
	// ����� ����������
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			printf("%2d", x[i][j]);
		    printf("\n");
	}
	return 0;
}
