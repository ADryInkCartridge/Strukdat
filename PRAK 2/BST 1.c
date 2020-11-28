

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

int count=0;
/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key,light,son,flag;
    struct bstnode_t \
        *left, *right, *dad;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

typedef struct queueNode_t {
    BSTNode *data;
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

void queue_push(Queue *queue, BSTNode *value)
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


int queue_size(Queue *queue) {
    return queue->_size;
}


BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->son = 0;
    newNode->flag = 0;
    newNode->light = 0;
    newNode->left = newNode->right = newNode->dad = NULL ;
    return newNode;
}


BSTNode* __bst__search(BSTNode *root, int value) {
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

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

void lights (BSTNode *root)
{
	if (root->light==0 && root->dad==NULL )
	{
		root->light=2;
		if (root->left)
		{
			root->left->light=1;
		}
		if (root->right)
		{
			root->right->light=1;
		}
		count++;
	}
	else if (root->light==0 && root->dad!=NULL)
    {
        root->dad->light=2;
        if (root->dad->left!=NULL)
        {
            root->dad->left->light=1;
        }
        if (root->dad->right!=NULL)
        {
            root->dad->right->light=1;
        }
        if (root->dad->dad!=NULL)
        {
        	root->dad->dad->light=1;
		}
        count++;
    }
}

void lightleaf (BSTNode *root)
{
	if (root->light==0 && root->left==NULL && root->right==NULL && root->dad!=NULL)
    {
        root->dad->light=2;
        if (root->dad->left!=NULL)
        {
            root->dad->left->light=1;
        }
        if (root->dad->right!=NULL)
        {
            root->dad->right->light=1;
        }
        if (root->dad->dad!=NULL)
        {
        	root->dad->dad->light=1;
		}
        count++;
        //printf("EDGE CASE\n");
    }
}

void  __bst__inorder(BSTNode *root) {
    if (root) {
		lightleaf(root);
    	__bst__inorder(root->left);
		__bst__inorder(root->right);
		lights(root);
		
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
         printf("now = %d status = %d\n", root->key,root->light);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("now = %d status = %d\n", root->key,root->light);
        __bst__preorder(root->left);
        __bst__preorder(root->right);
    }
}

/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0u;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

BSTNode* caribapak(BSTNode *root,unsigned long long value)
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

bool in(BST *tree, unsigned long long value) {
    BSTNode *newnode=__bst__createNode(value);
    if (newnode!=NULL)
    {
        if (tree->_root!=NULL)
        {
            BSTNode *daddy = caribapak(tree->_root,value);
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
            tree->_size++;
            return true;
        }
        else
        {
            tree->_root=newnode;
            tree->_size++;
            return true;
        }
    }

return false;
}


/**
 * Binary search tree traversal
 * - Inorder
 * - Postorder
 * - Preorder
 */

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}

void bst_postorder(BST *bst) {
    __bst__postorder(bst->_root);
}

void bst_preorder(BST *bst) {
    __bst__preorder(bst->_root);
}

void __bst__inorder2(BSTNode *root) {
    if (root) {
        __bst__inorder2(root->left);
        printf("now = %d status = %d\n", root->key,root->light);
        __bst__inorder2(root->right);
    }
}

void lvlorder(BSTNode *temp,Queue *queue)
{
    temp->flag=1;
    lights(temp);
    if (temp->left!=NULL)
    {
        queue_push(queue,temp->left);
    }
    if (temp->right!=NULL)
    {
        queue_push(queue,temp->right);
    }
    queue_pop(queue);
    if(!queue_isEmpty(queue))
    {
        lvlorder(queue->_front->data,queue);
    }
}

 
int main()
{
    clock_t time; 
	time = clock();
    BST tree;
    bst_init(&tree);
//  Queue bfs;
//  queue_init(&bfs);
	freopen("soal1_in4.txt","r",stdin);
	freopen("out.txt","w",stdout);
    int n,input;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&input);
        in(&tree,input);
    }
//  queue_push(&bfs,tree._root);
    bst_inorder(&tree);
    //lvlorder(tree._root,&bfs);
    printf("%d\n",count);
    //__bst__preorder(tree._root);
    time = clock()-time; 
	double tle = ((double) time)/ CLOCKS_PER_SEC ;
    //printf("\n%lf detik\n",tle);
    return 0;
}
