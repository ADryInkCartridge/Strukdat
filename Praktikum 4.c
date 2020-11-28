/**
 * Implementasi ADT SInglyList (Singly Linked List)
 *
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 *
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct snode_t {
    int data;
    char nama[20];
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
void slist_pushBack(SinglyList *list, char value[]);
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

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
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
    }
}

void slist_pushBack(SinglyList *list, char value[])
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = 1;
        strcpy(newNode->nama,value);
        newNode->next = NULL;

        if (slist_isEmpty(list))
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void do_the_thing(SinglyList *list,int n)
{
	int k,lol=0;
	if (!slist_isEmpty(list))
	{
		//printf("a");
		SListNode *temp =  list->_head;
		SListNode *prev =  list->_head;
		for (int wow=0;wow<n-1;++wow)
		{
			scanf("%d",&k);
			for (int i=0;i<k;++i)
			{
				printf("NOW = %s  PREV = %s Status = %d\n",temp->nama,prev->nama,temp->data);
			//	printf("a");
				if (temp->data==0)
				{
					printf("Dead pass %s",temp->nama);
					i--;
				}
				if (temp->next==NULL)
				{
					temp = list->_head;
				}
				else
				{
					temp=temp->next;
				}
				if (lol==0)
				{
					lol=1;
					continue;
				}
				else if (prev->next==NULL)
				{
					prev = list->_head;
				}
				else if (temp->data==0)
				{
					printf("Prev Pass %s",prev->nama);
					continue;
				}
				else
				{
					prev=prev->next;
				}
			}
			temp->data=0;
			printf("%s\n",prev->nama);
				printf("NOW = %s  PREV = %s Status = %d\n",temp->nama,prev->nama,temp->data);
			temp = list->_head;
			while (strcmp(prev->nama,temp->nama)!=0)
			{
				temp=temp->next;
			}
			//printf("NOW = %s  PREV = %s\n",temp->nama,prev->nama);
			prev = list->_head;
			//printf("NOW = %s  PREV = %s\n",temp->nama,prev->nama);
			int count=0;
			if (temp==list->_head)
			{
				while (prev->next!=NULL)
				{
					if (prev->next->data==0)
          {
            while (prev->next->data==0 && prev->next!=NULL)
            {
              count++;
            }
            for (int pow=0;pow<count;pow++)
            {
              prev=prev->next;
            }
          }
          else
          {
            prev=prev->next;
          }
				}
			}
			else
			{
				while (strcmp(prev->next->nama,temp->nama)!=0 && prev->next!=NULL)
				{
  					if (prev->next->data==0 && strcmp(prev->next->nama,temp->nama)!=0)
            {
              while (prev->next->data==0 && prev->next!=NULL && strcmp(prev->next->nama,temp->nama)!=0)
              {
                count++;
              }
              for (int pow=0;pow<count;pow++)
              {
                prev=prev->next;
              }
            }
            else
            {
              prev=prev->next;
            }
				 }
			}
			printf("NOW = %s  PREV = %s Status = %d\n",temp->nama,prev->nama,temp->data);
		}
	}
}


int main(int argc, char const *argv[])
{
    SinglyList list;
    slist_init(&list);
    int n;
    char nama[20];
 	scanf("%d",&n);
 	for (int i=0;i<n;i++)
 	{
 		scanf("%s",&nama);
 		slist_pushBack(&list,nama);
	}
	do_the_thing(&list,n);
}
