#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct dnode_t {
    int data;
    struct dnode_t      
        *next,
        *prev;
} DListNode;

/* Struktur ADT Deque */
/* Implementasi didasarkan pada Doubly-Linked List */

typedef struct deque_t {
    DListNode           
        *_head, 
        *_tail;
    unsigned _size;
} Deque;

/* DAFTAR FUNGSI YANG TERSEDIA */

DListNode* __dlist_createNode(int value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, int value);
void deq_pushBack(Deque *deque, int value);
int  deq_front(Deque *deque);
int  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

/* Definisi Fungsi */

DListNode* __dlist_createNode(int value)
{
    DListNode *newNode = 
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && 
            deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, int value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

int deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

int deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void clear (Deque *deque)
{
	while (!deq_isEmpty(deque))
	{
		deq_popFront(deque);
	}
}

void find (int arr[],int n,int k)
{
	Deque list;
    deq_init(&list);
	int i;
	for (i=0;i<k;i++)
	{
		//printf("%d %d\n",arr[i],arr[deq_back(&list)]);
        while((!deq_isEmpty(&list)) && arr[i]>=arr[deq_back(&list)])
        {
        	//printf("POP!!!\n");
            deq_popBack(&list);
		}
		//printf("%d\n",i);
        deq_pushBack(&list,i);
	}
	for(i=i;i<n;i++){
    	//printf("%d\n",i);
    	printf("%d ",arr[deq_front(&list)]);
    	//printf("%d %d \n",i-k,deq_front(&list));
        while((!deq_isEmpty(&list)) && deq_front(&list)<=i-k) 
        {
        	deq_popFront(&list);
        	//printf("a\n");
		}
        while((!deq_isEmpty(&list)) && arr[i]>=arr[deq_back(&list)]) 
            {
            	//printf("b\n");
            	deq_popBack(&list);
			}
        deq_pushBack(&list, i);
    }
    printf("%d\n",arr[deq_front(&list)]);
}

int main(int argc, char const *argv[])
{
    int tc;
    scanf("%d", &tc);
	for(int test=0;test<tc;test++)
	{
		int n,k;
		scanf("%d %d",&n,&k);
    	int arr[n];
    	for(int i=0;i<n;i++)
		{
    		scanf("%d",&arr[i]);
		}
		find(arr,n,k);
	}
	return 0;
}
