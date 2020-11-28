#include <bits/stdc++.h>
using namespace std;

struct AVLNode {
    int data;
    int count;
    int ca;
    long long int key;
    AVLNode *left, *right,*pnode;
    int height;
};
int ac=0;
int abc=0;
int n=0;
int dc=0;
int fc=1;
long long int ans=1;
vector<long long int> arr;
vector<long long int> check;
vector<long long int> d;
long long int fact[10000];
struct AVL
{
public:
    AVLNode *_root;
    unsigned _size;

    AVLNode* _avl_createNode(int value) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->count = 0;
    	newNode->key = 0;
    	newNode->ca=0;
        newNode->height =1;
        newNode->left = newNode->right = newNode->pnode = NULL;
        return newNode;
    }

    AVLNode* _search(AVLNode *root, int value) {
        while (root != NULL) {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode* node){
        if(node==NULL)
            return 0; 
        return node->height;
    }

    int _max(int a,int b){
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

    int _getBalanceFactor(AVLNode* node){
        if(node==NULL)
            return 0;
        return _getHeight(node->left)-_getHeight(node->right);
    }

    AVLNode* _insert_AVL(AVLNode* node,int value) {
        
        if(node==NULL)
            return _avl_createNode(value);
        if(value < node->data)
            node->left = _insert_AVL(node->left,value);
        else if(value > node->data)
            node->right = _insert_AVL(node->right,value);
        
        node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

        int balanceFactor=_getBalanceFactor(node);
        
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

    AVLNode* _remove_AVL(AVLNode* node,int value){
        if(node==NULL)
            return node;
        if(value > node->data)
            node->right=_remove_AVL(node->right,value);
        else if(value < node->data)
            node->left=_remove_AVL(node->left,value);
        else{
            AVLNode *temp;
            if((node->left==NULL)||(node->right==NULL)){
                temp=NULL;
                if(node->left==NULL) temp=node->right;  
                else if(node->right==NULL) temp=node->left;
                
                if(temp==NULL){
                    temp=node;
                    node=NULL;
                }
                else
                    *node=*temp;   
                
                free(temp);
            }
            else{
                temp = _findMinNode(node->right);
                node->data=temp->data;
                node->right=_remove_AVL(node->right,temp->data);
            }    
        }

        if(node==NULL) return node;
        
        node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

        int balanceFactor= _getBalanceFactor(node);
        
        if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
            return _leftCaseRotate(node);

        if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
            return _leftRightCaseRotate(node);
    
        if(balanceFactor<-1 && _getBalanceFactor(node->right)<=0) 
            return _rightCaseRotate(node);

        if(balanceFactor<-1 && _getBalanceFactor(node->right)>0) 
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    void _inorder(AVLNode *node) {
        if (node) {
            _inorder(node->left);
            printf("node = %d  key = %lld count = %d\n", node->data, node->key, node->count );
            if (node->pnode!=NULL)
            {
            	printf("parent node = %d\n",node->pnode->data);
			}
            _inorder(node->right);
        }
    }

public:
    void init() {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty() {
        return _root == NULL;
    }
    bool find(int value) {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;
        
        if (temp->data == value) return true;
        else return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    void inorder() {
        this->_inorder(_root);
    }
    void pareeent(AVLNode *node)
    {
    	if (node) 
		{
			if (node->left!=NULL)
			{
				node->left->pnode=node;
			}
			if (node->right!=NULL)
			{
				node->right->pnode=node;
			}
            pareeent(node->left);
            pareeent(node->right);
        }
	}
    void leaf(AVLNode *root) 
	{ 
	    if (!root) 
	        return; 
	      
	    if (!root->left && !root->right) 
	    { 
	        if (ac < n)
	        {
	        	root->key=arr[ac];
	        	root->ca=ac;
	        	ac++;
			}
	        return; 
	    } 
	    if (root->left) 
	       leaf(root->left); 
	    if (root->right) 
	       leaf(root->right); 
	}  
	void counting(AVLNode *node)
	{
		node->count++;
		//cout << dc << endl;
		if(node->pnode!=NULL)
		{
			if (node==node->pnode->right)
			{
				dc-=node->pnode->left->count;
			}
			counting(node->pnode);
		}
		if (node->pnode==NULL)
		{
			ans += dc*fact[n-fc];
			fc++;
			ans % 10^9+7;
			//cout << " AAAAA " << ans << endl;
		}
		return;
	}
	void ff(AVLNode *root,long long int value) 
	{
        if (!root) 
	        return;  
	    if (!root->left && !root->right) 
	    { 
	        if (root->key==value)
	        {
	        	dc=root->ca;
	        	counting(root);
			}
	        return; 
	    } 
	    if (root->left) 
	       ff(root->left,value); 
	    if (root->right) 
	       ff(root->right,value); 
    }
};


int main(int argc, char const *argv[])
{
    AVL set;
    set.init();
	cin>>n;
	int kk=0;
	fact[kk]=1;
	while (++kk < n)
	{
		fact[kk]=fact[kk-1]*kk;
	}
  	for (int i=0;i<n;i++)
  	{
  		long long int in;
  		cin >> in;
  		arr.push_back(in);
  		check.push_back(in);
	}
	sort(arr.begin(),arr.end());
	int k=1;
	while (n>pow(2,k))
	{
		k++;
	}
	for (int i=1;i<=pow(2,k+1)-1;i++)
	{
		set.insert(i);
	}
	set.leaf(set._root);
	set.pareeent(set._root);
	for (int i=0;i<n;i++)
	{	
		set.ff(set._root,check[i]);
	}
	cout << ans << endl;
	//set.inorder();
	//set.po(set._root);
    return 0;
}
