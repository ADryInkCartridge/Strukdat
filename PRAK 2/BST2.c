#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
int check,min;
typedef struct bstnode_t {
    unsigned long long key;
    unsigned long long length;
    unsigned long long total;
    unsigned long long flag;
    struct bstnode_t 
        *left, *right ,*dad;
} node;

typedef struct bst_t {
    node *top;
    unsigned long long size;
} bst;

typedef struct queueNode_t {
    node *data;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, node *value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}


unsigned long long queue_size(Queue *queue) {
    return queue->_size;
}

void init(bst *tree) {
    tree->top = NULL;
    tree->size = 0u;
}

node* __bst__search(node *root, unsigned long long value) {
    while (root != NULL) {
    //	printf("value = %llu key = %llu \n",value,root->key);
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

node* __bst__search2(node *root, unsigned long long value) {
    while (root != NULL) {
    	//printf("value = %llu key = %llu \n",value,root->key);
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

bool bst_find(bst *bst, unsigned long long value) {
    node *temp = __bst__search2(bst->top, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

node* __bst__createNode(unsigned long long value,unsigned long long length) {
    node *newnode = (node*) malloc(sizeof(node));
    newnode->key = value;
    newnode->length = length;
    newnode->flag=0;
    newnode->total=0;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->dad=NULL;
    return newnode;
}
node* __bst__insert(node *root, unsigned long long value,unsigned long long length) {
    if (root == NULL) 
        return __bst__createNode(value,length);

    if (value < root->key)
    {
		node *lchild = __bst__insert(root->left,value,length);
		root->left=lchild;
		lchild->dad=root;
	}   
    else if (value > root->key)
    {
    	node *rchild = __bst__insert(root->right, value,length);
    	root->right=rchild;
    	rchild->dad=root;
	}
    
    return root;
}
void bst_insert(bst *bst, unsigned long long value,unsigned long long length) {
    if (!bst_find(bst, value)) {
        bst->top = __bst__insert(bst->top, value,length);
        bst->size++;
    }
}

 void lvlorder(node *temp,Queue *queue)
 {
 	 temp->flag=1;
 	 //printf("now = %llu length = %llu total = %llu\n flag = %llu", temp->key,temp->length,temp->total,temp->flag);
     if (temp->left!=NULL&&temp->left->flag==0)
     {
        queue_push(queue,temp->left);
		temp->left->total=temp->left->length+temp->total;
     }
     if (temp->right!=NULL&&temp->right->flag==0)
     {
        queue_push(queue,temp->right);
		temp->right->total=temp->right->length+temp->total;
     }
     if (temp->dad!=NULL&&temp->dad->flag==0)
     {
        queue_push(queue,temp->dad);
		temp->dad->total=temp->total+temp->length; 
     }
     if (temp->left == NULL && temp->right == NULL)
     {
     	//printf("\nTOTAL = %llu\n\n",temp->total);
     	check=temp->total;
     	if (min==-1)
     	{
     		min=check;
		}
		else if (min>check)
		{
			min=check;
		}	
	 }
     queue_pop(queue);
     if(!queue_isEmpty(queue))
     {
         lvlorder(queue->_front->data,queue);
     }
 }

void __bst__postorder(node *root) {
    if (root) {
    	
        __bst__postorder(root->left);
        __bst__postorder(root->right);
    	root->flag=0;
    	root->total=0;
    }
}

void __bst__preorder(node *root) {
    if (root) {
       // printf("key = %llu total = %llu \n", root->key,root->total);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}
void __bst__preorder3(node *root) {
    if (root) {
        if (root->dad && root->dad->total + root->length < root -> total)
        {
            root->total=root->dad->total + root->length;
        }
        __bst__preorder3(root->left);
        __bst__preorder3(root->right);
    }
}
void __bst__preorder2(node *root) {
    if (root) {
        __bst__preorder2(root->left);
        __bst__preorder2(root->right);
          if (root->left==NULL && root->right==NULL)
        {
        	root->total=0;
		}
        else if (root->right && root->left==NULL)
        {
            root->total=root->right->total + root->right->length;
        }
        else if (root->left && root->right==NULL)
        {
            root->total=root->left->total + root->left->length;
        }
        else if (root->right && root->left)
        {
            unsigned long long l = root->left->total + root->left->length;
            unsigned long long  r = root->right->total + root->right->length;
            if (l<r)
            {
                root->total=l;
            }
            else 
            {
                root->total=r;
            }
        }
    }
}
void serch (bst *tree,unsigned long long pos)
{
	node *temp=__bst__search2(tree->top,pos);
	printf("%llu",temp->total);
}

int main ()
{
	bst tree;
	init(&tree);
//    Queue bfs;
//    queue_init(&bfs);
    freopen("soal2_in4.txt","r",stdin);
	freopen("out.txt","w",stdout);
    unsigned long long n,root;
    scanf("%llu",&n);
    scanf("%llu",&root);
    bst_insert(&tree,root,0);
    for (unsigned long long i=0;i<n-1;i++)
    {
        unsigned long long value,length;
        scanf("%llu %llu",&value,&length);
        bst_insert(&tree,value,length);
        //printf("%d ",i);
    }
    __bst__preorder2(tree.top);//POSORDER
    __bst__preorder3(tree.top);
   // __bst__preorder(tree.top);
    unsigned long long testcase;
  
    scanf("%llu",&testcase);
    for (unsigned long long j=0;j<testcase;j++)
    {
        unsigned long long pos;
        scanf("%llu",&pos);
        serch(&tree,pos);
//      queue_push(&bfs,temp);
//      lvlorder(temp,&bfs);
//		min=minimumDistance(tree.top, temp);
		if (j==testcase-1)
		{
			continue;
		}
		else 
		{
			printf(" ");
		}
    }
    printf("\n");
 }
