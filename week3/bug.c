#include <stdio.h>


int swit_ch(int a,int b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return 0;
}

int main(void)
{
    int swit_ch(int a,int b);

    int a = 1;
    int b = 2;
    swit_ch(a,b);
    printf("你好\n");
	return 0;
}

