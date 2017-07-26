#include <stdio.h>


int x1 = 1;
int x2 = 2;

int main(int argc,char const *argv[])
{
	void increas(void);
    int a;
    int b,c,d;
	increas();
	printf("x1 = %d  x2 = %d\n",x1,x2);
	printf("========================\n");
	printf("%d\n",'c' == 99);

    printf("%d\n", *(argv[2]+1) == 97);
    
    if (argc)
    {
    	printf("%d\n",argc);
    }
    a = scanf("%d%d%d",&b,&c,&d);
    printf("%d\n",a);

	return 0;
}


void increas(void)
{
	x1 = 10;//未重新定义x1
    int x2 = 10;//重新定义x2
	
	x1++;
	x2++;
}