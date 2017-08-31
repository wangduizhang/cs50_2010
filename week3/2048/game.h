#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <ncurses.h>



static int point;


int scanKeyboard(void)//监听键盘 
{  
    int key;
    initscr();
    raw();
    keypad(stdscr,TRUE);
    noecho();
    key = getch();
    return key;
    endwin();
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
    printf("*              方向键控制              *\n");
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
    printf("*              方向键控制              *\n");
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
        case 259:
            for (int i = 1; i < 5; ++i)
                for (int j = 0; j < 5; ++j)
                    if ((p[i][j] != 0 && p[i-1][j] == 0)||(p[i][j]==p[i-1][j]&&p[i][j] !=0))
                        return 1;
            return 0;
        case 258:
            for (int i = 3; i >-1; --i)
                for (int j = 0; j < 5; ++j)
                    if ((p[i][j] != 0 && p[i+1][j] == 0)||(p[i][j] == p[i+1][j]&&p[i][j] !=0))
                        return 1;
            return 0;
        case 261:   
            for (int i = 3; i >-1; --i)
                for (int j = 0; j < 5; ++j)
                    if ((p[j][i] != 0 && p[j][i+1] == 0)||(p[j][i] == p[j][i+1] && p[i][j] !=0))
                        return 1;
            return 0;
        case 260:
            for (int i = 1; i < 5; ++i)
                for (int j = 0; j < 5; ++j)
                    if ((p[j][i] != 0 && p[j][i-1] == 0)||(p[j][i] == p[j][i-1]&&p[i][j] !=0))
                        return 1;
            return 0;
            case 'q':
            case 'Q':
                return 1;
        default:
            return 0;
    }
}


int game_again5(int p[][5],int num)//5.游戏继续进行检测
{
    
    int check_move5(int p[][5],int key);

    if (check_move5(p,259)||check_move5(p,260)||check_move5(p,258)||check_move5(p,261))
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
        case 259:
            move_num_u5(p);
            break;
        case 258:
            move_num_d5(p);
            break;
        case 261: 
            move_num_r5(p);
            break;
        case 260:
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
        case 259:
            for (int i = 1; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if ((p[i][j] != 0 && p[i-1][j] == 0)||(p[i][j]==p[i-1][j]&&p[i][j] !=0))
                        return 1;
            return 0;
        case 258:
            for (int i = 2; i >-1; --i)
                for (int j = 0; j < 4; ++j)
                    if ((p[i][j] != 0 && p[i+1][j] == 0)||(p[i][j] == p[i+1][j]&&p[i][j] !=0))
                        return 1;
            return 0;
        case 261:    
            for (int i = 2; i >-1; --i)
                for (int j = 0; j < 4; ++j)
                    if ((p[j][i] != 0 && p[j][i+1] == 0)||(p[j][i] == p[j][i+1] && p[i][j] !=0))
                        return 1;
            return 0;
        case 260:
            for (int i = 1; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if ((p[j][i] != 0 && p[j][i-1] == 0)||(p[j][i] == p[j][i-1]&&p[i][j] !=0))
                        return 1;
            return 0;
        case 'Q':
        case 'q':
            return 1;

        default:
            return 0;
    }
}

int game_again4(int p[][4],int num)//4.游戏继续进行检测
{
    
    int check_move4(int p[][4],int key);

    if (check_move4(p,259)||check_move4(p,260)||check_move4(p,258)||check_move4(p,261))
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
        case 259:
            move_num_u4(p);
            break;
        case 258:
            move_num_d4(p);
            break;
        case 261: 
            move_num_r4(p);
            break;
        case 260:
            move_num_l4(p);
            break;
    }
    return 0;
}


int save_game4(FILE *f,int p[][4])
{  
    char ch;

    while(point)
    {
        ch = (char)(point % 10 + 48);
        fputc(ch,f);
        point /= 10;
    }
    fputc('\n',f);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j< 4; ++j){
            if (p[i][j] == 0)
                fputc('0',f);
            while(p[i][j])
            {
                ch = (char)(p[i][j] % 10 + 48);
                fputc(ch,f);
                p[i][j] /= 10;
            }
            fputc('\n',f);
        }
    

    return 0;
}



