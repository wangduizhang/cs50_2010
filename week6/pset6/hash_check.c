/*拼写检查程序；单词数据以散列方式存储*/
#include "hash_check.h"
#include <stdio.h>
#include <stdlib.h>

#define LEN_STRING 50
//字典索引
index_list len_two[27];
index_list len_three[81];
index_list len_six[162];

//初始化数组
void init_list(void)
{
	for (int i = 0; i < 27; ++i)
		len_two[i].listp = NULL;
	for (int i = 0; i < 81; ++i)
		len_three[i].listp = NULL;	
	for (int i = 0; i < 162; ++i)
		len_six[i].listp = NULL;
}

void init_dic(dictionary *p,int n)
{
	for (int i = 0; i < n; ++i)
		p  -> next= NULL;
	    p++;
}

//获取单词数目
int number_words(FILE *f)
{
	int cc = 0;
	int index = 0;

    while(!feof(f)){
    	cc = fgetc(f);
    	if (cc == '\n')
    	    index++;
    }
    fseek(f,0,SEEK_SET);
    return index+1;
}

int hash(char *p,int n)
{
	int h = 0;
	switch(n)
	{
		case 1:
		for (int i = 0; i < 1; ++i)
			if (p[i] != '\'')
                h += p[i] - 'a';
            else
                h += 27;
		break;
		case 2:
        for (int i = 0; i < 3; ++i)
            if (p[i] != '\'')
                h += p[i] - 'a';
            else
                h += 27;
		break;
		case 3:
        for (int i = 0; i < 6; ++i)
            if (p[i] != '\'')
                h += p[i] - 'a';
            else
                h += 27;
		break;
	}
	return (int)h;
}

int  len_of_string(char *str)
{
	int index = 0;

	for (int i = 0; i < LEN_STRING; ++i)
	{
		if (str[i] == '\n'||str[i] == '\0')
			return index;
		index++;
	}
	return 0;
}

//操作字典
void copy_str(char *from,char *to,int n)
{
    for (int i = 0; i < n; ++i)
    	to[i] = from[i];
}
//操作文章
void copy_str2(char *from,char *to,int n)
{
    for (int i = 0; i < n; ++i){
        if (from[i] > 64 && from[i] < 91)
            to[i] = from[i] + 32;
        else if (from[i] == '\'' || (from[i] > 96 && from[i] < 123))
            to[i] = from[i];
    }
}


void logo_dic(FILE *f,dictionary *p,int n)
{
    
    char str[LEN_STRING];
    int len_string;
    char *w;
    int h;

    for (int i = 0; i < n; ++i)
    {
    	dictionary *ip;
        fgets(str,LEN_STRING,f);
    	len_string = len_of_string(str);
    	w = (char *)malloc(len_string);
        copy_str(str,w,len_string);
        
        if (len_string <= 2){
        	h = hash(w,1);
        	p -> word = w;
            if (len_two[h].listp == NULL)
                len_two[h].listp = p;
            else{
                ip = len_two[h].listp;
                while(ip -> next != NULL)
                    ip = ip->next;
                ip -> next = p;
            }
        }
        else if (len_string < 6){
        	h = hash(w,2);
        	p -> word = w;
            if (len_three[h].listp == NULL)
                len_three[h].listp = p;
            else{
                ip = len_three[h].listp;
                while(ip -> next != NULL)
                    ip = ip->next;
                ip -> next = p;
            }
        }
        else{
        	h = hash(w,3);
        	p -> word = w;
            if (len_six[h].listp == NULL)
                len_six[h].listp = p;
            else{
                ip = len_six[h].listp;
                while(ip -> next != NULL)
                    ip = ip->next;
                ip -> next = p;
            }
        }
    	p++;
    }

}

int tsh(int pp)
{
    switch(pp)
    {
        case '\n':
        case '-':
        case '*':
        case '&':
        case '#':
        case '@':
        case '!':
        case ':':
        case ',':
        case ';':
        case '[':
        case ']':
        case '(':
        case ')':
        case '<':
        case '>':
        case '?':
        case '.':
        case '+':
        case '\\':
        case '/':
        case '%':
        case '^':
        case '~':
        return 0;
    }
    if (pp >='0' && pp <= '9')
        return 0;
    else
        return 1;
}


int get_text(FILE *f,char *p)
{
    int pp;
    int index = 0;

    while((pp = fgetc(f)) != ' ' && tsh(pp)){
        p[index] = pp;
        index ++;
        if(pp == EOF)
            return 0;
        if (index == 47)
            break;
    }
    if ( pp == '\n'){
        p[index] = '\n';
        p[index +1] = '\0';
    }
    else
        p[index] = '\0';
    return 1;
}

int bj(char *c1,char *c2,int n)
{
    if (c1[0] == '\n' || c1[0] == ' '|| c1[0] == '\0')
        return 1;
    for (int i = 0; i < n; ++i){
        if (c1[i] == '\'' && c1[i+1] == 's')
            return 1;
        else if (c1[i] != c2[i])
            return 0;
    }
    return 1;
}

int check_word(int l,int h,dictionary *p,char *c_c)
{
    
    if (p == NULL)
        return 1;
    else
    {
        int result = bj(c_c,p -> word,l);
        if (! result && p -> next == NULL)
            return 1;
        else if (result)
            return 0;
        else
            return check_word(l,h,p -> next,c_c);
        }
}

int main(int argc, char const *argv[])
{
	FILE *f = NULL;
    FILE *checkfile = NULL;
    dictionary *p = NULL;
    char w[LEN_STRING] = "BEGAN";
    int line = 1;

    if (argc == 1)
    {
        printf("NO FILE NAME!!!\n");
        exit(1);
    }
    init_list();//初始化索引

	f = fopen("large.txt","r");
	if (!f)
		exit(1);
    //全部单词,分配空间
    int n =  number_words(f);//单词数

    p = (dictionary *)malloc(sizeof(dictionary) *n);
    if (p == NULL)
    	exit(1);

    init_dic(p,n);//初始化字典
    logo_dic(f,p,n);//加载字典
    fclose(f);


    for (int i = 1; i < argc; ++i)
    {
    
    checkfile = fopen(argv[i],"r");
    if (checkfile == NULL){
        printf("NO \"%s\" FILE!!!\n",argv[i]);
        continue;
    }
    printf("%s:\n",argv[i]);
    while(get_text(checkfile,w))
    {
        int l = len_of_string(w);
        char *c_c = (char *)malloc(l);
        int result = 0;

        copy_str2(w,c_c,l);

        if (l <3 && l > 0)
            result = check_word(l,hash(c_c,1),len_two[hash(c_c,1)].listp,c_c);
        else if (l < 6  && l >= 3)
            result = check_word(l,hash(c_c,2),len_three[hash(c_c,2)].listp,c_c);
        if (l >= 6)
            result = check_word(l,hash(c_c,3),len_six[hash(c_c,3)].listp,c_c);
        if (result)
            printf("NO.%d line: %s\n",line,w);
        if (w[0] == '\n')
            line++;
        else if (w[l] == '\n')
            line++;
    }
    fclose(checkfile);
    }
	return 0;
}