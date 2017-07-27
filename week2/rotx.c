#include <stdio.h>

#define CLEAN_STDIN fgets(clean,99,stdin)
static char clean[100];
static int long_test = 0;
static int long_str = 0;

//加密算法
int enrot(char *p,int n)
{   
     
    if (n > 26)
    	n = n % 26;
	for (int i = 0; i <= long_str; ++i)
		if ('a'<=p[i] && p[i]<= 'z')
			p[i] = (p[i] + n > 'z' || p[i] + n < 'a')?  p[i] - 'z' + 'a'  +n - 1: p[i] + n;
		else if ('A'<=p[i] && p[i]<='Z')
			p[i] = (p[i] + n > 'Z' || p[i] + n < 'A')? p[i] - 'Z' - 1 + 'A' + n : p[i] + n;
	printf("====================================\n");
    printf("                 密文\n");
    printf("====================================\n");
	for (int i = 0; i <= long_str; ++i)
        putchar(p[i]);
    return 0;
}

//解密
int unrot(char *p,int n)
{
    
    if (n > 26)
    	n = n % 26;
    printf("%d\n",n);
    for (int i = 0; i <= long_str; ++i)
        if ('a'<=p[i] && p[i]<= 'z')
            p[i] = (p[i] + n > 'z' || p[i] + n < 'a')? 'a'  - p[i] + 'z' -1: p[i] + n;
        else if ('A'<=p[i] && p[i]<='Z')
            p[i] = (p[i] + n > 'Z' || p[i] + n < 'A')? 'A' - p[i] + 'Z' - 1: p[i] + n;


    printf("====================================\n");
    printf("                 明文\n");
    printf("====================================\n");
	for (int i = 0; i <= long_str; ++i)
        putchar(p[i]);
    return 0;
}

int cf(int n)
{
	int num = 1;
	if (n == 0)
		return num;
	for (int i = 1; i <= n; ++i)
	    num *=10;
	return num;
}

//获取密钥
int getkey(void)
{
    int key = 0;

    while(1){
        printf("输入你的密钥：");
        if(!scanf("%d",&key))
           CLEAN_STDIN;
        else
             break;
     }
    return key;
}


int size_p(char const *p)
{
	int size = 0;
	int index = 0;

	while(1)
		if (p[index++] != 0)
			size++;
		else
	        return size;
	return 0;
}


//处理命令行密钥
int del_key(char const **p)
{   
	int cf(int n);
	int getkey(void);
    int key = 0;
    int n = 0;
    for(int i = size_p(p[1]); i >= 0;i--){
    	if ( 48< p[1][i] && p[1][i]<59)
    		key += (p[1][i] - 48) * cf(n++);
    }
    if (key == 0)
        return getkey();
    return key;
}

//获取明文或密文
int gettest(char *ciphertext)
{
    int word = 1;

    

    if (stdin != NULL)
        CLEAN_STDIN;
    while(long_str < 10000)
    {   
        word = getchar();
        *ciphertext = word;

        if (word == '\n' && *(ciphertext-1) == '\n')
            break;
        if (('a'<=word && word<= 'z')||('A'<=word && word<='Z'))
            long_test++;
        ciphertext++;
        long_str++;
    }

    if (long_test == 0)
    {
    	printf("没有需要加密的文本！！\n");
    	return 1;
    }
    return 0;
}

int choice_user(void)
{
	
    int choice = 0;

	printf("====================================\n");
    printf("          《恺撒加解密》\n");
    printf("====================================\n");
    printf("           1.加密 2.解密\n");
    printf("====================================\n");
    printf(">>>你的选择:");
    while(1)
    {   
        scanf("%d",&choice);
        if(choice == 1 || choice == 2)
        	break;
        CLEAN_STDIN;
        printf(">>>你的选择:");
	}
	
	return choice;
}
 
int main(int argc, char const *argv[])
{

    int gettest(char *ciphertext);
    int getkey(void);
    int del_key(char const **p);
    int enrot(char *p,int n);
    int unrot(char *p,int n);
    int choice_user(void);

    char text[10000];
    int choice = 0;
    int key;

    choice = choice_user();

	switch(choice)
	{
		//加密
		case 1:
		    printf("输入你要加密的文字：\n");
		    while(gettest(text))
		    	;
		    if(argc != 1)
			    key = del_key(argv);
		    else
		    	key = getkey();
            enrot(text,key);
		    break;

        //解密
		case 2:
		    printf("输入你要解密的文字：\n");
		    while(gettest(text))
		    	;
		    if(argc != 1)
			    key = del_key(argv);
		    else
		    	key = getkey();
            unrot(text,key);
		    break;
    }
	return 0;
}


