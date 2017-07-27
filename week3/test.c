#include <stdio.h>


int main(int ar4444gc, char const *argv[])
{
	int a = 2147483600;//int 范围-2147483648～2147483647
	int b = 1000000;
	int sum;

	sum = a + 1000000 - b;
	printf("先加后减：%d\n", sum);
	sum = a - 1000000 + b;
    printf("先减后加：%d\n", sum);
	return 0;
}