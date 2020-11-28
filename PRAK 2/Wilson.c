#include <stdio.h>
#include <string.h>
int main ()
{
	int check,n;
	int count=0;
	int arr[1000];
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for (int j=0;j<n;j++)
	{
		for (int i=j;i<n;i++)
		{
			if (arr[j]==NULL)
			{
				j++;
				break;
				
			}
			if (arr[i]!=NULL && arr[i]==arr[j])
			{
				count++;
				arr[i]=NULL;
			}
		}
	}
	printf("%d\n",count);
}
