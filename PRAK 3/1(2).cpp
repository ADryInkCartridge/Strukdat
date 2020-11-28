// ========[AVL Tree]======== //
/*
    Dibuat dan ditulis oleh ABDUR ROCHMAN
    28-03-2020
    Struktur Data 2020
    For C
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

long long int count=0,x1;

typedef struct AVLNode_t
{
    long long int data,check,arr[100];
    struct AVLNode_t *left,*right;
    long long int height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned long long int _size;
}AVL;

AVLNode* _avl_createNode(long long int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->check=0;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    int flag=0;    
            for(int test =0; test <newNode->check;test++){
                if(x1 == newNode->arr[test]) {
                    flag=1;    
                }
            }
            if( flag == 0){
                newNode->arr[newNode->check] = 1;
                newNode->check++;
                count++;
            } 
    return newNode;
}

AVLNode* _search(AVLNode *root, long long int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
        {
            int flag=0;
            for (int test = 0; test < root -> check;test++)
            {
                if (x1 == root->arr[test])
                {
                    flag=1;
                }
            }
            if (flag == 0)
            {
                root ->arr[root->check] = x1;
                root->check++;
                count++;
            }
            return root;
        }
    }
    return root;
}

long long int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

long long int _max(long long int a,long long int b){
    return (a > b)? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode){

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

long long int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,long long int value){
    
    if(node==NULL)
        return _avl_createNode(value);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value);
    else if(value > node->data)
    	node->right = _insert_AVL(avl,node->right,value);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    long long int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && value < node->left->data)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->data)
		return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}


void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, long long int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
        
    // if (temp->data == value && temp->x == xin && temp->y!=yin)
    // {
    // 	count++;
    // //	printf("\nvalue = %d x in = %d y in %d \n",value,xin,yin);
    //     return true;
	// }
    // else if (temp->data == value && temp->x!= xin && temp->y==yin)
    // {
    // 	count++;
    // // 	printf("\nvalue = %d  x in = %d y in %d \n",value,xin,yin);
	// 	return true;
	// }
    else if (temp->data == value)
    {
    	//printf(" NABRAK \n");
    	return true;
	}
    else
        return false;
}

void avl_insert(AVL *avl,long long int value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
        count++;
    }

}


void preorder(AVLNode *root) {
    if (root) {
        preorder(root->left);
        printf("%d ", root->data);
        preorder(root->right);
    }
}

int main(){
	
	AVL board;
	avl_init(&board);
	long long int n,k,x,y;
    scanf("%lld %lld",&n,&k);
    if (n*n==k)
    {
    	printf("%lld\n",n*n);
	}
	else
	for (long long int i=0;i<k;i++)
	{
		scanf("%d %d",&x,&y);
		x1=x;
   		long long int y1=y;
   		avl_insert(&board,(x1*y1));
           x1--;y1--;
   		while (x1>0 && y1>0 && x1<=n &&y1<=n)
   		{
   			avl_insert(&board,x1*y1);
            x1--;y1--;
   		//	printf("x1 = %d  y1 = %d\n",x1,y1);
		}
		x1=x-1;
		y1=y+1;
		while (x1>0 && y1>0 && x1<=n &&y1<=n)
   		{
   			avl_insert(&board,x1*y1);
            x1--;y1++;
   		//	printf("x1 = %d  y1 = %d\n",x1,y1);
		}
		x1=x+1;
		y1=y-1;
		while (x1>0 && y1>0 && x1<=n &&y1<=n)
   		{
   			avl_insert(&board,x1*y1);
               x1++;y1--;
   		//	printf("x1 = %d  y1 = %d\n",x1,y1);
		}
		x1=x+1;
		y1=y+1;
		while (x1>0 && y1>0 && x1<=n &&y1<=n)
   		{
   			avl_insert(&board,x1*y1);
            x1++;y1++;
   		//	printf("x1 = %d  y1 = %d\n",x1,y1);
		}
   }
    printf("%lld\n",count);
   // preorder(board._root);
}
