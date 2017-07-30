#include <stdio.h>



int print(int p[][2])
{
	for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            printf("%d",p[i][j]);

    return 0;
}

int main(int argc, char const *argv[])
{
	int num[2][2] = {{1,1},{1,1}};
    
    print(num);

	return 0;
}