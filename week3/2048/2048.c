#include <stdio.h>
#include "menu.h"
#include "game.h"

extern int begen(void);
extern int game_modle(void);
extern int begame(int uc);



int main(void)
{
    int choice;
    int modle;
    choice = begen();//游戏开始
    
    switch(choice)
    {
    	case 1://新游戏
    	    modle = game_modle();
    	    if(!begame(modle)){
                return 0;
            }
    	    break;
    	case 2://继续游戏
    	    begame(0);
    	    break;
    	case 3://退出游戏
    	    return 0;
    }

	return 0;
}