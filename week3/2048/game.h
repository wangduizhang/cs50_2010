#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>

static int point;

int scanKeyboard(void)//监听键盘 
{  
    int in;  
    struct termios new_settings;  
    struct termios stored_settings; 
    tcgetattr(0,&stored_settings);  
    new_settings = stored_settings;  
    new_settings.c_lflag &= (~ICANON);  
    new_settings.c_cc[VTIME] = 0;  
    tcgetattr(0,&stored_settings);  
    new_settings.c_cc[VMIN] = 1;  
    tcsetattr(0,TCSANOW,&new_settings);  
  
    in = getchar();  
    tcsetattr(0,TCSANOW,&stored_settings);  
    return in;  
}  


int num_rand(int num,int choice)//生成随机数
{
    
    srand((int)time(0));
    if (choice)//1.随机坐标
        return rand()%num;
    else//0.随机数2或4
    	if (rand()%2 == 0)
    		return 2;
    	else
    		return 4;
}

int num_initialize5(int p[][5],int num)//5.棋盘数字随机生成
{      
	int num_rand(int num,int choice);
	int i,j;
    while(1){
        i = num_rand(num,1);
        j = num_rand(num,1);
       
        if (p[i][j] == 0){
            p[i][j] = num_rand(num,0);
            break;
           }
    }
    return 0;
}
int num_initialize4(int p[][4],int num)//4.棋盘数字随机生成
{      
    int num_rand(int num,int choice);
    int i,j;
    while(1){
        i = num_rand(num,1);
        j = num_rand(num,1);
       
        if (p[i][j] == 0){
            p[i][j] = num_rand(num,0);
            break;
           }
    }
    return 0; 
}


int initialize5(int p[][5],int num)//5.数组初始化
{
	for (int i = 0; i < num; ++i)
		for (int j = 0; j < num ; ++j)
		    p[i][j] = 0;
    return 0;
}


int print_chessboard5(int p[][5],int num,int point)//5.打印棋盘、分数
{
    system("clear");
    printf("****************************************\n");
    printf("*             Q:退出并存档             *\n");
    printf("****************************************\n");
    printf("*               W:上                   *\n");
    printf("*                                      *\n");
    printf("*          A:下  S:下  D:左            *\n");
    printf("****************************************\n");
    printf("当前分数：%d                            \n",point);
    printf("****************************************\n");
    for (int i = 0; i < num; ++i)
        for (int j = 0; j < num; ++j){
            printf("%-6d   ",p[i][j]);
        	if (j == num - 1  && i != num){
        		printf("\n"); 
                printf("\n");
                printf("\n");
            }
        }
    return 0;
}
int initialize4(int p[][4],int num)//4.数组初始化
{
    for (int i = 0; i < num; ++i)
        for (int j = 0; j < num ; ++j)
            p[i][j] = 0;
    return 0;
}


int print_chessboard4(int p[][4],int num,int point)//4.打印棋盘、分数
{
    system("clear");
    printf("****************************************\n");
    printf("*             Q:退出并存档             *\n");
    printf("****************************************\n");
    printf("*               W:上                   *\n");
    printf("*                                      *\n");
    printf("*          A:下  S:下  D:左            *\n");
    printf("****************************************\n");
    printf("当前分数：%d                            \n",point);
    printf("****************************************\n");
    for (int i = 0; i < num; ++i)
        for (int j = 0; j < num; ++j){
            printf("%-6d   ",p[i][j]);
            if (j == num - 1  && i != num){
                printf("\n"); 
                printf("\n");
                printf("\n");
            }
        }
    return 0;
}


int move_num_u5(int p[][5])//上移
{
    for (int i = 0; i < 4;i++)//前移
        for (int j = 0; j < 5; j++)
            if (p[i][j] == 0)
                for (int k = i+1; k < 5; ++k)
                    if (p[k][j] != 0)
                    {
                        p[i][j] = p[k][j];
                        p[k][j] = 0;
                        break;
                    }

    for (int i = 0; i < 4; ++i)//求和
        for (int j = 0; j < 5; ++j)
            if (p[i][j] == p[i+1][j] && p[i][j] != 0 )//加和
            {
                p[i][j] += p[i][j];
                p[i+1][j] = 0;
                point += p[i][j]*2;
            }

    for (int i = 0; i < 4;i++)//前移
        for (int j = 0; j < 5; j++)
            if (p[i][j] == 0)
                for (int k = i+1; k < 5; ++k)
                    if (p[k][j] != 0)
                    {
                        p[i][j] = p[k][j];
                        p[k][j] = 0;
                        break;
                    }
    return 0;
}

