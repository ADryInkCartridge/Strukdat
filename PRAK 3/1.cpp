#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

   long long int n,k,x,y;
   scanf("%lld %lld",&n,&k);
   int board[n+1][n+1];
   //printf("%d\n",board[4][2]);
   for (int i=1;i<=n;i++)
   {
		for (int j=1;j<=n;j++)
		{
			board[i][j]=0;
		}
   }

   for (int i=0;i<k;i++)
   {
   		//printf ("LOOP %d\n",i);
   		scanf ("%lld %lld",&x,&y);
   		board[x][y]=1;
   		int x1=x;
   		int y1=y;
   		//printf("%d\n",board[4][2]);
   		while (x1>=1 && y1>=1)
   		{
   		//	printf("x1= %d y1= %d\n",x1,y1);
   			board[--x1][--y1]=1;
		}
		//printf("%d\n",board[4][2]);
		x1=x;
		y1=y;
		while (x1<=n && y1<=n)
   		{
   		//	printf("x1= %d y1= %d\n",x1,y1);
   			board[++x1][++y1]=1;
		}
		//printf("%d\n",board[4][2]);
		x1=x;
		y1=y;
		while (x1>=1 && y1<=n)
   		{
   		//	printf("x1= %d y1= %d\n",x1,y1);
   			board[--x1][++y1]=1;
		}
		//printf("%d\n",board[4][2]);
		//puts("");
		x1=x;
		y1=y;
		while (x1<=n && y1>=1)
   		{
   			//printf("x1= %d y1= %d\n",x1,y1);
   			board[++x1][--y1]=1;
		}	
		//printf("%d\n",board[4][2]);
   }
   long long int count=0;
   for (int i=1;i<=n;i++)
   {
		for (int j=1;j<=n;j++)
		{
			if (board[i][j]==1)
			{
				//printf("x= %d y=% d\n",i,j);
				count++;
			}
		}
   }
   printf("%lld\n",count);
    return 0;
}
