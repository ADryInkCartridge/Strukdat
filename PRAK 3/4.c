#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int key;
    struct bstnode_t 
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;



BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL) 
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
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

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

bool allc (BSTNode *temp,int total, int value)
{
    if(temp)
    {
        total+=temp->key;
        //printf(" %d ",total);
        if (total<value)
        {
            allc(temp->left,total,value);
            allc(temp->right,total,value);
        }
        if (total==value)
        {
            return true;
        }
        return false;
    }
    return false;
}

bool fchild (BSTNode *temp,int value)
{
    if (temp)
    {
        if (temp->key<value)
        {
            int total;
            bool l,r;
            total = temp->key;
            l = allc(temp->left,total,value);
            r = allc(temp->right,total,value);
            if (l == true || r == true)
            {
                return true;
            }
        }
        else 
        {
            fchild(temp->left,value);
            fchild(temp->right,value);
        }
        return false;
    }
    return false;
}

bool find (BST *bst, int value)
{
    BSTNode *temp =__bst__search(bst->_root,value);
    if (temp!=NULL)
    {
        return true;
    }
    if (temp==NULL)
    {
        if (fchild(bst->_root,value))
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    return false;
}
 
int main()
{
    BST bst;
    bst_init(&bst);
    int n;
    scanf("%d",&n);
    for (int test=0;test<n;test++)
    {
    	int q,k;
    	scanf("%d %d",&q,&k);
    	if (q==1)
    	{
    		bst_insert(&bst,k);
		}
        if (q==2)
        {
            if (find(&bst,k))
            {
            	printf("<3\n");
			}
			else 
			{
				printf("<>\n");
        	}
		}
	}
    return 0;
}
