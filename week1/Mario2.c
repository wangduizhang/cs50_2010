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
    

    int kuan = (height+1)*2 + 2;

	for (int i = 0; i < height; ++i){
	    for (int j = 0; j <= kuan; ++j){
	    	if(j <height +1){
	    		if (j < height - i-1)
	    			printf("%c",' ');
	    		else
	    			printf("%c",'#');
	    	}
	    	if(height +1 < j && j <= height +3)
	    		printf("%c",' ');
	    	if (j > height + 3){
	    		if (j <= height + 5 + i)
	    			printf("%c",'#');
	    		else
	    			printf("%c",' ');
	    	}
	    }
		printf("\n");
	}

	return 0;
}