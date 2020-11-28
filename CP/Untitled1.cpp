#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


int main ()
{
	char s [1000000];
	int done[100000];
	int n,g=0,temp,k,count=0;
	scanf("%d %d",&n,&k);
	scanf("%s",s);
	for (int i=0;i<strlen(s);i++)
	{
		g++;
		if (g>k)
		{
			break;
		}
		for (int z=0;z<count;z++)
		{
			printf("%d %d\n",i,g);
			if (done[z]==i)
			{
				g--;
			}
		}
		temp=s[i];
		while (temp==s[i])
		{
			i++;
		}
		for (int j=strlen(s);j>=i;j--)
		{
			if (s[j]==temp)
			{
				done[count]=j;
				count++;
				break;
			}
			if (j==i)
			{
				g--;
				break;
			}
		}
	}	
	if (g>k)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