int save_game5(FILE *f,int p[][5])
{
    char ch;

    while(point)
    {
        ch = (char)(point % 10 + 48);
        fputc(ch,f);
        point /= 10;
    }
    fputc('\n',f);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j< 5; ++j){
            if (p[i][j] == 0)
                fputc('0',f);
            while(p[i][j])
            {
                ch = (char)(p[i][j] % 10 + 48);
                fputc(ch,f);
                p[i][j] /= 10;
            }
            fputc('\n',f);
        }
    return 0;
}

int cifang(int x)
{
   int n = 1;
   
   if (x == 0)
       return n;

   for (int i = 0; i < x; ++i)
       n *= 10;
   return n;
}

int open_save_number(FILE *f)
{
    int cifang(int n);

    char str[10];
    char word;
    int index = 0;
    int p = 0;

    while(1){
        word = fgetc(f);
        if (word == '\n')
            break;
        str[index] = word;
        index++;

    }

    for (int i = 0; i < index; ++i)
        p += (int)(str[i] - 48) * cifang(i);
    return p;
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
    int save_game4(FILE *f,int p[][4]);
    int save_game5(FILE *f,int p[][5]);
    int open_save_number(FILE *f);


    int key;

    if (uc == 0)//继续游戏，从文件载入数据
    {   
        FILE *text;
        text = fopen("save.txt","r");
        
        int chessboard[4][4];

        uc = open_save_number(text);
        point = open_save_number(text);
        switch(uc)
        {
            case 4:
                for (int i = 0; i < 4; ++i)
                    for (int j = 0; j < 4; ++j)
                        chessboard[i][j] = open_save_number(text);
            while(1)
            {
            print_chessboard4(chessboard,uc,point);
            if (!game_again4(chessboard,uc))
            {
                printf("游戏结束！！\n");
                return 0;//游戏结束
            }
            while(1){
                key = scanKeyboard();
                if (check_move4(chessboard,key))//判断键盘
                {if (key == 'Q'||key == 'q')//退出存档
                    {
                        FILE *text;
                        text = fopen("save.txt","w");
                        fputs("4\n",text);
                        save_game4(text,chessboard);
                        fclose(text);
                        printf("游戏以存档\n");

                        return 0;}
                    move_num4(key,chessboard);
                    break;
                }
                    }
            num_initialize4(chessboard,uc);        
            }
                break;
            


            case 5:
                for (int i = 0; i < 5; ++i)
                    for (int j = 0; j < 5; ++j)
                        chessboard[i][j] = open_save_number(text);
            while(1)
            {
            print_chessboard4(chessboard,uc,point);
            if (!game_again4(chessboard,uc))
            {
                printf("游戏结束！！\n");

                return 0;//游戏结束
            }
            while(1){
                key = scanKeyboard();
                if (check_move4(chessboard,key))//判断键盘
                {if (key == 'Q'||key == 'q')//退出存档
                    {
                        FILE *text;
                        text = fopen("save.txt","w");
                        fputs("5\n",text);
                        save_game4(text,chessboard);
                        fclose(text);
                        printf("游戏以存档\n");

                        return 0;
                    }
                    move_num4(key,chessboard);
                    break;
                }
                    }
            num_initialize4(chessboard,uc);        
            }
                break;
            default:
                return 0;
        }
        fclose(text);
        return 0;
	}
    



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
                    {
                    FILE *text;
                    text = fopen("save.txt","w");
                    fputs("5\n",text);
                    save_game5(text,chessboard);
                    fclose(text);
                    printf("游戏已存档\n");

                    return 0;
                    }
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
                    {
                        FILE *text;
                        text = fopen("save.txt","w");
                        fputs("4\n",text);
                        save_game4(text,chessboard);
                        fclose(text);
                        printf("游戏以存档\n");
                        return 0;
                    }
                    move_num4(key,chessboard);
                    break;
                }
            }

            }
        }
    return 0;
}