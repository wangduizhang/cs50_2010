#include <stdio.h>

int main(int argc, char const *argv[])
{
            for (int i = 0; i < 1000; ++i)//n行数据
                for (int j = 0; j < 4; ++j)//每行数据n倍
                    for (int k = 0; k < 4; ++k)//每个数据n遍
                    printf("%d\n",i+j+k);
	return 0;
}