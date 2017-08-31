#include <ncurses.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
	int ch;
    initscr();
    char jjj[4][4] = {"上","下","左","右"};
    setlocale(LC_ALL,"");
	raw();
	keypad(stdscr,TRUE);
    noecho();
    for (int i = 0; i < 4; ++i)
    {
        ch = getch();
        printw("%s:%d",jjj[i],ch);
    }

	refresh();
	getch();
	endwin();
	return 0;
}