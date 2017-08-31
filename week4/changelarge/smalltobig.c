#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


static int *olddata = NULL;

struct bmpfileheader
{
	short int assert;
	int large;
	short int reserved1;
	short int reserved2;
	int imageoffset;
};

struct bmpfileinformation
{
  int sizeofinformation;
  int width;
  int height;
  short int other1;
  short int bitspixel;
  int other2;
  int sizeofimage;
  int other3;
  int other4;
  int other5;
  int other6;
};

struct bmpfileheader bmp;
struct bmpfileinformation bmpinformation;



int get_file(char bmp_name[100])
{
    char ccc;
    int index = 0;

	while((ccc = fgetc(stdin)) != '\n'){
    bmp_name[index] = ccc;
    index++;
    if (index == 100)
        break;
    }

    bmp_name[index+1] = '\0';
    return 0;
}


int check_file_name(const char *n)
{
	int index = 0;

	while(index < sizeof(n) - 3){
		if (n[index] == '.')
			if (n[index+1] == 'b'&& n[index+2] == 'm' && n[index+3] == 'p')
				return 0;
		index++;
	}
	return 1;
}


int get_data(FILE *f)
{   
    short int *p1 = & bmp.assert;
   	int *p2 = &bmp.large;
	short int *p3 = &bmp.reserved1;
	short int *p4 = &bmp.reserved2;
	int *p5 = &bmp.imageoffset;
    
    fread(p1,sizeof(*p1),1,f);
    fread(p2,sizeof(*p2),1,f);
    fread(p3,sizeof(*p3),1,f);
    fread(p4,sizeof(*p4),1,f);
    fread(p5,sizeof(*p5),1,f);
    

   
    int *p6 = &bmpinformation.sizeofinformation;
    int *p7 = &bmpinformation.width;
    int *p8 = &bmpinformation.height;
    short int *p9 = &bmpinformation.other1;
    short int *p10 = &bmpinformation.bitspixel;
    int *p11 = &bmpinformation.other2;
    int *p12 = &bmpinformation.sizeofimage;
    int *p13 = &bmpinformation.other3;
    int *p14 = &bmpinformation.other4;
    int *p15 = &bmpinformation.other5;
    int *p16 = &bmpinformation.other6;

    fread(p6,sizeof(*p6),1,f);
    fread(p7,sizeof(*p7),1,f);
    fread(p8,sizeof(*p8),1,f);
    fread(p9,sizeof(*p9),1,f);
    fread(p10,sizeof(*p10),1,f);
    fread(p11,sizeof(*p11),1,f);
    fread(p12,sizeof(*p12),1,f);
    fread(p13,sizeof(*p13),1,f);
    fread(p14,sizeof(*p14),1,f);
    fread(p15,sizeof(*p15),1,f);
    fread(p16,sizeof(*p16),1,f);
    int bitsofpixel = bmpinformation.bitspixel/8;
    olddata = (int *)malloc(bitsofpixel);
    
    if(olddata == NULL)
    {
        printf("ERROR:The file is too large!\n");
        exit(1);
    }
    if (bmpinformation.bitspixel  < 8)
    {
        free(olddata);
        printf("ERROR:Unsupported bitmap\n");
        exit(1);
    }

    return 0;
    
}

int make_file(FILE * p)
{
    fwrite(&bmp.assert,sizeof(char),2,p);
    fwrite(&bmp.large,sizeof(char),4,p);
    fwrite(&bmp.reserved1,sizeof(char),2,p);
    fwrite(&bmp.reserved2,sizeof(char),2,p);
    fwrite(&bmp.imageoffset,sizeof(char),4,p);
    fwrite(&bmpinformation.sizeofinformation,sizeof(char),4,p);
    fwrite(&bmpinformation.width,sizeof(char),4,p);
    fwrite(&bmpinformation.height,sizeof(char),4,p);
    fwrite(&bmpinformation.other1,sizeof(char),2,p);
    fwrite(&bmpinformation.bitspixel,sizeof(char),2,p);
    fwrite(&bmpinformation.other2,sizeof(char),4,p);
    fwrite(&bmpinformation.sizeofimage,sizeof(char),4,p);
    fwrite(&bmpinformation.other3,sizeof(char),4,p);
    fwrite(&bmpinformation.other4,sizeof(char),4,p);
    fwrite(&bmpinformation.other5,sizeof(char),4,p);
    fwrite(&bmpinformation.other6,sizeof(char),4,p);
    return 0;

    fclose(p);
}



int change_large(FILE *f,int n)
{
    int make_file(FILE * p);


    int height = abs(bmpinformation.height);
    int width = abs(bmpinformation.width);
    FILE * p;
    int index = 0;
    p = fopen("new.bmp","wb");

    int bitsofpixel = bmpinformation.bitspixel/8;

  
    bmp.large += bmpinformation.sizeofimage * (n * n - 1);

    bmpinformation.width *= n;
    bmpinformation.height *= n;
    bmpinformation.sizeofimage = bmpinformation.sizeofimage * n * n;
    
    make_file(p);
    
    int *data;
    data = (int *)malloc(height * width);

    for (int i = 0; i < (height * width); ++i)
    {
        fread(data,1,bitsofpixel,f);
        data++;       
    }
    data -= height * width;

while(index < height){
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                fwrite(data,bitsofpixel,1,p);
            }
            data++;
        }
        data -= width;
    }
    index++;
    data += width;
    
    }



return 0;
}

int cho_ice()
{
    int n = 0;
    char clean[100];

    do{
        printf("Input amplification factor:1-100\n");
        if(scanf("%d",&n))
            break;
        fgets(clean,99,stdin);
    }
    while(n > 100 || n < 1);


    return n;
}



int main(int argc, char const *argv[])
{
	int get_file(char bmp_name[100]);
    int check_file_name(const char *n);
    int change_large(FILE *f,int n);
    int cho_ice();
    int n = 0;

	FILE *f;
    if (!(f = fopen(argv[1],"rb")) || check_file_name(argv[1])){
    	  printf("ERROR:invalid file name!\n");
        return 0;
        }
    
    get_data(f);
    n = cho_ice();

    change_large(f,n);


    fclose(f);
}
