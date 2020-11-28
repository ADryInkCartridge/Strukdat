#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/**
 * Node structure and
 * uniqueBST structure
 */

typedef struct bstnode_t {
    int key;
    char nama[105];
    struct bstnode_t *left, *right, *down;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value, char* temp) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    strcpy(newNode->nama, temp);
    newNode->left = newNode->right = newNode->down = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value,char *temp) {
    if (root == NULL) 
        return __bst__createNode(value,temp);

    if(value == root->key) 
	{
		root->down = __bst__insert(root->down, value, temp);
	}
    else if (value < root->key)
	{	        
		root->left = __bst__insert(root->left, value,temp);
	}

    else if (value > root->key)
	{
    	root->right = __bst__insert(root->right, value,temp);
	}

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

BSTNode* __bst__remove(BSTNode *root, int value) {
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

void _printbawah(BSTNode *root)
{
	if(root){
		printf(" %s", root->nama);
		if(root->down) _printbawah(root->down);	
	}
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->left);
        printf("Descendant : %d | Name : %s",root->key,root->nama);
        if(root->down == NULL) printf("\n");
        if(root->down != NULL)
        {
        	printf(" | Twins :");
			_printbawah(root->down);
			printf("\n");
		}
        __bst__inorder(root->right);
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
//    
//    if (temp->key == value)
//        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value, char temp[]) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value,temp);
        bst->_size++;
    }
}

void bst_remove(BST *bst, int value) {
    if (bst_find(bst, value)) {
        bst->_root = __bst__remove(bst->_root, value);
        bst->_size--;
    }
}

void bst_inorder(BST *bst) {
    __bst__inorder(bst->_root);
}
 
int main()
{
    BST tree;
    bst_init(&tree);
	char in[105];
	char temp2;
	int jumlah = 0,panjang;
	
	while(true)
	{
		scanf("%s",&in);
		panjang = strlen(in);
		for(int a = 0; a <panjang; a++)
		{
			jumlah = jumlah + in[a];
		}
		bst_insert(&tree, jumlah,in);
		jumlah = 0;
		if(getchar() == '\n') break;	
	}
	bst_inorder(&tree);
    return 0;
}