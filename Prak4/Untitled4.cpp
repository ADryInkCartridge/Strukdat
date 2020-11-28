#include <bits/stdc++.h>
using namespace std;
long long int ans[26];
vector<int> graph[26];
void findit(long long int count,long long int n)
{
	if (count == n)
	{
		ans[]++;
	}
	if( count < n)
	{
		for (int i=0;i<graph.end();i++)
	}
}

int main ()
{
	int m;
	cin >> m;
	pair <int,int> c;
	for (int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		a=a-97;
		b=b-97;
		graph[a].push_back(b);
	}
	int q;
	cin >> q;
	for (int i=0;i<q;i++)
	{
		long long int n;
		cin >> n;
		findit(0,n);
		for (int i=0;i<26;i++)
		{
			cout << ans[i]% 10^9+7 << " ";
		}
		cout << endl;
	}
}
