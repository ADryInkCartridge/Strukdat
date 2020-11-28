#include <stdlib.h>
#include <stdbool.h4vff]gm l
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct snode_t {
    int data;
    int max;
    int min;
    struct snode_t *next;
} SListNode;

/* Struktur ADT SinglyList */

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

/* DAFTAR FUNGSI YANG TERSEDIA */

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, int value);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, int index, int value);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, int value);
int  slist_front(SinglyList *list);
int  slist_back(SinglyList *list);
int  slist_getAt(SinglyList *list, int index);

/* Function definition below */

void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value) 
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        if (slist_isEmpty(list))
        {
        	newNode->next = NULL;
        	newNode->max  = newNode->data;
        	newNode->min  = newNode->data;
		}
        else 
        {
        	newNode->next = list->_head;
        	newNode->max = list->_head->max;
        	newNode->min = list->_head->min;
        	if (newNode->max<value)
        	{
        		newNode->max = value;
			}
			if (newNode->min>value)
			{
				newNode->min = value;
			}
		}
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list)
{
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
        printf("Berhasil Menghapus\n");
    }
    else 
    {
    	printf("Coba lagi gan\n");
	}
}


void skoymax (SinglyList *list)
{
	if (slist_isEmpty(list))
	{
		printf("Coba lagi gan\n");
		return;
	}
	else 
	{
		printf("%d\n",list->_head->max);
	}
}

void skoymin (SinglyList *list)
{
	if (slist_isEmpty(list))
	{
		printf("Coba lagi gan\n");
		return;
	}
	else 
	{
		printf("%d\n",list->_head->min);
	}
}

int main(int argc, char const *argv[])
{
    SinglyList list;
    slist_init(&list);
    while (1)
    {
    	char in[20];
    	scanf("%s",&in);
    	//printf("%s",in);
    	if (strcmp(in,"Add")==0)
    	{
    	//	printf("add\n");
    		int add;
    		scanf("%d",&add);
    		slist_pushFront(&list,add);
    	//	printf("%d\n",add);
		}
		else if (strcmp(in,"Max")==0)
		{
		//	printf("max\n");
			skoymax(&list);
		}
		else if (strcmp(in,"Min")==0)
		{
		//	printf("min\n");
			skoymin(&list);
		}
		else if (strcmp(in,"Del")==0)
		{
		//	printf("del\n");
			slist_popFront(&list);
		}
		else if (strcmp(in,"Stop")==0)
		{
		//	printf("stop\n");
			printf("Terminated\n");
			return 0;
		}
		else 
		{
			printf("Coba lagi gan\n");
		}
	}
    return 0;
}
