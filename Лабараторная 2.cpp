#include <stdio.h>

int main (void)
{
	float s;//сумма ряда
	float a;//очередной элемент ряда
	float c;//числитель элемета
	float b;//знаменатель элемента
	float x;//входной параметр ряда
	int n;//число элементов ряда
	int i;//номер очередного элемента
	//ввод параметров ряда
	printf("n=");
	scanf("%d", &n);
	printf("x=");
	scanf("%f", &x);
	//начальное присваивание переменных
	s=0;
	i=0;
	c=1;
	b=1;
	//цикл
	while(i<n)
	{
		i=i+1;
		a=c/b;
		s=s+a;
		c=c*x;
		b=b*i;
	}
	//вывод результата
	printf("s=%f\n", s);
	system ( "Pause" );
	return 0;
	
}