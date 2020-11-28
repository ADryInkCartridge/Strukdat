#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef struct bst_node_t{
  unsigned key,left_fruit;
  struct bst_node_t *left,
             *right,
             *parent;
}BSTNode;
 
typedef struct bst_metadata_t{
  unsigned _size_node;
  BSTNode *_head;
}BSTree;
 
 
/*
save node count
*/
/*
List fungsi
DONE Insert
DONE Remove
DONE Find
DONE Init
DONE Create Node (Init buat Node lol)
DONE Find Deepest
Delete certain Node
 
Traversal:
PreOrder
PostOrder
Inorder
 
the idea is to
*/
 
/* As for now, depth isn't used*/
 
void bst_init(BSTree *tree)
{
  tree->_size_node = 0;
  tree->_head = NULL;
}
 
BSTNode* bstNode_init(int value)
{
  BSTNode *newNode = (BSTNode*)malloc(sizeof(BSTNode));
 
  newNode->key = value;
  newNode->left_fruit = 0;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->parent = NULL;
 
  return newNode;
}
 
void __bst_ParentNodeAdd(BSTNode *now)
{
  if(now->parent && now==now->parent->left)
  {
    //printf("\nadding %u left_fruit to %u.\n",now->parent->key,now->parent->left_fruit+1);
    now->parent->left_fruit++;
    __bst_ParentNodeAdd(now->parent);
  }
}
 
BSTNode* __bst_findNode(BSTNode *node,unsigned value, unsigned *tracker)
{
  //printf("[tracker IS %u!!!]\n",*tracker);
  if(node)
  {
    if(node->left && value > node->key)
    {
      //*tracker+=1;
      return __bst_findNode(node->left,value,tracker);
    }
    //printf("[%d]->",node->key);
    else if(node->right && value < node->key)
    {
      *tracker+=node->left_fruit+1;
      return __bst_findNode(node->right,value,tracker);
    }
    else if(node->key == value)
    {
      *tracker+=node->left_fruit+1;
      //printf("[tracker IS %u!!!]\n",*tracker);
      return node;
    }
  }
  return NULL;
}
 
BSTNode* __bst_findParent(BSTNode *node,unsigned value)
{
  if(node)
  {
    if(node->left && value > node->key)
    {
      node=node->left;
      return __bst_findParent(node,value);\
    }else if(node->right && value < node->key)
    {
      node=node->right;
      return __bst_findParent(node,value);
    }
  }
  return node;
}
 
BSTNode* __bst_findDeepestNode(BSTNode *node)
{
  if(node)
  {
    if(node->left)
    {
      node=node->left;
      return __bst_findDeepestNode(node);
    }else if(node->right)
    {
      node=node->right;
      return __bst_findDeepestNode(node);
    }
  }
  return node;
}
 
bool bst_insert(BSTree *tree, unsigned value)
{
  BSTNode *newNode=bstNode_init(value);
  if(newNode)
  {
    if(tree->_head)
    {
      BSTNode *parent=__bst_findParent(tree->_head,value);
      newNode->parent=parent;
      if(parent && value > parent->key)
      {
        parent->left=newNode;
      }
      else if(parent && value < parent->key)
      {
        parent->right=newNode;
      }
 
      __bst_ParentNodeAdd(newNode);
      tree->_size_node++;
      return true;
    }else
    {
      tree->_head=newNode;
      tree->_size_node++;
      return true;
    }
  }
  return false;
}
 
bool bst_remove(BSTree *tree)
{
  BSTNode *delThis=__bst_findDeepestNode(tree->_head),*temp;
  if(delThis)
  {
      temp=delThis->parent;
      if(temp->left == delThis) //SHITSHITSBHIT WILL IT BE NULL OR NOT???
        temp->left=NULL;
      else
        temp->right=NULL;
      free(delThis);
      tree->_size_node--;
      return true;
  }
  return false;
}
 
void bst_print_inorder(BSTNode *now)
{
  //printf("[IN]");
  if(now)
  {
    if(now->parent) printf("%u->",now->parent->key);
    else printf("head->");
    printf("[%u,<%u]\n",now->key,now->left_fruit);
    bst_print_inorder(now->left);
    bst_print_inorder(now->right);
  }
}
 
int main()
{
  BSTree myTree;
  BSTNode *found = NULL;
  bst_init(&myTree);
 
  unsigned t,value,track;
  short int query;
 
  scanf("%u",&t);
  while(t--)
  {
    scanf("%hd %u",&query, &value);
    printf("%hd %u\n",query, value);
    if(query == 1)
    {
      bst_insert(&myTree,value);
    }else
    {
    	track=0;
      found=__bst_findNode(myTree._head,value,&track);
      if(found) printf("%u\n",track);
      else  printf("Data tidak ada\n");
    }
    bst_print_inorder(myTree._head);
  }
  return 0;
}
