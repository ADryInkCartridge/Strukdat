// C++ program for implementation of Bubble sort  
#include <bits/stdc++.h> 
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
// Driver code  
int main()  
{  
    for (int abc=1;abc<=10;abc++)
    {
    	int* arr = new int[1000000];
		ifstream inFile;
		inFile.open("hash.in.txt");
		int n;
		inFile >> n ;
		for (int i=0;i<n;i++)
		{
			inFile >> arr[i];
		}
		inFile.close();
		clock_t time; 
		time = clock();
		double total=0;
	    bubbleSort(arr, abc * 100000); 
	  	time = clock()-time; 
		double tle = ((double) time)/ CLOCKS_PER_SEC ;
		total+=tle;
		printf("%lf\n",total);
	}
}  
