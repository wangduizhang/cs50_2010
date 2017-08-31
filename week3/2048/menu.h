#include <stdio.h>

#define CLEAN fgets(clean_,99,stdin)
static char clean_[100];


//进入程序时
int choice1(void)
{
    
    int user_choice = 0;
    
    printf("你的选择：");
    while(!scanf("%d",&user_choice) || user_choice > 3 || user_choice < 1 )
    {
        CLEAN;
        printf("请重新输入：");
    }
    return user_choice;
}

//选择游戏模式
int choice2(void)
{
    int user_choice = 0;
    
    printf("你的选择：");
    while(!scanf("%d",&user_choice) || user_choice > 5 || user_choice < 4  )
    {
        CLEAN;
        printf("请重新输入：");
    }
    return user_choice;
}


int game_modle(void)
{

    int choice2(void);

    printf("请选择你要进行的游戏模式\n 4:4x4  5:5x5\n");
    return choice2();
}


int begen(void)
{
    int choice1(void);
    int game_modle(void);

    int uc;

    printf("1.开始新游戏 2.继续游戏 3.结束游戏\n");
    uc = choice1();
    if (uc == 1){
        return 1;
    }
    else if (uc == 2){
        return 2;
    }
    else{
        printf("游戏以退出！\n");
        return 3;
    }
}
