#include <bits/stdc++.h>
using namespace std;

int main ()
{
	while (1)
	{	
		int n,k,max=0,count=0,flag=0;
		cin >> n >> k;
		pair<int,int> jadwal[101];
		stack<int> s;
		if (n==0 && k==0)
		{
			return 0;
		}
		for (int i=0;i<n;i++)
		{
			cin >> jadwal[i].first >> jadwal[i].second;
			if (jadwal[i].second>max)
			{
				max=jadwal[i].second;
			}
			if (jadwal[i].first>max)
			{
				max=jadwal[i].first;
			}
		}
		for (int time=0;time<=max;time++)
		{
			if (!s.empty())
			{
				if (time==s.top())
				{
					s.pop();
				}
			}
			for (int i=0;i<n;i++)
			{
				if (time==jadwal[i].first)
				{
					s.push(jadwal[i].second);
				}
			}
			if (s.size() > k)
			{
				printf("Gak Bisa Woi\n");
				flag=1;
				break;
			}
		}
		if (flag==0)
		{
			printf("Lancar Jaya\n");
		}
	}
}
