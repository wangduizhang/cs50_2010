#include <stdio.h>
#include <string.h>

#define FILEPATHs "/Users/wp/Desktop/studentinformation.txt"
#define FILEPATHa "/Users/wp/Desktop/address.txt"
#define NUMBEROFSTUDENT 13266
#define LENSTRING 50
#define MAXLEN 150
#define PRINTFLINE 0


struct student
{
	char studyid[LENSTRING];
	char name[LENSTRING];
	char xi[LENSTRING];
	char zhuanye[LENSTRING];
	char idcard[LENSTRING];
	char moneyid[LENSTRING];
};

struct addressid
{
    char id[10];
    char address[LENSTRING];

} studentaddress[3467];


int main()
{

    FILE *text1;
    FILE *text2;
    
    int number = 0;
    char selfname[51];
    
    struct student students[NUMBEROFSTUDENT]; 

    if ((text1 = fopen(FILEPATHs,"r")) == NULL)
    	printf(" 打开文件失败\n");
    if ((text2 = fopen(FILEPATHa,"r")) == NULL)
    	printf(" 打开文件失败\n");
    //获取学生信息
    for (int i = 1; i <= NUMBEROFSTUDENT; ++i)
    {
        fscanf(text1,"%s",students[i].studyid);
        fscanf(text1,"%s",students[i].name);
        fscanf(text1,"%s",students[i].xi);
        fscanf(text1,"%s",students[i].zhuanye);
        fscanf(text1,"%s",students[i].idcard);
        fscanf(text1,"%s",students[i].moneyid);
    }

    //获取地址匹配信息
    for (int i = 1; i <= 3465; ++i)
    {
        fscanf(text2,"%s",studentaddress[i].id);
        fscanf(text2,"%s",studentaddress[i].address);
    }
    
    printf(">>>");
    
    scanf("%50s",selfname);
    
    
    for (int i = 1; i <= NUMBEROFSTUDENT; ++i){                                                                                                                                       
        if (strcmp(students[i].name, selfname) == 0){
            number++;
            printf("= = = = = = = = = = = = = = = = = = =\n");
            printf("姓名：%s     ", students[i].name );
            printf("学号：%s\n", students[i].studyid );
            printf("系：%s       ", students[i].xi );
            printf("专业：%s\n", students[i].zhuanye );
            for (int j = 1; j <=3465 ; ++j)
                if (strncmp(students[i].idcard,studentaddress[j].id,6)==0)
                    printf("家庭住址：%s\n", studentaddress[j].address);

        }
    }
    if (number == 0)
       printf("没有这个人\n"); 




    #if PRINTFLINE
    for (int i = 1; i <= 1; ++i)
    {
        printf("%s\n",students[i].studyid);
        printf("%s\n",students[i].name);
        printf("%s\n",students[i].xi);
        printf("%s\n",students[i].zhuanye);
        printf("%s\n",students[i].idcard);
        printf("%s\n",students[i].moneyid);
    }
    #endif

    #if PRINTFLINE
    for (int i = 3465; i <= 3465; ++i)
    {
        printf("%s\n",studentaddress[i].id);
        printf("%s\n",studentaddress[i].address);
    }
    #endif


	return 0;
}