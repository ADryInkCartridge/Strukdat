#include <bits/stdc++.h> 
using namespace std; 
long long int s;
int rank1(int n,long long int p[],long long int p2[])
{
	if (n=1)
	{
		return s;
	}
	long long int s=p[n-1];
	swap(p[n-1], p[p2[n-1]]);
	swap(p2[s], p2[n-1]);
	return (s+n*rank1(n-1,p,p2));
}

int main ()
{
	int n ;
  	cin >> n;
  	long long int p[100000];
  	long long int p2[100000];
  	for (int i=0;i<n;i++)
  	{
  		long long int in;
  		cin >> p[i];
	}
	for (int i=0;i<n;i++)
	{
		p2[p[i]]=i;
	}
	for (int i=0;i<n;i++)
	{
		p2[p[i]]=i;
	}
	rank1(n-1,p,p2);
	cout << s%1000000007;
}
