#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

unsigned long long count;

typedef struct bstnode_t {
    unsigned long long key;
    unsigned long long son;
    struct bstnode_t 
        *left, *right ,*dad;
} node;

typedef struct bst_t {
    node *top;
    unsigned int size;
} bst;

typedef struct queueNode_t {
    node *address;
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

void queue_push(Queue *queue,node *value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->address = value;
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


void init(bst *tree) {
    tree->top = NULL;
    tree->size = 0u;
}

node* new(unsigned long long value)
{
    node *newnode = (node*) malloc(sizeof(node));
    newnode->key = value;
    newnode->son = 0;
    newnode->left = newnode->right = NULL;
    newnode->dad=NULL;
    
    return newnode;
}

node* __bst__findMinNode(node *Node) {
    node *currNode = Node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

node* __bst__search(node *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

//node* __bst__search2(node *root, int value) {
//    while (root != NULL) {
//        if (value < root->key)
//            {
//            	root = root->left;
//            	count++;
//			}
//        else if (value > root->key)
//            {
//            	root = root->right;
//            	count++;
//			}
//        else
//            return root;
//    }
//    return root;
//}

bool bst_find(bst *bst, int value) {
    node *temp = __bst__search(bst->top, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
		return true;
    else
        return false;
}
//
//bool bst_find2(bst *bst, int value) {
//    node *temp = __bst__search2(bst->top, value);
//    if (temp == NULL)
//        return false;
//    
//    if (temp->key == value)
//        return true;
//    else
//        return false;
//}

node* caribapak(node *root,unsigned long long value)
{
    if (root!=NULL)
    {
        if (root->right!=NULL && root->key < value)
        {
            root->son++;
   //         printf("Right Side\n");
            return caribapak(root->right,value);
        }
        else if (root->left!=NULL && root->key > value)
        {
   //         printf("Left Side\n");
            return caribapak(root->left,value);
        }
    }
 //   printf("Found The Spot\n");
    return root;
}
node* __bst__remove(node *root, int value) {
    if (root == NULL) return NULL;
	if (value<1) return NULL;
    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            node *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            node *leftChild = root->left;
            free(root);
            return leftChild;
        }

        node *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

bst* tambahsmua(node *now)
{
    if (now->dad!=NULL && now->dad->right == now)
    {
        now->dad->son++;
        tambahsmua(now->dad);
    }
}

bool in(bst *tree, unsigned long long value) {
    node *newnode=new(value);
    if (newnode!=NULL)
    {
        if (tree->top!=NULL)
        {
            node *daddy = caribapak(tree->top,value);
           // printf("%d\n",daddy->key);
            newnode->dad=daddy;
            if (daddy!= NULL && value>daddy->key)
            {
                daddy->right=newnode;
                daddy->son++;
            }
            else if (daddy!=NULL && value<daddy->key)
            {
                daddy->left=newnode;
            }
            //tambahsmua(newnode);
            tree->size++;
            return true;
        }
        else
        {
            tree->top=newnode;
            tree->size++;
            return true;
        }
    }
return false;
}

node* indexing(node *root,unsigned long long value, unsigned long long *index)
{
  if(root!=NULL)
  {
    if(root->right && value >root->key)
    {
      return indexing(root->right,value,index);
    }
    else if(root->left && value < root->key)
    {
      (*index)+=root->son+1;
      return indexing(root->left,value,index);
    }
    else if(root->key == value)
    {
      *index+=root->son+1;
      return root;
    }
  }
  return NULL;
}

void bstremove(bst *bste, int value) {
    if (bst_find(bste, value)) {
        bste->top = __bst__remove(bste->top, value);
        bste->size--;
    }
}

void inorder(node *now)
{
  //printf("[IN]");
  if(now)
  {
    if(now->dad) printf("Atas = %llu",now->dad->key);
    else printf("head->");
    printf("[Now %u,Son %u]",now->key,now->son);
    if (now->left!=NULL)
    {
    	printf(" Left = %u",now->left->key);
	}
	if (now->right!=NULL)
    {
    	printf(" Right = %u",now->right->key);
	}
	printf("\n");
    inorder(now->left);
    inorder(now->right);
  }
}

bool  __bst__inorder(node *root,unsigned long long find) {
    if (root) {
    	if (__bst__inorder(root->left,find))
		{
			return true;
		}
		count++;
    //	printf("find = %llu now = %llu count = %llu\n",find,root->key,count);
    	if (root->key==find)
    	{
    		return true;
		}
		if (__bst__inorder(root->right,find))
		{
			return true;
		}
		return false;
    }
}


void __bst__inorder2(node *root) {
    if (root) {
        __bst__inorder2(root->left);
        printf("%d ", root->key);
        __bst__inorder2(root->right);
    }
}

void printall(Queue *queue)
{
	while (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        printf("%p ",temp->address);
        queue_pop(queue);
    }
}
void wow (bst *tree,unsigned long long a, unsigned long long b,unsigned long long cuk,unsigned long long div)
{
//	printf("cuk = %llu div = %llu\n",cuk,div);
	if (cuk>0 && cuk<=b)
	{
		in(tree,cuk);
	}
	if (cuk % 2 == 0)
	{
		wow(tree,a,b,cuk-div,div/2);
		wow(tree,a,b,cuk+div,div/2);
	}
	
}

int main ()
{
	clock_t time; 
	time = clock();
	
	/* code  */

    bst tree;
    init(&tree);
    node *beh=NULL;
    freopen("1.in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    unsigned long long a,b;
    scanf("%llu %llu",&a,&b);
   // printf("a\n");
    unsigned long long cuk,mincount=0;
    if (a>1)
    {
    	while (a>1)
    	{
    		a--;
    		b--;
    		mincount++;
		}
	}
	cuk=1;
	while (cuk*2<b)
	{
		cuk=cuk*2;
	}
    unsigned long long div=cuk/2;
//	printf("a\n");
    wow(&tree,a,b,cuk,div);
   // printf("a\n");
    //inorder(tree.top);
   // __bst__inorder2(tree.top);
    int n;
    scanf("%d",&n);
    for (int i=0; i<n;i++)
    {
        int option;
        scanf("%d",&option);
        if (option==1)
        {
            unsigned long long input;
            scanf("%llu",&input);
            bstremove(&tree,input-mincount);
            //inorder(tree.top);
        }
        if (option==2)
        {
            unsigned long long find;
			count=0;
            scanf("%llu",&find);
            //printall(&queue);1
            if ( __bst__inorder(tree.top,find-mincount))
            {
                printf("%llu ada di index ke-%llu",find,count);
            }
            else 
            {
                printf("%llu tidak ditemukan",find);
            }
    		if (i==n-2)
            {
            	continue;
			}
			else
			{
				printf("\n");
			}
    	}
 	}
 	time = clock()-time; 
	double tle = ((double) time)/ CLOCKS_PER_SEC ;
   // printf("\n%lf detik\n",tle);
}
