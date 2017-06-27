#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

struct time
{
	int h;
	int m;
	int s;
};

//计时时间更新
struct time updatetime(struct time nowtime)
{
	struct time nexttime;

	if (nowtime.s == 59){
		if (nowtime.m == 59){
                if (nowtime.h!=23 ){
                    nexttime.s = 00;
                    nexttime.m = 00;
                    nexttime.h = nowtime.h + 1;
                }
                else{
                    nexttime.s = 00;
                    nexttime.m = 00;
                    nexttime.h = 00;
                }
		}
        else{
            nexttime.s = 00;
            nexttime.m = nowtime.m + 1;
            nexttime.h = nowtime.h;
        }
    }
	else{
		nexttime.s = nowtime.s + 1;
		nexttime.m = nowtime.m;
		nexttime.h = nowtime.h;
	}

	
	return nexttime;
}


//倒计时时间更新
struct time updatetimedrop(struct time gettime)
{
	struct time lasttime;

	if (gettime.s == 00 ){
		if (gettime.m != 00){

		    lasttime.s = 59;
		    lasttime.m = gettime.m - 1;
		    lasttime.h = gettime.h;
		}
		if (gettime.m ==0 && gettime.h != 0 ){

			lasttime.s = 59;
		    lasttime.m = 59;
		    lasttime.h = gettime.h - 1;
		}
		if (gettime.m ==0 && gettime.h == 0){

			lasttime.s = 59;
		    lasttime.m = 59;
		    lasttime.h = 23;
		}
	}
	
	else{
		
		lasttime.s = gettime.s - 1;
		lasttime.m = gettime.m;
		lasttime.h = gettime.h;
	}

	
	return lasttime;
}

//用户的选择
char choice_(void)
{
    char choi;
    bool r;



    printf("- - - - - - - - - - - - - - - - - - - - - - \n");
    printf("             《简易计时器》\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - \n");
    printf("            ***请选择你的模式***\n");
    printf("       0.退出程序 1.正计时 2.倒计时\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - \n");
    
    do{
		r = false;
		scanf ("%c", &choi);
    	switch(choi){
    		case '0':
    			printf("***退出程序***\n");
    			break;
    		case '1':
    			printf("             ***计时模式***\n");
    			printf("- - - - - - - - - - - - - - - - - - - - - - \n");
    			break;
    		case '2':
    	   		printf("             ***倒计时模式***\n");
    	   		printf("- - - - - - - - - - - - - - - - - - - - - - \n");
    	   		break;
    		default:
    	   		r = true;
    	if (r == true)
    	    printf("错误的指令！\n");
        }
    }while(r);

return choi;
}
//倒计时，获取时间
struct time getusertime(void)
{
    struct time gettime;
    bool r1,r2,r3;
    
    printf("输入你的时间\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - \n");
    printf(">>>时：");
    do{
    	r1 = false;
    	scanf("%d",&gettime.h);
    	if (gettime.h > 23|| gettime.h<0){
    		printf("错误的输入！\n" );
    		printf(">>>时：");
    		r1 = true;
    	}
    }while(r1);

    
    printf(">>>分：");
    do{
    	r2 = false;
    	scanf("%d",&gettime.m);
    	if (gettime.m > 60|| gettime.m<0){
    		printf("错误的输入！\n");
    		printf(">>>分：");
    		r2 = true;
    	}
    }while(r2);

    printf(">>>秒：");
    do{
    	r3 = false;
    	scanf("%d",&gettime.s);
    	if (gettime.s > 60|| gettime.s<0){
    		printf("错误的输入！\n");
    		printf(">>>秒：");
    		r3 = true;
    	}
    }while(r3);
return gettime;
}


//入口
int main(void)
{
	struct time updatetime (struct time nowtime);//处理时间
	struct time getusertime(void);//获取用户手机时间
    struct time updatetimedrop (struct time gettime);//更新倒计时

    char choice_(void);//获取用户选择

    char choi;

	struct time nexttime;
	struct time gettime;
 
    choi = choice_();
    if (choi == '0')
    	return 0;
    

    else if (choi == '1')//正计时模式
    {
    	struct time nowtime;

    	nowtime = (struct time){.s = 00,.m = 00,.h = 00};
    	
    	while(1) {
            
	    	
	    	printf("当前时间：%.2d:%.2d:%.2d\r",nowtime.h,nowtime.m,nowtime.s);
        	fflush(stdout);
            nexttime = updatetime(nowtime);
	    	sleep(1);
	    	nowtime = nexttime;
        }
    }
    
    
    else{
        struct time lasttime;

        gettime = getusertime();
        

        printf("- - - - - - - - - - - - - - - - - - - - - - \n");
        printf("设置时间：%.2d:%.2d:%.2d\n",gettime.h,gettime.m,gettime.s);
    	
    	while(1) {
	    	
	    	
	    	printf("剩余时间：%.2d:%.2d:%.2d\r",gettime.h,gettime.m,gettime.s);
	    	fflush(stdout);
            lasttime = updatetimedrop(gettime);
	    	sleep(1);
	    	gettime = lasttime;
	    	
	    	if (lasttime.h==0 && lasttime.m==0 && lasttime.s==0){
	    		printf("！！！时间到！！！\n");
	    		break;
	    	}
         }

    }
	return 0;
}