#include <stdio.h>

int main (void)
{
	float s;//����� ����
	float a;//��������� ������� ����
	float c;//��������� �������
	float b;//����������� ��������
	float x;//������� �������� ����
	int n;//����� ��������� ����
	int i;//����� ���������� ��������
	//���� ���������� ����
	printf("n=");
	scanf("%d", &n);
	printf("x=");
	scanf("%f", &x);
	//��������� ������������ ����������
	s=0;
	i=0;
	c=1;
	b=1;
	//����
	while(i<n)
	{
		i=i+1;
		a=c/b;
		s=s+a;
		c=c*x;
		b=b*i;
	}
	//����� ����������
	printf("s=%f\n", s);
	system ( "Pause" );
	return 0;
	
}