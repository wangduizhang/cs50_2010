#include <stdio.h>
#include <stdlib.h>


int get_jpg(FILE *f)
{
    int chch;
    FILE *of;
    char file_name[8];

    printf("Output file name:");
    scanf("%3s",file_name);
    file_name[3] = '.';
    file_name[4] = 'j';
    file_name[5] = 'p';
    file_name[6] = 'g';
    file_name[7] = '\0';
    
    of = fopen(file_name,"wb");

    fseek(f,-4,SEEK_CUR);

    while((chch = fgetc(f)) != EOF){
        fwrite(&chch,1,1,of);
        if (chch == 255){
            if((chch = fgetc(f)) == 217){
                fwrite(&chch,1,1,of);
                break;
            }
        fwrite(&chch,1,1,of);   
        }
    }
    fclose(of);
    return 0;
}



int del_jpg(FILE *f)
{
    int chch;
    
    while((chch = fgetc(f)) != EOF)
    {
        if (chch == 255 && (chch = fgetc(f)) == 216 && (chch = fgetc(f)) == 255 && (chch = fgetc(f)) == 224)
            get_jpg(f);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    FILE *f;

    if (argc == 1)
    {
        printf("No file!\n");
        return 0;
    }
    
    f = fopen(argv[1],"rb");
    
    if (f == NULL)
    {
        printf("No find this file!\n");
        return 0;
    }
    del_jpg(f);
    fclose(f);
    return 0;
}
