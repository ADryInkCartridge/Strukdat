#include<cstdio>
#include<cstdlib>
#include<queue>
#include<limits.h>
#include<algorithm>
using namespace std;

typedef struct node{
    int val;
    struct node *left, *right;
}node;

/* Enter your in code here */

int max (int a,int b)
{
    if (a>=b)
    {
        return a;
    }
    else 
    {
        return b;
    }
}

int check(node* root)  
{
  if (root == NULL)  
    return 1;  
    
  if (root->left != NULL && root->left->val > root->val)  
    return 0;  
      
  if (root->right != NULL && root->right->val < root->val)  
    return 0;  
    
  if (!check(root->left) || !check(root->right))  
    return 0;  
    
  else
  return 1;  
} 

int height(struct node* node) 
{ 
    if (node == NULL) 
        return 0; 
  
    return 1 + max(height(node->left), height(node->right)); 
} 

bool is_valid(node *root){
    
    int lheight,rheight;
    if (check(root))
    {
         if (root==NULL)
        {
            return true;
        }
        lheight = height(root->left);
        rheight = height(root->right); 

        if (abs(lheight-rheight)<=1 && is_valid(root->left) && is_valid(root->right))
        {
            return true;
        }
    }
    else 
    {
    	return false;
	}
	return false;
}


node* insert(){
   int n;
   scanf("%d", &n);
   if(n < 1)
      return NULL;
  
   node *temp,
        *head = (node*) malloc(sizeof(node));
   queue<node*> q;
   int x;
  
   n--;
   scanf("%d", &x);
   head->val = x;
   q.push(head);

   while(n > 0){
      temp = q.front();
      q.pop();

      scanf("%d", &x);
      if(x == -1)
         temp->left = NULL;
      else{
         node *left = (node*) malloc(sizeof(node));
         left->val = x;
         temp->left = left;
         q.push(left);
         n--;
      }
      if(n > 0){
         scanf("%d", &x);
         if(x == -1)
            temp->right = NULL;
         else{
            node *right = (node*) malloc(sizeof(node));
            right->val = x;
            temp->right = right;
            q.push(right);
            n--;
         }
      }
      else
         temp->right = NULL;
   }

   while(!q.empty()){
      temp = q.front();
      temp->left = NULL;
      temp->right = NULL;
      q.pop();
   }

   return head;
}

int main() {
   node* head = insert();

   if( is_valid(head) )
      printf("YES\n");
   else
      printf("NO\n");
   return 0;
}

