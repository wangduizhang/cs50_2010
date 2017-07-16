#include <stdio.h>

#define FILEPATH "/Users/wp/Desktop/studentinformation.txt"

int main(void)
{
	FILE *text;
    char fget_s[150];
	
	text = fopen(FILEPATH,"r");
    fgets(fget_s,150,text);
    for(int i = 0 ;i <150;i++) 
        printf("%c\n", fget_s[i]);
	return 0;
}