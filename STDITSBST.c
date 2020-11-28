#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    int index;
    struct bstnode_t \
        *left, *right ,*dad;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

/**
 * !!! WARNING UTILITY FUNCTION !!!
 * Recognized by prefix "__bst__"
 * ---------------------------------------------
 * Note that you better never access these functions, 
 * unless you need to modify or you know how these functions work.
 */

BSTNode* __bst__createNode(unsigned long long value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    newNode->index=0;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, unsigned long long value) {
    BSTNode *newNode=bstNode_createnode(value);
    if (root == NULL) 
        return __bst__createNode(value);
    else
    {
        BSTNode *bapak = caribapak(BST->root,value);
    }
    if (bapak!=NULL && value < bapak->key)
    {
        bapak->right=newNode;
        newNode->index=bapak->index+1;
    }
    else if (bapak!=NULL && value > bapak->key)
    {
        bapak->left=newNode;
    }
    
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, unsigned long long value) {
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

BSTNode* caribapak(BSTNode *root, unsigned long long value,)
{
    if (root==NULL)
    {
        return root;
    }
    else if (root->right!=NULL && value < root->key)
    {
        root->index++;
        return caribapak(root->right,value);
    }
    else if (root->left!=NULL && value > root->key)
    {
        return caribapak(root->left,value);
    }
    return root;
}

BSTNode* __bst__search2(BSTNode *root, unsigned long long value,unsigned long long *count) {
    while (root != NULL) {
        if (value < root->key)
            {
                root = root->left;
                (*count)++;
            }
        else if (value > root->key)
            {
                root = root->right;
                *count++;
            }
        else
       	{
        	(*count)++;
        	return root;
		}
    }
    return root;
}

BSTNode* __bst__searchiter(BSTNode *root, unsigned long long value,unsigned long long *count)
{
    if (root==NULL)
    {
        return false;
    }
    else if (node->right!=NULL && value>root->key)
    {
        count++;
        return ( __bst__searchiter(root->right,value,count));
    }
    else if (node->left!=NULL && value<root)
    {
        count++;
        return (__bst__searchiter(root->left,value,count))
    }
    else 
    {
        return (count);
    }
}


BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, unsigned long long value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("%d ", root->key);
        __bst__inorder(root->right);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->left);
        __bst__postorder(root->right);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
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

bool bst_find(BST *bst, unsigned long long value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}
bool bst_find2(BST *bst, unsigned long long value) {
    unsigned long long count=0;
    BSTNode *temp = __bst__search2(bst->_root, value, &count);
    if (temp == NULL)
        {
            printf("Data tidak ada\n");
            return false;
        }
    if (temp->key == value)
        {
            printf("%llu\n",count);
            return true;
        }
    else
    {
        printf("Data tidak ada\n");
        return false;
    }
}

bool bst_finditer (BST *bst, unsigned long long value)
{
     if (root==NULL)
    {
        return false;
    }
    else if (value>root)
    {
        count++;
        return ( __bst__searchiter(root->right,value,count));
    }
    else if (value<root)
    {
        count++;
        return (__bst__searchiter(root->left,value,count))
    }
    else 
    {
        return (count);
    }
}

void bst_insert(BST *bst, unsigned long long value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void bst_remove(BST *bst, unsigned long long value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
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
 
int main()
{
    BST set;
    bst_init(&set);
    int testcase;
    scanf("%d",&testcase);
    for (int i=0;i<testcase;i++)
    {
        int option;
        scanf("%d",&option);
        if (option==1)
        {
            unsigned long long input;
            scanf("%llu",&input);
            bst_insert(&set,input);
        }
        if (option==2)
        {
            unsigned long long find;
            scanf("%llu",&find);
            unsigned long long count=0;
            bst_find2(&set,find,&count);
        }
    }
}
