#include <stdio.h>
#include <stdlib.h>


int del_bmp(FILE *f)//读取数据并处理
{
    int bmp_size;
    int info;

    fseek(f,2,SEEK_SET);
    fread(&bmp_size,4,1,f);
    fseek(f,4,SEEK_CUR);
    fread(&info,1,4,f);
    fseek(f,0,SEEK_SET);
    
    int data_size = bmp_size - info;
    unsigned int *p_info = (unsigned int *)malloc(info + 1);
    unsigned int *p_data = (unsigned int *)malloc(data_size + 1);
   
    if (p_info == NULL || p_data == NULL)
    {
    	printf("Insufficient memory!\n");
    	exit(1);
    }
    
    fread(p_info,info,1,f);
    fread(p_data,data_size,1,f);
     
    for (int i = 0; i < data_size/4; ++i)
     {
        if (p_data[i] == 4294967295)
            p_data[i] = 0;
     }
    FILE *of = fopen("1.bmp","wb");
    fwrite(p_info,info,1,of);
    fwrite(p_data,data_size,1,of);
    
    free(p_data);
    free(p_info);
    fclose(f);
    fclose(of);
    return 0;
}

int main(int argc, char const *argv[])
{
	
	FILE *f;


	if (argc == 1)
	{
		printf("No file name!\n");
		return 0;
	}
	else
	{
		f = fopen(argv[1],"rb");
		if (f == NULL)
		{
		printf("No this file!\n");
		return 0;
		}
	}
    del_bmp(f);
	return 0;
}

