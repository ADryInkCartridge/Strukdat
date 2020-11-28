#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include <stdio.h>

typedef struct dnode_t {
    int data;
    char nama[100];
    struct dnode_t      
        *next,
        *prev;
} DListNode;


typedef struct deque_t {
    DListNode           
        *_head, 
        *_tail;
    unsigned _size;
    unsigned nomor;
} Deque;

DListNode* awal;

DListNode* __dlist_createNode(int value, char name[])
{
    DListNode *newNode = 
        (DListNode*) malloc (sizeof(DListNode));
    if (!newNode) return NULL;
    newNode->data = value;
    strcpy(newNode->nama, name);
    newNode->next = NULL;
    newNode->prev = NULL;
    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
    deque->nomor = 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
        deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, int value, char name[])
{
    DListNode *newNode = __dlist_createNode(value, name);
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

void deq_pushBack(Deque *deque, int value, char name[])
{
    DListNode *newNode = __dlist_createNode(value, name);
    if (newNode) {
        deque->_size++;
        deque->nomor++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }
       deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
        awal = deque->_tail;
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

void print(DListNode *now)
{
    printf ("%d\n", now->data);
    printf ("%s\n", now->nama);
}

bool search(Deque *deque, int x)
{
    DListNode *temp = deque->_head;
    while(temp != NULL)
    {
        if(temp->data == x)
        {
            awal = temp;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void reset(Deque *deq, int x)
{
    DListNode *temp = deq->_tail;
    while(temp->prev != NULL)
    {
        if(temp->data == x) break;
        if(temp->prev->data ==  x)
        {
            awal = temp->prev;
            deq_popBack(deq);
            deq->_tail = awal;
            break;
        }
        temp = temp->prev;
        deq_popBack(deq);
    }
}

bool sync(Deque *deq, int no, char name[])
{
    DListNode *temp = deq->_tail;
    while(temp != NULL)
    {
        if(temp->data == no && strcmp(temp->nama, name)==0) 
            return true;
        if(temp->data < no) 
            return false;
        temp = temp->prev;
    }
    return false;
}
int main()
{
    Deque master,feature;
    deq_init(&master);
    deq_init(&feature);

    Deque *pos = &master;
    Deque *branch = &feature;
    while(1)
    {
        char perintah[20];
        scanf("%s",&perintah);
        getchar();
        if(strcmp(perintah, "commit")==0)
        {
            char nama[101];
            gets(nama);
            deq_pushBack(pos, pos->nomor, nama);
        }
        else if(strcmp(perintah, "reset")==0)
        {
            int pil;
            scanf("%d", &pil);
            reset(pos, pil);
            printf("Anda berada di commit %s\n", awal->nama);
        }
        else if(strcmp(perintah, "log")==0)
        {
            if(!deq_isEmpty(pos))
            {
                DListNode *temp = pos->_tail;
                for(int i = 0; i<pos->_size; i++)
                {
                    print(temp);
                    temp = temp->prev;
                }    
            }
            else printf("\n");
        }
        else if(strcmp(perintah, "checkout")==0)
        {
            int num;
            scanf("%d", &num);
            if(search(pos, num))
            {
                printf("Anda berada di commit %s\n", awal->nama);
            }
            else printf("ID tidak ditemukan\n");    
        }
        else if(strcmp(perintah, "status")==0)
        {
            printf("Anda berada di commit %s\n", awal->nama);
        }
        else if(strcmp(perintah, "branch")==0)
        {
            char pil[20];
            gets(pil);
            if(strcmp(pil, "master") == 0)
            {
                pos = &master;
                branch = &feature;
                awal = pos->_tail;
            }
            else if(strcmp(pil, "feature") == 0)
            {
                pos = &feature;
                branch = &master;
                awal = pos->_tail;
            }    
        }
        else if(strcmp(perintah, "sync")==0)
        {
            DListNode *temp = pos->_tail;
            while(temp != NULL)
            {
                int cariid = temp->data;
                char cariname[101];
                strcpy(cariname,temp->nama);
                if(sync(branch, cariid, cariname))
                {
                    reset(branch, cariid);
                    break;
                }
                temp = temp->prev;
            }
        }
        else if(strcmp(perintah, "quit")==0)
            break;
    }

    return 0;
}
