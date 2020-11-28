#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

	long long int m,n;
    scanf("%lld %lld",&m,&n);
    long long int total[m+1];
    for (int i=1;i<=m;i++)
    {
    	long long int id,price;
    	scanf ("%lld %lld",&id,&price);
    	if (id!=i)
    	{
    		printf("ID harus urut\n");
    		return 0;
		}
		else
		{
			total[id]=price;
			//printf("%lld %lld\n",id,total[id]);
		}
	}
	long long int all=0;
	for (int i=1;i<=n;i++)
	{
		long long int ids,sale;
    	scanf ("%lld %lld",&sale,&ids);
    	if (ids>m)
    	{
    		printf("Maaf barang tidak tersedia\n");
    		continue;
		}
		else 
		{
			all=all+total[ids]*sale;
			//printf("%lld %lld\n",ids,total[ids]);
		}
	}
	printf("%lld\n",all);
    return 0;
}
