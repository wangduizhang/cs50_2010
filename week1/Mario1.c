#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	int height;
    bool r = true;

	printf("高度：\n");
	printf(">>>");
	while(r) { 
	    scanf("%d",&height);
	    
	    if (height <= 0 | height > 10){
	    	printf("重新输入\n");
	    	printf(">>>");
	    }
	    else if (height > 0 && height <= 10)
	     	r = false;


	}

	for (int i = 0; i < height; ++i){
	    for (int j = 0; j < height + 1; ++j)
	    	if (j < height - i-1)
	    		printf("%c",' ');
	    	else
	    		printf("%c",'#');
		printf("\n");
	}

	return 0;
}