
#include<stdio.h>

int func (int n)
{
	int skrng = 3,c,d,cek;
	if (n==1) return 2;
	for (c=1;c<n;skrng++)
	{
		cek=1;
		for (d=2;d<skrng;d++)
		{
			if (skrng%d==0)
			cek=0;
		}
		if (cek==1) 
		c++;
	}
	return skrng-1;
}

int main ()
{
	int n;
	while (scanf("%d",&n)==1)
	printf("%d\n",func(n));
	return 0;
}
