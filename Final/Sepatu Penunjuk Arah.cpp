#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n,orang,count=0;
	int num = 0;
	cin >> n;
	vector <int> mid;
	vector <int> other;
	for (int i=1;i<=n;i++)
	{
		num=count;
		other.clear();
		for (int j=1;j<=i;j++)
		{
			count = num + j;
			if(count%10 == 0)
			{
				count++;
				num++;
			}
			other.push_back(count);
		}
		if (i%2!=0)
		{
			mid.push_back(other.at(ceil(i/2)));
		}
		else
		{
			mid.push_back(other.at(ceil(i/2)-1));
		}
	}
	cout << mid.at(n-1) << endl;
}
