#include <stdio.h>


int x1 = 1;
int x2 = 2;

int main(void)
{
	void increas(void);

	increas();
	printf("x1 = %d  x2 = %d\n",x1,x2);
	return 0;
}


void increas(void)
{
	x1 = 10;//未重新定义x1
    int x2 = 10;//重新定义x2
	
	x1++;
	x2++;
}