int move_num_d5(int p[][5])//下移
{
    for (int i = 4; i > 0;i--)//前移
        for (int j = 0; j < 5; j++)
            if (p[i][j] == 0)
                for (int k = i-1; k > -1; --k)
                    if (p[k][j] != 0)
                    {
                        p[i][j] = p[k][j];
                        p[k][j] = 0;
                        break;
                    }
    for (int i = 4; i >0; i--)//求和
        for (int j = 0; j < 5; j++)
            if (p[i][j] == p[i-1][j] && p[i][j] != 0)//加和
            {
                p[i][j] += p[i][j];
                p[i-1][j] = 0;
                point += p[i][j]*2;
            }

    for (int i = 4; i > 0;i--)//前移
        for (int j = 0; j < 5; j++)
            if (p[i][j] == 0)
                for (int k = i-1; k >-1; --k)
                    if (p[k][j] != 0)
                    {
                        p[i][j] = p[k][j];
                        p[k][j] = 0;
                        break;
                    }
    return 0;
}
int move_num_l5(int p[][5])//左移
{
    for (int j = 0; j < 4;j++)//前移
        for (int i = 0; i < 5; i++)
            if (p[i][j] == 0)
                for (int k = j+1; k < 5; ++k)
                    if (p[i][k] != 0)
                    {
                        p[i][j] = p[i][k];
                        p[i][k] = 0;
                        break;
                    }
    for (int j = 0; j <4; ++j)//求和
        for (int i = 0; i < 5; i++)
            if (p[i][j] == p[i][j+1]&& p[i][j] != 0)
            {
                p[i][j] += p[i][j];
                p[i][j+1] = 0;
                point += p[i][j]*2;
            }
    for (int j = 0; j < 4;j++)//前移
        for (int i = 0; i < 5; i++)
            if (p[i][j] == 0)
                for (int k = j+1; k < 5; ++k)
                    if (p[i][k] != 0)
                    {
                        p[i][j] = p[i][k];
                        p[i][k] = 0;
                        break;
                    }
    return 0;
}
int move_num_r5(int p[][5])//右移
{
    for (int j = 4; j > 0;j--)//前移
        for (int i = 0; i < 5; i++)
            if (p[i][j] == 0)
                for (int k = j-1; k >-1; --k)
                    if (p[i][k] != 0)
                    {
                        p[i][j] = p[i][k];
                        p[i][k] = 0;
                        break;
                    }

    for (int j = 4; j > 0; j--)//求和
        for (int i = 0; i < 5; i++)
            if (p[i][j] == p[i][j-1]&& p[i][j] != 0)//加和
            {
                p[i][j] += p[i][j];
                p[i][j-1] = 0;
                point += p[i][j]*2;

            }

    for (int j = 4; j > 0;j--)//前移
        for (int i = 0; i < 5; i++)
            if (p[i][j] == 0)
                for (int k = j-1; k > -1; --k)
                    if (p[i][k] != 0)
                    {
                        p[i][j] = p[i][k];
                        p[i][k] = 0;
                        break;
                    }

    return 0;
}

int check_move5(int p[][5],int key)
{
    switch(key)
    {
        case 'W':
        case 'w':
            for (int i = 1; i < 5; ++i)
                for (int j = 0; j < 5; ++j)
                    if ((p[i][j] != 0 && p[i-1][j] == 0)||(p[i][j]==p[i-1][j]&&p[i][j] !=0))
                        return 1;
            return 0;
        case 'S':
        case 's':
            for (int i = 3; i >-1; --i)
                for (int j = 0; j < 5; ++j)
                    if ((p[i][j] != 0 && p[i+1][j] == 0)||(p[i][j] == p[i+1][j]&&p[i][j] !=0))
                        return 1;
            return 0;
        case 'D':
        case 'd':    
            for (int i = 3; i >-1; --i)
                for (int j = 0; j < 5; ++j)
                    if ((p[j][i] != 0 && p[j][i+1] == 0)||(p[j][i] == p[j][i+1] && p[i][j] !=0))
                        return 1;
            return 0;
        case 'A':
        case 'a':
            for (int i = 1; i < 5; ++i)
                for (int j = 0; j < 5; ++j)
                    if ((p[j][i] != 0 && p[j][i-1] == 0)||(p[j][i] == p[j][i-1]&&p[i][j] !=0))
                        return 1;
            return 0;
        default:
            return 0;
    }
}


