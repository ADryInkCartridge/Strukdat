// C++ program to implement recursive Binary Search 
#include <bits/stdc++.h> 
using namespace std; 
  
// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
		//printf("%d ",mid);
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
} 
  
int main(void) 
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
	sort(arr,arr+n);
	int in=1;
	if (in==1)
	{
		clock_t time; 
		time = clock();
		double total=0;
		for (int x=1;x<=1000000;x++)
		{
			int result = binarySearch(arr, 0, n - 1, x); 
			//printf("%d ",result);
			if (x%100000==0)
			{
				time = clock()-time; 
				double tle = ((double) time)/ CLOCKS_PER_SEC ;
				total+=tle;
				printf("%d searches done in %lf seconds\n",x,total);
			}
		}
	}
    return 0; 
} 
