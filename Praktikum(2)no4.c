#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int key;
    int length;
    int jundi;
    struct bstnode_t 
        *left, *right ,*dad;
} node;

typedef struct bst_t {
    node *top;
    unsigned int size;
} bst;

void init(bst *tree) {
    tree->top = NULL;
    tree->size = 0u;
}

node* new(int value,int length)
{
    node *newnode = (node*) malloc(sizeof(node));
    newnode->key = value;
    newnode->length = length;
    newnode->left = newnode->right = NULL;
    newnode->dad=NULL;
    newnode->jundi=0;
    
    return newnode;
}

node* caribapak(node *root,unsigned long long value)
{
    if (root!=NULL)
    {
        if (root->right!=NULL && root->key < value)
        {
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


bool in(bst *tree, int value,int length) {
    node *newnode=new(value,length);
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
            }
            else if (daddy!=NULL && value<daddy->key)
            {
                daddy->left=newnode;
            }
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

node* search(node *root, int value) {
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

void inorder(node *now)
{
  //printf("[IN]");
  if(now)
  {
    if(now->dad) printf("Atas = %llu",now->dad->key);
    else printf("head->");
    printf("[Now %u]",now->key);
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
void recurpos(node *now)
{
    if (now->left == NULL && now->right == NULL)
    {
        return 
    }
}

void wayout(int pos)
{
    node* now = search(bst->top,pos);
    if (now)
    {
        if (now->left==NULL && now->right==NULL)
        {
            printf("0 ");
        }
        else 
        {
            recurpos(now);
        }
    }
}


int main ()
{
    bst tree;
    init(&tree);
    node *beh=NULL;
    int n,root;
    scanf("%d",&n);
    scanf("%d",&root);
    in(&tree,root,0);
    for (int i=0;i<n-1;i++)
    {
        int value,length;
        scanf("%d %d",&value,&length);
        in(&tree,value,length);
    }
    inorder(tree.top);
    int testcase;
    scanf("%d",&testcase);
    for (int i=0;i<testcase;i++)
    {
        int pos;
        scanf("%d",&pos);
        wayout(pos);
        printf("DONE\n");
    }
 }