int game_again5(int p[][5],int num)//5.游戏继续进行检测
{
    
    int check_move5(int p[][5],int key);

    if (check_move5(p,'w')||check_move5(p,'a')||check_move5(p,'s')||check_move5(p,'d'))
        return 1;
    return 0;
}

int move_num5(int key,int p[][5])//根据用户操作，移动数块
{
    int move_num_u5(int p[][5]);
    int move_num_d5(int p[][5]);
    int move_num_l5(int p[][5]);
    int move_num_r5(int p[][5]);

    switch(key)
    { 
        case 'W':
        case 'w':
            move_num_u5(p);
            break;
        case 'S':
        case 's':
            move_num_d5(p);
            break;
        case 'D':
        case 'd':    
            move_num_r5(p);
            break;
        case 'A':
        case 'a':
            move_num_l5(p);
            break;
    }
    return 0;
}

int move_num_u4(int p[][4])//上移
{
    for (int i = 0; i < 3;i++)//前移
        for (int j = 0; j < 4; j++)
            if (p[i][j] == 0)
                for (int k = i+1; k < 4; ++k)
                    if (p[k][j] != 0)
                    {
                        p[i][j] = p[k][j];
                        p[k][j] = 0;
                        break;
                    }

    for (int i = 0; i < 3; ++i)//求和
        for (int j = 0; j < 4; ++j)
            if (p[i][j] == p[i+1][j] && p[i][j] != 0 )//加和
            {
                p[i][j] += p[i][j];
                p[i+1][j] = 0;
                point += p[i][j]*3;
            }

    for (int i = 0; i < 3;i++)//前移
        for (int j = 0; j < 4; j++)
            if (p[i][j] == 0)
                for (int k = i+1; k < 4; ++k)
                    if (p[k][j] != 0)
                    {
                        p[i][j] = p[k][j];
                        p[k][j] = 0;
                        break;
                    }
    return 0;
}

int move_num_d4(int p[][4])//下移
{
    for (int i = 3; i > 0;i--)//前移
        for (int j = 0; j < 4; j++)
            if (p[i][j] == 0)
                for (int k = i-1; k > -1; --k)
                    if (p[k][j] != 0)
                    {
                        p[i][j] = p[k][j];
                        p[k][j] = 0;
                        break;
                    }
    for (int i = 3; i >0; i--)//求和
        for (int j = 0; j < 4; j++)
            if (p[i][j] == p[i-1][j] && p[i][j] != 0)//加和
            {
                p[i][j] += p[i][j];
                p[i-1][j] = 0;
                point += p[i][j]*3;
            }

    for (int i = 3; i > 0;i--)//前移
        for (int j = 0; j < 4; j++)
            if (p[i][j] == 0)
                for (int k = i-1; k >-1; --k)
                    if (p[k][j] != 0)
                    {
                        p[i][j] = p[k][j];
                        p[k][j] = 0;
                        break;
                    }
    return 0;
}
int move_num_l4(int p[][4])//左移
{
    for (int j = 0; j < 3;j++)//前移
        for (int i = 0; i < 4; i++)
            if (p[i][j] == 0)
                for (int k = j+1; k < 4; ++k)
                    if (p[i][k] != 0)
                    {
                        p[i][j] = p[i][k];
                        p[i][k] = 0;
                        break;
                    }
    for (int j = 0; j <3; ++j)//求和
        for (int i = 0; i < 4; i++)
            if (p[i][j] == p[i][j+1]&& p[i][j] != 0)
            {
                p[i][j] += p[i][j];
                p[i][j+1] = 0;
                point += p[i][j]*3;
            }
    for (int j = 0; j < 3;j++)//前移
        for (int i = 0; i < 4; i++)
            if (p[i][j] == 0)
                for (int k = j+1; k < 4; ++k)
                    if (p[i][k] != 0)
                    {
                        p[i][j] = p[i][k];
                        p[i][k] = 0;
                        break;
                    }
    return 0;
}
int move_num_r4(int p[][4])//右移
{
    for (int j = 3; j > 0;j--)//前移
        for (int i = 0; i < 4; i++)
            if (p[i][j] == 0)
                for (int k = j-1; k >-1; --k)
                    if (p[i][k] != 0)
                    {
                        p[i][j] = p[i][k];
                        p[i][k] = 0;
                        break;
                    }

    for (int j = 3; j > 0; j--)//求和
        for (int i = 0; i < 4; i++)
            if (p[i][j] == p[i][j-1]&& p[i][j] != 0)//加和
            {
                p[i][j] += p[i][j];
                p[i][j-1] = 0;
                point += p[i][j]*3;
            }

    for (int j = 3; j > 0;j--)//前移
        for (int i = 0; i < 4; i++)
            if (p[i][j] == 0)
                for (int k = j-1; k > -1; --k)
                    if (p[i][k] != 0)
                    {
                        p[i][j] = p[i][k];
                        p[i][k] = 0;
                        break;
                    }

    return 0;
}

