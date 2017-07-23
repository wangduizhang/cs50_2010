#include <stdio.h>
#include <ctype.h>

#define TEST 0
#define CLEAN_STDIN fgets(chch,99,stdin);
static int long_test = 0;//要转换的字符数
static int long_str = 0;
static int long_key = 0;



//加密
int encrypt(char *ciphertext,char *key)
{
	int n = 0;
	int index = 0;
    
    while(n < long_test){
   	    char word = *ciphertext;
   	    n++;
        if (index == long_key){
             index = 0;
             key = key - long_key;
         }
        if ('A'<=word && word<='Z'){
        	
        	if ((*ciphertext + *key - 65)>'Z')
        		*ciphertext = *ciphertext + *key - 65 - 26;
        	else
        		*ciphertext = *ciphertext + *key - 65;
        	key++;
        	index++;
        }
        ciphertext++; 	
   }

    return 0;
}  

//解密
int uncrypt(char *ciphertext,char *key)
{
    int n = 0;
	int index = 0;
    
    while(n < long_test){
   	    char word = *ciphertext;
   	    n++;
        if (index == long_key){
             index = 0;
             key = key - long_key;
         }
        if ('A'<=word && word<='Z'){
        	
        	if ((*ciphertext + 65 - *key) < 'A')
        		*ciphertext = *ciphertext - *key + 65 + 26;
        	
        	else
        		*ciphertext = *ciphertext - *key + 65;
        	key++;
        	index++;
        }
        ciphertext++; 
    }	
	return 0;
}


//密钥 明文转大写
int upstr(char *ciphertext,char *key)
{
    for (int i = 0; i < 10000 && *ciphertext != EOF; ++i)
    {
     	if ('a' <= *ciphertext && *ciphertext <= 'z')
     		*ciphertext = toupper(*ciphertext);
        ciphertext++;
    }


    for (int i = 0; i < 100; ++i)
    { 
     	if ('a' <= *key && *key  < 'z')
     		*key = toupper(*key);
     	key++;
    
    }

    return 0;
}



//获取明文或密文
int gettest(char *ciphertext)
{
    int word = 1;

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
   return 0;
}


//获取密钥
int getkey(char *key)
{
	int word;
	int l = 0;

    while(l < 100)
    {
        word = getchar();
        if (word == '\n')
            break;
        else if (('a'<=word && word<= 'z')||('A'<=word && word<='Z')){
            long_key++;
            *key = word;
            key++;
            l++;
        }
    }
   return 0;
}





//入口
int main(void)
{
	int uncrypt(char *ciphertext,char *key);
    int encrypt(char *ciphertext,char *key);
	int upstr(char *ciphertext,char *key);
	int gettest(char *ciphertext);
	int getkey(char *key);



    int choice;
    char chch[100];
    char key[100];
    char ciphertext[10000];

    printf("====================================\n");
    printf("          《Vigenere加解密》\n");
    printf("====================================\n");
    printf("           1.加密 2.解密\n");
    printf("====================================\n");
    printf(">>>你的选择:");
	while(!scanf("%d",&choice) && (choice != 1 || choice != 2))
	{
        CLEAN_STDIN;
        printf(">>>你的选择:");
	}

    switch(choice){
        case 1:
            printf(">>>输入你要加密的文本:\n");
            //清空缓冲区
            CLEAN_STDIN;
            gettest(ciphertext);
            CLEAN_STDIN;
            printf(">>>输入你的密钥：\n");
            getkey(key);
            upstr(ciphertext,key);
    
    //测试
    #if TEST
    printf("====================================\n");
    printf("               明文\n");
    printf("====================================\n");
    printf("%s\n",ciphertext);
    printf("需要转换的字符：%d\n",long_test);
    printf("====================================\n");
    printf("               密钥\n");
    printf("====================================\n");
    printf("%s\n",key);
    printf("====================================\n");
    #endif
            //加密
            encrypt(ciphertext,key);
            printf("====================================\n");
            printf("                 密文\n");
            printf("====================================\n");
            for (int i = 0; i <= long_test; ++i)
                putchar(ciphertext[i]);
            printf("\n");

    #if TEST
    printf("               密文\n");
    printf("====================================\n");
    printf("%s\n",ciphertext);
    printf("====================================\n");
    #endif
            break;
        

        //解密
        case 2:
            printf(">>>输入你要解密的文本:\n");
            //清空缓冲区
            CLEAN_STDIN;
            gettest(ciphertext);
            CLEAN_STDIN;
            printf(">>>输入你的密钥：\n");
            getkey(key);
            upstr(ciphertext,key);
            uncrypt(ciphertext,key);
            printf("====================================\n");
            printf("                 明文\n");
            printf("====================================\n");
            for (int i = 0; i <= long_test; ++i)
                putchar(ciphertext[i]);
            printf("\n");
            break;
    }

    return 0;
}