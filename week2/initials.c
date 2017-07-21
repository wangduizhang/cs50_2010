#include <stdio.h>
#include <string.h>

int main()
{
	char name[30];

	scanf("%29s" ,name);

	printf("你好:%.3s先生\n",name);

	return 0;
}