int check_move4(int p[][4],int key)
{
    switch(key)
    {
        case 'W':
        case 'w':
            for (int i = 1; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if ((p[i][j] != 0 && p[i-1][j] == 0)||(p[i][j]==p[i-1][j]&&p[i][j] !=0))
                        return 1;
            return 0;
        case 'S':
        case 's':
            for (int i = 2; i >-1; --i)
                for (int j = 0; j < 4; ++j)
                    if ((p[i][j] != 0 && p[i+1][j] == 0)||(p[i][j] == p[i+1][j]&&p[i][j] !=0))
                        return 1;
            return 0;
        case 'D':
        case 'd':    
            for (int i = 2; i >-1; --i)
                for (int j = 0; j < 4; ++j)
                    if ((p[j][i] != 0 && p[j][i+1] == 0)||(p[j][i] == p[j][i+1] && p[i][j] !=0))
                        return 1;
            return 0;
        case 'A':
        case 'a':
            for (int i = 1; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if ((p[j][i] != 0 && p[j][i-1] == 0)||(p[j][i] == p[j][i-1]&&p[i][j] !=0))
                        return 1;
            return 0;
        default:
            return 0;
    }
}

int game_again4(int p[][4],int num)//4.游戏继续进行检测
{
    
    int check_move4(int p[][4],int key);

    if (check_move4(p,'w')||check_move4(p,'a')||check_move4(p,'s')||check_move4(p,'d'))
        return 1;
    return 0;
}


int move_num4(int key,int p[][4])//根据用户操作，移动数块
{
    int move_num_u4(int p[][4]);
    int move_num_d4(int p[][4]);
    int move_num_l4(int p[][4]);
    int move_num_r4(int p[][4]);

    switch(key)
    { 
        case 'W':
        case 'w':
            move_num_u4(p);
            break;
        case 'S':
        case 's':
            move_num_d4(p);
            break;
        case 'D':
        case 'd':    
            move_num_r4(p);
            break;
        case 'A':
        case 'a':
            move_num_l4(p);
            break;
    }
    return 0;
}



int begame(int uc)//游戏模块
{
	int num_initialize5(int p[][5],int num);
	int initialize5(int p[][5],int num);
	int num_rand(int num,int choice);
	int print_chessboard5(int p[][5],int num,int point);
    int num_initialize4(int p[][4],int num);
    int initialize4(int p[][4],int num);
    int print_chessboard4(int p[][4],int num,int point);
    int scanKeyboard(void);
    int check_move5(int p[][5],int key);
    int check_move4(int p[][4],int key);
    int move_num5(int key,int p[][5]);
    int move_num4(int key,int p[][4]);

    int key;

    if (uc == 0)//继续游戏，从文件载入数据
    	;
	
    //5*5
	else if (uc == 5){
	    int chessboard[5][5];//新游戏
	    initialize5(chessboard,5);//初始化数组

	    while(1)
        {
            num_initialize5(chessboard,uc);
            print_chessboard5(chessboard,uc,point);
            if (!game_again5(chessboard,uc))
            {
                printf("游戏结束！！\n");
                return 0;//游戏结束
            
            }
            while(1){
                key = scanKeyboard();
                if (check_move5(chessboard,key))//判断键盘
                {
                    if (key == 'Q'||key == 'q')//退出存档
                        return 0;
                    move_num5(key,chessboard);
                    break;
                }
            }
        }
	}



	//4*4
	else{
        int chessboard[4][4];//新游戏
        initialize4(chessboard,4);//初始化数组

        while(1)
        {
            num_initialize4(chessboard,uc);
            print_chessboard4(chessboard,uc,point);
            if (!game_again4(chessboard,uc))
            {
                printf("游戏结束！！\n");
                return 0;//游戏结束
            }
            while(1){
                key = scanKeyboard();
                if (check_move4(chessboard,key))//判断键盘
                {
                    if (key == 'Q'||key == 'q')//退出存档
                        return 0;
                    move_num4(key,chessboard);
                    break;
                }
            }

            }
        }
    return 0;
}