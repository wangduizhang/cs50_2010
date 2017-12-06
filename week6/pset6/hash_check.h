
typedef struct//字典索引
{
	struct dictionary *listp;

} index_list;

typedef struct dictionary//字典结构
{
    char *word;
    struct dictionary *next;
} dictionary;