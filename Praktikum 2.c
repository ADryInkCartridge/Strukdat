#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//func hehe(var N as int, var K as int, var ARR as int array)
//	for i from 0 to N-K
//		MAX = INT_MIN
//		for j from i to i+K-1
//			if MAX < ARR[j]
//				MAX = ARR[j]
//		PRINT MAX
//end func


void hehe (int n, int k, int arr[])
{
	for (int i=0;i<=n-k;i++)	
	{
		int max=arr[i];
		//printf("%d",&arr[0]);
		for (int j=i;j<=i+k-1;j++)
		{
			if (max<arr[j])
			{
				max=arr[j];
			}
		}
		printf("%d ",max);
	}
	printf("\n");
}

// Quicksort trus ambil paling ujung dengan size dari I -> i+k-
void partition (int low, int high, int arr[])
{
	
}

void qsort (int low,int high,int arr[])
{
	partition 
	if (high)
}

int main ()
{
	int tc;
	scanf ("%d",&tc);
	for (int test=0;test<tc;test++)
	{
		int n,k;
		scanf ("%d %d",&n,&k);
		int arr[n];
		for (int i=0;i<n;i++)
		{
			scanf ("%d",&arr[i]);
		//	printf ("%d ",arr[i]);	
		}
		qsort(n,0,arr);
		hehe (n,k,arr);
	}
}
