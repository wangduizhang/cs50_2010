#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *f;
    int pp;
    char ccc[50];

	
	f = fopen("test.txt","r");
	while(1){
	int index = 0;
	while((pp = fgetc(f)) != ' '){
		if (pp == EOF)
			return 0;
		ccc[index] = pp;
		index ++;
	}
	ccc[index] = '\0';
    printf("%s\n",ccc);
    }

	return 0;
}