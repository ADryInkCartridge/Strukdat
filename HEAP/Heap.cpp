#include<stdio.h>
#include <time.h>

void swap (int *x,int *y)
{
	int temp = *x; 
    *x = *y; 
    *y = temp; 
}
int rchild(int heap[], int index,int n) 
{
	if((((2*index)+1) < n) && (index >= 1))
	return (2*index)+1;
	return -1;
}

int lchild(int heap[], int index,int n) {
    if(((2*index) < n) && (index >= 1))
    return 2*index;
    return -1;
}

int parent(int heap[], int index,int n)
{
	if ((index > 1) && (index < n))
    return index/2;
    return -1;
}

void heapup(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1;
    int r = 2*i + 2; 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]); 

        heapup(arr, n, largest); 
    } 
} 
void heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapup(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 
    {
        swap(&arr[0], &arr[i]); 
        heapup(arr, i, 0); 
    } 
} 

int main ()
{
	clock_t time; 
	time = clock();
	int arr[1000];
    int n = 1000;
  	freopen("test4.txt","r",stdin);
  	for (int i=0;i<n;i++)
  	{
  		scanf("%d",&arr[i]);
	}
    heapSort(arr, n); 
    for(int i=0;i<n;i++)
    {
    	printf ("%d ",arr[i]);
	}
	time = clock()-time; 
	double tle = ((double) time)/ CLOCKS_PER_SEC ;
    printf("\n%lf detik\n",tle);
}
