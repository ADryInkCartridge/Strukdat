#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/* Struktur Node */

typedef struct dnode_t {
    int data;
    char nama[26];
    struct dnode_t      \
        *next,
        *prev;
} DListNode;

/* Struktur ADT List */

typedef struct dlist_t {
    DListNode           \
        *_head,
        *_tail;
    unsigned _size;
} List;


DListNode* __dlist_createNode(char nama_in[])
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));

    if (!newNode) return NULL;
    newNode->data = 1;
    strcpy(newNode->nama,nama_in);
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void dlist_init(List *list)
{
    list->_head = list->_tail = NULL;
    list->_size = (unsigned) 0;
}

bool dlist_isEmpty(List *list) {
    return (list->_head == NULL && 
            list->_tail == NULL);
}

void dlist_pushBack(List *list, char nama_in[])
{
    DListNode *newNode = __dlist_createNode(nama_in);
    if (newNode) {
        list->_size++;
        if (dlist_isEmpty(list)) {
            list->_head = newNode;
            list->_tail = newNode;
            return;
        }

        list->_tail->next = newNode;
        newNode->prev = list->_tail;
        list->_tail = newNode;
    }
}

void dlist_popFront(List *list)
{
    if (!dlist_isEmpty(list)) {
        DListNode *temp = list->_head;
        if (list->_head == list->_tail) {
            list->_head = NULL;
            list->_tail = NULL;
            free(temp);
        }
        else {
            list->_head = list->_head->next;
            list->_head->prev = NULL;
            free(temp);
        }
        list->_size--;
    }
}

void showall (List *list)
{
	DListNode *temp = list->_head;
	while (temp->next!=NULL)
	{
		printf("%s ",temp->nama);
		temp=temp->next;
	}
	printf("%s\n",temp->nama);
}

void do_the_thing (List *list,int n)
{
    int k;
    if (!dlist_isEmpty(list))
    {
      DListNode *temp = list->_head;
      DListNode *prev = list->_tail;
      for (int wow=0;wow<n-1;wow++)
      {
        scanf("%d",&k);
        for (int i=0;i<k;i++)
        {
            if (temp->next==NULL)
			{
				temp = list->_head;
			}
			else
			{
				temp=temp->next;
			}
            if (prev->next==NULL)
  			{
  				prev = list->_head;
  			}
  			else
  			{
  				prev=prev->next;
  			}
  	//		printf("NOW = %s  PREV = %s Status = %d\n",temp->nama,prev->nama,temp->data);
       	}
       	if (temp->next==NULL)
       	{
       		prev->next = NULL;
       		temp->prev = NULL;
       		list ->_tail = prev;
		}
		else if (temp->prev==NULL)
		{
			temp->next->prev=NULL;
			list->_head=temp->next;
			temp->next=NULL;
		}
		else
		{
			temp->prev->next = temp->next;
        	temp->next->prev = temp->prev;
		}
    	printf("%s\n",prev->nama);
    	free(temp);
    	temp = prev;
    	if (temp->prev==NULL)
    	{
    		prev = list->_tail;
		}
		else 
		{
			prev = temp->prev;
		}
    	list->_size--;
    //	showall(list);
    //	printf("a\n");
    //	printf("NOW = %s  PREV = %s Status = %d\n",temp->nama,prev->nama,temp->data);
      }
    }
}

int main(int argc, char const *argv[])
{
    List list;
    dlist_init(&list);
    char nama[26];
    int n;
   	scanf("%d",&n);
   	for (int i=0;i<n;i++)
   	{
   		scanf("%s",&nama);
   		dlist_pushBack(&list,nama);
  	}
  	do_the_thing(&list,n);
    return 0;
}
